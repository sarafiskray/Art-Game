cmake_minimum_required(VERSION 3.8)
project(The-Statistics)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fpermissive")

find_package (OpenGL REQUIRED)
find_package (GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS})

file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

add_executable(main.cpp ${SOURCE_FILES} Brush.cpp Brush.h Character.cpp Character.h DottedBrush.cpp DottedBrush.h graphics.cpp graphics.h Map.cpp Map.h Splatter.cpp Splatter.h Headings.h Headings.cpp Eraser.cpp Eraser.h)

target_link_libraries (main.cpp ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} m dl pthread)