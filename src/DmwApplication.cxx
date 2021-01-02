#include <memory>

#include <QApplication>
#include <QSurfaceFormat>

#include <QVTKOpenGLStereoWidget.h>

#include "DmwKernel.hxx"

#include "DmwApplication.hxx"

using std::make_unique;

DmwApplication::DmwApplication(int argc, char ** argv)
: qApplication(nullptr)
{
    // Taken from VTK example "vtk/Examples/Gui/Qt/SimpleView"
    // needed to ensure appropriate OpenGL context is created for VTK rendering.
    // ! This call must be done before construction of QApplication (see docs of QSurfaceFormat::setDefaultFormat())
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLStereoWidget::defaultFormat());

    qApplication = make_unique<QApplication>(argc, argv);
}

DmwApplication::~DmwApplication() noexcept {
    // Nothing to do yet
}

int DmwApplication::exec() {

    DmwKernel kernel;
    kernel.showMainWindow();

    return qApplication->exec();
}
