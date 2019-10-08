-------------------------------------------------------------------------------
-- Module     : smencode
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: stepper motor encoder module
--              encodes binary dual values to drive a stepper motor
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY smencode IS
  PORT (bin_i : IN  std_ulogic_vector(2 DOWNTO 0);  -- binary dual input
        sm_o  : OUT std_ulogic_vector(3 DOWNTO 0) -- stepper motor output values
        );
END smencode;

ARCHITECTURE truthtable OF smencode IS

BEGIN



END truthtable;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

