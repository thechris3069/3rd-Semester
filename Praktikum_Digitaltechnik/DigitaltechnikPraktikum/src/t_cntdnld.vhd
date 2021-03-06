-------------------------------------------------------------------------------
-- Module     : t_cntdnld
-------------------------------------------------------------------------------
-- Author     :   <haf@fh-augsburg.de>
-- Company    : University of Applied Sciences Augsburg
-- Copyright (c) 2016   <haf@fh-augsburg.de>
-------------------------------------------------------------------------------
-- Description: Testbench for design "cntupdn"
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY t_cntdnld IS
END t_cntdnld;

ARCHITECTURE tbench OF t_cntdnld IS

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

  -- definition of a clock period
  CONSTANT period : time    := 10 ns;
  -- switch for clock generator
  SIGNAL clken_p  : boolean := true;

  -- component ports
  SIGNAL clk_i   : std_ulogic;
  SIGNAL rst_ni  : std_ulogic;
  SIGNAL ld_pi   : std_ulogic;
  SIGNAL en_pi   : std_ulogic;
  SIGNAL data_i  : std_ulogic_vector(3 DOWNTO 0);
  SIGNAL count_o : std_ulogic_vector(3 DOWNTO 0);
  SIGNAL tc_o    : std_ulogic;
  
BEGIN  -- tbench

  -- component instantiation
  MUT: ENTITY work.cntdnld(structure)
    PORT MAP (
      clk_i   => clk_i,
      rst_ni  => rst_ni,
      ld_pi   => ld_pi,
      en_pi   => en_pi,
      data_i  => data_i,
      count_o => count_o,
      tc_o    => tc_o);

  -- clock generation
  clock_proc : PROCESS
  BEGIN
    WHILE clken_p LOOP
      clk_i <= '0'; WAIT FOR period/2;
      clk_i <= '1'; WAIT FOR period/2;
    END LOOP;
    WAIT;
  END PROCESS;

  -- initial reset, always necessary at the beginning of a simulation
  reset : rst_ni <= '0', '1' AFTER period;

  stimuli_p : PROCESS

  BEGIN

    WAIT UNTIL rst_ni = '1';            -- wait until asynchronous reset ...
                                        -- ... is deactivated

    data_i <= "0101";                   -- assign preload count value
    ld_pi <= '1';                       -- activate load input data
    en_pi  <= '0';                      -- disable counting
    WAIT FOR period;
    
    ld_pi <= '0';                       -- deactivate load
    en_pi  <= '1';                      -- activate enable input en_pi
    WAIT FOR period;
    
    WAIT UNTIL tc_o = '1';              -- until count value = 0
                                        -- visually, check for tc_o ='1' ?

    -- Follow the comments below to continue verification
    ---------------------------------------------------------------------------
    data_i  <= "0011";                  -- assign preload count value
    ld_pi <= '1';              -- activate load input data
    WAIT FOR period;
    
    
    ld_pi <= '0';              -- deactivate load
    WAIT FOR period;
    
    
    
    en_pi <= '0'; -- disable counting
    WAIT FOR 2* period;              -- for some cycles
    
    en_pi <= '1';              -- activate counting again
    WAIT UNTIL tc_o <= '1';  --AUSGANG FF = 1            -- until count value = 0
    
      en_pi <= '0';            -- disable counting
      WAIT FOR 2 * period;            -- for some cycles
    ---------------------------------------------------------------------------

    clken_p <= false;                   -- switch clock generator off

    WAIT;                               -- suspend proces
  END PROCESS;
  
END tbench;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

