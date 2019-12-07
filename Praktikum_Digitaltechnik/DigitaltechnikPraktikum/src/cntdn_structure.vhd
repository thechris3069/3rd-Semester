-------------------------------------------------------------------------------
-- Module     : cntdn
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: n-Bit Down-Counter
--              including a low-active asynchronous reset input rst_ni
--              and a high-active enable input en_pi
--              additionally, a high_active output signal tc_o is produced,
--              when the counter reaches it's minimum value
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY cntdn IS
  PORT (clk_i   : IN  std_ulogic;
        rst_ni  : IN  std_ulogic;
        en_pi   : IN  std_ulogic;
        count_o : OUT std_ulogic_vector(3 DOWNTO 0);
        tc_o    : OUT std_ulogic
        );
END cntdn;

ARCHITECTURE structure OF cntdn IS


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



  
BEGIN

  --decrementer :
  decrementer : ENTITY work.add4(structure)
    PORT MAP (
      a_i   => B"1111",
      b_i   => current_state,
      ci_i  => '0',
      sum_o => next_state,
      co_o  => OPEN);
    

--  state_register :
  
        state_register : ENTITY work.dregen(rtl)
    PORT MAP (
      clk_i  => clk_i,
      rst_ni => rst_ni,
      en_pi => en_pi,
      d_i    => next_state,
      q_o    => current_state);
    
 -- counter_output :

      counter_output : count_o <= current_state;

  --terminal_count :
  tc_o <= (NOT (current_state(0) OR current_state(1) OR current_state(2) OR current_state(3)));
    

END structure;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

