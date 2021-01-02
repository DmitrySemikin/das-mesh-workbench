#include <memory>

// TODO: Remove unused includes
#include <vtkActor.h>
#include <vtkElevationFilter.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkVectorText.h>

#include "ui_DmwMainWindow.h"

#include "DmwMainWindow.hxx"

using std::make_unique;

DmwMainWindow::DmwMainWindow()
: ui(nullptr)
{
    ui = make_unique<Ui_DmwMainWindow>();
    ui->setupUi(this);

    // TODO: Remove this
//    create3dText();

    connect(this->ui->actionQuit, SIGNAL(triggered()), this, SLOT(slotExit()));
}

DmwMainWindow::~DmwMainWindow() noexcept {
    // Nothing to do here
}

void DmwMainWindow::slotExit() {
    qApp->exit();
}

// TODO: Remove this
void DmwMainWindow::create3dText() {
    // This code mostly follows SimpleView example from "vtk/Examples/Gui/Qt/SimpleExample"
    vtkNew<vtkVectorText> vectorText;
    vectorText->SetText("DAS-Mesh-Workbench");
    vtkNew<vtkElevationFilter> elevationFilter;
    elevationFilter->SetInputConnection(vectorText->GetOutputPort());
    elevationFilter->SetLowPoint(0, 0, 0);
    elevationFilter->SetHighPoint(10, 0, 0);

    vtkNew<vtkPolyDataMapper> polyDataMapper;
    polyDataMapper->SetInputConnection(elevationFilter->GetOutputPort());

    vtkNew<vtkActor> actor;
    actor->SetMapper(polyDataMapper);

    vtkNew<vtkRenderer> renderer;
    renderer->AddActor(actor);

    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
    renderWindow->AddRenderer(renderer);

    this->ui->viewer->setRenderWindow(renderWindow);
}

void DmwMainWindow::setViewerRenderWindow(vtkGenericOpenGLRenderWindow *renderWindow) {
    this->ui->viewer->setRenderWindow(renderWindow);
}
