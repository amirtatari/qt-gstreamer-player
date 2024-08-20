cmake_minimum_required(VERSION 3.10)

project(Qt-Gstreamer-Player VERSION 0.0.0.1)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)



include_directories(
    ${GSTREAMER_INCLUDE_DIRS}
    ${Qt6Widgets_INCLUDE_DIRS}
    stream
    gst
    )

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.hpp
        mainwindow.ui
        stream/stream.cpp
        gst/pipeline.cpp
)

add_executable(Qt-Gstreamer-Player ${PROJECT_SOURCES})


target_link_libraries(Qt-Gstreamer-Player 
                    ${GSTREAMER_LIBRARIES}
                    Qt6::Widgets
                    )

add_definitions(${GSTREAMER_CFLAGS_OTHER})