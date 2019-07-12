cmake_minimum_required(VERSION 2.8)

project(fmtStuff)
add_executable(${PROJECT_NAME} "main.cpp")
find_package(fmt)
target_link_libraries(${PROJECT_NAME} fmt::fmt)
