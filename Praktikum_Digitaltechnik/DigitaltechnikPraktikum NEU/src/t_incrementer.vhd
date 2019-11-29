-------------------------------------------------------------------------------
-- Module     : t_incrementer
-------------------------------------------------------------------------------
-- Author     : <haf@fh-augsburg.de>
-- Company    : University of Applied Sciences Augsburg
-- Copyright (c) 2011   <haf@fh-augsburg.de>
-------------------------------------------------------------------------------
-- Description: Testbench for design "incrementer"
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY t_incrementer IS
END t_incrementer;

ARCHITECTURE tbench OF t_incrementer IS

  COMPONENT incrementer
    PORT (
      clk_i    : IN  std_ulogic;
      rst_ni   : IN  std_ulogic;
      sensor_i : IN  std_ulogic_vector(1 DOWNTO 0);
      count_o  : OUT std_ulogic_vector(3 DOWNTO 0));
  END COMPONENT;


  -- definition of a clock period
  CONSTANT period : time    := 10 ns;
  -- switch for clock generator
  SIGNAL clken_p  : boolean := true;

  -- component ports
  SIGNAL clk_i    : std_ulogic;
  SIGNAL rst_ni   : std_ulogic;
  SIGNAL sensor_i : std_ulogic_vector(1 DOWNTO 0);
  SIGNAL count_o  : std_ulogic_vector(3 DOWNTO 0);

BEGIN  -- tbench

  -- component instantiation
  DUT : incrementer
    PORT MAP (
      clk_i    => clk_i,
      rst_ni   => rst_ni,
      sensor_i => sensor_i,
      count_o  => count_o);

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

    -- purpose: apply stimuli to input signals of module under test
    PROCEDURE apply_sensor (
      CONSTANT sensor_stim   : IN std_ulogic_vector;
      CONSTANT no_of_periods : IN natural) IS
    BEGIN  -- apply_stimuli
      sensor_i <= sensor_stim;          -- set a value to input sensor_i 
      WAIT FOR no_of_periods * period;  -- sensor input is much slower ...
                                        -- ... compared to clock input
    END PROCEDURE apply_sensor;
  
  BEGIN
    
    WAIT UNTIL rst_ni = '1';            -- wait until asynchronous reset ...
                                        -- ... is deactivated

    -- FORWARD
    sensor_i <= B"00";                  -- set a value to input sensor_i 
    WAIT FOR 10 * period;               -- sensor input is much slower ...
                                        -- ... compared to clock input

    sensor_i <= B"01";                  -- set a value to input sensor_i 
    WAIT FOR 10 * period;               -- sensor input is much slower ...
                                        -- ... compared to clock input

    sensor_i <= B"11";                  -- set a value to input sensor_i 
    WAIT FOR 10 * period;               -- sensor input is much slower ...
                                        -- ... compared to clock input

    sensor_i <= B"10";                  -- set a value to input sensor_i 
    WAIT FOR 10 * period;               -- sensor input is much slower ...
                                        -- ... compared to clock input

    
    -- alternatively, a local procedure can be used to assign input values:
    -- FORWARD
--    apply_sensor(B"00", 10);
--    apply_sensor(B"01", 10);
--    apply_sensor(B"11", 10);
--    apply_sensor(B"10", 10);

    -- add your stimuli here ...



    


    clken_p <= false;                   -- switch clock generator off

    WAIT;
  END PROCESS;

END tbench;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------
