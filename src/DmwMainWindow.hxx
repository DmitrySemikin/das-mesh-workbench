#ifndef DmwMainWindow_hxx
#define DmwMainWindow_hxx

#include <memory>

#include <QAction>
#include <QMainWindow>

class vtkGenericOpenGLRenderWindow;
class Ui_DmwMainWindow;

class DmwMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DmwMainWindow();
    ~DmwMainWindow() noexcept override;

    void setViewerRenderWindow(vtkGenericOpenGLRenderWindow * renderWindow);
    void addMeshAction(QAction & action);

private slots:
    virtual void slotExit();

private:
    std::unique_ptr<Ui_DmwMainWindow> ui;
};

#endif // DmwMainWindow_hxx
