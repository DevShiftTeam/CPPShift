cmake_minimum_required(VERSION 3.15)
project(CPPShift)

set(CMAKE_CXX_STANDARD 17)

set(Boost_INCLUDE_DIR C:/Projects/boost_1_72_0)
set(Boost_LIBRARY_DIR C:/Projects/boost_1_72_0/stage/lib)


include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(CPPShift main.cpp Master.cpp Master.h ComponentManager.cpp ComponentManager.h ComponentUnit.h ComponentTypes.h Component.cpp Configurations.cpp Configurations.h)