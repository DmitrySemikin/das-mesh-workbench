#include <memory>

#include <vtkNew.h>
#include <vtkNamedColors.h>
#include <vtkPoints.h>
#include <vtkUnstructuredGrid.h>
#include <vtkCellType.h>

#include "DmwModel.hxx"

#include "DmwMeshActionGenerateSampleUnstructuredGrid.hxx"

using std::shared_ptr;

DmwMeshActionGenerateSampleUnstructuredGrid::DmwMeshActionGenerateSampleUnstructuredGrid(shared_ptr<DmwModel> model)
: model(model)
{
    // Nothing to do here
}

DmwMeshActionGenerateSampleUnstructuredGrid::~DmwMeshActionGenerateSampleUnstructuredGrid() noexcept {
    // Nothing to do here
}

void DmwMeshActionGenerateSampleUnstructuredGrid::call() {

    vtkNew<vtkNamedColors> colors;

    static double pointsCoordinates[27][3] = {
            {0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {0, 1, 0}, {1, 1, 0}, {2, 1, 0},
            {0, 0, 1}, {1, 0, 1}, {2, 0, 1}, {0, 1, 1}, {1, 1, 1}, {2, 1, 1},
            {0, 1, 2}, {1, 1, 2}, {2, 1, 2}, {0, 1, 3}, {1, 1, 3}, {2, 1, 3},
            {0, 1, 4}, {1, 1, 4}, {2, 1, 4}, {0, 1, 5}, {1, 1, 5}, {2, 1, 5},
            {0, 1, 6}, {1, 1, 6}, {2, 1, 6}
    };

    static vtkIdType elements[12][8] = {
            {0, 1, 4, 3, 6, 7, 10, 9},      {1, 2, 5, 4, 7, 8, 11, 10},
            {6, 10, 9, 12, 0, 0, 0, 0},     {8, 11, 10, 14, 0, 0, 0, 0},
            {16, 17, 14, 13, 12, 15, 0, 0}, {18, 15, 19, 16, 20, 17, 0, 0},
            {22, 23, 20, 19, 0, 0, 0, 0},   {21, 22, 18, 0, 0, 0, 0, 0},
            {22, 19, 18, 0, 0, 0, 0, 0},    {23, 26, 0, 0, 0, 0, 0, 0},
            {21, 24, 0, 0, 0, 0, 0, 0},     {25, 0, 0, 0, 0, 0, 0, 0}
    };

    vtkNew<vtkPoints> points;
    for (vtkIdType kk = 0; kk < 27; kk++) {
        points->InsertPoint(kk, pointsCoordinates[kk]);
    }

    vtkNew<vtkUnstructuredGrid> unstructuredGrid;

    unstructuredGrid->SetPoints(points);

    unstructuredGrid->Allocate(100);
    unstructuredGrid->InsertNextCell(VTK_HEXAHEDRON, 8, elements[0]);
    unstructuredGrid->InsertNextCell(VTK_HEXAHEDRON, 8, elements[1]);
    unstructuredGrid->InsertNextCell(VTK_TETRA, 4, elements[2]);
    unstructuredGrid->InsertNextCell(VTK_TETRA, 4, elements[3]);
    unstructuredGrid->InsertNextCell(VTK_POLYGON, 6, elements[4]);
    unstructuredGrid->InsertNextCell(VTK_TRIANGLE_STRIP, 6, elements[5]);
    unstructuredGrid->InsertNextCell(VTK_QUAD, 4, elements[6]);
    unstructuredGrid->InsertNextCell(VTK_TRIANGLE, 3, elements[7]);
    unstructuredGrid->InsertNextCell(VTK_TRIANGLE, 3, elements[8]);
    unstructuredGrid->InsertNextCell(VTK_LINE, 2, elements[9]);
    unstructuredGrid->InsertNextCell(VTK_LINE, 2, elements[10]);
    unstructuredGrid->InsertNextCell(VTK_VERTEX, 1, elements[11]);

    model->setDataSet(unstructuredGrid);
}
