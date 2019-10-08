-------------------------------------------------------------------------------
-- Module     : cntupdn
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: 4-Bit Up-Down-Counter
--              including a low-active asynchronous reset input rst_ni
--              and a high-active enable input en_pi
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY cntupdn IS
  PORT (clk_i   : IN  std_ulogic;
        rst_ni  : IN  std_ulogic;
        en_pi   : IN  std_ulogic;
        mode_i  : IN  std_ulogic;
        count_o : OUT std_ulogic_vector(3 DOWNTO 0)
        );
END cntupdn;

ARCHITECTURE structure OF cntupdn IS

  COMPONENT dregen
    PORT (
      clk_i  : IN  std_ulogic;
      rst_ni : IN  std_ulogic;
      en_pi  : IN  std_ulogic;
      d_i    : IN  std_ulogic_vector(3 DOWNTO 0);
      q_o    : OUT std_ulogic_vector(3 DOWNTO 0));
  END COMPONENT;

  COMPONENT add4
    PORT (
      a_i   : IN  std_ulogic_vector(3 DOWNTO 0);
      b_i   : IN  std_ulogic_vector(3 DOWNTO 0);
      ci_i  : IN  std_ulogic;
      sum_o : OUT std_ulogic_vector(3 DOWNTO 0);
      co_o  : OUT std_ulogic);
  END COMPONENT;


  SIGNAL next_state, current_state : std_ulogic_vector(3 DOWNTO 0);
  SIGNAL increment, decrement      : std_ulogic_vector(3 DOWNTO 0);
  
BEGIN

  decrementer : add4

    
  incrementer : add4

    
  state_register : dregen

    
  mode_mux : next_state <= increment WHEN mode_i = '1' ELSE
                           decrement WHEN mode_i = '0' ELSE
                           (OTHERS => 'X');


  counter_output : count_o <= current_state;

END structure;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

