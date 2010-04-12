project(tgalaxy)

find_package(SDL)
find_package(OpenGL)

include_directories(${tgalaxy_SOURCE_DIR}/include)

add_executable(tgalaxy alien.cpp alienstates.cpp defender.cpp dispatcher.cpp
    entitymanager.cpp game_constants.cpp game.cpp gameobj.cpp main.cpp
    printer.cpp projectile.cpp star.cpp world.cpp)

target_link_libraries(tgalaxy ${SDL_LIBRARY} ${OPENGL_gl_LIBRARY})

