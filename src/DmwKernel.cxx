#include <memory>

#include <vtkPolyData.h>
#include <vtkSmartPointer.h>

#include "DmwGuiKernel.hxx"
#include "DmwText3dGenerator.hxx"
#include "DmwViewer.hxx"

#include "DmwKernel.hxx"

using std::make_unique;

DmwKernel::DmwKernel()
: viewer(make_unique<DmwViewer>()),
  guiKernel(make_unique<DmwGuiKernel>())
{
    DmwText3dGenerator text3DGenerator;
    vtkSmartPointer<vtkPolyData> textPolyData = text3DGenerator.generate3dText("Hi there!");

    // TODO: there should be DmwModel in the middle.

    viewer->setDataSet(textPolyData);
    guiKernel->setViewerRenderWindow(viewer->getRenderWindow());
}

DmwKernel::~DmwKernel() noexcept {
    // Nothing to do yet
}

void DmwKernel::showMainWindow() {
    guiKernel->showMainWindow();
}
