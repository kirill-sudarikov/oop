cmake_minimum_required(VERSION 4.1)

project("lab5" CXX)

add_executable("${PROJECT_NAME}")

target_compile_features("${PROJECT_NAME}" PUBLIC cxx_std_23)

target_sources("${PROJECT_NAME}"
	PRIVATE 
		"main.cpp" 
	PRIVATE FILE_SET "modules" TYPE CXX_MODULES FILES
		"upload_file.cppm"
 "count_unique_words.cppm" "find_most_frequent_words.cppm")