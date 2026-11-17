cmake_minimum_required(VERSION 4.2)
project(CppGame)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL3 CONFIG REQUIRED)
find_package(SDL3_image CONFIG REQUIRED)
find_package(tmx REQUIRED)
find_package(Boost REQUIRED)

add_subdirectory(src)

target_link_libraries(CppGame PRIVATE SDL3::SDL3 )
target_link_libraries(CppGame PRIVATE $<IF:$<TARGET_EXISTS:SDL3_image::SDL3_image-shared>,SDL3_image::SDL3_image-shared,SDL3_image::SDL3_image-static>)
target_link_libraries(CppGame PRIVATE tmx)
target_link_libraries(CppGame PRIVATE Boost::headers)
