#ifndef DmwKernel_hxx
#define DmwKernel_hxx

#include <memory>

class DmwGuiKernel;
class DmwViewer;

class DmwKernel {

public:
    explicit DmwKernel();
    ~DmwKernel() noexcept;

    void showMainWindow();

private:
    std::unique_ptr<DmwViewer> viewer;
    std::unique_ptr<DmwGuiKernel> guiKernel;
};


#endif //DmwKernel_hxx
