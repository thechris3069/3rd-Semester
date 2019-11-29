-------------------------------------------------------------------------------
-- Module     : decimal_upcounter
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: connection of components for a two-digit modulo-60 up-counter
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY decimal_upcounter IS
  PORT (
    clk_i       : IN  std_ulogic;
    rst_ni      : IN  std_ulogic;
    en_pi       : IN  std_ulogic;
    digit_one_o : OUT std_ulogic_vector(3 DOWNTO 0);
    digit_ten_o : OUT std_ulogic_vector(2 DOWNTO 0);
    tc_o        : OUT std_ulogic
    );
END decimal_upcounter;

ARCHITECTURE structure OF decimal_upcounter IS

  COMPONENT cnt4upmod10
    PORT (
      clk     : IN  std_ulogic;
      rst_n   : IN  std_ulogic;
      en_pi   : IN  std_ulogic;
      tc_o    : OUT std_ulogic;
      count_o : OUT std_ulogic_vector(3 DOWNTO 0));
  END COMPONENT;

  COMPONENT cnt3upmod6
    PORT (
      clk     : IN  std_ulogic;
      rst_n   : IN  std_ulogic;
      en_pi   : IN  std_ulogic;
      tc_o    : OUT std_ulogic;
      count_o : OUT std_ulogic_vector(2 DOWNTO 0));
  END COMPONENT;

  SIGNAL tc_digit_one : std_ulogic;
  SIGNAL digit_ten_en : std_ulogic;
  
BEGIN

  digit0 : cnt4upmod10
    PORT MAP (

      
  -- the terminal count output of the previous stage is used
  -- directly as input to the next stage !
  next_stage_enable : digit_ten_en <= tc_digit_one;


  digit1 : cnt3upmod6
    PORT MAP (

      
END structure;
-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------
