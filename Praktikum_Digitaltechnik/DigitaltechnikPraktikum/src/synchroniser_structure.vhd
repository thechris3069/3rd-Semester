-------------------------------------------------------------------------------
-- Module     : synchroniser
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: synchronises an external input signal unsync_i
--              to the clock domain of clk_i
--              an provides an output signal sync_o
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY synchroniser IS
  PORT (
    clk_i    : IN  std_ulogic;
    rst_ni   : IN  std_ulogic;
    unsync_i : IN  std_ulogic;
    sync_o   : OUT std_ulogic
    );
END synchroniser;

ARCHITECTURE structure OF synchroniser IS

  
BEGIN



END structure;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

