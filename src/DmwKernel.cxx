#include <memory>

#include <vtkPolyData.h>

#include "DmwGuiKernel.hxx"
#include "DmwMeshActionGenerateSampleUnstructuredGrid.hxx"
#include "DmwMeshActionImportSalomeDatFile.hxx"
#include "DmwMeshActionText3dGenerator.hxx"
#include "DmwModel.hxx"
#include "DmwViewer.hxx"

#include "DmwKernel.hxx"

using std::make_shared;
using std::make_unique;
using std::shared_ptr;

DmwKernel::DmwKernel()
: viewer(make_shared<DmwViewer>()),
  guiKernel(make_unique<DmwGuiKernel>()),
  model(make_shared<DmwModel>())
{
    model->setViewer(viewer);

    guiKernel->setViewerRenderWindow(viewer->getRenderWindow());

    shared_ptr<DmwMeshActionText3dGenerator> text3DGenerator = make_shared<DmwMeshActionText3dGenerator>(model);
    guiKernel->registerAction(text3DGenerator, "Make 3D Text");

    shared_ptr<DmwMeshActionGenerateSampleUnstructuredGrid> generateSampleUnstructuredGrid = make_shared<DmwMeshActionGenerateSampleUnstructuredGrid>(model);
    guiKernel->registerAction(generateSampleUnstructuredGrid, "Generate Sample Unstructured Grid");

    shared_ptr<DmwMeshActionImportSalomeDatFile> importSalomeDatFile = make_shared<DmwMeshActionImportSalomeDatFile>(model);
    guiKernel->registerAction(importSalomeDatFile, "Import Salome DAT file");
}

DmwKernel::~DmwKernel() noexcept {
    // Nothing to do yet
}

void DmwKernel::showMainWindow() {
    // TODO: Theoretically we can show main window in the constructor. There is no really much use in separate method for it.
    guiKernel->showMainWindow();
}
