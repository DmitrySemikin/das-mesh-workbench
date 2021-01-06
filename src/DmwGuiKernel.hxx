#ifndef DmwGuiKernel_hxx
#define DmwGuiKernel_hxx

#include <memory>

class vtkGenericOpenGLRenderWindow;
class DmwActionCallback;
class DmwMainWindow;

class DmwGuiKernel_Impl;

class DmwGuiKernel {

public:
    explicit DmwGuiKernel();
    ~DmwGuiKernel() noexcept;

    void setViewerRenderWindow(vtkGenericOpenGLRenderWindow * renderWindow);
    void showMainWindow();

    // TODO: It is temporary solution. More sophisticated registration mechanism is needed.
    void registerAction(std::shared_ptr<const DmwActionCallback> callback, char const * const actionName);

private:
    std::unique_ptr<DmwGuiKernel_Impl> impl;
};

#endif //DmwGuiKernel_hxx
