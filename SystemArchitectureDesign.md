# Overview #
The quad-rotor UAV architecture is addressed at three separate but loosely related layers:
  1. mechanical construction layer
    * including frame, weight budget, mountings, materials
  1. electronic sensing and control layer
    * including sensors, communication methods,
  1. dynamic/inertial software model layer
    * using various sensor inputs, controlling outputs

# Mechanical construction #
The total system weight is estimated to be around 650g.
The upper limit of thrust each motor can produce is estimated to be not more than 600g.

# Electronic sensing and control #
Design
  * Use brushless DC outrunner motors
    * higher efficiency due to lack of brush friction and wear
    * larger volume of magnets for higher torque and efficiency
    * better cooling, thus higher power output
  * Use I2C/SPI motor controllers
    * allowing many to be used
    * allows higher update rates (~300Hz) than PWM-driven (~80Hz) ones
    * potential for reading data back (eg temperature/RPM)

Optimisations
  * keep the wiring from the motors to the motor controllers as short as possible
    * reducing losses due to resistance
    * allowing higher current thus motor power
  * place the motor controller in the down-draft of the rotor
    * cooling the MOSFET transistors thus keeping efficiency
  * mount motor controllers edge-on to the down-draft
    * minimising turbulence