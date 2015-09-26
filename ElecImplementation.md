Constraints:
  * the (IGEP) control board provides 1.8v I2C and SPI bus via it's 28-pin expansion connector
  * the control board requires 4.8v-5.2v DC at around 650mA-750mA
  * the terminal voltage of the LiPo battery varies from 9v-11.1v
  * the motor controllers use I2C at 5v logic levels
  * the digital gyro needs a supply voltage of 2.1v-3.6v
  * the digital accelerometer needs a supply voltage of 2.0v-3.6v

Implementation:
  * a two-sided power board will be developed
  * the battery will connect to some large vias
  * there will be a 5v power supply for the control board
  * there will be a 3.3v linear regulator for the sensors
  * the power board will mount under the control board, interfacing via the 28-pin expansion connector
  * the expansion connector allows delivery of 5Vdd
  * the expansion connector supplies 1.8Vio
  * the gyro will integrate onto the power board, using 3.3Vdd and 1.8Vio and one SPI bus
  * the accelerometer integrate onto the power board, using 3.3Vdd and 1.8Vio and one I2C bus
  * the I2C 1.8v-5v level shifter chip will interface one I2C bus to the four motor controllers