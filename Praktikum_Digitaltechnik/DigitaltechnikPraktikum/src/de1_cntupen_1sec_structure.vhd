-------------------------------------------------------------------------------
-- Module     : de1_cntupen_1sec
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: test the module cnt4up on a DE1 prototype board
--              connecting device under test (DUT) cnt4up
--              to input/output signals of the DE1 prototype board
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY de1_cntupen_1sec IS
  PORT (
    CLOCK_50 : IN  std_ulogic;                    -- 50 MHz Clock
    KEY      : IN  std_ulogic;                    -- KEY[0]
    HEX0     : OUT std_ulogic_vector(6 DOWNTO 0)  -- Seven Segment Digit 0
    );
END de1_cntupen_1sec;

ARCHITECTURE structure OF de1_cntupen_1sec IS

   COMPONENT cntdnmodm
	GENERIC(
	n : natural :=4;
	m : natural :=10);

	PORT (
	     clk_i   :IN std_ulogic;
        rst_ni  :IN std_ulogic;
        en_pi   :IN std_ulogic;
        count_o :out std_ulogic_vector(n-1 DOWNTO 0);
        tc_o    :OUT std_ulogic
	
	);
	END COMPONENT;
	
	COMPONENT  cntupen
	PORT (clk_i   : IN  std_ulogic;
        rst_ni  : IN  std_ulogic;
        en_pi   : IN  std_ulogic;
        count_o : OUT std_ulogic_vector(3 DOWNTO 0)
        );
	END COMPONENT;
		  
   COMPONENT binto7segment 
	PORT (bin_i      : IN  std_ulogic_vector(3 DOWNTO 0);
        segments_o : OUT std_ulogic_vector(6 DOWNTO 0)
        );
	END COMPONENT;


	
  -- make components visible

  -- signal declarations for interconnects
  SIGNAL one_second_period : std_ulogic;
  SIGNAL count_o : std_ulogic_vector(3 DOWNTO 0);
  SIGNAL clk_i   : std_ulogic;
  SIGNAL rst_ni  : std_ulogic;
  --SIGNAL en_pi   : std_ulogic;

BEGIN
 
  -- connecting clock generator master clock of synchronous system
   clk_i <= CLOCK_50;
  
  -- connecting asynchronous system reset to digital system
  rst_ni <= KEY;
  
  -- based on the 50 MHz clock, generates an enable signal of period T = 1 sec
  clock_driver : ENTITY work.cntdnmodm(rtl)
  GENERIC MAP (
  n => 26,
  m => 50000000)
  
  PORT MAP (
  clk_i => clk_i,
  rst_ni => rst_ni,
  en_pi => '1',
  count_o => OPEN,
  tc_o => one_second_period);
  
  -- connecting device under test with peripheral elements
DUT : ENTITY WORK.cntupen(structure)
  PORT MAP (
  clk_i => clk_i,
  rst_ni => rst_ni,
  en_pi => one_second_period,
  count_o => count_o);
  
 
 count_value :  work.binto7segment(truthtable)
  PORT MAP (
  bin_i => count_o,
  segments_o => HEX0
  );
  
 
  -- connecting count value to HEX display

END structure;
-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------
