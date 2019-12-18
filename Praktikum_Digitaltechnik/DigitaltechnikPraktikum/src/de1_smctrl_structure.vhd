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
CLOCK_50 : IN  std_ulogic;                     -- 50 MHz Clock
    GPI_1 : IN  std_ulogic_vector(1 DOWNTO 0);                     -- KEY
	 --GPI_1(1)      : IN  std_ulogic;                     -- KEY
	 KEY : IN std_ulogic;
	 
    --GPI_1    : IN  std_ulogic_vector(1 DOWNTO 0);  -- Input Connector GPIO_1
                                                   -- GPI_1[0] = sensor(0)
                                                   -- GPI_1[1] = sensor(1)
    LEDG     : OUT std_ulogic_vector(1 DOWNTO 0);  -- connected to GPI_1[1:0]
    HEX0     : OUT std_ulogic_vector(6 DOWNTO 0);  -- Seven Segment Digit 0
    
    -- add the missing signals here ...
    GPO_1_3  : OUT std_ulogic;                     -- connected to GPO_1[3]
    GPO_1_5  : OUT std_ulogic;                     -- connected to GPO_1[5]
    GPO_1_7  : OUT std_ulogic;                     -- connected to GPO_1[7]
    GPO_1_9  : OUT std_ulogic                      -- connected to GPO_1[9]
    );
END de1_smctrl;

ARCHITECTURE structure OF de1_smctrl IS

COMPONENT synchroniser IS
  PORT (
    clk_i    : IN  std_ulogic;
    rst_ni   : IN  std_ulogic;
    unsync_i : IN  std_ulogic;
    sync_o   : OUT std_ulogic
    );
	 END COMPONENT;
	 
	   COMPONENT binto7segment
    PORT (
      bin_i      : IN  std_ulogic_vector(3 DOWNTO 0);
      segments_o : OUT std_ulogic_vector(6 DOWNTO 0));
  END COMPONENT;
  
  COMPONENT smctrl
  PORT (clk_i    :  IN std_ulogic;
        rst_ni   :   IN std_ulogic;
        sensor_i :  IN std_ulogic_vector(1 DOWNTO 0);
        count_o  :   OUT std_ulogic_vector(3 DOWNTO 0);
        sm_o     :   OUT std_ulogic_vector(3 DOWNTO 0)
        );
END COMPONENT;

  SIGNAL clk_i  : std_ulogic;
  SIGNAL rst_ni : std_ulogic;


    SIGNAL count_value : std_ulogic_vector(3 DOWNTO 0);
	   SIGNAL motor_control_output : std_ulogic_vector(3 DOWNTO 0);
  SIGNAL sensor : std_ulogic_vector(1 DOWNTO 0);

  --SIGNAL motor_control_output : std_ulogic_vector(3 DOWNTO 0);

BEGIN

  clk_i <= CLOCK_50;
  rst_ni <= KEY;
  LEDG(0) <= sensor(0);
  LEDG(1) <= sensor(1);

  -- connecting clock generator master clock of synchronous system

  
  -- connecting asynchronous system reset to digital system

  -- connecting sensor input signals to green LEDs

  -- connecting input sensor signals via GPIO_1 connector
  -- synchronised by separate module

  -- connecting device under test with peripheral elements
  DUT : smctrl
  PORT MAP (clk_i  => clk_i,
        rst_ni  => rst_ni,
        sensor_i(0) => sensor(0),
		  sensor_i(1) => sensor(1),
        count_o  => count_value,
		  sm_o => motor_control_output
        );

		  
synchroniser0 : synchroniser
  PORT  MAP(
    clk_i   => clk_i,
    rst_ni   => rst_ni,
    unsync_i => GPI_1(0),
    sync_o   => sensor(0)
    );

	 synchroniser1 : synchroniser
  PORT  MAP(
    clk_i   => clk_i,
    rst_ni   => rst_ni,
    unsync_i => GPI_1(1),
    sync_o   => sensor(1)
    );
	 
		  
  count_val : binto7segment
    PORT MAP (
      bin_i      => count_value,
      segments_o => HEX0);
  -- connecting count value to HEX display
  
 LEDG(0) <= sensor(0);
 LEDG(1) <= sensor(1);

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
