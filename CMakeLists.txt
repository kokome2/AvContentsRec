project(WebServer)
cmake_minimum_required(VERSION 3.11.0)
SET(CMAKE_CXX_STANDARD 11)

include_directories(/opt/homebrew/Cellar/cppcms/1.2.1/include)
link_directories(/opt/homebrew/Cellar/cppcms/1.2.1/lib)

add_executable(run main.cpp)
target_link_libraries(run cppcms booster)
