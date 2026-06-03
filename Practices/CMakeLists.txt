cmake_minimum_required(VERSION 4.1)

set(CMAKE_CXX_MODULE_STD ON)

if(CMAKE_VERSION VERSION_GREATER_EQUAL "4.3.0")
  # https://github.com/Kitware/CMake/blob/v4.3.0/Help/dev/experimental.rst
  set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD 451f2fe2-a8a2-47c3-bc32-94786d8fc91b)
elseif(CMAKE_VERSION VERSION_GREATER_EQUAL "4.1.0")
  # https://github.com/Kitware/CMake/blob/v4.1.0/Help/dev/experimental.rst
  set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD d0edc3af-4c50-42ea-a356-e2862fe7a444)
endif()

project("Practices" CXX)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR
   CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  endif()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8 /W4")
  add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_WIN32_WINNT=0x0A00)
endif()

add_subdirectory("03-functions")
add_subdirectory("04-classes")
add_subdirectory("09-vcpkg")
add_subdirectory("10-sfml")
add_subdirectory("05-operator-overloading")
