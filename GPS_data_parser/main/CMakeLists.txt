# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

# Our Project
set(SOURCE_FILES
    main.cpp
    GPS_data_parser_header.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
