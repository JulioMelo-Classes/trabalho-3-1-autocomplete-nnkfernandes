cmake_minimum_required(VERSION 3.0)
project (Autocomplete VERSION 1.0 LANGUAGES CXX)

set( CMAKE_CXX_STANDAR 17)

include_directories( ./include)

add_executable( autocomplete
                ./src/main.cpp
                ./src/DataBase.cpp
                ./src/File.cpp
                ./src/Interface.cpp
                ./src/Match.cpp
                ./src/Sentence.cpp )


#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 11)
#--------------------------------

### [1] Application target
# configura o diretório contendo os .h, assim você pode incluílos apenas com include "arquivo.h"
include_directories( include )

### [2] Test engine
# includes do test manager
include_directories( test_manager/include )

set ( TEST_NAME "all_tests")

# Cria um executável com nome "run_tests", adiciona neste executável os arquivos do test manager e o seu main.cpp
add_executable( ${TEST_NAME}
                test_manager/src/test_manager.cpp
                ./src/test.cpp
                ./src/DataBase.cpp
                ./src/File.cpp
                ./src/Interface.cpp
                ./src/Match.cpp
                ./src/Sentence.cpp )


# define C++11 standard
set_property(TARGET all_tests PROPERTY CXX_STANDARD 11)

add_custom_target(
    run_tests
    COMMAND ${TEST_NAME}
)
