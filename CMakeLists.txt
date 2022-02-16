cmake_minimum_required(VERSION 3.20)
project(credit VERSION 0.1.0 LANGUAGES C)

set(CREDIT_EXE ${PROJECT_NAME})
set(GENERATED_DIR ${PROJECT_BINARY_DIR}/generated)

configure_file(${CMAKE_SOURCE_DIR}/src/config.h.in ${GENERATED_DIR}/config.h)

add_executable(${CREDIT_EXE})
target_include_directories(${CREDIT_EXE} PRIVATE
  ${GENERATED_DIR}
  ${CMAKE_SOURCE_DIR}/src
  )

add_subdirectory(${CMAKE_SOURCE_DIR}/src)
