cmake_minimum_required(VERSION 3.22)
project(myttr)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)

find_package(Boost 1.78 COMPONENTS range REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

ad_executable(myttr main.cpp Parser.cpp Timer.cpp Parser.h Timer.h)

target_link_libraries(myttr LINK_PUBLIC ${Boost_LIBRARIES})

