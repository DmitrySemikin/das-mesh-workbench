#ifndef DmwText3dGenerator_hxx
#define DmwText3dGenerator_hxx

#include <memory>

#include <QObject>

#include <vtkSmartPointer.h>

class vtkPolyData;

class DmwActionCallback;
class DmwModel;
class DmwText3dGeneratorActionCallback;
class DmwText3dGeneratorGui;

class DmwText3dGenerator_Impl;

class DmwText3dGenerator :
        public QObject
{

    Q_OBJECT

public:
    explicit DmwText3dGenerator(std::shared_ptr<DmwModel> model);
    ~DmwText3dGenerator() noexcept;

    // TODO: Make it completely private and move to cxx file.
    vtkSmartPointer<vtkPolyData> generate3dText(char const * const text) const;

    void generate3dTextWithGuiAndUpdateModel();

    std::shared_ptr<const DmwActionCallback> getActionCallback() const;

private slots:
    void onDialogFinished(int result);

private:
    std::shared_ptr<DmwModel> model;
    std::unique_ptr<DmwText3dGeneratorGui> dialog;
    std::shared_ptr<DmwText3dGeneratorActionCallback> callback; // we cannot put it into `impl` because we need to pass `this` to its constructor.

};

#endif //DmwText3dGenerator_hxx
