# Global CMake file for CMPE320 Terminator group

# Specify minimum version of CMake tool
cmake_minimum_required( VERSION 3.10 )

# Find the OpenCV library
message("Finding OpenCV Libraries...")
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS})
message("Found OpenCV Libraries")

# Start the Package Config
find_package(PkgConfig)
find_package(PythonLibs 2.7)
# Find our modules
pkg_search_module( TESSERACT REQUIRED tesseract )
pkg_search_module( LEPTONICA REQUIRED lept )
pkg_check_modules(GTKMM gtkmm-3.0)

# Include everything
include_directories(${GTKMM_INCLUDE_DIRS})
include_directories( ${TESSERACT_INCLUDE_DIRS} )
include_directories( ${LEPTONICA_INCLUDE_DIRS} )

link_directories( ${TESSERACT_LIBRARY_DIRS} )
link_directories( ${LEPTONICA_LIBRARY_DIRS} )

set(GUI_src
    src/GUI/mainwindow.cpp
)

set(IMAGE_src
    src/image/Image.cpp
)

set(MATH_src
    src/equationSolverV2/Equation.cpp
    src/equationSolverV2/Fraction.cpp
    src/equationSolverV2/Polynomial.cpp
)

set(DISPLAY_src
    src/display/V3/Display.cpp)

# Include top level header files to the project
include_directories(include/)

add_executable(TERMINATOR src/main.cpp ${IMAGE_src} ${MATH_src} ${GUI_src} )
target_include_directories(TERMINATOR PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(TERMINATOR ${GTKMM_LIBRARIES} tesseract lept ${PYTHON_LIBRARIES} ${OpenCV_LIBS})

add_executable(otsuTransformation src/image/otsuTransform.cpp)
target_link_libraries(otsuTransformation ${OpenCV_LIBS})

add_executable(myproject src/testplot.cpp )
target_include_directories(myproject PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(myproject ${PYTHON_LIBRARIES})