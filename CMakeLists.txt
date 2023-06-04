project(WebServer)
cmake_minimum_required(VERSION 3.11.0)
SET(CMAKE_CXX_STANDARD 14)


if(WIN32)

elseif(APPLE)
    set(HOMEBREW "/opt/homebrew/Cellar")
    #cppcms
    include_directories(${HOMEBREW}/cppcms/1.2.1/include)
    link_directories(${HOMEBREW}/cppcms/1.2.1/lib)

    #boost
    include_directories(${HOMEBREW}/boost/1.81.0_1/include)
    link_directories(${HOMEBREW}/boost/1.81.0_1/lib)
elseif(UNIX)

endif()

find_package(Boost REQUIRED COMPONENTS log)

set(HEADER_FILES
        include/cppcms_sample_server.h
        include/cppcms_sample_client.h
        )

set(SOURCE_FILES
        main.cpp
        src/server/cppcms_sample_server.cpp
        src/client/cppcms_sample_client.cpp
        )

add_executable(run
        ${HEADER_FILES}
        ${SOURCE_FILES}

        main.cpp
        )

target_link_libraries(run
                        cppcms
                        booster
                        Boost::log)

