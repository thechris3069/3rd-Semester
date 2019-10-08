-------------------------------------------------------------------------------
-- Module     : xor2
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: 2-input exclusive or function
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY xor2 IS
  PORT (a_i : IN  std_ulogic;
        b_i : IN  std_ulogic;
        f_o : OUT std_ulogic
        );
END xor2;

ARCHITECTURE equation OF xor2 IS

BEGIN

  output_function: f_o <= a_i XOR b_i;

END equation;
-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

