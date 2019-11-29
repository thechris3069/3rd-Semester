-------------------------------------------------------------------------------
-- Module     : incrementer
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: 4-Bit Incrementer
--              Based on two quadrature input signals sensor(1 DOWNTO 0)
--              a resolver module detects forward and backward to
--              control an up/down-counter
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY incrementer IS
  PORT (clk_i    : IN  std_ulogic;
        rst_ni   : IN  std_ulogic;
        sensor_i : IN  std_ulogic_vector(1 DOWNTO 0);
        count_o  : OUT std_ulogic_vector(3 DOWNTO 0)
        );
END incrementer;

ARCHITECTURE structure OF incrementer IS

  -- make components visible


  -- internal signals for connecting components
  SIGNAL enable    : std_ulogic;
  SIGNAL direction : std_ulogic;
  
BEGIN

  quadrature_resolver : resolver
    PORT MAP (


  updown_counter : cntupdn
    PORT MAP (

END structure;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

