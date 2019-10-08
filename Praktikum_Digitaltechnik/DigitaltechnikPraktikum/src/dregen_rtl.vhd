-------------------------------------------------------------------------------
-- Module     : dregen
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: D-Type Register
--              including a low-active asynchronous reset input rst_ni
--              and a high-active enable input en_pi
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY dregen IS
  PORT (clk_i  : IN  std_ulogic;
        rst_ni : IN  std_ulogic;
        en_pi  : IN  std_ulogic;
        d_i    : IN  std_ulogic_vector;
        q_o    : OUT std_ulogic_vector
        );
END dregen;

ARCHITECTURE rtl OF dregen IS
  
  CONSTANT zero : std_ulogic_vector(d_i'length-1 DOWNTO 0) := (OTHERS => '0');

BEGIN
  dregister_p : q_o <= zero WHEN rst_ni = '0' ELSE
                       d_i WHEN rising_edge(clk_i) AND (en_pi = '1');
  
END rtl;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

