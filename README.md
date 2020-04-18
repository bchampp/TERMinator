# Team Terminator

Codebase for CMPE320 Project.
The project consists of reading images of numbers and math equations, processing them and providing feedback. 

## Software Requirements
- OpenCV v4.1
- CMake v3.10 or higher
- OCR Tesseract
- Leptonica
- Matplotlibcpp
- GTKmm

## Deployment
### Build files
All of the source code within this repository uses CMake to build.
CMake was chosen as it allows cross-platform building, and takes care of
any overhead with including the multitude of libraries used. 

### Building the project
If this is your first time building the project on your computer, remember to create a build directory.

Navigate to your build folder and run the 'cmake command'
````
cmake ..
````

#### To generate all executable files
````
make
````

#### Generating specific executable files
````
make <executable name>
````
#### These are the current available target programs
- TERMINATOR (The main program)
- otsuTransformation
- myproject (Tests matplotlib)
- OpenCV_Test 
- OCR_Test

## Structure
### The project structure follows a general C++ application structure.
#### The folders are:
- build
- include
- release
- res
- scripts
- src
- testing

## Components

### The project consists of several moving parts. The main components are:
- Math Engine
- GUI 
- display
- capture
- image

Each of these folders contains the source files for each component used within the project. 

Unit testing was done throughout development of each of these components as seen by the build files within each source folder. 

Bottom up testing was done while putting all of the pieces together in the final build process using cmake. Each component was integrated one at a time into the build process and GUI to verify it works.

First the equation solving engine was integrated with the GUI and a hard-coded result from the OCR engine to validate the equation solving methods and generate a way to display the text. 

Next the matplotlib library was integrated with the project to validate that plots were being generated based on the sample equations and that all results were consistent in the GUI. 

Finally the OCR was integrated to the project and tested with several sample images. This was the moment of "Big Bang Testing" as the team was unsure what would happen. The OCR does not always return nice strings and it can throw curveballs to our other components. 

Several more iterations have been made in the GUI to ensure everything is working properly. This includes preprocessing the strings from the OCR to avoid confusing the math and display engines. Features such as dynamic window resizing and additional buttons have been implemented for ease of use. 

This was a fun one :) 
