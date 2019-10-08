-------------------------------------------------------------------------------
-- Module     : t_mux2to1
-------------------------------------------------------------------------------
-- Author     :   <haf@fh-augsburg.de>
-- Company    : University of Applied Sciences Augsburg
-- Copyright (c) 2011   <haf@fh-augsburg.de>
-------------------------------------------------------------------------------
-- Description: Testbench for design "mux2to1"
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

-------------------------------------------------------------------------------

ENTITY t_mux2to1 IS
END t_mux2to1;

-------------------------------------------------------------------------------

ARCHITECTURE tbench OF t_mux2to1 IS

  COMPONENT mux2to1
    PORT (
      a_i   : IN  std_ulogic;
      b_i   : IN  std_ulogic;
      sel_i : IN  std_ulogic;
      y_o   : OUT std_ulogic);
  END COMPONENT;

  -- definition of a clock period
  CONSTANT period : time := 10 ns;

  -- component ports
  SIGNAL a_i   : std_ulogic;
  SIGNAL b_i   : std_ulogic;
  SIGNAL sel_i : std_ulogic;
  SIGNAL y_o   : std_ulogic;
  
BEGIN  -- tbench

  -- component instantiation
  MUV : mux2to1
    PORT MAP (
      a_i   => a_i,
      b_i   => b_i,
      sel_i => sel_i,
      y_o   => y_o);

  stimuli_p : PROCESS

    -- purpose: apply stimuli to input signals of module under test
    PROCEDURE apply_stimuli (
      CONSTANT sel_stim, b_stim, a_stim : IN std_ulogic) IS
    BEGIN  -- apply_stimuli
      a_i   <= a_stim;
      b_i   <= b_stim;
      sel_i <= sel_stim;
      WAIT FOR period;
    END PROCEDURE apply_stimuli;
  
  BEGIN
    a_i   <= '0';                       -- set a value to input a_i 
    b_i   <= '0';                       -- set a value to input b_i 
    sel_i <= '0';                       -- set a value to input ci_i 
    WAIT FOR period;                    -- values are assigned here

    a_i <= '1';                         -- change value of a_i
    WAIT FOR period;

    a_i <= '0';                         -- change value of a_i
    b_i <= '1';                         -- change value of b_i
    WAIT FOR period;

    -- alternatively, a local procedure can be used to assign input values:
--    apply_stimuli('0', '0', '0');
--    apply_stimuli('0', '0', '1');
--    apply_stimuli('0', '1', '0');
    apply_stimuli('0', '1', '1');
    apply_stimuli('1', '0', '0');
    apply_stimuli('1', '0', '1');
    apply_stimuli('1', '1', '0');
    apply_stimuli('1', '1', '1');

    WAIT;
  END PROCESS;

END tbench;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------
