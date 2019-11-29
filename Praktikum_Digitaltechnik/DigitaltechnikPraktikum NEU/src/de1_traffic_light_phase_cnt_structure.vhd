-------------------------------------------------------------------------------
-- Module     : de1_traffic_light_phase_cnt
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

ENTITY de1_traffic_light_phase_cnt IS
  PORT (
    CLOCK_50 : IN  std_ulogic;          -- 50 MHz Clock
    KEY      : IN  std_ulogic;          -- KEY[0] -> rst_ni
    SW : IN std_ulogic_vector(7 DOWNTO 0);  -- SW[3:0] -> red_phase_value
                                            -- SW[7:4] -> g_phase_value
    HEX0     : OUT std_ulogic_vector(6 DOWNTO 0);  -- HEX0 -> phase counter
    GPO_0_8  : OUT std_ulogic;          -- output at GPO_0_8 NS_YELLOW
    GPO_0_11 : OUT std_ulogic;          -- output at GPO_0_11 NS_RED
    GPO_0_26 : OUT std_ulogic;          -- output at GPO_0_26 NS_GREEN
    GPO_0_24 : OUT std_ulogic;          -- output at GPO_0_24 EW_YELLOW
    GPO_0_18 : OUT std_ulogic;          -- output at GPO_0_18 EW_RED
    GPO_0_19 : OUT std_ulogic           -- output at GPO_0_19 EW_GREEN
    );
END de1_traffic_light_phase_cnt;

ARCHITECTURE structure OF de1_traffic_light_phase_cnt IS

  COMPONENT binto7segment
    PORT (
      bin_i      : IN  std_ulogic_vector(3 DOWNTO 0);
      segments_o : OUT std_ulogic_vector(6 DOWNTO 0));
  END COMPONENT;

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

  COMPONENT traffic_light_phase_cnt IS
    PORT (
      clk_i           : IN  std_ulogic;
      rst_ni          : IN  std_ulogic;
      en_pi           : IN  std_ulogic;
      red_phase_value : IN  std_ulogic_vector(3 DOWNTO 0);
      ry_phase_value  : IN  std_ulogic_vector(3 DOWNTO 0);
      g_phase_value   : IN  std_ulogic_vector(3 DOWNTO 0);
      y_phase_value   : IN  std_ulogic_vector(3 DOWNTO 0);
      count_o         : OUT std_ulogic_vector(3 DOWNTO 0);
      ns_red_o        : OUT std_ulogic;
      ns_yellow_o     : OUT std_ulogic;
      ns_green_o      : OUT std_ulogic;
      ew_red_o        : OUT std_ulogic;
      ew_yellow_o     : OUT std_ulogic;
      ew_green_o      : OUT std_ulogic);
  END COMPONENT traffic_light_phase_cnt;
  
  SIGNAL clk_i       : std_ulogic;
  SIGNAL rst_ni      : std_ulogic;

  SIGNAL red_phase_value : std_ulogic_vector(3 DOWNTO 0);
  SIGNAL ry_phase_value  : std_ulogic_vector(3 DOWNTO 0);
  SIGNAL g_phase_value   : std_ulogic_vector(3 DOWNTO 0);
  SIGNAL y_phase_value   : std_ulogic_vector(3 DOWNTO 0);
  
  SIGNAL ns_red_o    : std_ulogic;
  SIGNAL ns_yellow_o : std_ulogic;
  SIGNAL ns_green_o  : std_ulogic;
  SIGNAL ew_red_o    : std_ulogic;
  SIGNAL ew_yellow_o : std_ulogic;
  SIGNAL ew_green_o  : std_ulogic;
  SIGNAL count_o     : std_ulogic_vector(3 DOWNTO 0);

  SIGNAL one_second_period : std_ulogic;

BEGIN

  -- connecting clock generator master clock of synchronous system
  clk_i <= CLOCK_50;

  -- connecting asynchronous system reset to digital system
  rst_ni <= KEY;

  -- assigning phase values:
  -- SW[3:0] -> red_phase_value
  red_phase_value <= SW(3 DOWNTO 0);
  -- SW[7:4] -> g_phase_value
  g_phase_value <= SW(7 DOWNTO 4);
  -- constant values to redyellow and yellow phase
  ry_phase_value  <= "0000";
  y_phase_value   <= X"0";  


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
  DUT : ENTITY work.traffic_light_phase_cnt
    PORT MAP (
      clk_i    => clk_i,
      rst_ni   => rst_ni,
      en_pi    => one_second_period,
      red_phase_value => red_phase_value,
      ry_phase_value  => ry_phase_value,
      g_phase_value   => g_phase_value,
      y_phase_value   => y_phase_value,
      count_o  => count_o,
      ns_red_o        => ns_red_o,
      ns_yellow_o     => ns_yellow_o,
      ns_green_o      => ns_green_o,
      ew_red_o        => ew_red_o,
      ew_yellow_o     => ew_yellow_o,
      ew_green_o      => ew_green_o);
  
  -- connecting output signals
  -- North-South street
  GPO_0_11    <= ns_red_o;
  GPO_0_8     <= ns_yellow_o;
  GPO_0_26    <= ns_green_o;
  -- East-West road
  GPO_0_24    <= ew_red_o;
  GPO_0_18    <= ew_yellow_o;
  GPO_0_19    <= ew_green_o;
  

  -- connecting count value to HEX display
  count_val : ENTITY work.binto7segment(truthtable)
    PORT MAP (
      bin_i      => count_o,
      segments_o => HEX0);

END structure;
-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------
