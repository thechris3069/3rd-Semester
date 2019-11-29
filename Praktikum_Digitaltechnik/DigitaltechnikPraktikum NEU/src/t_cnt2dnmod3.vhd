-------------------------------------------------------------------------------
-- Module     : t_cnt2dnmod3
-------------------------------------------------------------------------------
-- Author     : H.F.
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: Testbench for 2-Bit Modulo-3 Down-Counter modelled by QFSM
-------------------------------------------------------------------------------
-- Revisions : 0.1 - 
-------------------------------------------------------------------------------

-- Inputs:   en_pi
-- State/Output tc_o count_o[1] count_o[0]
-- s0           1    0          0          
-- s1           0    0          1          
-- s2           0    1          0          

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY t_cnt2dnmod3 IS
END t_cnt2dnmod3;

ARCHITECTURE tbench OF t_cnt2dnmod3 IS
  
  COMPONENT cnt2dnmod3
    PORT (clk     : IN  std_ulogic;
          rst_n   : IN  std_ulogic;
          en_pi   : IN  std_ulogic;
          tc_o    : OUT std_ulogic;
          count_o : OUT std_ulogic_vector(1 DOWNTO 0));
  END COMPONENT;
  
  -- component ports 
  SIGNAL clk     : std_ulogic;
  SIGNAL rst_n   : std_ulogic;
  SIGNAL en_pi   : std_ulogic;
  SIGNAL tc_o    : std_ulogic;
  SIGNAL count_o : std_ulogic_vector(1 DOWNTO 0);

  -- definition of a clock period
  CONSTANT period : time    := 10 ns;

  -- switch for clock generator
  SIGNAL clken_p  : boolean := true;

BEGIN  -- tbench
  -- component instantiation 
  MUT : cnt2dnmod3
    PORT MAP (
      clk     => clk,
      rst_n   => rst_n,
      en_pi   => en_pi,
      tc_o    => tc_o,
      count_o => count_o);

  -- clock generation
  clock_proc : PROCESS
  BEGIN
    WHILE clken_p LOOP
      clk <= '0'; WAIT FOR period/2;
      clk <= '1'; WAIT FOR period/2;
    END LOOP;
    WAIT;
  END PROCESS;

  -- initial reset, always necessary at the beginning of a simulation
  reset : rst_n <= '0', '1' AFTER period;

  
  stimuli_p : PROCESS

  BEGIN

    WAIT UNTIL rst_n = '1';            -- wait until asynchronous reset ...
                                        -- ... is deactivated

--    en_pi <= '1';                       -- activate enable input en_pi

--    WAIT FOR 3 * period;                -- wait for at least one count cycle


    -- Complete Verification of State Machine means: stimulate every transition:
    -- Transition 0
    en_pi <= '0';                       -- deactivate enable input en_pi
    WAIT FOR period;

    -- Transition 1
    en_pi <= '1';                       -- activate enable input en_pi
    WAIT FOR period;

    -- Transition 2
    en_pi <= '0';                       -- deactivate enable input en_pi
    WAIT FOR period;

    -- Transition 3
    en_pi <= '1';                       -- activate enable input en_pi
    WAIT FOR period;

    -- Transition 4
    en_pi <= '0';                       -- deactivate enable input en_pi
    WAIT FOR period;

    -- Transition 5
    en_pi <= '1';                       -- activate enable input en_pi
    WAIT FOR period;

    clken_p <= false;                   -- switch clock generator off

    WAIT;                               -- suspend proces
  END PROCESS;

END tbench;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------
