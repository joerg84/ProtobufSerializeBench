PROJECT(psb)
CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
SET(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")

ADD_SUBDIRECTORY(proto)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
ADD_EXECUTABLE(benchmark main.cpp)
TARGET_LINK_LIBRARIES(benchmark proto ${PROTOBUF_LIBRARY})
