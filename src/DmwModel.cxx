#include <memory>

#include <vtkDataSet.h>
#include <vtkNew.h>
#include <vtkSmartPointer.h>
#include <vtkUnstructuredGrid.h>

#include "DmwViewer.hxx"

#include "DmwModel.hxx"

using std::shared_ptr;

DmwModel::DmwModel()
: maybeViewer(), // nullptr
  maybeDataSet(vtkNew<vtkUnstructuredGrid>())
{
    // Nothing to do here
}

DmwModel::~DmwModel() noexcept {
    // Nothing to do here
}

void DmwModel::setDataSet(vtkSmartPointer<vtkDataSet> newDataSet) {
    maybeDataSet = newDataSet;
    notifyViewerOnDataSetUpdate();
}

void DmwModel::setViewer(std::weak_ptr<DmwViewer> newViewer) {
    maybeViewer = newViewer;
    notifyViewerOnDataSetUpdate();
}

void DmwModel::notifyViewerOnDataSetUpdate() {
    shared_ptr<DmwViewer> viewer = maybeViewer.lock();
    if (viewer != nullptr) {
        // TODO: As the structure of the model gets more complicated we will need more sophisticated way of notifying, what exactly change to avoid need to update big parts of the picture.
        viewer->onDataSetUpdated(*this);
    }
}

vtkSmartPointer<vtkDataSet> DmwModel::getMaybeDataSet() const {
    return maybeDataSet;
}
