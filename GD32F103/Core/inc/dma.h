#pragma once

#include "gd32f10x.h"

typedef struct 
{
  void(*callback)(void *);
  void *user_data;
}dma_callback_t;

void bsp_dma_full_transmit_callback_register(uint32_t dma, dma_channel_enum channel, void (*callback)(void *), void *param);
