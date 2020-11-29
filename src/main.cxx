#include <QApplication>
#include <QSurfaceFormat>

#include <QVTKOpenGLStereoWidget.h>

#include "MainWindow.hxx"

int main(int argc, char ** argv) {

    // Taken from VTK example "vtk/Examples/Gui/Qt/SimpleView"
    // needed to ensure appropriate OpenGL context is created for VTK rendering.
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLStereoWidget::defaultFormat());

    QApplication application(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return application.exec();
}
