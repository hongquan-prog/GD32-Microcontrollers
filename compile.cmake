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

######################################
# cross compile 
######################################
add_executable(${TARGET} 
  ${ASM_SOURCES} 
  ${C_SOURCES}
)

target_compile_definitions(${TARGET} PRIVATE
  ${TARGET_MACRO}
)

set_target_properties(${TARGET} PROPERTIES 
  SUFFIX .elf 
  LINK_DEPENDS ${LINKER_SCRIPTS}
)

target_compile_options(${TARGET} PRIVATE
  ${ARM_OPTIONS}
)

target_link_options(${TARGET} PRIVATE
  ${ARM_OPTIONS}
  -specs=nano.specs
  -u 
  _printf_float
  -T${LINKER_SCRIPTS}
  LINKER:--print-memory-usage
  LINKER:-Map,${CMAKE_CURRENT_BINARY_DIR}/${TARGET}.map,--cref 
)

target_link_libraries(${TARGET}
  c_nano 
  nosys
  m
)

target_include_directories(${TARGET} PRIVATE ${C_INCLUDES})

######################################
# convert elf to bin and hex 
######################################
if (EXISTS ${ARM_TOOL_OBJCOPY})
  add_custom_command(
    TARGET ${TARGET}
    POST_BUILD
    COMMAND ${ARM_TOOL_OBJCOPY} -O ihex $<TARGET_FILE:${TARGET}> 
            ${CMAKE_CURRENT_BINARY_DIR}/$<TARGET_NAME:${TARGET}>.hex
    COMMAND ${ARM_TOOL_OBJCOPY} -O binary -S $<TARGET_FILE:${TARGET}> 
            ${CMAKE_CURRENT_BINARY_DIR}/$<TARGET_NAME:${TARGET}>.bin
  )
else()
  message(STATUS "'objcopy' not found: cannot generate .hex and .bin file")
endif()

######################################
# output segment information
######################################
if (EXISTS "${ARM_TOOL_SIZE}")
  add_custom_command(
    TARGET ${TARGET}
    POST_BUILD
    COMMAND ${ARM_TOOL_SIZE} --format=berkeley $<TARGET_FILE:${TARGET}>
            >${CMAKE_CURRENT_BINARY_DIR}/$<TARGET_NAME:${TARGET}>.bsz
  )

  add_custom_command(
    TARGET ${TARGET}
    POST_BUILD
    COMMAND ${ARM_TOOL_SIZE} --format=sysv -x $<TARGET_FILE:${TARGET}>
            >${CMAKE_CURRENT_BINARY_DIR}/$<TARGET_NAME:${TARGET}>.ssz
  )

else()

    message(STATUS "'size' not found: cannot generate .[bs]sz files")

endif()
