#ifndef DmwGuiKernel_hxx
#define DmwGuiKernel_hxx

#include <memory>

class vtkGenericOpenGLRenderWindow;
class DmwActionCallback;
class DmwMainWindow;

class DmwGuiKernel {

public:
    explicit DmwGuiKernel();
    ~DmwGuiKernel() noexcept;

    void setViewerRenderWindow(vtkGenericOpenGLRenderWindow * renderWindow);
    void showMainWindow();

    // TODO: It is temporary solution. More sophisticated registration mechanism is needed.
    void registerAction(DmwActionCallback const & callback, char const * const actionName);

private:
    std::shared_ptr<DmwMainWindow> mainWindow;
};

#endif //DmwGuiKernel_hxx
