-------------------------------------------------------------------------------
-- Module     : cntdnld
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: 4-Bit Down-Counter
--              including a low-active asynchronous reset input rst_ni
--              and a high-active preload parallal input data control ld_pi
--              prioritised over a high-active enable input en_pi
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY cntdnld IS
  PORT (clk_i   : IN  std_ulogic;
        rst_ni  : IN  std_ulogic;
        ld_pi   : IN  std_ulogic;                     -- '1' -> preload data_i
        en_pi   : IN  std_ulogic;                     -- '1' -> enable counting
        data_i  : IN  std_ulogic_vector(3 DOWNTO 0);  -- data input
        count_o : OUT std_ulogic_vector(3 DOWNTO 0);
        tc_o    : OUT std_ulogic
        );
END cntdnld;

ARCHITECTURE structure OF cntdnld IS

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
  SIGNAL decrement, en_data        : std_ulogic_vector(3 DOWNTO 0);

BEGIN

  decrementer : add4
    PORT MAP (
      a_i   => current_state,                     
      b_i   => B"",                     -- fill in the increment
      ci_i  => '',                      -- set the correct constant
      sum_o => decrement,
      co_o  => OPEN);

  state_register : dreg
    PORT MAP (
      clk_i  => clk_i,
      rst_ni => rst_ni,
      d_i    => next_state,
      q_o    => current_state);

  -- Multiplexer Example:
  -----------------------------------------------------------------------------
  --     y_o <= a_i WHEN sel_i = '1' ELSE
  --            b_i WHEN sel_i = '0' ELSE
  --            (OTHERS => 'X');
  -----------------------------------------------------------------------------


  --  complete the multiplexer statement
  -----------------------------------------------------------------------------
  mux1 : next_state <= 


  -----------------------------------------------------------------------------


  --  complete the multiplexer statement
  -----------------------------------------------------------------------------
  mux2 : en_data <= 


  -----------------------------------------------------------------------------


  counter_output : count_o <= current_state;

  -- provides a H-active signal, when current_state = 0
  -- fill in a boolean equation 
  terminal_count : tc_o <= 



END structure;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

