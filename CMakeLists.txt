cmake_minimum_required(VERSION 3.20)
project(cpp17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Define the main source directory for clarity
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

if(CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang)")
    add_compile_options(-Wall -Wextra -Wpedantic -Wshadow)
endif()
#set(SOURCES ${SOURCE_DIR}/*.cpp)
add_executable(cpp17 main.cpp ${SOURCES})
