#ifndef DmwMeshChunk_hxx
#define DmwMeshChunk_hxx

#include <vtkSmartPointer.h>

class vtkUnstructuredGrid;

class DmwMeshChunk {

public:
    explicit DmwMeshChunk(vtkSmartPointer<vtkUnstructuredGrid> mesh);
    ~DmwMeshChunk() noexcept;

    vtkSmartPointer<vtkUnstructuredGrid> getMesh();

    bool visible() const;
    void visible(bool newVisible);
//    void getColor();
//    void setColor();

private:
    vtkSmartPointer<vtkUnstructuredGrid> mesh;
    bool isVisible;

};

#endif // DmwMeshChunk_hxx
