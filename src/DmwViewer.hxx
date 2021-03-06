#ifndef DmwViewer_hxx
#define DmwViewer_hxx

#include <vtkSmartPointer.h>

class vtkDataSet;
class vtkDataSetMapper;
class vtkActor;
class vtkRenderer;
class vtkGenericOpenGLRenderWindow;

class DmwModel;

class DmwViewer {

public:
    explicit DmwViewer();
    ~DmwViewer() noexcept;

    void setDataSet(vtkSmartPointer<vtkDataSet> newDataSet);
    vtkGenericOpenGLRenderWindow * getRenderWindow();
    void onDataSetUpdated(DmwModel const & model);

private:
    void resetCamera();

private:
    vtkSmartPointer<vtkDataSet> dataSet;
    vtkSmartPointer<vtkDataSetMapper> mapper;
    vtkSmartPointer<vtkActor> actor;
    vtkSmartPointer<vtkRenderer> renderer;
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow;
};

#endif // DmwViewer_hxx
