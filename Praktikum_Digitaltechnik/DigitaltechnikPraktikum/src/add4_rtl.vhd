-------------------------------------------------------------------------------
-- Module     : add4
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: 4-bit adder
--              function modelled by '+'-operator
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY add4 IS
  PORT (a_i   : IN  std_ulogic_vector(3 DOWNTO 0);  -- operand a
        b_i   : IN  std_ulogic_vector(3 DOWNTO 0);  -- operand b
        ci_i  : IN  std_ulogic;                     -- carry in
        sum_o : OUT std_ulogic_vector(3 DOWNTO 0);  -- sum
        co_o  : OUT std_ulogic                      -- carry out
        );
END add4;

ARCHITECTURE rtl OF add4 IS

  SIGNAL temp_sum : unsigned(4 DOWNTO 0);

BEGIN

  -- add the missing function here ...

END rtl;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

