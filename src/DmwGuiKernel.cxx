#include <map>
#include <memory>
#include <string>

#include <QAction>
#include <QMenuBar>
#include <QPointer>

#include "DmwActionCallback.hxx"
#include "DmwMainWindow.hxx"

#include "DmwGuiKernel.hxx"

using std::make_shared;
using std::make_unique;
using std::map;
using std::move;
using std::pair;
using std::shared_ptr;
using std::string;
using std::unique_ptr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



namespace {

    class DmwActionAndCallback {
    public:
        const string name;
        shared_ptr<const DmwActionCallback> callback;
        QPointer<QAction> action;

        DmwActionAndCallback(
                char const * const name,
                shared_ptr<const DmwActionCallback> callback,
                QPointer<QAction> action
        ) : name(name),
            callback(callback),
            action(action)
        {
            // Nothing to do here.
        }

        DmwActionAndCallback(DmwActionAndCallback const & other)
        : name(other.name),
          callback(other.callback),
          action(other.action)
        {
            // Nothing to do here
        }
    };

} // namespace <unnamed>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



class DmwGuiKernel_Impl {

public:
    explicit DmwGuiKernel_Impl();
    ~DmwGuiKernel_Impl() noexcept;

    void setViewerRenderWindow(vtkGenericOpenGLRenderWindow * renderWindow);
    void showMainWindow();

    // TODO: It is temporary solution. More sophisticated registration mechanism is needed.
    void registerAction(shared_ptr<const DmwActionCallback> callback, char const * const actionName);

private:
    shared_ptr<DmwMainWindow> mainWindow;
    map<string, DmwActionAndCallback> registeredActions;
};



// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

DmwGuiKernel_Impl::DmwGuiKernel_Impl()
: mainWindow(make_shared<DmwMainWindow>()),
  registeredActions()
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

void DmwGuiKernel_Impl::registerAction(shared_ptr<const DmwActionCallback> callback, const char *const actionName) {
    if (registeredActions.find(actionName) != registeredActions.end()) {
        // Action with this name is already registered.
        // TODO: We need to return something in this case.
        return;
    }

    // Don't we have here a problem, that the action may be deleted by both: parent (mainWindow) and by owning shared_ptr?
    QPointer<QAction> action = new QAction(actionName, mainWindow.get());
    mainWindow->addMeshAction(*action);
    QObject::connect(action, &QAction::triggered, callback.get(), &DmwActionCallback::call);
    registeredActions.insert(pair<string, DmwActionAndCallback>(actionName, DmwActionAndCallback(actionName, callback, action)));
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

void DmwGuiKernel::registerAction(shared_ptr<const DmwActionCallback> callback, const char *const actionName) {
    impl->registerAction(callback, actionName);
}
