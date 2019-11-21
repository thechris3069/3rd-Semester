-------------------------------------------------------------------------------
-- Module     : mux2to1
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: 2-to-1 multiplexer
--              function modelled as structure of basic logic gates
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY mux2to1 IS
  PORT (a_i   : IN  std_ulogic;
        b_i   : IN  std_ulogic;
        sel_i : IN  std_ulogic;
--        y_o   : OUT std_ulogic; -- kein ; nach letztem Signal
        y_o   : OUT std_ulogic
        );
--END mux21; Error (10396): VHDL syntax error at mux2to1_structure_errors.vhd(22): name used in construct must match previously specified name "mux2to1"
-- END mu2to1 Falsch geschrieben
END mux2to1;


ARCHITECTURE structure OF mux2to1 IS

  COMPONENT invgate
    PORT (
      a_i : IN  std_ulogic;
      y_o : OUT std_ulogic);
  END COMPONENT;

  COMPONENT or2gate
    PORT (
      a_i : IN  std_ulogic;
      b_i : IN  std_ulogic;
      y_o : std_ulogic);
  END COMPONENT;

  SIGNAL p1  : std_ulogic;
  SIGNAL p2 : std_ulogic;
  SIGNAL p3 : std_ulogic;
  
BEGIN

  inv_gate_1 : invgate
    PORT MAP (
      a_i => sel_i,
      y_o <= p2);


  and2_gate_1 : and2gate
    PORT MAP (
      a_i => a_i,
      b_i => p2,
		-- y_o => p2 Error (10500): VHDL syntax error at mux2to1_structure_errors.vhd(58) near text "y_o";  expecting ")", or ","
		-- Komma an p2 vergessen
      y_o => p0);

  and2_gate_2 : and2gate
    PORT MAP (
      a_i => b_i,
      b_i => sel_i,
      y_o => p1);

  or2_gate_1 : or2gate
    PORT MAP (
      a_i => p0,
      b_i => p1,
      y_o => p3);


END structure;
--END struct Error (10522): VHDL Syntax error at mux2to1_structure_errors.vhd(84): experienced unexpected end-of-file ;  expecting ";"
-- structure falsch geschrieben und Semikolon vergessen


-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

