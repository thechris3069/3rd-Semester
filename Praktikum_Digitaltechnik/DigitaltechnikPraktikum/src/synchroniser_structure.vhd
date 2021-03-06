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

COMPONENT d_ff 
  PORT (
    clk_i  : IN  std_ulogic;
    rst_ni : IN  std_ulogic;
    d_i    : IN  std_ulogic;
    q_o    : OUT std_ulogic
    );
END COMPONENT;
  SIGNAL  sync : std_ulogic;
BEGIN
d_ff_1 : d_ff
PORT MAP(
	clk_i => clk_i,
	rst_ni => rst_ni,
	d_i => unsync_i,
	q_o => sync);

	
d_ff_2 : d_ff
PORT MAP(
clk_i => clk_i,
rst_ni => rst_ni,
d_i => sync, 
q_o => sync_o);

END structure;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

