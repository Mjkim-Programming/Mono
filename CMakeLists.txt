cmake_minimum_required(VERSION 3.16)
project(MonoObservable LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_observable tests/main.cpp)
target_include_directories(test_observable PRIVATE include)

find_package(GTest REQUIRED)
target_link_libraries(test_observable PRIVATE GTest::GTest GTest::Main)

enable_testing()
add_test(NAME TestObservable COMMAND test_observable)

install(DIRECTORY include/mono DESTINATION include)