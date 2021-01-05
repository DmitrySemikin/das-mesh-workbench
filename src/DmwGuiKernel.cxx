#include <memory>

#include "DmwMainWindow.hxx"

#include "DmwGuiKernel.hxx"

using std::make_shared;
using std::make_unique;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



class DmwGuiKernel_Impl {

public:
    explicit DmwGuiKernel_Impl();
    ~DmwGuiKernel_Impl() noexcept;

    void setViewerRenderWindow(vtkGenericOpenGLRenderWindow * renderWindow);
    void showMainWindow();

    // TODO: It is temporary solution. More sophisticated registration mechanism is needed.
    void registerAction(DmwActionCallback const & callback, char const * const actionName);

private:
    std::shared_ptr<DmwMainWindow> mainWindow;
};



// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

DmwGuiKernel_Impl::DmwGuiKernel_Impl()
        : mainWindow(make_shared<DmwMainWindow>())
{
    // Nothing to do yet
}

DmwGuiKernel_Impl::~DmwGuiKernel_Impl() noexcept {
    // Nothing to do yet
}

void DmwGuiKernel_Impl::setViewerRenderWindow(vtkGenericOpenGLRenderWindow * renderWindow) {
    mainWindow->setViewerRenderWindow(renderWindow);
}

void DmwGuiKernel_Impl::showMainWindow() {
    mainWindow->show();
}

void DmwGuiKernel_Impl::registerAction(const DmwActionCallback &callback, const char *const actionName) {
    // TODO: Not implemented yet.
}



// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

DmwGuiKernel::DmwGuiKernel()
: impl(make_unique<DmwGuiKernel_Impl>())
{
    // Nothing to do yet
}

DmwGuiKernel::~DmwGuiKernel() noexcept {
    // Nothing to do yet
}

void DmwGuiKernel::setViewerRenderWindow(vtkGenericOpenGLRenderWindow * renderWindow) {
    impl->setViewerRenderWindow(renderWindow);
}

void DmwGuiKernel::showMainWindow() {
    impl->showMainWindow();
}

void DmwGuiKernel::registerAction(const DmwActionCallback &callback, const char *const actionName) {
    impl->registerAction(callback, actionName);
}
