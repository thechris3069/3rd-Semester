-------------------------------------------------------------------------------
-- Module     : de1_xor2
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: test the module xor2 on a DE1 prototype board
--              by connecting device under test (DUT) xor2
--              to input/output signals of the DE1 prototype board
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY de1_xor2 IS
  PORT (
    SW   : IN  std_ulogic_vector(1 DOWNTO 0);  -- Toggle Switch[1:0]
    LEDR : OUT std_ulogic_vector(1 DOWNTO 0);  -- LED Red[1:0]  
    LEDG : OUT std_ulogic                      -- LED Green[0] 
    );
END de1_xor2;

ARCHITECTURE structure OF de1_xor2 IS
  
  COMPONENT xor2
    PORT (
      a_i : IN  std_ulogic;
      b_i : IN  std_ulogic;
      f_o : OUT std_ulogic);
  END COMPONENT;
  
BEGIN

  -- connecting device under test with peripheral elements
  DUT : xor2
    PORT MAP (
      a_i => SW(0),
      b_i => SW(1),
      f_o => LEDG);                  -- connect output to green LED[0]

  -- connect switches to red LEDs
  LEDR <= SW;

END structure;
-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------
