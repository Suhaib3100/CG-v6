cmake_minimum_required(VERSION 3.10)

# Set the project name
project(EmotionDetection)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set OpenCV, SDL2, and OpenGL directories (Update paths as per your system)
set(OpenCV_DIR "C:/OpenCV/build/x64/vc16/lib")
set(SDL2_INCLUDE_DIR "C:/SDL2/i686-w64-mingw32/include/SDL2")
set(SDL2_LIB_DIR "C:/SDL2/i686-w64-mingw32/lib")

# Find OpenCV
find_package(OpenCV REQUIRED)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Find SDL2
find_library(SDL2_LIBRARY SDL2 HINTS ${SDL2_LIB_DIR})
find_library(SDL2MAIN_LIBRARY SDL2main HINTS ${SDL2_LIB_DIR})

# Include directories for headers
include_directories(
    ${OpenCV_INCLUDE_DIRS} 
    ${SDL2_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/include  # Include header directory from project
)

# Add the source files
set(SOURCES
    src/main.cpp
    src/EmotionDetector.cpp
    src/Renderer.cpp
    src/AudioPlayer.cpp
)

# Add the headers
set(HEADERS
    include/EmotionDetector.h
    include/Renderer.h
    include/AudioPlayer.h
)

# Add the shaders directory
file(GLOB SHADERS shaders/*.glsl)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${SHADERS})

# Link libraries
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} ${OPENGL_LIBRARIES} ${SDL2_LIBRARY} ${SDL2MAIN_LIBRARY})
