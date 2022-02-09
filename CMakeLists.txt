cmake_minimum_required(VERSION 3.20)
project(credit C)

set(CREDIT_EXE ${PROJECT_NAME})

add_executable(${CREDIT_EXE})
target_include_directories(${CREDIT_EXE} PRIVATE
  ${CMAKE_SOURCE_DIR}/src
  )

add_subdirectory(${CMAKE_SOURCE_DIR}/src)
