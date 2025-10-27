# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.2.0)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.2.0-a4)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico2 CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(build_variant2 C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

#add_executable(build_variants main.c )

#pico_set_program_name(build_variants "build_variants")
#pico_set_program_version(build_variants "0.1")

# Modify the below lines to enable/disable output over UART/USB
#pico_enable_stdio_uart(build_variants 0)
#pico_enable_stdio_usb(build_variants 0)

#1
add_library(common_stuff INTERFACE)

# note cmake policy is to use absolute paths for interface libraries.
target_sources(common_stuff INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/main.c
        ${CMAKE_CURRENT_LIST_DIR}/lib/other.c
        )
target_compile_definitions(common_stuff INTERFACE
        A_DEFINE_THAT_IS_SHARED=123
        )

# Add the standard library to the build
target_link_libraries(common_stuff INTERFACE
        pico_stdlib
        )


#2
#add_executable(build_variant1)
#target_link_libraries(build_variant1 common_stuff)
#target_compile_definitions(build_variant1 PRIVATE 
#        A_DEFINE_THAT_IS_NOT_SHARED=456)
#pico_add_extra_outputs(build_variant1)
#3
add_executable(build_variant2)
target_link_libraries(build_variant2 common_stuff)
target_compile_definitions(build_variant2 PRIVATE
        A_DEFINE_THAT_IS_NOT_SHARED=789
        DO_EXTRA)
pico_add_extra_outputs(build_variant2)

