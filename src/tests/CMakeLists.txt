cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

set(test_sources
	FractionTests.cxx
   )

add_executable(FractionTests FractionTests.cxx)

set_target_properties(FractionTests PROPERTIES FOLDER "Tests")

target_link_libraries(FractionTests PUBLIC gtest gtest_main operations)