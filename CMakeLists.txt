cmake_minimum_required(VERSION 3.13.4)

project(Search)
SET(CMAKE_CXX_STANDARD 14)



set (MACHINE_LEARNING_SOURCES
        src/main.cpp 
        src/Node.cpp 
        src/GreedySerach.cpp
)

include_directories(header)

add_executable(${PROJECT_NAME} ${MACHINE_LEARNING_SOURCES})