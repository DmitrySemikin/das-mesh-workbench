#include <memory>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>

#include <vtkCellType.h>
#include <vtkIdList.h>
#include <vtkNew.h>
#include <vtkPoints.h>
#include <vtkType.h>
#include <vtkUnstructuredGrid.h>

#include "DmwModel.hxx"

#include "DmwMeshActionImportSalomeDatFile.hxx"

using std::shared_ptr;
using std::ifstream;

DmwMeshActionImportSalomeDatFile::DmwMeshActionImportSalomeDatFile(shared_ptr<DmwModel> model) {
    this->model = model;
}

DmwMeshActionImportSalomeDatFile::~DmwMeshActionImportSalomeDatFile() noexcept {
    // nothing to do here
}

void DmwMeshActionImportSalomeDatFile::call() {
    importSalomeDatFile();
}

void DmwMeshActionImportSalomeDatFile::importSalomeDatFile() {
    QString filePath = requestSalomeDatFilePath();
    importSalomeDatFile(filePath);
}

void DmwMeshActionImportSalomeDatFile::importSalomeDatFile(const QString &filePath) {
    // TODO: Reimplement reading algorithm in separate file (class or function) not using Qt. Problem: non-ASCII file paths.

    // TODO: Handling of the errors!!!

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // TODO: report the error somehow
        return;
    }

    QTextStream inputFileStream(&file);

    vtkIdType pointsCount = 0;
    vtkIdType totalElementsCount = 0;

    inputFileStream >> pointsCount >> totalElementsCount;

    vtkNew<vtkUnstructuredGrid> unstructuredGrid;
    const vtkIdType maxNodesPerElement = 4; // we don't have more than tetrahedrons
    unstructuredGrid->AllocateEstimate(totalElementsCount, maxNodesPerElement);

    vtkNew<vtkPoints> points;
    points->Allocate(pointsCount);


    double x = 0;
    double y = 0;
    double z = 0;

    vtkIdType unusedFilePointNum = 0;

    for (vtkIdType pointIdx = 0; pointIdx < pointsCount; ++pointIdx) {
        inputFileStream >> unusedFilePointNum >> x >> y >> z;
        points->InsertNextPoint(x, y, z);
    }

    unstructuredGrid->SetPoints(points);

    vtkIdType unusedFileElementNum = 0;
    int fileElementType = 0;
    const int fileElementTypeLineSegment = 102;
    const int fileElementTypeTriangle = 203;
    const int fileElementTypeTetrahedron = 304;

    vtkNew<vtkIdList> elementNodes;
    elementNodes->Allocate(4);
    vtkIdType fileNodeId0 = 0;
    vtkIdType fileNodeId1 = 0;
    vtkIdType fileNodeId2 = 0;
    vtkIdType fileNodeId3 = 0;


    for (vtkIdType elementIdx = 0; elementIdx < totalElementsCount; ++elementIdx) {
        inputFileStream >> unusedFileElementNum >> fileElementType;
        if (fileElementType == fileElementTypeLineSegment) {
            elementNodes->SetNumberOfIds(2);
            inputFileStream >> fileNodeId0 >> fileNodeId1;
            elementNodes->SetId(0, fileNodeId0 - 1);
            elementNodes->SetId(1, fileNodeId1 - 1);
            unstructuredGrid->InsertNextCell(VTK_LINE, elementNodes);
        } else if (fileElementType == fileElementTypeTriangle) {
            elementNodes->SetNumberOfIds(3);
            inputFileStream >> fileNodeId0 >> fileNodeId1 >> fileNodeId2;
            elementNodes->SetId(0, fileNodeId0 - 1);
            elementNodes->SetId(1, fileNodeId1 - 1);
            elementNodes->SetId(2, fileNodeId2 - 1);
            unstructuredGrid->InsertNextCell(VTK_TRIANGLE, elementNodes);
        } else if (fileElementType == fileElementTypeTetrahedron) {
            elementNodes->SetNumberOfIds(4);
            inputFileStream >> fileNodeId0 >> fileNodeId1 >> fileNodeId2 >> fileNodeId3;
            elementNodes->SetId(0, fileNodeId0 - 1);
            elementNodes->SetId(1, fileNodeId1 - 1);
            elementNodes->SetId(2, fileNodeId2 - 1);
            elementNodes->SetId(3, fileNodeId3 - 1);
            unstructuredGrid->InsertNextCell(VTK_TETRA, elementNodes);
        }
    }

    model->setDataSet(unstructuredGrid);
}

QString DmwMeshActionImportSalomeDatFile::requestSalomeDatFilePath() {
    return QFileDialog::getOpenFileName(nullptr, tr("Open Salome DAT File"), QString(), tr("Salome DAT files (*.dat)"));
}
