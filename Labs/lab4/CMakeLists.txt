cmake_minimum_required(VERSION 4.1)

project("lab4" CXX)

add_executable("${PROJECT_NAME}")

target_compile_features("${PROJECT_NAME}" PUBLIC cxx_std_23)

target_sources("${PROJECT_NAME}" PRIVATE "src/main.cpp"
PRIVATE FILE_SET "constants" TYPE CXX_MODULES FILES
"src/logic/constants.cppm" 
"src/utils/random.cppm"
"src/logic/character.cppm"
"src/logic/characters/Knight.cppm"
"src/logic/characters/Assassin.cppm"
"src/logic/characters/Berserker.cppm"
)