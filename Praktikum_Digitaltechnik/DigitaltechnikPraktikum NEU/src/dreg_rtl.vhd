-------------------------------------------------------------------------------
-- Module     : dreg
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: D-Type Register
--              including a low-active asynchronous reset input rst_ni
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY dreg IS
  PORT (clk_i  : IN  std_ulogic;
        rst_ni : IN  std_ulogic;
        d_i    : IN  std_ulogic_vector(3 DOWNTO 0);
        q_o    : OUT std_ulogic_vector(3 DOWNTO 0)
        );
END dreg;

ARCHITECTURE rtl OF dreg IS

  COMPONENT d_ff
    PORT (
      clk_i  : IN  std_ulogic;
      rst_ni : IN  std_ulogic;
      d_i    : IN  std_ulogic;
      q_o    : OUT std_ulogic);
  END COMPONENT;
  
BEGIN

  dregister_p : q_o <= "0000" WHEN rst_ni = '0' ELSE
                       d_i WHEN rising_edge(clk_i);
END rtl;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

