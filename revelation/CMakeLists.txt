cmake_minimum_required(VERSION 3.3)
project(Revelationn)

find_package(OpenCV REQUIRED)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
set(CMAKE_C_FLAGS "-std=c99 -lm")

include_directories(${OpenCV_INCLUDE_DIRS})

set(SOURCE_FILES src/reveal.c)
set(SOURCE_FILES src/image.c)
set(SOURCE_FILES src/util.c)

add_executable(
        Revelation

        src/reveal.c
        src/image.c
        src/util.c
)

target_link_libraries(
        Revelation

        ${OpenCV_LIBS}
)