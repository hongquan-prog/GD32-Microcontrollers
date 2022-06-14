#include "exti.h"

static exti_callback_t s_exti5_callback = {0};
static exti_callback_t s_exti6_callback = {0};

void bsp_exti_handler(void)
{
    if(SET == exti_interrupt_flag_get(EXTI_5))
    {
        if(s_exti5_callback.callback)
        {
            s_exti5_callback.callback(s_exti5_callback.user_data);
        }
        exti_interrupt_flag_clear(EXTI_5);
    }
    else if(SET == exti_interrupt_flag_get(EXTI_6))
    {
        if(s_exti6_callback.callback)
        {
            s_exti6_callback.callback(s_exti6_callback.user_data);
        }
        exti_interrupt_flag_clear(EXTI_6);
    }
}

void bsp_exti_callback_register(exti_line_enum exti_line, void (*callback)(void *), void *param)
{
    switch (exti_line)
    {
    case EXTI_5:
    s_exti5_callback.callback = callback;
    s_exti5_callback.user_data = param;
        break;
    case EXTI_6:
    s_exti6_callback.callback = callback;
    s_exti6_callback.user_data = param;
        break;
    default:
        break;
    }
}
