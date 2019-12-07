-------------------------------------------------------------------------------
-- Module     : rising_edge_detector
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: detects a rising edge of input signal x_i
--              and produces a high-active signal for one clock period at
--              output rise_o
--              clk_i  __|--|__|--|__|--|__|--|__|--|__|--|__|--|__|--|__|--|
--                x_i  _____|-----------------------------------|___________
--              rise_o ________|-----|______________________________________
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY rising_edge_detector IS
  PORT (
    clk_i  : IN  std_ulogic;
    rst_ni : IN  std_ulogic;
    x_i    : IN  std_ulogic;
  --  new_i    : IN  std_ulogic;
    --new_o    : OUT  std_ulogic;
    rise_o : OUT std_ulogic
    );
END rising_edge_detector;

ARCHITECTURE structure OF rising_edge_detector IS

  COMPONENT d_ff
    PORT (
      clk_i  : IN  std_ulogic;
      rst_ni : IN  std_ulogic;
      d_i    : IN  std_ulogic;
      q_o    : OUT std_ulogic);
  END COMPONENT;

  SIGNAL q0, q1 : std_ulogic;           -- D-Type Flip-Flop outputs
  
BEGIN

  dflipflop_0 : d_ff
    PORT MAP (
      clk_i  => clk_i,
      rst_ni => rst_ni,
      d_i    => x_i,
      q_o    => q0);

  dflipflop_1 : d_ff
    PORT MAP (
      clk_i  => clk_i,
      rst_ni => rst_ni,
      d_i    => q0,
      q_o    => q1);

  output_logic : rise_o <= ((NOT q1) AND q0);          -- <- fill in correct equation here
 -- output_logic : new_o <= q1 AND new_i;
  
END structure;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

