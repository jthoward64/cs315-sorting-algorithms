cmake_minimum_required(VERSION 3.13)  # CMake version check
project(pokemonsort)               # Create project "pokemonsort"
set(CMAKE_CXX_STANDARD 17)            # Enable c++17 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.cpp pokemondata.cpp pokemondataitem.cpp sorter.cpp insertionsorter.cpp quicksorter.cpp mergesorter.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(pokemonsort ${SOURCE_FILES})
