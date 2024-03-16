cmake_minimum_required(VERSION 3.28)
project(MatrixCreatorLib)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the include directory
include_directories(include)

# Collect all source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Define the library
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Specify the target's include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
