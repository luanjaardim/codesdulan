cmake_minimum_required(VERSION 3.0)
project(LIBC C)
add_library(libc STATIC c.c)
install(TARGETS libc DESTINATION .)
