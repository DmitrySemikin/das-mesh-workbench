#include "ui_MainWindow.h"

#include "MainWindow.hxx"

MainWindow::MainWindow() {
    ui = new Ui_MainWindow();
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    if (ui != nullptr) {
        delete ui;
        ui = nullptr;
    }
}
