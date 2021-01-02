#include <vtkElevationFilter.h>
#include <vtkNew.h>
#include <vtkSmartPointer.h>
#include <vtkVectorText.h>

#include "DmwText3dGenerator.hxx"

DmwText3dGenerator::DmwText3dGenerator() {
    // Nothing to do yet
}

DmwText3dGenerator::~DmwText3dGenerator() noexcept {
    // Nothing to do yet
}

vtkSmartPointer<vtkPolyData> DmwText3dGenerator::generate3dText(const char *const text) {

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
