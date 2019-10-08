-------------------------------------------------------------------------------
-- Module     : de1_traffic_light
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: test the module traffic_light on a DE1 prototype board
--              connecting device under test (DUT) add1
--              to input/output signals of the DE1 prototype board
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY de1_traffic_light IS
  PORT (
    CLOCK_50 : IN  std_ulogic;                     -- 50 MHz Clock
    KEY      : IN  std_ulogic_vector(1 DOWNTO 0);  -- KEY[1:0]
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
END de1_traffic_light;

ARCHITECTURE structure OF de1_traffic_light IS
  COMPONENT rising_edge_detector
    PORT (
      clk_i  : IN  std_ulogic;
      rst_ni : IN  std_ulogic;
      x_i    : IN  std_ulogic;
      rise_o : OUT std_ulogic);
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

  SIGNAL clk      : std_ulogic;
  SIGNAL rst_n    : std_ulogic;
  SIGNAL red_o    : std_ulogic;
  SIGNAL yellow_o : std_ulogic;
  SIGNAL green_o  : std_ulogic;

  SIGNAL long_pulse    : std_ulogic;
  SIGNAL next_phase_en : std_ulogic;
  
BEGIN

  -- connecting clock generator master clock of synchronous system
  clk <= CLOCK_50;

  -- connecting asynchronous system reset to digital system
  rst_n <= KEY(0);

  -- count enable input is high-active
  long_pulse <= NOT KEY(1);

  -- connecting device under test with peripheral elements
  DUT : traffic_light
    PORT MAP (
      clk              => clk,
      rst_n            => rst_n,
      next_phase_en_pi => next_phase_en,
      red_o            => red_o,
      yellow_o         => yellow_o,
      green_o          => green_o);

  -- enable signal en_pi has to be connected via a rising edge detector
  single_pulse_generator : rising_edge_detector
    PORT MAP (
      clk_i  => clk,
      rst_ni => rst_n,
      x_i    => long_pulse,
      rise_o => next_phase_en);

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
