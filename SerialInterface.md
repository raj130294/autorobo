### Standard cable ###
  1. obtain:
    * DB9 male plug (optionally with back)
    * 10 mil spacing 2x5 connector (with socket-pins)
    * 9-way ribbon cable
    * null serial cable
  1. wire DB9 pin 1 to RS232 header's pin 1
  1. straight through wiring with pin 2 .. pin N
  1. for modern systems, obtain:
    * USB-serial adapter
    * serial

### Ninja/travel cable ###
  1. obtain USB-serial adapter
    * eg _Sweex_ brand, easy to open
  1. open and desolder DB9 plug
  1. solder ribbon cable with equivalent wiring
  1. optionally heat-shrink exposed USB-serial PCB

### Software configuration ###
  1. use either:
    * _Microsoft Terminal_ on Windows
    * minicom on Ubuntu (sudo apt-get install -y minicom)
  1. configure for:
    * 115200 baud
    * 8 data bits, 1 stop, no parity
    * software-only flow control
  1. output should be received as soon as board power is applied

### Troubleshooting ###
  * ensure hardware flowcontrol is disabled