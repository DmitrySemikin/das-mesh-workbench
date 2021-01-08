#include <vtkActor.h>
#include <vtkDataSet.h>
#include <vtkDataSetMapper.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>

#include "DmwModel.hxx"

#include "DmwViewer.hxx"

DmwViewer::DmwViewer()
: dataSet(nullptr),
  mapper(vtkSmartPointer<vtkDataSetMapper>::New()),
  actor(vtkSmartPointer<vtkActor>::New()),
  renderer(vtkSmartPointer<vtkRenderer>::New()),
  renderWindow(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New())
{
    actor->SetMapper(mapper);
    renderer->AddActor(actor);
    renderWindow->AddRenderer(renderer);
}

DmwViewer::~DmwViewer() noexcept {
    // Nothing to do yet.
}

void DmwViewer::setDataSet(vtkSmartPointer<vtkDataSet> newDataSet) {
    dataSet = newDataSet;
    mapper->SetInputData(newDataSet);
}

vtkGenericOpenGLRenderWindow * DmwViewer::getRenderWindow() {
    return renderWindow;
}

void DmwViewer::onDataSetUpdated(DmwModel const & model) {
    vtkSmartPointer<vtkDataSet> maybeDataSet = model.getMaybeDataSet();
    if (maybeDataSet != nullptr) {
        setDataSet(maybeDataSet);
        renderer->ResetCamera();
        renderWindow->Render();
    }
}
