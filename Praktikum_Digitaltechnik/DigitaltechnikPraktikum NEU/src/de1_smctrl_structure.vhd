-------------------------------------------------------------------------------
-- Module     : de1_smctrl
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: test the module smctrl on a DE1 prototype board
--              connecting device under test (DUT) smctrl
--              to input/output signals of the DE1 prototype board
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY de1_smctrl IS
  PORT (

    -- add the missing signals here ...

    
    GPO_1_3  : OUT std_ulogic;                     -- connected to GPO_1[3]
    GPO_1_5  : OUT std_ulogic;                     -- connected to GPO_1[5]
    GPO_1_7  : OUT std_ulogic;                     -- connected to GPO_1[7]
    GPO_1_9  : OUT std_ulogic                      -- connected to GPO_1[9]
    );
END de1_smctrl;

ARCHITECTURE structure OF de1_smctrl IS




  
  SIGNAL sensor : std_ulogic_vector(1 DOWNTO 0);

  SIGNAL motor_control_output : std_ulogic_vector(3 DOWNTO 0);

BEGIN








  

  -- connecting motor control outputs to GPO_1 ports
  GPO_1_3 <= motor_control_output(0);
  GPO_1_5 <= motor_control_output(1);
  GPO_1_7 <= motor_control_output(2);
  GPO_1_9 <= motor_control_output(3);

END structure;
-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------
