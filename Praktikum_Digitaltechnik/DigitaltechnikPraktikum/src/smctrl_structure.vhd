-------------------------------------------------------------------------------
-- Module     : smctrl
-------------------------------------------------------------------------------
-- Author     : Johann Faerber
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: Stepper Motor Controller
--              Based on two quadrature input signals sensor(1 DOWNTO 0)
--              a resolver module detects forward and backward to
--              control an up/down-counter
--              whose output is encoded for forward/backward control of
--              a stepper motor
-------------------------------------------------------------------------------
-- Revisions  : see end of file
-------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY smctrl IS
  PORT (clk_i    : IN  std_ulogic;
        rst_ni   : IN  std_ulogic;
        sensor_i : IN  std_ulogic_vector(1 DOWNTO 0);
        count_o  : OUT std_ulogic_vector(3 DOWNTO 0);
        sm_o     : OUT std_ulogic_vector(3 DOWNTO 0)
        );
END smctrl;

ARCHITECTURE structure OF smctrl IS

  COMPONENT incrementer
    PORT (
      clk_i    : IN  std_ulogic;
      rst_ni   : IN  std_ulogic;
      sensor_i : IN  std_ulogic_vector(1 DOWNTO 0);
      count_o  : OUT std_ulogic_vector(3 DOWNTO 0));
  END COMPONENT;
  
  
    COMPONENT smencode
    PORT (
      bin_i : IN  std_ulogic_vector(2 DOWNTO 0);
      sm_o  : OUT std_ulogic_vector(3 DOWNTO 0));
  END COMPONENT;

  -- make components visible



  -- internal signals for connecting components

  SIGNAL count_value : std_ulogic_vector(3 DOWNTO 0);

  
BEGIN

  incrementer_module : incrementer
    PORT MAP (
      clk_i    => clk_i,
      rst_ni   => rst_ni,
      sensor_i => sensor_i,
      count_o  => count_value);
      
      
  stepper_motor_encoder : smencode
    PORT MAP (
      bin_i(0) => count_value(0),
      bin_i(1) => count_value(1),
      bin_i(2) => count_value(2), -- Signal als 
      sm_o => sm_o);

count_o <=count_value;


END structure;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------

