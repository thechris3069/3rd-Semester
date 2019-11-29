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
        d_i    : IN  std_ulogic_vector(3 DOWNTO 0);
        q_o    : OUT std_ulogic_vector(3 DOWNTO 0)
        );
END dregen;

ARCHITECTURE structure OF dregen IS

  COMPONENT dffen
    PORT (
      clk_i  : IN  std_ulogic;
      rst_ni : IN  std_ulogic;
      en_pi  : IN  std_ulogic;
      d_i    : IN  std_ulogic;
      q_o    : OUT std_ulogic);
  END COMPONENT;
  
BEGIN

  dffen_0 : dffen
    PORT MAP (
      clk_i  => clk_i,
      rst_ni => rst_ni,
      en_pi  => en_pi,
      d_i    => d_i(0),
      q_o    => q_o(0));

  dffen_1 : dffen
    PORT MAP (
      clk_i  => clk_i,
      rst_ni => rst_ni,
      en_pi  => en_pi,
      d_i    => d_i(1),
      q_o    => q_o(1));

  dffen_2 : dffen
    PORT MAP (
      clk_i  => clk_i,
      rst_ni => rst_ni,
      en_pi  => en_pi,
      d_i    => d_i(2),
      q_o    => q_o(2));

  dffen_3 : dffen
    PORT MAP (
      clk_i  => clk_i,
      rst_ni => rst_ni,
      en_pi  => en_pi,
      d_i    => d_i(3),
      q_o    => q_o(3));

END structure;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

