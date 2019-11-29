-------------------------------------------------------------------------------
-- Module     : de1_incrementer
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: test the module incrementer on a DE1 prototype board
--              connecting device under test (DUT) incrementer
--              to input/output signals of the DE1 prototype board
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY de1_incrementer IS
  PORT (
    CLOCK_50 : IN  std_ulogic;                     -- 50 MHz Clock
    KEY      : IN  std_ulogic;                     -- KEY
    GPI_1    : IN  std_ulogic_vector(1 DOWNTO 0);  -- Input Connector GPIO_1
                                                   -- GPI_1[0] = sensor(0)
                                                   -- GPI_1[1] = sensor(1)
    LEDG     : OUT std_ulogic_vector(1 DOWNTO 0);  -- connected to GPI_1[1:0]
    HEX0     : OUT std_ulogic_vector(6 DOWNTO 0)   -- Seven Segment Digit 0
    );
END de1_incrementer;

ARCHITECTURE structure OF de1_incrementer IS


  SIGNAL clk_i  : std_ulogic;
  SIGNAL rst_ni : std_ulogic;

  SIGNAL sensor : std_ulogic_vector(1 DOWNTO 0);

  SIGNAL count_value : std_ulogic_vector(3 DOWNTO 0);

BEGIN

  -- connecting clock generator master clock of synchronous system

  
  -- connecting asynchronous system reset to digital system

  -- connecting sensor input signals to green LEDs

  -- connecting input sensor signals via GPIO_1 connector
  -- synchronised by separate module

  

  -- connecting device under test with peripheral elements
  DUT : incrementer


  -- connecting count value to HEX display

END structure;
-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------
