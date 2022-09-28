cmake_minimum_required(VERSION 3.12)

set(NAME pico-trivia)

include(pimoroni_pico_import.cmake)
include(pico_sdk_import.cmake)

# Gooey boilerplate
project(${NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

# Add your source files
add_executable(${NAME}
    main.cpp # <-- Add source files here!n
    trivia_questions.hpp
)

# Include required libraries
include(common/pimoroni_bus)
include(libraries/pico_graphics/pico_graphics)
include(drivers/rgbled/rgbled)
include(drivers/button/button)
include(drivers/st7789/st7789)
include(libraries/bitmap_fonts/bitmap_fonts)
include(libraries/hershey_fonts/hershey_fonts)
include(libraries/pico_display_2/pico_display_2)

# Don't forget to link the libraries you need!
target_link_libraries(${NAME}
    pimoroni_bus
    rgbled
    button
    st7789
    pico_graphics
    bitmap_fonts
    hershey_fonts
    pico_display_2
    pico_stdlib
)

# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})

# Set up files for the release packages
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${NAME}.uf2
    ${CMAKE_CURRENT_LIST_DIR}/README.md
    DESTINATION .
)

set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_GENERATOR "ZIP" "TGZ")
include(CPack)
