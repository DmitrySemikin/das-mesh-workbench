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
  model(make_unique<DmwModel>())
{
    DmwText3dGenerator text3DGenerator;
    vtkSmartPointer<vtkPolyData> textPolyData = text3DGenerator.generate3dText("Hi there!");

    model->setViewer(viewer);
    model->setDataSet(textPolyData);

    guiKernel->setViewerRenderWindow(viewer->getRenderWindow());
}

DmwKernel::~DmwKernel() noexcept {
    // Nothing to do yet
}

void DmwKernel::showMainWindow() {
    guiKernel->showMainWindow();
}
