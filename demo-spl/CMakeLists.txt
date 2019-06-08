cmake_minimum_required(VERSION 3.2)

set(CMAKE_C_OUTPUT_EXTENSION ".rel")
set(CMAKE_C_COMPILER sdcc)
set(CMAKE_SYSTEM_NAME Generic) # No linux target etc

# Prevent default configuration
set(CMAKE_C_FLAGS_INIT "")
set(CMAKE_EXE_LINKER_FLAGS_INIT "")

project(STM8Blink C)
SET(CMAKE_C_FLAGS "-mstm8 --std-c99")
set(SPL_PATH STM8S-SDCC-SPL/)
set(SPL_SRC_PATH ${SPL_PATH}/src)
include_directories(${SPL_PATH}/inc ${SPL_PATH}/conf AFTER)
include_directories(. BEFORE)
# Configure which STM8S we are using
add_definitions(-DSTM8S105)

add_executable(main.ihx
    main.c
    ${SPL_SRC_PATH}/stm8s_gpio_Init.c
    ${SPL_SRC_PATH}/stm8s_gpio_WriteLow.c
    ${SPL_SRC_PATH}/stm8s_gpio_WriteHigh.c
    ${SPL_SRC_PATH}/stm8s_tim1_GetCounter.c
    ${SPL_SRC_PATH}/stm8s_tim1_Cmd.c
    ${SPL_SRC_PATH}/stm8s_tim1_TimeBaseInit.c
    ${SPL_SRC_PATH}/stm8s_clk_HSIPrescalerConfig.c
)

# Flash targets
add_custom_target(flash COMMAND stm8flash -c stlink -p stm8s105c6 -w main.ihx)
