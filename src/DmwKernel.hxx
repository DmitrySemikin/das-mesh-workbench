#ifndef DmwKernel_hxx
#define DmwKernel_hxx

#include <memory>

class DmwGuiKernel;
class DmwModel;
class DmwViewer;

class DmwKernel {

public:
    explicit DmwKernel();
    ~DmwKernel() noexcept;

    void showMainWindow();

private:
    std::shared_ptr<DmwViewer> viewer;
    std::unique_ptr<DmwGuiKernel> guiKernel;
    std::unique_ptr<DmwModel> model;
};


#endif //DmwKernel_hxx
