cmake_minimum_required(VERSION 4.1)

project("08-subtype-polymorphism" CXX)

add_executable("${PROJECT_NAME}")

target_compile_features("${PROJECT_NAME}" PUBLIC cxx_std_23)

target_sources("${PROJECT_NAME}" PRIVATE "src/main.cpp"
PRIVATE FILE_SET "modules" TYPE CXX_MODULES FILES
"interfaces/IEnumerator.cppm"
"interfaces/IEnumerable.cppm"
"interfaces/ICollection.cppm"
"containers/List.cppm"
)
