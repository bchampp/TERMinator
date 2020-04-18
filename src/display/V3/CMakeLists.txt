cmake_minimum_required(VERSION 3.15)
project(DisplayV2)

set(CMAKE_CXX_STANDARD 14)

add_executable(DisplayV2 main.cpp Display.cpp Display.h)


#[[find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(DisplayV2 ${PYTHON_LIBRARIES})
target_link_libraries(DisplayV2 ${VC_ExecutablePath_x64})
find_package(Python3 COMPONENTS Interpreter Development)

find_package(NumPy)
if (${PYTHON_NUMPY_FOUND})
    include_directories(${PYTHON_NUMPY_INCLUDE_DIR})
else()
    message(WARNING "Python3 NumPy not found, proceeding with -DWITHOUT_NUMPY."
            " Some functions might not work.")
    add_definitions(-DWITHOUT_NUMPY)
endif()]]
