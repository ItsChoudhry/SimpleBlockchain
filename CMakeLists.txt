cmake_minimum_required(VERSION 3.2)
project(Crypto)

include_directories ("${PROJECT_SOURCE_DIR}/Blockchain")
add_subdirectory (Blockchain)

add_executable(Crypto main.cpp)
target_link_libraries (Crypto Blockchain)