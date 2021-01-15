#ifndef DmwMeshActionText3dGenerator_hxx
#define DmwMeshActionText3dGenerator_hxx

#include <memory>

#include <vtkSmartPointer.h>

#include "DmwMeshAction.hxx"

class vtkPolyData;

class DmwMeshAction;
class DmwModel;
class DmwMeshActionText3dGeneratorGui;

class DmwMeshActionText3dGenerator :
        public DmwMeshAction
{

    Q_OBJECT

public:
    explicit DmwMeshActionText3dGenerator(std::shared_ptr<DmwModel> model);
    ~DmwMeshActionText3dGenerator() noexcept override;

public slots:
    virtual void call() override;

private slots:
    void onDialogFinished(int result);

private:
    // TODO: Make it completely private and move to cxx file.
    vtkSmartPointer<vtkPolyData> generate3dText(char const * const text) const;
    void generate3dTextWithGuiAndUpdateModel();

private:
    std::shared_ptr<DmwModel> model;
    std::unique_ptr<DmwMeshActionText3dGeneratorGui> dialog;

};

#endif //DmwMeshActionText3dGenerator_hxx
