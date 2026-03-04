cmake_minimum_required(VERSION 3.28)
project(Game_Engine LANGUAGES CXX)

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

add_executable(${PROJECT_NAME} main.cpp Collision.cpp Game.cpp
    GameObject.cpp Map.cpp TextureManager.cpp Vector2D.cpp)

add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    ${CMAKE_BINARY_DIR}/assets
)

add_dependencies(${PROJECT_NAME} copy_assets)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)
