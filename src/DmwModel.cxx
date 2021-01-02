#include <vtkElevationFilter.h>
#include <vtkNew.h>
#include <vtkVectorText.h>

#include "DmwModel.hxx"

DmwModel::DmwModel() {
    // TODO: how do we keep reference to all the pipeline components?
    // In fact for the meshes themselves we don't really need to keep
    // objects, which produce UnstructuredMesh. We need to only keep
    // the mesh itself (we may though store the parameters, like
    // file name of the file, from which it was loaded or parameters
    // of the gemetric primitive - like cone - from which it was
    // created, - to enable recreation with another parameters).

    // TODO: Probably to make other discussed points more clear I should switch from using 3dText to using UnstructuredMesh (just create couple of triangles or tetrahedrons).

    // TODO: creation should happen in some other component

    // TODO: we need API to add and remove (delete) visualisable objects
    // (or actually meshes).

    vtkNew<vtkVectorText> vectorText;
    vectorText->SetText("DAS-Mesh-Workbench");

    vtkNew<vtkElevationFilter> elevationFilter;
    elevationFilter->SetInputConnection(vectorText->GetOutputPort());
    elevationFilter->SetLowPoint(0, 0, 0);
    elevationFilter->SetHighPoint(10, 0, 0);

    // TODO: Where should mapper and actor go? Probably I will understand it, when I start implementing visualization options.

    // TODO: For now add here PolyDataMapper and Actor from DmwMainWindows.cxx

    // Add GUI for creating and deleting objects.
}

DmwModel::~DmwModel() noexcept {
    // Nothing to do
}
