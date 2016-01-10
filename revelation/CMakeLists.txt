cmake_minimum_required(VERSION 3.3)
project(Revelationn)

find_package(OpenCV REQUIRED)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BUILD_TYPE})
set(CMAKE_C_FLAGS "-std=c99 -lm")

include_directories(${OpenCV_INCLUDE_DIRS})

set(SOURCE_FILES src/)

add_executable(
        reveal

        src/main.c
        src/reveal.c
        src/image.c
        src/utils/utilBit.c
        src/utils/formatDetector.c
        src/utils/checkFormat.c
        src/arguments.c
)

target_link_libraries(
        reveal

        ${OpenCV_LIBS}
)