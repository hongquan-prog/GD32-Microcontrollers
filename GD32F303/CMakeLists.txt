cmake_minimum_required(VERSION 3.16)

project(GD32F303 LANGUAGES C CXX ASM VERSION 1.0)

set(TARGET GD32F303)

# ASM sources
set(ASM_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/../Drivers/CMSIS/GD/GD32F30x/Source/GCC/startup_gd32f30x_hd.s)

# linker scripts interrupt vector table offset
set(LINKER_SCRIPTS ${CMAKE_CURRENT_SOURCE_DIR}/../Drivers/CMSIS/GD/GD32F30x/Source/GCC/GD32F303Cxx_FLASH.ld)

# --specs=nano.specs is both a compiler and linker option
set(ARM_OPTIONS -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard)

# macro
set(TARGET_MACRO USE_STDPERIPH_DRIVER GD32F30X_HD)

# C includes
set(C_INCLUDES 
  ${CMAKE_CURRENT_SOURCE_DIR}/Core/inc
  ${CMAKE_CURRENT_SOURCE_DIR}/../Drivers/GD32F30x_standard_peripheral/Include 
  ${CMAKE_CURRENT_SOURCE_DIR}/../Middlewares/FreeRTOS/Source/include 
  ${CMAKE_CURRENT_SOURCE_DIR}/../Middlewares/FreeRTOS/Source/CMSIS_RTOS_V2/ARM_CM4 
  ${CMAKE_CURRENT_SOURCE_DIR}/../Middlewares/FreeRTOS/Source/portable/GCC/ARM_CM4F 
  ${CMAKE_CURRENT_SOURCE_DIR}/..//Drivers/CMSIS/GD/GD32F30x/Include 
  ${CMAKE_CURRENT_SOURCE_DIR}/../Drivers/CMSIS/Include
)

# C sources
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/Core/src C_SOURCES)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/../Drivers/CMSIS/GD/GD32F30x/Source C_SOURCES)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/../Drivers/GD32F30x_standard_peripheral/Source C_SOURCES)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/../Middlewares/FreeRTOS/Source C_SOURCES)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/../Middlewares/FreeRTOS/Source/CMSIS_RTOS_V2/ARM_CM4 C_SOURCES)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/../Middlewares/FreeRTOS/Source/portable/MemMang C_SOURCES)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/../Middlewares/FreeRTOS/Source/portable/GCC/ARM_CM4F C_SOURCES)

# compile
if(NOT COMPILE_RULE_PATH)
  set(COMPILE_RULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../compile.cmake)
endif()
include(${COMPILE_RULE_PATH})