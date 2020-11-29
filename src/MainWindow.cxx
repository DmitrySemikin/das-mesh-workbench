#include "ui_MainWindow.h"

#include "MainWindow.hxx"

MainWindow::MainWindow() {
    ui = new Ui_MainWindow();
    ui->setupUi(this);

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
