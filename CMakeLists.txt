cmake_minimum_required(VERSION 3.29)
project(Dapper_dasher)

set(CMAKE_CXX_STANDARD 20)

# raylib 경로 설정
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_executable(Dapper_dasher main.cpp)

# raylib 링크
target_link_libraries(Dapper_dasher raylib)


find_package(SFML 2.6.2 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Dapper_dasher sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

# Mac specific settings
if (APPLE)
    target_link_libraries(Dapper_dasher "-framework IOKit")
    target_link_libraries(Dapper_dasher "-framework Cocoa")
    target_link_libraries(Dapper_dasher "-framework OpenGL")
endif()