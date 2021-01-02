#include <memory>

#include "DmwMainWindow.hxx"

#include "DmwGuiKernel.hxx"

using std::make_shared;

DmwGuiKernel::DmwGuiKernel()
: mainWindow(make_shared<DmwMainWindow>())
{
    // Nothing to do yet
}

DmwGuiKernel::~DmwGuiKernel() noexcept {
    // Nothing to do yet
}

void DmwGuiKernel::setViewerRenderWindow(vtkGenericOpenGLRenderWindow * renderWindow) {
    mainWindow->setViewerRenderWindow(renderWindow);
}

void DmwGuiKernel::showMainWindow() {
    mainWindow->show();
}
