-------------------------------------------------------------------------------
-- Module     : t_cntupdn
-------------------------------------------------------------------------------
-- Author     :   <haf@fh-augsburg.de>
-- Company    : University of Applied Sciences Augsburg
-- Copyright (c) 2011   <haf@fh-augsburg.de>
-------------------------------------------------------------------------------
-- Description: Testbench for design "cntupdn"
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY t_cntupdn IS
END t_cntupdn;

ARCHITECTURE tbench OF t_cntupdn IS

  COMPONENT cntupdn
    PORT (
      clk_i   : IN  std_ulogic;
      rst_ni  : IN  std_ulogic;
      en_pi   : IN  std_ulogic;
      mode_i  : IN  std_ulogic;
      count_o : OUT std_ulogic_vector(3 DOWNTO 0)); 
  END COMPONENT;

  -- definition of a clock period
  CONSTANT period : time    := 10 ns;
  -- switch for clock generator
  SIGNAL clken_p  : boolean := true;


  -- component ports
  SIGNAL clk_i   : std_ulogic;
  SIGNAL rst_ni  : std_ulogic;
  SIGNAL en_pi   : std_ulogic;
  SIGNAL mode_i  : std_ulogic;
  SIGNAL count_o : std_ulogic_vector(3 DOWNTO 0);
  
BEGIN  -- tbench

  -- component instantiation
  DUT : cntupdn
    PORT MAP (
      clk_i   => clk_i,
      rst_ni  => rst_ni,
      en_pi   => en_pi,
      mode_i  => mode_i,
      count_o => count_o);

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

  --  rst_ni <= '1';
    WAIT UNTIL rst_ni = '1';            -- wait until asynchronous reset ...
                                        -- ... is deactivated

           en_pi <= '1';  -- activate enable input en_pi
           mode_i <= '1';  -- count up

           WAIT UNTIL count_o = "0000";  -- wait for at least one count cycle
            
            
        
            WAIT FOR 1* period;
            
           
            WAIT FOR 3 * period; 
             mode_i <= '0'; -- count down
             WAIT UNTIL count_o = "1010";  -- wait until count value = 10

             en_pi <= '0'; -- deactivate enable input en_pi
            WAIT FOR 3* period;  
  
            en_pi <= '1';  -- activate enable input en_pi
            WAIT FOR 5* period;

    clken_p <= false;                   -- switch clock generator off

    WAIT;                               -- suspend proces
  END PROCESS;
  
END tbench;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

