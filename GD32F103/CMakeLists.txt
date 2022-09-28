cmake_minimum_required(VERSION 3.16)

project(GD32F103 LANGUAGES C CXX ASM VERSION 1.0)

set(TARGET GD32F103-V${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR})

# ASM sources
set(ASM_SOURCES ${CMAKE_SOURCE_DIR}/Drivers/CMSIS/GD/GD32F10x/Source/GCC/startup_gd32f10x_md.s)

# linker scripts interrupt vector table offset
set(LINKER_SCRIPTS ${CMAKE_SOURCE_DIR}/Drivers/CMSIS/GD/GD32F10x/Source/GCC/GD32F103C8Tx_FLASH.ld)

# --specs=nano.specs is both a compiler and linker option
set(ARM_OPTIONS -mcpu=cortex-m3 -mthumb)

# macro
set(TARGET_MACRO USE_STDPERIPH_DRIVER GD32F10X_MD)

# C includes
set(C_INCLUDES 
  ${CMAKE_CURRENT_SOURCE_DIR}/Core/inc
  ${CMAKE_SOURCE_DIR}/Drivers/GD32F10x_standard_peripheral/Include 
  ${CMAKE_SOURCE_DIR}/Middlewares/FreeRTOS/Source/include 
  ${CMAKE_SOURCE_DIR}/Middlewares/FreeRTOS/Source/CMSIS_RTOS_V2/ARM_CM3 
  ${CMAKE_SOURCE_DIR}/Middlewares/FreeRTOS/Source/portable/GCC/ARM_CM3 
  ${CMAKE_SOURCE_DIR}/Drivers/CMSIS/GD/GD32F10x/Include 
  ${CMAKE_SOURCE_DIR}/Drivers/CMSIS/Include
)

# C sources
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/Core/src C_SOURCES)
aux_source_directory(${CMAKE_SOURCE_DIR}/Drivers/CMSIS/GD/GD32F10x/Source C_SOURCES)
aux_source_directory(${CMAKE_SOURCE_DIR}/Drivers/GD32F10x_standard_peripheral/Source C_SOURCES)
aux_source_directory(${CMAKE_SOURCE_DIR}/Middlewares/FreeRTOS/Source C_SOURCES)
aux_source_directory(${CMAKE_SOURCE_DIR}/Middlewares/FreeRTOS/Source/CMSIS_RTOS_V2/ARM_CM3 C_SOURCES)
aux_source_directory(${CMAKE_SOURCE_DIR}/Middlewares/FreeRTOS/Source/portable/MemMang C_SOURCES)
aux_source_directory(${CMAKE_SOURCE_DIR}/Middlewares/FreeRTOS/Source/portable/GCC/ARM_CM3 C_SOURCES)

######################################
# cross compile option
######################################
add_compile_options(
  -Wall
  $<$<CONFIG:DEBUG>:-g>
  $<$<CONFIG:DEBUG>:-gdwarf-2>
  $<$<CONFIG:DEBUG>:-O0>
  $<$<CONFIG:RELEASE>:-O1>
)

include(${COMPILE_RULE_PATH})
