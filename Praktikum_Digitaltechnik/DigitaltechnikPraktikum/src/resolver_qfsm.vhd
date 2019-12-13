------------------------------------------------------------------
-- Module     : resolver
------------------------------------------------------------------
-- Author     : H.F.
-- Company    : University of Applied Sciences Augsburg
------------------------------------------------------------------
-- Description: FSM for resolving a quadrature input signal
--              at sensor1, sensor0 to produce
--              a direction signal dir_or (1:= forward, 0:= backward) and
--              a high-active enable signal en_po
--              
--              v0.1: using 12 states: 4 forward, 4 backward, 4 idle
--              v0.2: adding state init to decide which idle state is correct
--              adding states delay0, delay1 due to external input synchronisation
------------------------------------------------------------------
-- Revisions : 0.2 - 
------------------------------------------------------------------

-- Inputs:   sensor_i[1]   sensor_i[0]
-- State/Output en_po dir_o
-- idle1        0     0     
-- idle3        0     0     
-- idle2        0     0     
-- idle0        0     0     
-- fw1          1     1     
-- fw3          1     1     
-- fw2          1     1     
-- fw0          1     1     
-- bw0          1     0     
-- bw1          1     0     
-- bw3          1     0     
-- bw2          1     0     

LIBRARY IEEE;

USE IEEE.std_logic_1164.ALL;

ENTITY resolver IS
  PORT (clk: IN std_ulogic;
        rst_n: IN std_ulogic;
        sensor_i: IN std_ulogic_vector(1 DOWNTO 0);
        en_po: OUT std_ulogic;
        dir_o: OUT std_ulogic);
END resolver;

ARCHITECTURE behave OF resolver IS

TYPE state_type IS (idle1, idle3, idle2, idle0, fw1, fw3, fw2, fw0, bw0, bw1, bw3, bw2);
SIGNAL next_state, current_state : state_type;

BEGIN
  state_register: PROCESS (rst_n, clk)
  BEGIN
    IF rst_n='0' THEN
      current_state <= idle0;
    ELSIF rising_edge(clk) THEN
      current_state <= next_state;
    END IF;
  END PROCESS;

  next_state_and_output_logic: PROCESS (current_state, sensor_i(1 DOWNTO 0))
    VARIABLE temp_input : std_ulogic_vector(1 DOWNTO 0);
    VARIABLE temp_output : std_ulogic_vector(1 DOWNTO 0);
  BEGIN
    temp_input := sensor_i(1) & sensor_i(0);
    CASE current_state IS
      WHEN idle1 => temp_output := "00";
        IF temp_input="11" THEN
          next_state <= fw3;
        ELSIF temp_input="00" THEN
          next_state <= bw0;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN idle3 => temp_output := "00";
        IF temp_input="10" THEN
          next_state <= fw2;
        ELSIF temp_input="01" THEN
          next_state <= bw1;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN idle2 => temp_output := "00";
        IF temp_input="00" THEN
          next_state <= fw0;
        ELSIF temp_input="11" THEN
          next_state <= bw3;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN idle0 => temp_output := "00";
        IF temp_input="01" THEN
          next_state <= fw1;
        ELSIF temp_input="00" THEN
          next_state <= idle0;
        ELSIF temp_input="10" THEN
          next_state <= bw2;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN fw1 => temp_output := "11";
          next_state <= idle1;
      WHEN fw3 => temp_output := "11";
        IF temp_input="00" or temp_input="10" or temp_input="01" or temp_input="11" THEN
          next_state <= idle3;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN fw2 => temp_output := "11";
        IF temp_input="00" or temp_input="10" or temp_input="01" or temp_input="11" THEN
          next_state <= idle2;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN fw0 => temp_output := "11";
        IF temp_input="00" or temp_input="10" or temp_input="01" or temp_input="11" THEN
          next_state <= idle0;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN bw0 => temp_output := "10";
        IF temp_input="00" or temp_input="10" or temp_input="01" or temp_input="11" THEN
          next_state <= idle0;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN bw1 => temp_output := "10";
        IF temp_input="00" or temp_input="10" or temp_input="01" or temp_input="11" THEN
          next_state <= idle1;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN bw3 => temp_output := "10";
        IF temp_input="00" or temp_input="10" or temp_input="01" or temp_input="11" THEN
          next_state <= idle3;
        ELSE
          next_state <= current_state;
        END IF;
      WHEN bw2 => temp_output := "10";
          next_state <= idle2;
      WHEN OTHERS => temp_output := (OTHERS =>'X');
      next_state <= idle0;
    END CASE;
    en_po <= temp_output(1);
    dir_o <= temp_output(0);
  END PROCESS;

END behave;
