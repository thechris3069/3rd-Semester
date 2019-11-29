------------------------------------------------------------------
-- Module     : cnt2dnmod3
------------------------------------------------------------------
-- Author     : H.F.
-- Company    : University of Applied Sciences Augsburg
------------------------------------------------------------------
-- Description: 2-Bit Modulo-3 Down-Counter modelled by QFSM
------------------------------------------------------------------
-- Revisions : 0.1 - 
------------------------------------------------------------------

-- Inputs:   en_pi
-- State/Output tc_o count_o[1] count_o[0]
-- s0           1    0          0          
-- s1           0    1          0          
-- s2           0    0          1          

LIBRARY IEEE;

USE IEEE.std_logic_1164.ALL;

ENTITY cnt2dnmod3 IS
  PORT (clk: IN std_ulogic;
        rst_n: IN std_ulogic;
        en_pi: IN std_ulogic;
        tc_o: OUT std_ulogic;
        count_o: OUT std_ulogic_vector(1 DOWNTO 0));
END cnt2dnmod3;

ARCHITECTURE behave OF cnt2dnmod3 IS

TYPE state_type IS (s0, s1, s2);
SIGNAL next_state, current_state : state_type;

BEGIN
  state_register: PROCESS (rst_n, clk)
  BEGIN
    IF rst_n='0' THEN
      current_state <= s0;
    ELSIF rising_edge(clk) THEN
      current_state <= next_state;
    END IF;
  END PROCESS;

  next_state_and_output_logic: PROCESS (current_state, en_pi)
    VARIABLE temp_input : std_ulogic_vector(0 DOWNTO 0);
    VARIABLE temp_output : std_ulogic_vector(2 DOWNTO 0);
  BEGIN
    temp_input(0) := en_pi;
    CASE current_state IS
      WHEN s0 => temp_output := "100";
        CASE temp_input IS
          WHEN "0" =>
            next_state <= s0;
          WHEN "1" =>
            next_state <= s1;
          WHEN OTHERS => next_state <= current_state;
        END CASE;
      WHEN s1 => temp_output := "010";
        CASE temp_input IS
          WHEN "0" =>
            next_state <= s1;
          WHEN "1" =>
            next_state <= s2;
          WHEN OTHERS => next_state <= current_state;
        END CASE;
      WHEN s2 => temp_output := "001";
        CASE temp_input IS
          WHEN "0" =>
            next_state <= s2;
          WHEN "1" =>
            next_state <= s0;
          WHEN OTHERS => next_state <= current_state;
        END CASE;
      WHEN OTHERS => temp_output := (OTHERS =>'X');
      next_state <= s0;
    END CASE;
    tc_o <= temp_output(2);
    count_o(1) <= temp_output(1);
    count_o(0) <= temp_output(0);
  END PROCESS;

END behave;
