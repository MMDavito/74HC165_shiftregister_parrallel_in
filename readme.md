This is a small part in order to implement version two of:
https://github.com/MMDavito/8_switch_rgb

Leassons learnt from experiments:
1. Pull-Down resistors are needed also for SPDT switches.
2. Unused inputs needs to be pulled low/grounded.
3. Clock inhibit is useful, but not for this project => GND it.
4. MSB == bit0 == Input H; LSB == bit7 == Input A.
