cmake_minimum_required(VERSION 3.10.2)

project("fmodtest")

file(GLOB allFile *.c *.h *.cpp)
add_library(
        native-lib
        SHARED
        ${allFile})

target_link_libraries(
        native-lib
        log)