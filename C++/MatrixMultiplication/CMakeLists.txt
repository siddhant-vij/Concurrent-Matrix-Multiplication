cmake_minimum_required(VERSION 3.28)
project(MatrixMultiplication)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ../MatrixCreatorLib/include)

# Recursively find all .cpp files in the src directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Specify the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Specify the target's include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link with the MatrixCreatorLib library
target_link_libraries(${PROJECT_NAME} PRIVATE MatrixCreatorLib)
