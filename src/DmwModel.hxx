#ifndef DmwModel_hxx
#define DmwModel_hxx

#include <memory>

#include <vtkSmartPointer.h>

class vtkDataSet;
class DmwViewer;

class DmwModel {

public:
    explicit DmwModel();
    ~DmwModel() noexcept;

    void setDataSet(vtkSmartPointer<vtkDataSet> newDataSet);
    void setViewer(std::weak_ptr<DmwViewer> newViewer);

    /** Caller is expected not to modify content of returned dataset */
    vtkSmartPointer<vtkDataSet> getMaybeDataSet() const;

private:
    void notifyViewerOnDataSetUpdate();

private:
    std::weak_ptr<DmwViewer> maybeViewer; // TODO: we use it to trigger updates. Should we use generic observer?
    mutable vtkSmartPointer<vtkDataSet> maybeDataSet;
};

#endif //  DmwModel_hxx
