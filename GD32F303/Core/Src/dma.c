#include "dma.h"

static dma_callback_t s_dma0_ch0_callback = {0};
static dma_callback_t s_dma1_ch2_callback = {0};

void bsp_dma_handler(uint32_t dma)
{
    if (DMA0 == dma)
    {
        if (dma_interrupt_flag_get(DMA0, DMA_CH0, DMA_INT_FLAG_FTF))
        {
            if (s_dma0_ch0_callback.callback)
            {
                s_dma0_ch0_callback.callback(s_dma0_ch0_callback.user_data);
            }
            dma_interrupt_flag_clear(DMA0, DMA_CH0, DMA_INT_FLAG_FTF);
        }
    }
    else if (DMA1 == dma)
    {
        if (dma_interrupt_flag_get(DMA1, DMA_CH2, DMA_INT_FLAG_FTF))
        {
            if (s_dma1_ch2_callback.callback)
            {
                s_dma1_ch2_callback.callback(s_dma1_ch2_callback.user_data);
            }
            dma_interrupt_flag_clear(DMA1, DMA_CH2, DMA_INT_FLAG_FTF);
        }
    }
}

void bsp_dma0_full_transmit_callback_register(uint32_t dma, dma_channel_enum channel, void (*callback)(void *), void *param)
{
    if (DMA0 == dma)
    {
        if (DMA_CH0 == channel)
        {
            s_dma0_ch0_callback.callback = callback;
            s_dma0_ch0_callback.user_data = param;
        }
    }
    else if (DMA1 == dma)
    {
        if (DMA_CH2 == channel)
        {
            s_dma1_ch2_callback.callback = callback;
            s_dma1_ch2_callback.user_data = param;
        }
    }
}
