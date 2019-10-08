-------------------------------------------------------------------------------
-- Module     : t_d_ff
-------------------------------------------------------------------------------
-- Author     :   <haf@fh-augsburg.de>
-- Company    : University of Applied Sciences Augsburg
-- Copyright (c) 2011   <haf@fh-augsburg.de>
-------------------------------------------------------------------------------
-- Description: Testbench for design "d_ff"
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY t_d_ff IS
END t_d_ff;


ARCHITECTURE tbench OF t_d_ff IS

  COMPONENT d_ff
    PORT (
      clk_i  : IN  std_ulogic;
      rst_ni : IN  std_ulogic;
      d_i    : IN  std_ulogic;
      q_o    : OUT std_ulogic);
  END COMPONENT;

  -- definition of a clock period
  CONSTANT period : time    := 10 ns;
  -- switch for clock generator
  SIGNAL clken_p  : boolean := true;

  -- component ports
  SIGNAL clk_i  : std_ulogic;
  SIGNAL rst_ni : std_ulogic;
  SIGNAL d_i    : std_ulogic;
  SIGNAL q_o    : std_ulogic;


BEGIN  -- tbench

  -- component instantiation
  DUT : d_ff
    PORT MAP (
      clk_i  => clk_i,
      rst_ni => rst_ni,
      d_i    => d_i,
      q_o    => q_o);

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

    d_i <= '0';                         -- set a value to input d_i 
    WAIT FOR period;                    -- values are assigned here

    d_i <= '1';                         -- change value of d_i
    WAIT FOR period;

    d_i <= '0';                         -- change value of d_i
    WAIT FOR 2 * period;                -- wait for a no. operiods ...
                                        -- ... before assigning new values

    d_i <= '1';                         -- value of d_i is not read ...
    WAIT FOR 4 * period;                -- wait for a no. operiods ...

    d_i <= '0';
    WAIT FOR period;

    clken_p <= false;                   -- switch clock generator off

    WAIT;                               -- suspend process
  END PROCESS;
  
END tbench;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------
