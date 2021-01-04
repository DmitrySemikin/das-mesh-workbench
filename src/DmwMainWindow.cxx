#include <memory>

#include "ui_DmwMainWindow.h"

#include "DmwMainWindow.hxx"

using std::make_unique;

DmwMainWindow::DmwMainWindow()
: ui(nullptr)
{
    ui = make_unique<Ui_DmwMainWindow>();
    ui->setupUi(this);

    connect(this->ui->actionQuit, SIGNAL(triggered()), this, SLOT(slotExit()));
}

DmwMainWindow::~DmwMainWindow() noexcept {
    // Nothing to do here.
}

void DmwMainWindow::slotExit() {
    qApp->exit();
}

void DmwMainWindow::setViewerRenderWindow(vtkGenericOpenGLRenderWindow * renderWindow) {
    this->ui->viewer->setRenderWindow(renderWindow);
}
