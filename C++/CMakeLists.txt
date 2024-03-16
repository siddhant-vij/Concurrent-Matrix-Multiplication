cmake_minimum_required(VERSION 3.28)
project(FullMatrixProject)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Macro with the path to the Input.txt file
add_compile_definitions(INPUT_FILE_PATH="${CMAKE_SOURCE_DIR}/Input.txt")

# Add subdirectories for the library and the executable
add_subdirectory(MatrixCreatorLib)
add_subdirectory(MatrixMultiplication)
