#ifndef DmwMainWindow_hxx
#define DmwMainWindow_hxx

#include <memory>

#include <QMainWindow>

class vtkGenericOpenGLRenderWindow;
class Ui_DmwMainWindow;

class DmwMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DmwMainWindow();

    void setViewerRenderWindow(vtkGenericOpenGLRenderWindow * renderWindow);

private slots:
    virtual void slotExit();

private:
    std::unique_ptr<Ui_DmwMainWindow> ui;
};

#endif // DmwMainWindow_hxx
