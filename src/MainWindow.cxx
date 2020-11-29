#include <vtkActor.h>
#include <vtkElevationFilter.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkVectorText.h>

#include "ui_MainWindow.h"

#include "MainWindow.hxx"

MainWindow::MainWindow() {
    ui = new Ui_MainWindow();
    ui->setupUi(this);

    create3dText();

    connect(this->ui->actionQuit, SIGNAL(triggered()), this, SLOT(slotExit()));
}

MainWindow::~MainWindow() {
    if (ui != nullptr) {
        delete ui;
        ui = nullptr;
    }
}

void MainWindow::slotExit() {
    qApp->exit();
}

void MainWindow::create3dText() {
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
