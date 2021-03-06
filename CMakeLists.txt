cmake_minimum_required(VERSION 3.16)
project(das-mesh-workbench)

find_package(
    VTK
    COMPONENTS
        CommonCore
        CommonColor
        GUISupportQt
        ViewsQt
        RenderingFreeType
)

if (NOT VTK_FOUND)
    message(FATAL_ERROR "Cannot find VTK")
endif (NOT VTK_FOUND)

find_package(
    Qt5
    COMPONENTS
        Widgets
        Gui
)

if (NOT TARGET Qt5::Widgets OR NOT TARGET Qt5::Gui)
    message(FATAL_ERROR "Cannot find Qt5")
endif (NOT TARGET Qt5::Widgets OR NOT TARGET Qt5::Gui)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#################

set (
    SOURCES
        src/main.cxx
        src/DmwApplication.cxx
        src/DmwGuiKernel.cxx
        src/DmwKernel.cxx
        src/DmwMainWindow.cxx
        src/DmwMeshActionGenerateSampleUnstructuredGrid.cxx
        src/DmwMeshActionImportSalomeDatFile.cxx
        src/DmwMeshActionText3dGenerator.cxx
        src/DmwMeshActionText3dGeneratorGui.cxx
        src/DmwMeshChunk.cxx
        src/DmwMeshChunkVisual.cxx
        src/DmwModel.cxx
        src/DmwViewer.cxx
)

set (
    HEADERS
        src/DmwApplication.hxx
        src/DmwGuiKernel.hxx
        src/DmwKernel.hxx
        src/DmwMainWindow.hxx
        src/DmwMeshAction.hxx
        src/DmwMeshActionGenerateSampleUnstructuredGrid.hxx
        src/DmwMeshActionImportSalomeDatFile.hxx
        src/DmwMeshActionText3dGenerator.hxx
        src/DmwMeshActionText3dGeneratorGui.hxx
        src/DmwMeshChunk.hxx
        src/DmwMeshChunkVisual.hxx
        src/DmwModel.hxx
        src/DmwViewer.hxx
)

set (
    UIS
        src/DmwMainWindow.ui
        src/DmwMeshActionText3dGeneratorGui.ui
)

set (
    QRCS
        res/application.qrc
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
