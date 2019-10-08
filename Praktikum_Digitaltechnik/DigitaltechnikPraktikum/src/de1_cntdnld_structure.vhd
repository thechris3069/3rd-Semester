-------------------------------------------------------------------------------
-- Module     : de1_cntdnld
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: test the module cntdnldp on a DE1 prototype board
--              connecting device under test (DUT) cntdnld
--              to input/output signals of the DE1 prototype board
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY de1_cntdnld IS
  PORT (
    CLOCK_50 : IN  std_ulogic;                     -- 50 MHz Clock
    KEY      : IN  std_ulogic_vector(2 DOWNTO 0);  -- KEY[0] -> rst_ni
                                                   -- KEY[1] -> ld_pi
                                                   -- KEY[2] -> en_pi
    SW       : IN  std_ulogic_vector(3 DOWNTO 0);  -- SW[3:0] -> data_i
    GPO_1    : OUT std_ulogic_vector(6 DOWNTO 0)   -- Output Connector GPIO_1
                                                   -- GPO_1[3:0] = count_o
                                                   -- GPO_1[4] = tc_o
                                                   -- GPO_1[5] = clk_i
                                                   -- GPO_1[6] = ld_pi
    );
END de1_cntdnld;

ARCHITECTURE structure OF de1_cntdnld IS

  COMPONENT cntdnld IS
    PORT (
      clk_i   : IN  std_ulogic;
      rst_ni  : IN  std_ulogic;
      ld_pi   : IN  std_ulogic;
      en_pi   : IN  std_ulogic;
      data_i  : IN  std_ulogic_vector(3 DOWNTO 0);
      count_o : OUT std_ulogic_vector(3 DOWNTO 0);
      tc_o    : OUT std_ulogic);
  END COMPONENT cntdnld;

  SIGNAL clk_i   : std_ulogic;
  SIGNAL rst_ni  : std_ulogic;
  SIGNAL ld_pi   : std_ulogic;
  SIGNAL en_pi   : std_ulogic;
  SIGNAL data_i  : std_ulogic_vector(3 DOWNTO 0);
  SIGNAL count_o : std_ulogic_vector(3 DOWNTO 0);
  SIGNAL tc_o    : std_ulogic;

BEGIN

  -- connecting clock generator master clock of synchronous system
  clk_i <= CLOCK_50;
  GPO_1(5) <= clk_i;                    -- to measure clk signal

  -- connecting asynchronous system reset to digital system
  rst_ni <= KEY(0);

  -- assign preload counter data
  data_i <= SW;
  
  -- KEY(1) to preload counter value
  -- KEYs are L-active -> inverter necessary
  ld_pi <= NOT KEY(1);
  GPO_1(6) <= ld_pi;                    -- to measure signal
  

  -- KEY(2) to enable/disable counting
  en_pi <= KEY(2);

  -- connecting device under test with peripheral elements
  DUT : ENTITY work.cntdnld(structure)
    PORT MAP (
      clk_i   => clk_i,
      rst_ni  => rst_ni,
      ld_pi   => ld_pi,
      en_pi   => en_pi,
      data_i  => data_i,
      count_o => count_o,
      tc_o    => tc_o);
  
  -- connecting count value to GPIO1
  GPO_1(3 DOWNTO 0) <= count_o;
  GPO_1(4)          <= tc_o;

END structure;
-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------
