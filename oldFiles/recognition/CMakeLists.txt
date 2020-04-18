cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME "recognition-test")
project(${PROJECT_NAME} CXX)

find_package(Tesseract REQUIRED)
message("Found ${Tesseract_LIBRARIES}")

# Include directories
include_directories(${Tesseract_INCLUDE_DIRS})

add_executable(test main.cpp)
target_link_libraries(test libtesseract)