-------------------------------------------------------------------------------
-- Module     : de1_decimal_upcounter
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: test the module decimal_upcounter on a DE1 prototype board
--              connecting device under test (DUT) decimal_upcounter
--              to input/output signals of the DE1 prototype board
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY de1_decimal_upcounter IS
  PORT (
    CLOCK_50 : IN  std_ulogic;                     -- 50 MHz Clock
    KEY      : IN  std_ulogic_vector(1 DOWNTO 0);  -- KEY[1:0]
                                                   -- KEY[0] = rst_ni
                                                   -- KEY[1] = en_pi
    GPO_1    : OUT std_ulogic_vector(8 DOWNTO 0)   -- Output Connector GPIO_1
                                                   -- GPO_1[3:0] = digit_one_o
                                                   -- GPO_1[6:4] = digit_ten_o
                                                   -- GPO_1[7] = tc_o
                                                   -- GPO_1[8] = clk_i
    );
END de1_decimal_upcounter;

ARCHITECTURE structure OF de1_decimal_upcounter IS

  COMPONENT decimal_upcounter
    PORT (
      clk_i       : IN  std_ulogic;
      rst_ni      : IN  std_ulogic;
      en_pi       : IN  std_ulogic;
      digit_one_o : OUT std_ulogic_vector(3 DOWNTO 0);
      digit_ten_o : OUT std_ulogic_vector(2 DOWNTO 0);
      tc_o        : OUT std_ulogic);
  END COMPONENT;


  SIGNAL clk_i       : std_ulogic;
  SIGNAL rst_ni      : std_ulogic;
  SIGNAL en_pi       : std_ulogic;
  SIGNAL digit_one_o : std_ulogic_vector(3 DOWNTO 0);
  SIGNAL digit_ten_o : std_ulogic_vector(2 DOWNTO 0);
  SIGNAL tc_o        : std_ulogic;


BEGIN

  -- connecting clock generator master clock of synchronous system
  clk_i    <= CLOCK_50;
  GPO_1(8) <= clk_i;                    -- to measure clk signal

  -- connecting asynchronous system reset to digital system
  rst_ni <= KEY(0);

  -- count enable input is high-active, KEY(1) ist low-aktive, therefore ...
  -- ... if KEY1 is release, high signal is produced
  en_pi <= KEY(1);


  -- connecting device under test with peripheral elements
  DUT : ENTITY work.decimal_upcounter(structure)
    PORT MAP (
      clk_i       => clk_i,
      rst_ni      => rst_ni,
      en_pi       => en_pi,
      digit_one_o => digit_one_o,
      digit_ten_o => digit_ten_o,
      tc_o        => tc_o);

  -- connecting count values to GPIO1
  GPO_1(3 DOWNTO 0) <= digit_one_o;
  GPO_1(6 DOWNTO 4) <= digit_ten_o;
  GPO_1(7)          <= tc_o;

END structure;
-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------
