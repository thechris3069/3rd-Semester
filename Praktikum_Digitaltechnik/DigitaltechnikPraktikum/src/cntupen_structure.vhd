-------------------------------------------------------------------------------
-- Module     : cntupen
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: Up-Counter
--              including a low-active asynchronous reset input rst_ni
--              and a high-active enable input en_pi
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY cntupen IS
  PORT (clk_i   : IN  std_ulogic;
        rst_ni  : IN  std_ulogic;
        en_pi   : IN  std_ulogic;
        count_o : OUT std_ulogic_vector(3 DOWNTO 0)
        );
END cntupen;

ARCHITECTURE structure OF cntupen IS

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

  incrementer : ENTITY work.add4(structure)
    PORT MAP (
      -- insert port mappings here

      
  state_register : ENTITY work.dregen(rtl)
    PORT MAP (
      -- insert port mappings here

      
  counter_output : count_o <= current_state;

END structure;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

