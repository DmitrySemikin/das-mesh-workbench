#ifndef DmwMeshActionGenerateSampleUnstructuredGrid_hxx
#define DmwMeshActionGenerateSampleUnstructuredGrid_hxx

#include <memory>

#include "DmwActionCallback.hxx"

class DmwModel;

class DmwMeshActionGenerateSampleUnstructuredGrid :
        public DmwActionCallback
{
    Q_OBJECT

public:
    explicit DmwMeshActionGenerateSampleUnstructuredGrid(std::shared_ptr<DmwModel> model);
    ~DmwMeshActionGenerateSampleUnstructuredGrid() noexcept override;

public slots:
    void call() override;

private:
    std::shared_ptr<DmwModel> model;
};

#endif //DmwMeshActionGenerateSampleUnstructuredGrid_hxx
