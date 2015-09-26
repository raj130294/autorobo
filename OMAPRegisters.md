To set the processor frequency:
  * CM\_CLKSEL1\_PLL\_MPU is at 0x48004940
  * write (MHZ << 8 | 0x10000c) to 0x48004940
  * eg 720MHz with U-Boot:
```
mw 0x48004940 0x12d00c
```