cmake_minimum_required(VERSION 3.18)
project(das-mesh-workbench)

find_package(
    VTK
    COMPONENTS
        CommonCore
        GUISupportQt
        ViewsQt
)

if (NOT VTK_FOUND)
    error()
endif (NOT VTK_FOUND)

find_package(
    Qt5
    COMPONENTS
        Widgets
        Gui
)

if (NOT TARGET Qt5::Widgets OR NOT TARGET Qt5::Gui)
    error()
endif (NOT TARGET Qt5::Widgets OR NOT TARGET Qt5::Gui)

#################

set (
    SOURCES
    src/main.cxx
)

set (
    HEADERS
)

set (
    UIS
)

set (
    QRCS
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

source_group(
    "Resources"
    FILES
    ${UIS}
    ${QRCS}
)

add_executable(
    das-mesh-workbench
    ${SOURCES}
    ${HEADERS}
    ${UIS}
    ${QRCS}
)

target_link_libraries(
    das-mesh-workbench
    PRIVATE
    ${VTK_LIBRARIES}
    Qt5::Gui
    Qt5::Widgets
)
