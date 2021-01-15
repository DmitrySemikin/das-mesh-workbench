#include <memory>

#include <vtkPolyData.h>

#include "DmwGuiKernel.hxx"
#include "DmwMeshActionGenerateSampleUnstructuredGrid.hxx"
#include "DmwModel.hxx"
#include "DmwText3dGenerator.hxx"
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

    shared_ptr<DmwText3dGenerator> text3DGenerator = make_shared<DmwText3dGenerator>(model);
    guiKernel->registerAction(text3DGenerator, "Make 3D Text");

    shared_ptr<DmwMeshActionGenerateSampleUnstructuredGrid> generateSampleUnstructuredGrid = make_shared<DmwMeshActionGenerateSampleUnstructuredGrid>(model);
    guiKernel->registerAction(generateSampleUnstructuredGrid, "Generate Sample Unstructured Grid");
}

DmwKernel::~DmwKernel() noexcept {
    // Nothing to do yet
}

void DmwKernel::showMainWindow() {
    // TODO: Theoretically we can show main window in the constructor. There is no really much use in separate method for it.
    guiKernel->showMainWindow();
}
