-------------------------------------------------------------------------------
-- Module     : smctrl
-------------------------------------------------------------------------------
-- Author     : <haf@fh-augsburg.de>
-- Company    : University of Applied Sciences Augsburg
-- Copyright (c) 2011   <haf@fh-augsburg.de>
-------------------------------------------------------------------------------
-- Description: Testbench for design "smctrl"
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY t_smctrl IS
END t_smctrl;

ARCHITECTURE tbench OF t_smctrl IS
  COMPONENT smctrl 
    PORT (
      clk              : IN  std_ulogic;
      rst_ni          : IN  std_ulogic;
     sensor_i     : IN std_ulogic_vector(1 DOWNTO 0);
    sm_o : OUT std_ulogic_vector(3 DOWNTO 0);
  count_o :OUT  std_ulogic_vector(3 DOWNTO 0));
  END COMPONENT;
  
  -- definition of a clock period
  CONSTANT period : time    := 20 ns;
  -- switch for clock generator
  SIGNAL clken_p  : boolean := true;


  -- component ports
  SIGNAL clk_i    : std_ulogic;
  SIGNAL rst_ni   : std_ulogic;
  SIGNAL count_o  : std_ulogic_vector(3 DOWNTO 0);
  SIGNAL count_value : std_ulogic_vector(3 DOWNTO 0);
  SIGNAL sm_o  : std_ulogic_vector(3 DOWNTO 0);
  SIGNAL sensor_i :   std_ulogic_vector(1 DOWNTO 0);

   
 -- SIGNAL scaled_period : std_ulogic;

BEGIN  -- tbench
  
  -- component instantiation
  DUT : smctrl
    PORT MAP (
      clk    => clk_i,
      rst_ni   => rst_ni,
      sensor_i => sensor_i,
      count_o  => count_value,
      sm_o => sm_o);


 
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
  sensor_i <= B"00";  --    apply_sensor(B"00", 10);
  WAIT FOR 10 *period;
  
  
   sensor_i <= B"01"; 
   WAIT FOR 10* period;
      --    apply_sensor(B"01", 10);
      
   sensor_i <= B"11"; 
   WAIT FOR 10* period;
        --    apply_sensor(B"11", 10);
           sensor_i <= B"10"; 
   WAIT FOR 10* period;
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
