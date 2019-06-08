# stm8s-discovery-sdcc-blink
A minimal demo project demonstrating blink &amp; build with SDCC &amp; CMake.
**This project is mainly intended to be used as a template for custom projects.**

It is built for the [STM8S-DISCOVERY](https://www.st.com/en/evaluation-tools/stm8s-discovery.html?sc=stm8s-discovery) but should be very easy to port to other STM8 devices.

There are **two indepedent versions of this demo application**:

* One [without any dependencies](https://github.com/ulikoehler/stm8s-discovery-sdcc-blink/blob/demo-no-peripherial-library/README.md)
* Another one [with the standard peripheral library](https://github.com/ulikoehler/stm8s-discovery-sdcc-blink/blob/demo-spl/README.md)

At the time of writing this, SDCC does not really support dead code elision, therefore the SPL version is (without further manual optimizations) generating huge binaries (around 10kB) while the no-dependencies version is only using <0.5kB of binary size. However, the SPL version is MUCH easier to read.

In case you are not limited by space for your application, I recommend to use the SPL version. Since the STM8 microcontrollers tend to have lots of flash space, this should be the case for many applications.