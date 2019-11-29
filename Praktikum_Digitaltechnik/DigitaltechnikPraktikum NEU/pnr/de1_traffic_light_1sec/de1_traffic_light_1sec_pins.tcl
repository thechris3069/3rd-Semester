# assign pin locations to a quartus project

#----------------------------------------------------------------------
# Pin Assignments
set_location_assignment PIN_L1 -to CLOCK_50
set_location_assignment PIN_R22 -to KEY
# traffic lights on adapter board:
set_location_assignment PIN_A17 -to GPO_0_8
set_location_assignment PIN_B18 -to GPO_0_11
set_location_assignment PIN_J21 -to GPO_0_26
# traffic lights at green LEDs:
# RED traffic light at LEDG[0]
set_location_assignment PIN_U22 -to LEDG[0]
# YELLOW traffic light at LEDG[1]
set_location_assignment PIN_U21 -to LEDG[1]
# GREEN traffic light at LEDG[2]
set_location_assignment PIN_V22 -to LEDG[2]
# ----------------------------------------------------------------------------
