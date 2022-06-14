#pragma once

#include "gd32f10x.h"

typedef struct 
{
  void(*callback)(void *);
  void *user_data;
}exti_callback_t;

void bsp_exti_handler(void);
void bsp_exti_callback_register(exti_line_enum exti_line, void (*callback)(void *), void *param);