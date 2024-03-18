cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)

# Include ESP-IDF build system
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(my_project_name)

# Add your source files to the project
idf_component_register(SRCS "unitTest.cpp"
                       INCLUDE_DIRS ".")

# Include directories
target_include_directories(${COMPONENT_LIB} INTERFACE .)
