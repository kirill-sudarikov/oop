cmake_minimum_required(VERSION 4.1)

project("lab4" CXX)

add_executable("${PROJECT_NAME}")

target_compile_features("${PROJECT_NAME}" PUBLIC cxx_std_23)

target_sources("${PROJECT_NAME}" PRIVATE "main.cpp"
PRIVATE FILE_SET "constants" TYPE CXX_MODULES FILES "constants.cppm"  "random.cppm" "character.cppm" "Knight.cppm" "Assassin.cppm" "Berserker.cppm")