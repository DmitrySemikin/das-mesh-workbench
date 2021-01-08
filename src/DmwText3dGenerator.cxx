#include <memory>
#include <string>

#include <QObject>

#include <vtkElevationFilter.h>
#include <vtkNew.h>
#include <vtkSmartPointer.h>
#include <vtkVectorText.h>

#include "DmwActionCallback.hxx"
#include "DmwModel.hxx"
#include "DmwText3dGeneratorActionCallback.hxx"
#include "DmwText3dGeneratorGui.hxx"

#include "DmwText3dGenerator.hxx"



using std::make_unique;
using std::make_shared;
using std::shared_ptr;
using std::string;
using std::unique_ptr;



DmwText3dGenerator::DmwText3dGenerator(shared_ptr<DmwModel> model)
: model(model),
  dialog(nullptr),
  callback(make_shared<DmwText3dGeneratorActionCallback>(*this))
{
    // Nothing to do here
}

DmwText3dGenerator::~DmwText3dGenerator() noexcept {
    // Nothing to do here
}

vtkSmartPointer<vtkPolyData> DmwText3dGenerator::generate3dText(const char *const text) const {
    vtkNew<vtkVectorText> vectorText;
    vectorText->SetText(text);
    // TODO: How to specify coordinates? Or probably we can offset it after creation.

    vtkNew<vtkElevationFilter> elevationFilter;
    elevationFilter->SetInputConnection(vectorText->GetOutputPort());
    elevationFilter->SetLowPoint(0, 0, 0);
    elevationFilter->SetHighPoint(10, 0, 0);

    elevationFilter->Update();

    vtkSmartPointer<vtkDataSet> dataSet = elevationFilter->GetOutput();
    // TODO: Find the way to manage stdout with qt (without explicit reference to qt here)
//    dataSet->PrintSelf();

    vtkSmartPointer<vtkPolyData> polyData = vtkPolyData::SafeDownCast(dataSet);
    if (polyData == nullptr) {
        // TODO: What to do?
    }
    return polyData;
}

std::shared_ptr<const DmwActionCallback> DmwText3dGenerator::getActionCallback() const {
    return callback;
}

void DmwText3dGenerator::generate3dTextWithGuiAndUpdateModel() {
    if (dialog == nullptr) {
        dialog = make_unique<DmwText3dGeneratorGui>();
        dialog->connect(dialog.get(), &QDialog::finished, this, &DmwText3dGenerator::onDialogFinished);
        dialog->open();
    }
}

void DmwText3dGenerator::onDialogFinished(int result) {
    if (result == (int)QDialog::DialogCode::Accepted && dialog != nullptr) {
        const string text = dialog->getText();
        vtkSmartPointer<vtkDataSet> textDataSet = generate3dText(text.c_str());
        model->setDataSet(textDataSet);
    }
    dialog.reset();
}
