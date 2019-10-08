-------------------------------------------------------------------------------
-- Module     : de1_cntupen
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: test the module cntupen on a DE1 prototype board
--              connecting device under test (DUT) cntdn
--              to input/output signals of the DE1 prototype board
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY de1_cntupen IS
  PORT (
    CLOCK_50 : IN  std_ulogic;                     -- 50 MHz Clock
    KEY      : IN  std_ulogic_vector(1 DOWNTO 0);  -- KEY[1:0]
                                                   -- KEY[0] = rst_ni
                                                   -- KEY[1] = en_pi
    HEX0     : OUT std_ulogic_vector(6 DOWNTO 0);  -- Seven Segment Digit 0

    GPO_1    : OUT std_ulogic_vector(4 DOWNTO 0)   -- Output Connector GPIO_1
                                                   -- GPO_1[3:0] = count_o
                                                   -- GPO_1[4] = clk_i
    );
END de1_cntupen;

ARCHITECTURE structure OF de1_cntupen IS

  COMPONENT binto7segment
    PORT (
      bin_i      : IN  std_ulogic_vector(3 DOWNTO 0);
      segments_o : OUT std_ulogic_vector(6 DOWNTO 0));
  END COMPONENT;

  COMPONENT cntupen
    PORT (
      clk_i   : IN  std_ulogic;
      rst_ni  : IN  std_ulogic;
      en_pi   : IN  std_ulogic;
      count_o : OUT std_ulogic_vector(3 DOWNTO 0));

  END COMPONENT;

  SIGNAL clk_i   : std_ulogic;
  SIGNAL rst_ni  : std_ulogic;
  SIGNAL en_pi   : std_ulogic;
  SIGNAL count_o : std_ulogic_vector(3 DOWNTO 0);
  SIGNAL tc_o    : std_ulogic;

BEGIN

  -- connecting clock generator master clock of synchronous system
  clk_i    <= CLOCK_50;
  GPO_1(4) <= clk_i;                    -- to measure clk signal

  -- connecting asynchronous system reset to digital system
  rst_ni <= KEY(0);

  -- count enable input is high-active, KEY(1) is low-active, therefore ...
  -- ... an inverter is needed
  en_pi <= NOT KEY(1);


  -- connecting device under test with peripheral elements
  DUT : ENTITY work.cntupen(structure)
    PORT MAP (
      clk_i   => clk_i,
      rst_ni  => rst_ni,
      en_pi   => en_pi,
      count_o => count_o);

  -- connecting count value to HEX display
  count_value : ENTITY work.binto7segment(truthtable)
    PORT MAP (
      bin_i      => count_o,
      segments_o => HEX0);


  -- connecting count value to GPIO1
  GPO_1(3 DOWNTO 0) <= count_o;
  
END structure;
-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------
