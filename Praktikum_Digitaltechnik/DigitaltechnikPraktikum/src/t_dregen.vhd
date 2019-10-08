-------------------------------------------------------------------------------
-- Module     : t_dregen
-------------------------------------------------------------------------------
-- Author     :   <haf@fh-augsburg.de>
-- Company    : University of Applied Sciences Augsburg
-- Copyright (c) 2011   <haf@fh-augsburg.de>
-------------------------------------------------------------------------------
-- Description: Testbench for design "dregen"
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY t_dregen IS
END t_dregen;


ARCHITECTURE tbench OF t_dregen IS
  
  COMPONENT dregen
    PORT (
      clk_i  : IN  std_ulogic;
      rst_ni : IN  std_ulogic;
      en_pi  : IN  std_ulogic;
      d_i    : IN  std_ulogic_vector(3 DOWNTO 0);
      q_o    : OUT std_ulogic_vector(3 DOWNTO 0));
  END COMPONENT;

  -- definition of a clock period
  CONSTANT period : time    := 10 ns;
  -- switch for clock generator
  SIGNAL clken_p  : boolean := true;

  -- component ports
  SIGNAL clk_i  : std_ulogic;
  SIGNAL rst_ni : std_ulogic;
  SIGNAL en_pi  : std_ulogic;
  SIGNAL d_i    : std_ulogic_vector(3 DOWNTO 0);
  SIGNAL q_o    : std_ulogic_vector(3 DOWNTO 0);

BEGIN  -- tbench

  -- component instantiation
  DUT : ENTITY work.dregen(structure)
    PORT MAP (
      clk_i  => clk_i,
      rst_ni => rst_ni,
      en_pi  => en_pi,
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

    en_pi <= '0';                       -- set a value to input en_pi 
    d_i   <= B"0101";                   -- set a value to input d_i 
    WAIT FOR period;                    -- values are assigned here

    en_pi <= '1';                       -- activate enable input en_pi
    d_i   <= B"1010";                   -- change value of d_i
    WAIT FOR period;

    d_i <= B"0101";                     -- change value of d_i
    WAIT FOR 2 * period;                -- wait for a no. operiods ...
                                        -- ... before assigning new values

    en_pi <= '0';                       -- deactivate enable input en_pi
    WAIT FOR period;

    d_i <= X"F";                        -- value of d_i is not read ...
    WAIT FOR period;                    -- ... because enable is not active

    en_pi <= '1';                       -- activate enable input en_pi
    WAIT FOR 4 * period;                -- wait for a no. operiods ...

    en_pi <= '0';
    d_i   <= (OTHERS => '0');
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