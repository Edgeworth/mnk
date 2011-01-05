cmake_minimum_required(VERSION 2.8)

set(PREFIX ../)

file(GLOB_RECURSE SOURCE ${PREFIX}/src/*.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PREFIX})

set(CMAKE_MODULE_PATH ./)
find_package(SFML REQUIRED)

include_directories(${PREFIX}/include ${SFML_INCLUDE_DIR})

add_executable(main ${SOURCE})
target_link_libraries(main ${SFML_LIBRARY})