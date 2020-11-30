#ifndef DmwMainWindow_hxx
#define DmwMainWindow_hxx

#include <QMainWindow>

class Ui_DmwMainWindow;

class DmwMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    DmwMainWindow();
    virtual ~DmwMainWindow() override;

private slots:
    virtual void slotExit();

private:
    void create3dText();

private:
    Ui_DmwMainWindow * ui;
};

#endif // DmwMainWindow_hxx
