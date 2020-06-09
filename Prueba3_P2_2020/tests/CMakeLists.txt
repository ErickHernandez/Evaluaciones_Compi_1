cmake_minimum_required (VERSION 2.6)
project (test_parser)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Run ECC to generate the parser table
add_custom_command (
  OUTPUT expr_slr_table.cpp expr_slr_table.h
  COMMAND ecc --hdr expr_slr_table.h --src expr_slr_table.cpp -g ${PROJECT_SOURCE_DIR}/../grammar_slr.txt --alg slr
  MAIN_DEPENDENCY ${PROJECT_SOURCE_DIR}/../grammar_slr.txt
  )

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/../)
  
add_executable(${PROJECT_NAME}  ../expr_parser.cpp
                                ../expr_lexer.cpp
                                expr_slr_table.cpp
                                test_parser.cpp)

enable_testing()
add_test(NAME ${PROJECT_NAME}
         COMMAND ${PROJECT_NAME})
