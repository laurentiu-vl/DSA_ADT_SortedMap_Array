cmake_minimum_required(VERSION 3.30)
project(SDA_2024_2025_Lab1_SortedMap)

set(CMAKE_CXX_STANDARD 20)

add_executable(SDA_2024_2025_Lab1_SortedMap main.cpp
        SMIterator.cpp
        SMIterator.h
        SortedMap.cpp
        SortedMap.h
        ShortTest.cpp
        ShortTest.h
        ExtendedTest.cpp
        ExtendedTest.h)
