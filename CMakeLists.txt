cmake_minimum_required(VERSION 3.27)
project(sae_s1_01_s1_02 C)

set(CMAKE_C_STANDARD 99)

add_executable(sae_s1_01_s1_02
        head/type.h
        head/head.h
        source/main.c
        source/fonctions.c
        source/Larz.c)
