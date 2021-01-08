#include <memory>

#include <vtkPolyData.h>
#include <vtkSmartPointer.h>

#include "DmwGuiKernel.hxx"
#include "DmwModel.hxx"
#include "DmwText3dGenerator.hxx"
#include "DmwViewer.hxx"

#include "DmwKernel.hxx"

using std::make_shared;
using std::make_unique;

DmwKernel::DmwKernel()
: viewer(make_shared<DmwViewer>()),
  guiKernel(make_unique<DmwGuiKernel>()),
  model(make_shared<DmwModel>()),
  text3DGenerator(make_unique<DmwText3dGenerator>(model))
{
    model->setViewer(viewer);

    guiKernel->setViewerRenderWindow(viewer->getRenderWindow());

    guiKernel->registerAction(text3DGenerator->getActionCallback(), "Make 3D Text");
}

DmwKernel::~DmwKernel() noexcept {
    // Nothing to do yet
}

void DmwKernel::showMainWindow() {
    // TODO: Theoretically we can show main window in the constructor. There is no really much use in separate method for it.
    guiKernel->showMainWindow();
}
