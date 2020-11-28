#ifndef MainWindow_hxx
#define MainWindow_hxx

#include <QMainWindow>

class Ui_MainWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:
    Ui_MainWindow * ui;
};

#endif // MainWindow_hxx
