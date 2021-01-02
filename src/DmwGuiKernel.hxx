#ifndef DmwGuiKernel_hxx
#define DmwGuiKernel_hxx

#include <memory>

class vtkGenericOpenGLRenderWindow;
class DmwMainWindow;

class DmwGuiKernel {

public:
    explicit DmwGuiKernel();
    ~DmwGuiKernel() noexcept;

    void setViewerRenderWindow(vtkGenericOpenGLRenderWindow * renderWindow);
    void showMainWindow();

private:
    std::shared_ptr<DmwMainWindow> mainWindow;
};

#endif //DmwGuiKernel_hxx
