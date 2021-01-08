#ifndef DmwKernel_hxx
#define DmwKernel_hxx

#include <memory>

class DmwGuiKernel;
class DmwModel;
class DmwText3dGenerator;
class DmwViewer;

class DmwKernel {

public:
    explicit DmwKernel();
    ~DmwKernel() noexcept;

    void showMainWindow();

private:
    std::shared_ptr<DmwViewer> viewer;
    std::unique_ptr<DmwGuiKernel> guiKernel;
    std::shared_ptr<DmwModel> model;
    std::unique_ptr<DmwText3dGenerator> text3DGenerator;
};


#endif //DmwKernel_hxx
