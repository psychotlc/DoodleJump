cmake_minimum_required(VERSION 3.2)
project (DoodleJump)

add_executable(DoodleJump
    src/main.cpp
    src/hero.cpp
    src/platforms.cpp
)

target_link_libraries(DoodleJump sfml-graphics sfml-window sfml-system)