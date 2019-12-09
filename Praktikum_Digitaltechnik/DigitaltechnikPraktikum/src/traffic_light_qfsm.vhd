------------------------------------------------------------------
-- Module     : traffic_light
------------------------------------------------------------------
-- Author     : H.F.
-- Company    : University of Applied Sciences Augsburg
------------------------------------------------------------------
-- Description: FSM of a traffic light
--              0.1: first simple version with 4 states and 3 light outputs,
--              including one next phase enable signal next_phase_en_pi
------------------------------------------------------------------
-- Revisions : 0.1 - 
------------------------------------------------------------------

-- Inputs:   en_pi   end_of_phase_pi
-- State/Output    ld_cnt_po phase_select_o[1] phase_select_o[0] ns_red_o ns_yellow_o ns_green_o ew_red_o ew_yellow_o ew_green_o
-- ld_red_phase    1         0                 0                 1        0           0          0        0           1          
-- red_state       0         0                 0                 1        0           0          0        0           1          
-- ld_ry_phase     1         0                 1                 1        1           0          0        1           0          
-- redyellow_state 0         0                 1                 1        1           0          0        1           0          
-- ld_g_phase      1         1                 0                 1        1           0          0        1           0          
-- green_state     0         1                 0                 0        0           1          1        0           0          
-- ld_y_phase      1         1                 1                 0        1           0          1        0           0          
-- yellow_state    0         1                 1                 0        1           0          1        1           0          

LIBRARY IEEE;

USE IEEE.std_logic_1164.ALL;

ENTITY traffic_light IS
  PORT (clk: IN std_ulogic;
        rst_n: IN std_ulogic;
        en_pi: IN std_ulogic;
        end_of_phase_pi: IN std_ulogic;
        ld_cnt_po: OUT std_ulogic;
        phase_select_o: OUT std_ulogic_vector(1 DOWNTO 0);
        ns_red_o: OUT std_ulogic;
        ns_yellow_o: OUT std_ulogic;
        ns_green_o: OUT std_ulogic;
        ew_red_o: OUT std_ulogic;
        ew_yellow_o: OUT std_ulogic;
        ew_green_o: OUT std_ulogic);
END traffic_light;

ARCHITECTURE behave OF traffic_light IS

TYPE state_type IS (ld_red_phase, red_state, ld_ry_phase, redyellow_state, ld_g_phase, green_state, ld_y_phase, yellow_state);
SIGNAL next_state, current_state : state_type;

BEGIN
  state_register: PROCESS (rst_n, clk)
  BEGIN
    IF rst_n='0' THEN
      current_state <= ld_red_phase;
    ELSIF rising_edge(clk) THEN
      current_state <= next_state;
    END IF;
  END PROCESS;

  next_state_and_output_logic: PROCESS (current_state, en_pi, end_of_phase_pi)
    VARIABLE temp_input : std_ulogic_vector(1 DOWNTO 0);
    VARIABLE temp_output : std_ulogic_vector(8 DOWNTO 0);
  BEGIN
    temp_input := en_pi & end_of_phase_pi;
    CASE current_state IS
      WHEN ld_red_phase => temp_output := "100100001";
          next_state <= red_state;
      WHEN red_state => temp_output := "000100001";
        IF temp_input="00" or temp_input="10" or temp_input="01" THEN
          next_state <= red_state;
        ELSIF temp_input="11" THEN
          next_state <= ld_ry_phase;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN ld_ry_phase => temp_output := "101110010";
          next_state <= redyellow_state;
      WHEN redyellow_state => temp_output := "001110010";
        IF temp_input="11" THEN
          next_state <= ld_g_phase;
        ELSIF temp_input="00" or temp_input="01" THEN
          next_state <= redyellow_state;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN ld_g_phase => temp_output := "110110010";
          next_state <= green_state;
      WHEN green_state => temp_output := "010001100";
        IF temp_input="00" or temp_input="10" or temp_input="01" THEN
          next_state <= green_state;
        ELSIF temp_input="11" THEN
          next_state <= ld_y_phase;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN ld_y_phase => temp_output := "111010100";
          next_state <= yellow_state;
      WHEN yellow_state => temp_output := "011010110";
        IF temp_input="11" THEN
          next_state <= ld_red_phase;
        ELSIF temp_input="00" or temp_input="01" THEN
          next_state <= yellow_state;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN OTHERS => temp_output := (OTHERS =>'X');
      next_state <= ld_red_phase;
    END CASE;
    ld_cnt_po <= temp_output(8);
    phase_select_o(1) <= temp_output(7);
    phase_select_o(0) <= temp_output(6);
    ns_red_o <= temp_output(5);
    ns_yellow_o <= temp_output(4);
    ns_green_o <= temp_output(3);
    ew_red_o <= temp_output(2);
    ew_yellow_o <= temp_output(1);
    ew_green_o <= temp_output(0);
  END PROCESS;

END behave;
