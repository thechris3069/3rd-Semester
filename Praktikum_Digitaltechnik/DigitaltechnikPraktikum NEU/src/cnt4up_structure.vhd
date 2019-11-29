-------------------------------------------------------------------------------
-- Module     : cnt4up
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: 4-Bit Up-Counter
--              including a low-active asynchronous reset input rst_ni
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY cnt4up IS
  PORT (clk_i   : IN  std_ulogic;
        rst_ni  : IN  std_ulogic;
        count_o : OUT std_ulogic_vector(3 DOWNTO 0)
        );
END cnt4up;

ARCHITECTURE structure OF cnt4up IS

  COMPONENT dreg
    PORT (
      clk_i  : IN  std_ulogic;
      rst_ni : IN  std_ulogic;
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
      a_i   => B"0001",
      b_i   => current_state,
      ci_i  => '0',
      sum_o => next_state,
      co_o  => OPEN);

  state_register : ENTITY work.dreg(structure)
    PORT MAP (
      clk_i  => clk_i,
      rst_ni => rst_ni,
      d_i    => next_state,
      q_o    => current_state);

  counter_output : count_o <= current_state;

END structure;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

