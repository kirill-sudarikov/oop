cmake_minimum_required(VERSION 4.1)

project("09-vcpkg" CXX)

find_package("Stb" REQUIRED)

add_executable("${PROJECT_NAME}")

target_compile_features("${PROJECT_NAME}" PUBLIC cxx_std_23)

target_include_directories("${PROJECT_NAME}" PRIVATE "${Stb_INCLUDE_DIR}")

target_sources("${PROJECT_NAME}" PRIVATE "main.cpp")