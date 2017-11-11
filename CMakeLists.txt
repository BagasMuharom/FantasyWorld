cmake_minimum_required(VERSION 3.8)
project(FantasyWorld)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

file(
    GLOB OBJEK 
    Objek/*.cpp 
    Objek/*.h 
    Camera/*.cpp 
    Camera/*.h 
    Warna/*.cpp 
    Warna/*.h 
    Input/*.cpp
    Input/*.h 
    Util/*.cpp
    Util/*.h
)

set(CMAKE_CXX_STANDARD 11)

set(
    SOURCE_FILES
    index.cpp
    )
    
add_executable(FantasyWorld ${SOURCE_FILES} ${OBJEK})

target_link_libraries(
    FantasyWorld
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARY}
)