#include <QApplication>
#include <QSurfaceFormat>

#include <QVTKOpenGLStereoWidget.h>

#include "DmwApplication.hxx"
#include "DmwMainWindow.hxx"

int main(int argc, char ** argv) {

    DmwApplication application(argc, argv);
    return application.exec();
}
