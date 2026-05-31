cmake_minimum_required(VERSION 4.1)

project("10-sfml" CXX)

find_package("SFML" REQUIRED COMPONENTS "Graphics")

add_executable("${PROJECT_NAME}")

target_compile_features("${PROJECT_NAME}" PUBLIC cxx_std_23)

target_link_libraries("${PROJECT_NAME}" PRIVATE "SFML::Graphics")

target_sources("${PROJECT_NAME}" PRIVATE "main.cpp")


