#include "gpio.h"

void bsp_gpio_config(void)
{
    /* enable the LEDs GPIO clock */
    rcu_periph_clock_enable(RCU_GPIOB);
    
    /* configure LED1 LED2 GPIO port */
    gpio_init(SYS_LED_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, SYS_LED_PIN);

    /* reset LED1 LED2 GPIO pin */
    gpio_bit_reset(SYS_LED_PORT, SYS_LED_PIN);
}
