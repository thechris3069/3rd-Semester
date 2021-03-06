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
      END mux2to1;
--END mux21;
--** Error: /home/caeuser/Desktop/GIT/3rd-Semester/Praktikum_Digitaltechnik/DigitaltechnikPraktikum/src/mux2to1_structure.vhd(22): Labels do not match: 'mux2to1' and 'mux21'.

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
      y_o : OUT std_ulogic);
  END COMPONENT;
  
    COMPONENT and2gate
    PORT (
      a_i : IN  std_ulogic;
      b_i : IN  std_ulogic;
      y_o : OUT std_ulogic);
  END COMPONENT;
  
  SIGNAL p0 : std_ulogic;
  SIGNAL p1 : std_ulogic;
  SIGNAL p2 : std_ulogic;
  SIGNAL p3 : std_ulogic;
  
BEGIN

  inv_gate_1 : invgate
    PORT MAP (
      a_i => sel_i,
      y_o => p2);
     -- y_o <= p2);

--** Error: /home/caeuser/Desktop/GIT/3rd-Semester/Praktikum_Digitaltechnik/DigitaltechnikPraktikum/src/mux2to1_structure.vhd(50): (vcom-1023) Positional association (infix expression) found after named association.
--** Error: /home/caeuser/Desktop/GIT/3rd-Semester/Praktikum_Digitaltechnik/DigitaltechnikPraktikum/src/mux2to1_structure.vhd(57): near "y_o": expecting ',' or ')'

  and2_gate_1 : and2gate
  --** Error: /home/caeuser/Desktop/GIT/3rd-Semester/Praktikum_Digitaltechnik/DigitaltechnikPraktikum/src/mux2to1_structure.vhd(57): (vcom-1141) Identifier "and2gate" does not identify a component declaration.
    PORT MAP (
      a_i => a_i,
      b_i => p2,
      y_o => p0);
      
      --** Error: /home/caeuser/Desktop/GIT/3rd-Semester/Praktikum_Digitaltechnik/DigitaltechnikPraktikum/src/mux2to1_structure.vhd(60): near "y_o": expecting ',' or ')'


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
--** Error: /home/caeuser/Desktop/GIT/3rd-Semester/Praktikum_Digitaltechnik/DigitaltechnikPraktikum/src/mux2to1_structure.vhd(224): near "EOF": expecting ';'
--** Error: /home/caeuser/Desktop/GIT/3rd-Semester/Praktikum_Digitaltechnik/DigitaltechnikPraktikum/src/mux2to1_structure.vhd(87): Labels do not match: 'structure' and 'struct'.

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------




---------------------------------------------------------------------------------
--sim:/t_mux2to1/MUV/inv_gate_1 sim:/t_mux2to1/MUV/a_i sim:/t_mux2to1/MUV/y_o sim:/t_mux2to1/MUV/inv_gate_2 sim:/t_mux2to1/MUV/and2_gate_1 sim:/t_mux2to1/MUV/b_i sim:/t_mux2to1/MUV/and2_gate_2 sim:/t_mux2to1/MUV/and2gate3 sim:/t_mux2to1/MUV/inv_gate_3 sim:/t_mux2to1/MUV/inv_gate_4---- Module     : mux2to1
---------------------------------------------------------------------------------
---- Author     : Johann Faerber
---- Company    : University of Applied Sciences Augsburg
---------------------------------------------------------------------------------
---- Description: 2-to-1 multiplexer
----              function modelled as structure of basic logic gates
---------------------------------------------------------------------------------
---- Revisions  : see end of file
---------------------------------------------------------------------------------
--LIBRARY IEEE;
--USE IEEE.std_logic_1164.ALL;
--
--ENTITY mux2to1 IS
--  PORT (a_i   : IN  std_ulogic;
--        b_i   : IN  std_ulogic;
--        sel_i : IN  std_ulogic;
----        y_o   : OUT std_ulogic; -- kein ; nach letztem Signal
--        y_o   : OUT std_ulogic
--        );
----END mux21; Error (10396): VHDL syntax error at mux2to1_structure_errors.vhd(22): name used in construct must match previously specified name "mux2to1"
---- END mu2to1 Falsch geschrieben
--END mux2to1;
--
--
--ARCHITECTURE structure OF mux2to1 IS
--
--  COMPONENT invgate
--    PORT (
--      a_i : IN  std_ulogic;
--      y_o : OUT std_ulogic);
--  END COMPONENT;
--
--  COMPONENT or2gate
--    PORT (
--      a_i : IN  std_ulogic;
--      b_i : IN  std_ulogic;
--      y_o : OUT std_ulogic);
--		END COMPONENT;
--		
--		COMPONENT and2gate
--			PORT 	(
--			a_i : IN std_ulogic;
--			b_i : IN  std_ulogic;
--			y_o : OUT std_ulogic);
--	  END COMPONENT;
--
--	SIGNAL p0 : std_ulogic;
--  SIGNAL p1  : std_ulogic;
--  SIGNAL p2 : std_ulogic;
--  SIGNAL p3 : std_ulogic;
--  SIGNAL p4 : std_ulogic;
--  SIGNAL p5 : std_ulogic;
--  
--  
--BEGIN
--
--  inv_gate_1 : invgate
--    PORT MAP (
--      a_i => p0,
--      y_o => p2);
--     --y_o <= p2);		Error (10437): VHDL Association List error at mux2to1_structure.vhd(51): positional associations must be listed before named associations
--		--Pfeil in falsche Richtung
--
--		inv_gate_2 : invgate
--		PORT MAP (
--      a_i => p1,
--      y_o => p3);
--		
--		
--		
--
--  and2_gate_1 : and2gate
--    PORT MAP (
--      a_i => a_i,
--      b_i => sel_i,
--		-- y_o => p2 Error (10500): VHDL syntax error at mux2to1_structure_errors.vhd(58) near text "y_o";  expecting ")", or ","
--		-- Komma an p2 vergessen
--      y_o => p0);
--
--  and2_gate_2 : and2gate 	--Error (10482): VHDL error at mux2to1_structure.vhd(56): object "and2gate" is used but not declared
---- COMPONENT von and2gate noch anlegen
--    PORT MAP (
--      a_i => b_i,
--      b_i => p5,
--      y_o => p1);
--
--		--MUX MIT UND GATTER 
--		and2gate3 : and2gate 
--			PORT MAP (
--			a_i => p2,
--			b_i =>  p3,
--			y_o => p4);
--			
--			inv_gate_3 : invgate
--    PORT MAP (
--      a_i => p4,
--      y_o => y_o);
--		
--					inv_gate_4 : invgate
--    PORT MAP (
--      a_i => sel_i,
--      y_o => p5);
--		
--		
--		--MUX MIT OR GATTER
--  --or2_gate_1 : or2gate
--    --PORT MAP (
--      --a_i => p0,
--      --b_i => p1,
--      --y_o => y_o);
--
--
--END structure;
----END struct Error (10522): VHDL Syntax error at mux2to1_structure_errors.vhd(84): experienced unexpected end-of-file ;  expecting ";"
---- structure falsch geschrieben und Semikolon vergessen
--
--
---------------------------------------------------------------------------------
---- Revisions:
---- ----------
---- $Id:$
---------------------------------------------------------------------------------
--
