-------------------------------------------------------------------------------
-- Module     : t_cntdn
-------------------------------------------------------------------------------
-- Author     :   <haf@fh-augsburg.de>
-- Company    : University of Applied Sciences Augsburg
-- Copyright (c) 2011   <haf@fh-augsburg.de>
-------------------------------------------------------------------------------
-- Description: Testbench for design "cntdn"
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY t_cntdn IS
END t_cntdn;

ARCHITECTURE tbench OF t_cntdn IS

  COMPONENT cntdn
    PORT (
      clk_i   : IN  std_ulogic;
      rst_ni  : IN  std_ulogic;
      en_pi   : IN  std_ulogic;
      count_o : OUT std_ulogic_vector(3 DOWNTO 0);
      tc_o    : OUT std_ulogic);
  END COMPONENT;

  -- definition of a clock period
  CONSTANT period : time    := 20 ns;
  -- switch for clock generator
  SIGNAL clken_p  : boolean := true;

  -- component ports
  SIGNAL clk_i   : std_ulogic;
  SIGNAL rst_ni  : std_ulogic;
  SIGNAL en_pi   : std_ulogic;
  SIGNAL count_o : std_ulogic_vector(3 DOWNTO 0);
  SIGNAL tc_o    : std_ulogic;
  
BEGIN  -- tbench

  -- component instantiation
  DUT : cntdn
    PORT MAP (
      clk_i   => clk_i,
      rst_ni  => rst_ni,
      en_pi   => en_pi,
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

    en_pi <= '1';                       -- activate enable input en_pi

              WAIT UNTIL count_o = B"1111";           -- wait for at least one count cycle

                WAIT FOR 5 * period;     -- wait for a no. of count values
                   -- then ...

                      en_pi <= '0'; -- .... deactivate enable input en_pi
    

                    WAIT FOR 3 * period;
    
                      en_pi <= '1';   -- activate enable input en_pi
                      
                        WAIT UNTIL count_o = B"1111";           -- wait for at least one count cycle
                        
                                            WAIT FOR 3 * period;
                                            
                                             WAIT UNTIL count_o = B"1111";           -- wait for at least one count cycle
    

    clken_p <= false;                   -- switch clock generator off

    WAIT;                               -- suspend proces
  END PROCESS;
  
END tbench;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------
