#include <stdint.h>
#include <stm8s_clk.h>
#include <stm8s_gpio.h>
#include <stm8s_tim1.h>
#include <stm8s_flash.h>

void assert_failed(uint8_t* file, uint32_t line) {
    (void)file;
    (void)line;
}

void main(void)
{
    // Set 16 MHz CPU clock
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);

    GPIO_Init(GPIOD, GPIO_PIN_0, GPIO_MODE_OUT_OD_LOW_SLOW);

	// Configure timer
	// 1000 ticks per second
    TIM1_TimeBaseInit(16000, TIM1_COUNTERMODE_UP, 16000 /* a */, 1 /* RCR */);
	TIM1_Cmd(ENABLE);
	// Enable timer

    while (1) {
        if(TIM1_GetCounter() % 1000 < 500) {
            GPIO_WriteLow(GPIOD, GPIO_PIN_0);
        } else {
            GPIO_WriteHigh(GPIOD, GPIO_PIN_0);
        }
    }
}
