# stm8s-discovery-sdcc-blink
A minimal demo project demonstrating blink &amp; build with SDCC &amp; CMake

It is built for the [STM8S-DISCOVERY](https://www.st.com/en/evaluation-tools/stm8s-discovery.html?sc=stm8s-discovery) but should be very easy to port to other STM8 devices.


Based on [this public domain previous work](http://www.colecovision.eu/stm8/L-Discovery%20LED.shtml) but with an actual build system.

This project does NOT use the STM8 peripheral library. I might release a STM8PL-based variant in the future.

Also see [my blogpost on the CMake build configuration](https://techoverflow.net/2019/06/08/a-working-sdcc-stm8-cmake-configuration/) used for this project.

# Prerequisites

I tested this on Ubuntu 18.04

* Install sdcc, e.g. using `sudo apt install sdcc`
* Install cmake, e.g. using `sudo apt install cmake`
* For flashing, install [stm8flash](https://github.com/vdudouyt/stm8flash). I have a deb buildscript available for that at https://github.com/ulikoehler/deb-buildscripts

# How to compile & flash

```sh
cmake .
make
make flash
```

`make flash` will try to flash an attached demo board. If it worked, you should see a slow LED blink.