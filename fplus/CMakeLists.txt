cmake_minimum_required(VERSION 2.8)

project(fplus)

include(ExternalProject)
ExternalProject_Add(functional_plus
  GIT_REPOSITORY https://github.com/Dobiasd/FunctionalPlus.git
  GIT_TAG master

  SOURCE_DIR "${CMAKE_BINARY_DIR}/thirdparty/fplus"

  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND ""

  LOG_DOWNLOAD ON
  LOG_BUILD ON
)
set(FPLUS_INCLUDE_DIR ${CMAKE_BINARY_DIR}/thirdparty/fplus/include)
include_directories(${FPLUS_INCLUDE_DIR})

add_executable(${PROJECT_NAME} "main.cpp")
add_dependencies(${PROJECT_NAME} functional_plus)
