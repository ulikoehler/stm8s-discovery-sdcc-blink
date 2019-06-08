# stm8s-discovery-sdcc-blink (demo-spl)
A minimal demo project demonstrating blink &amp; build with SDCC &amp; CMake using the STM8S Standard Peripheral Library (SPL) [modified for the SDCC compiler](https://github.com/ulikoehler/STM8S-SDCC-SPL).

**This project is mainly intended to be used as a template for custom projects.**

*Note:* This project requires at least SDCC 3.4.3!

It is built for the [STM8S-DISCOVERY](https://www.st.com/en/evaluation-tools/stm8s-discovery.html?sc=stm8s-discovery) but should be very easy to port to other STM8 devices.

Also see [my blogpost on the CMake build configuration](https://techoverflow.net/2019/06/08/a-working-sdcc-stm8-cmake-configuration/) used for this project.

# Prerequisites

I tested this on Ubuntu 18.04

* Install sdcc, e.g. using `sudo apt install sdcc`
* Install cmake, e.g. using `sudo apt install cmake`
* For flashing, install [stm8flash](https://github.com/vdudouyt/stm8flash). I have a deb buildscript available for that at https://github.com/ulikoehler/deb-buildscripts

# How to compile & flash

This project pulls the [STM8S peripheral library](https://github.com/ulikoehler/STM8S-SDCC-SPL) using *git submodule*.

```sh
git submodule init
git submodule update
cmake .
make
make flash
```

`make flash` will try to flash an attached demo board. If it worked, you should see a slow LED blink.
