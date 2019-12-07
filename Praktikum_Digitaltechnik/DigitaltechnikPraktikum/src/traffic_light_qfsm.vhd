------------------------------------------------------------------
-- Module     : traffic_light
------------------------------------------------------------------
-- Author     : 
-- Company    : University of Applied Sciences Augsburg
------------------------------------------------------------------
-- Description: 
------------------------------------------------------------------
-- Revisions :  - 
------------------------------------------------------------------

-- Inputs:   next_phase_en_pi
-- State/Output    red_o yellow_o green_o
-- red_state0      1     0        0       
-- red_State1      1     0        0       
-- red_state2      1     0        0       
-- red_state3      1     0        0       
-- red_state4      1     0        0       
-- redyellow_state 1     1        0       
-- green_state     0     0        1       
-- green_state1    0     0        1       
-- green_state2    0     0        1       
-- yellow_state    0     1        0       

LIBRARY IEEE;

USE IEEE.std_logic_1164.ALL;

ENTITY traffic_light IS
  PORT (clk: IN std_ulogic;
        rst_n: IN std_ulogic;
        next_phase_en_pi: IN std_ulogic;
        red_o: OUT std_ulogic;
        yellow_o: OUT std_ulogic;
        green_o: OUT std_ulogic);
END traffic_light;

ARCHITECTURE behave OF traffic_light IS

TYPE state_type IS (red_state0, red_State1, red_state2, red_state3, red_state4, redyellow_state, green_state, green_state1, green_state2, yellow_state);
SIGNAL next_state, current_state : state_type;

BEGIN
  state_register: PROCESS (rst_n, clk)
  BEGIN
    IF rst_n='0' THEN
      current_state <= red_state0;
    ELSIF rising_edge(clk) THEN
      current_state <= next_state;
    END IF;
  END PROCESS;

  next_state_and_output_logic: PROCESS (current_state, next_phase_en_pi)
    VARIABLE temp_input : std_ulogic_vector(0 DOWNTO 0);
    VARIABLE temp_output : std_ulogic_vector(2 DOWNTO 0);
  BEGIN
    temp_input(0) := next_phase_en_pi;
    CASE current_state IS
      WHEN red_state0 => temp_output := "100";
        IF temp_input="1" THEN
          next_state <= red_State1;
        ELSIF temp_input="0" THEN
          next_state <= red_state0;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN red_State1 => temp_output := "100";
        IF temp_input="1" THEN
          next_state <= red_state2;
        ELSIF temp_input="0" THEN
          next_state <= red_State1;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN red_state2 => temp_output := "100";
        IF temp_input="1" THEN
          next_state <= red_state3;
        ELSIF temp_input="0" THEN
          next_state <= red_state2;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN red_state3 => temp_output := "100";
        IF temp_input="1" THEN
          next_state <= red_state4;
        ELSIF temp_input="0" THEN
          next_state <= red_state3;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN red_state4 => temp_output := "100";
        IF temp_input="1" THEN
          next_state <= redyellow_state;
        ELSIF temp_input="0" THEN
          next_state <= red_state4;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN redyellow_state => temp_output := "110";
        IF temp_input="1" THEN
          next_state <= green_state;
        ELSIF temp_input="0" THEN
          next_state <= redyellow_state;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN green_state => temp_output := "001";
        IF temp_input="1" THEN
          next_state <= green_state1;
        ELSIF temp_input="0" THEN
          next_state <= green_state;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN green_state1 => temp_output := "001";
        IF temp_input="1" THEN
          next_state <= green_state2;
        ELSIF temp_input="0" THEN
          next_state <= green_state1;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN green_state2 => temp_output := "001";
        IF temp_input="1" THEN
          next_state <= yellow_state;
        ELSIF temp_input="0" THEN
          next_state <= green_state2;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN yellow_state => temp_output := "010";
        IF temp_input="1" THEN
          next_state <= red_state0;
        ELSIF temp_input="0" THEN
          next_state <= yellow_state;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN OTHERS => temp_output := (OTHERS =>'X');
      next_state <= red_state0;
    END CASE;
    red_o <= temp_output(2);
    yellow_o <= temp_output(1);
    green_o <= temp_output(0);
  END PROCESS;

END behave;
