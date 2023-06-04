project(WebServer)
cmake_minimum_required(VERSION 3.11.0)
SET(CMAKE_CXX_STANDARD 14)

if(APPLE)
SET(HOMEBREW "/opt/homebrew/Cellar")
include_directories(${HOMEBREW}/cppcms/1.2.1/include)
link_directories(${HOMEBREW}/cppcms/1.2.1/lib)
endif()

add_executable(run main.cpp)
target_link_libraries(run cppcms booster)
