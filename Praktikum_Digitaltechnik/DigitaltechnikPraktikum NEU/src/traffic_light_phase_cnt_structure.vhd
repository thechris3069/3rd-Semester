-------------------------------------------------------------------------------
-- Module     : traffic_light_phase_cnt
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: Traffic Light System
--              Based on a phase counter and a finite state machine controller
--              for the different light phases
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY traffic_light_phase_cnt IS
  PORT (clk_i           : IN  std_ulogic;
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
        ew_green_o      : OUT std_ulogic
        );
END traffic_light_phase_cnt;

ARCHITECTURE structure OF traffic_light_phase_cnt IS

  COMPONENT traffic_light IS
    PORT (
      clk             : IN  std_ulogic;
      rst_n           : IN  std_ulogic;
      en_pi           : IN  std_ulogic;
      end_of_phase_pi : IN  std_ulogic;
      ld_cnt_po       : OUT std_ulogic;
      phase_select_o  : OUT std_ulogic_vector(1 DOWNTO 0);
      ns_red_o        : OUT std_ulogic;
      ns_yellow_o     : OUT std_ulogic;
      ns_green_o      : OUT std_ulogic;
      ew_red_o        : OUT std_ulogic;
      ew_yellow_o     : OUT std_ulogic;
      ew_green_o      : OUT std_ulogic);
  END COMPONENT traffic_light;

  COMPONENT cntdnld IS
    PORT (
      clk_i   : IN  std_ulogic;
      rst_ni  : IN  std_ulogic;
      ld_pi   : IN  std_ulogic;
      en_pi   : IN  std_ulogic;
      data_i  : IN  std_ulogic_vector(3 DOWNTO 0);
      count_o : OUT std_ulogic_vector(3 DOWNTO 0);
      tc_o    : OUT std_ulogic);
  END COMPONENT cntdnld;

  SIGNAL end_of_phase : std_ulogic;
  SIGNAL ld_cnt       : std_ulogic;
  SIGNAL phase_select : std_ulogic_vector(1 DOWNTO 0);
  SIGNAL phase_data   : std_ulogic_vector(3 DOWNTO 0);

BEGIN

  tl_ctrl : ENTITY work.traffic_light
    PORT MAP (
      clk             => clk_i,
      rst_n           => rst_ni,
      en_pi           => en_pi,
      end_of_phase_pi => end_of_phase,
      ld_cnt_po       => ld_cnt,
      phase_select_o  => phase_select,
      ns_red_o        => ns_red_o,
      ns_yellow_o     => ns_yellow_o,
      ns_green_o      => ns_green_o,
      ew_red_o        => ew_red_o,
      ew_yellow_o     => ew_yellow_o,
      ew_green_o      => ew_green_o);

  phase_mux : phase_data <= red_phase_value WHEN phase_select = "00" ELSE
                            ry_phase_value WHEN phase_select = "01" ELSE
                            g_phase_value  WHEN phase_select = "10" ELSE
                            y_phase_value  WHEN phase_select = "11" ELSE
                            (OTHERS => 'X');


  phase_counter : ENTITY work.cntdnld
    PORT MAP (
      clk_i   => clk_i,
      rst_ni  => rst_ni,
      ld_pi   => ld_cnt,
      en_pi   => en_pi,
      data_i  => phase_data,
      count_o => count_o,
      tc_o    => end_of_phase);

END structure;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

