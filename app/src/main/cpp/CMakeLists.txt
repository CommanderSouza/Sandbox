cmake_minimum_required(VERSION 3.18.1)

project("sandbox")

add_library(
        encrypt
        SHARED
        encrypt.c
)

find_library(
        log-lib
        log)

target_link_libraries(
        encrypt
        ${log-lib})