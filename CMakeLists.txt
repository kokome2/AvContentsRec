project(WebServer)
cmake_minimum_required(VERSION 3.11.0)
SET(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED COMPONENTS log)

set(HEADER_FILES
        )

set(SOURCE_FILES
        main.cpp
        )

add_executable(run
        ${HEADER_FILES}
        ${SOURCE_FILES}

        main.cpp
        )

target_link_libraries(run
                        Boost::log)

