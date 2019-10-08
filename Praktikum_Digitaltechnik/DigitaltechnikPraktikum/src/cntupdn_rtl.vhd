-------------------------------------------------------------------------------
-- Module     : cntupdn
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: n-Bit Up-Down-Counter
--              including a low-active asynchronous reset input rst_ni
--              and a high-active enable input en_pi
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY cntupdn IS
  GENERIC (
    n : positive := 4);                 -- counter width
  PORT (clk_i   : IN  std_ulogic;
        rst_ni  : IN  std_ulogic;
        en_pi   : IN  std_ulogic;
        mode_i  : IN  std_ulogic;
        count_o : OUT std_ulogic_vector(n-1 DOWNTO 0)
        );
END cntupdn;

ARCHITECTURE rtl OF cntupdn IS

  SIGNAL next_state, current_state : std_ulogic_vector(n-1 DOWNTO 0);
  SIGNAL increment, decrement      : std_ulogic_vector(n-1 DOWNTO 0);
  
BEGIN

  decrementer : decrement <= std_ulogic_vector(unsigned(current_state) - 1);

  incrementer : increment <= std_ulogic_vector(unsigned(current_state) + 1);

  state_register : PROCESS (rst_ni, clk_i)
  BEGIN
    IF rst_ni = '0' THEN
      current_state <= (OTHERS => '0');
    ELSIF rising_edge(clk_i) THEN
      IF en_pi = '1' THEN
        current_state <= next_state;
      END IF;
    END IF;
  END PROCESS state_register;

  mode_mux : next_state <= increment WHEN mode_i = '1' ELSE
                           decrement WHEN mode_i = '0' ELSE
                           (OTHERS => 'X');

  counter_output : count_o <= current_state;

END rtl;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

