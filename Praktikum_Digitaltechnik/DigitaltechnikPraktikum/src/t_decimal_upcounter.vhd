-------------------------------------------------------------------------------
-- Module     : t_decimal_upcounter
-------------------------------------------------------------------------------
-- Author     : H.F.
-- Company    : University of Applied Sciences Augsburg
-------------------------------------------------------------------------------
-- Description: Testbench for 2-Bit Modulo-3 Down-Counter modelled by QFSM
-------------------------------------------------------------------------------
-- Revisions : 0.1 - 
-------------------------------------------------------------------------------

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY t_decimal_upcounter IS
END t_decimal_upcounter;

ARCHITECTURE tbench OF t_decimal_upcounter IS
  
  COMPONENT decimal_upcounter
    PORT (
      clk_i       : IN  std_ulogic;
      rst_ni      : IN  std_ulogic;
      en_pi       : IN  std_ulogic;
      digit_one_o : OUT std_ulogic_vector(3 DOWNTO 0);
      digit_ten_o : OUT std_ulogic_vector(2 DOWNTO 0);
      tc_o        : OUT std_ulogic);
  END COMPONENT;

  -- component ports 
  SIGNAL clk_i       : std_ulogic;
  SIGNAL rst_ni      : std_ulogic;
  SIGNAL en_pi       : std_ulogic;
  SIGNAL digit_one_o : std_ulogic_vector(3 DOWNTO 0);
  SIGNAL digit_ten_o : std_ulogic_vector(2 DOWNTO 0);
  SIGNAL tc_o        : std_ulogic;

  -- definition of a clock period
  CONSTANT period : time := 10 ns;

  -- switch for clock generator
  SIGNAL clken_p : boolean := true;

  SIGNAL scaled_period : std_ulogic;

BEGIN  -- tbench
  -- component instantiation 
  MUT : decimal_upcounter
    PORT MAP (
      clk_i       => clk_i,
      rst_ni      => rst_ni,
      en_pi       => en_pi,
      digit_one_o => digit_one_o,
      digit_ten_o => digit_ten_o,
      tc_o        => tc_o);

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

  ---------------------------------------------------------------------
  -- prescaler, generates an enable signal
  -- in dependence of clock period and generic parameter m
  -- clock_divider : ENTITY work.cntdnmodm(rtl)
    -- GENERIC MAP (
      -- n => 3,
      -- m => 4)
    -- PORT MAP (
      -- clk_i   => clk_i,
      -- rst_ni  => rst_ni,
      -- en_pi   => '1',                   -- permanently enabled
      -- count_o => OPEN,                  -- open, because not needed
      -- tc_o    => scaled_period);
	  
  ---------------------------------------------------------------------
  -- ONLY one of the following two lines should be used !!!
--  en_pi <= scaled_period;               -- use output of prescaler as
                                        -- input to en_pi
										-- OR 
  en_pi <= '1';                       -- activate enable input permanently

  stimuli_p : PROCESS

  BEGIN

    WAIT UNTIL rst_ni = '1';            -- wait until asynchronous reset ...
                                        -- ... is deactivated



               -- wait for at least one count cycle




    clken_p <= false;                   -- switch clock generator off

    WAIT;                               -- suspend proces
  END PROCESS;

END tbench;

-------------------------------------------------------------------------------
-- Revisions:
-- ----------
-- $Id:$
-------------------------------------------------------------------------------
