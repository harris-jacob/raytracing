 
cmake_minimum_required(VERSION 3.17.2)
project(raytracing
    VERSION 0.1.0
    DESCRIPTION "Toy Raytracer"
    LANGUAGES CXX)

# Project wide C++ standard
set(CMAKE_CXX_STANDARD 17)

# Recurse into src.
add_subdirectory(src)