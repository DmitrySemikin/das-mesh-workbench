#ifndef MainWindow_hxx
#define MainWindow_hxx

#include <QMainWindow>

class Ui_MainWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    virtual ~MainWindow() override;

private slots:
    virtual void slotExit();

private:
    void create3dText();

private:
    Ui_MainWindow * ui;
};

#endif // MainWindow_hxx
