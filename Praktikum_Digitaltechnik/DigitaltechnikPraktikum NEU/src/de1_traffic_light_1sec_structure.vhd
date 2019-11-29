-------------------------------------------------------------------------------
-- Module     : de1_traffic_light_1sec
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: test the module traffic_light on a DE1 prototype board
--              connecting device under test (DUT) traffic_light
--              to input/output signals of the DE1 prototype board
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY de1_traffic_light_1sec IS
  PORT (
    CLOCK_50 : IN  std_ulogic;  -- 50 MHz Clock
    KEY      : IN  std_ulogic;  -- KEY[0]
    ---------------------------------------------------------------------------
    LEDG : OUT std_ulogic_vector(2 DOWNTO 0); -- traffic lights at green LEDs:
                                              --------------------------------
                                              -- RED    -> LEDG[0]
                                              -- YELLOW -> LEDG[1]
                                              -- GREEN  -> LEDG[2]
    ---------------------------------------------------------------------------
                                -- traffic lights on adapter board:
                                -----------------------------------
    GPO_0_8  : OUT std_ulogic;  -- output at GPO_0_8 NS_YELLOW
    GPO_0_11 : OUT std_ulogic;  -- output at GPO_0_11 NS_RED
    GPO_0_26 : OUT std_ulogic   -- output at GPO_0_26 NS_GREEN
    );
END de1_traffic_light_1sec;

ARCHITECTURE structure OF de1_traffic_light_1sec IS

  COMPONENT cntdnmodm
    GENERIC (
      n : natural;
      m : natural);
    PORT (
      clk_i   : IN  std_ulogic;
      rst_ni  : IN  std_ulogic;
      en_pi   : IN  std_ulogic;
      count_o : OUT std_ulogic_vector(n-1 DOWNTO 0);
      tc_o    : OUT std_ulogic);
  END COMPONENT;

  COMPONENT traffic_light
    PORT (
      clk              : IN  std_ulogic;
      rst_n            : IN  std_ulogic;
      next_phase_en_pi : IN  std_ulogic;
      red_o            : OUT std_ulogic;
      yellow_o         : OUT std_ulogic;
      green_o          : OUT std_ulogic);
  END COMPONENT;

  SIGNAL clk_i    : std_ulogic;
  SIGNAL rst_ni   : std_ulogic;
  SIGNAL red_o    : std_ulogic;
  SIGNAL yellow_o : std_ulogic;
  SIGNAL green_o  : std_ulogic;

  SIGNAL one_second_period : std_ulogic;

BEGIN

  -- connecting clock generator master clock of synchronous system
  clk_i <= CLOCK_50;

  -- connecting asynchronous system reset to digital system
  rst_ni <= KEY;

  -- based on the 50 MHz clock, generates an enable signal of period T = 1 sec
  clock_divider : cntdnmodm
    GENERIC MAP (
      n => 26,
      m => 50000000)
    PORT MAP (
      clk_i   => clk_i,
      rst_ni  => rst_ni,
      en_pi   => '1',                   -- permanently enabled
      count_o => OPEN,                  -- open, because not needed
      tc_o    => one_second_period);

  -- connecting device under test with peripheral elements
  DUT : traffic_light
    PORT MAP (
      clk              => clk_i,
      rst_n            => rst_ni,
      next_phase_en_pi => one_second_period,
      red_o            => red_o,
      yellow_o         => yellow_o,
      green_o          => green_o);

  -- connecting output signals on traffic light adapter board
  GPO_0_8  <= yellow_o;
  GPO_0_11 <= red_o;
  GPO_0_26 <= green_o;

  -- connecting output signals to green LEDs on DE1 board
  LEDG(0) <= red_o;
  LEDG(1) <= yellow_o;
  LEDG(2) <= green_o;

END structure;
-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------
