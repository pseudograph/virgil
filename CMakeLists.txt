cmake_minimum_required(VERSION 3.26)
project(virgil)

set(CMAKE_CXX_STANDARD 23)
include_directories("${CMAKE_SOURCE_DIR}/src/")

# Dependencies
set(RAYLIB_VERSION 4.5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

add_executable(virgil src/main.cpp
        src/entities/text/TextBlock.cpp
        src/entities/text/TextBlock.h
        src/config/Consts.h
        src/interfaces/Drawable.h
        src/interfaces/Text.h
        src/interfaces/Repositionable.h
        src/interfaces/Resizable.h
        src/virgil/Virgil.cpp
        src/virgil/Virgil.h
        src/viewport/Viewport.cpp
        src/viewport/Viewport.h
        src/screen/Screen.cpp
        src/screen/Screen.h
        src/interfaces/CanResize.h
        src/interfaces/Entity.h
        src/entities/visitors/Visitor.h
        src/entities/visitors/drawVisitor/DrawVisitor.cpp
        src/entities/visitors/drawVisitor/DrawVisitor.h
        src/entities/visitors/scaleXYVisitor/ScaleXYVisitor.cpp
        src/entities/visitors/scaleXYVisitor/ScaleXYVisitor.h
)

target_link_libraries(virgil raylib)

