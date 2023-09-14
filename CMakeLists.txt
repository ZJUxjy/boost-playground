cmake_minimum_required(VERSION 3.14)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(playground)
#use pthread    
set(CXX_STANDARD 20)
set(CPLUSPLUS_VER c++20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=${CPLUSPLUS_VER} -fPIC -fno-omit-frame-pointer")
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
include(cmake/CPM.cmake)
include(extern_dep.cmake)
find_package(Boost REQUIRED
COMPONENTS 
system
thread
chrono
date_time
regex
filesystem
coroutine 
fiber
context
# interprocess 
)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

# add_library(
#     session
#     session.cpp
# )
add_executable(
    coroutine
    coroutines.cpp
)
target_link_libraries(
    coroutine
    ${Boost_LIBRARIES}
    glog
    # session
)
add_executable(
    fiber
    fiber.cpp
)
target_link_libraries(
    fiber
    ${Boost_LIBRARIES}
    glog
    # session
)
add_executable(
    fiberpool
    fiberpool.cpp
)
target_link_libraries(
    fiberpool
    ${Boost_LIBRARIES}
    glog
    # session
)