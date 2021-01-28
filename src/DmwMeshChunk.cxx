#include "DmwMeshChunk.hxx"

DmwMeshChunk::DmwMeshChunk(vtkSmartPointer<vtkUnstructuredGrid> mesh)
: mesh(mesh)
{
    // Nothing to do here
}

DmwMeshChunk::~DmwMeshChunk() noexcept {
    // Nothing to do here
}

vtkSmartPointer<vtkUnstructuredGrid> DmwMeshChunk::getMesh() {
    return mesh;
}


bool DmwMeshChunk::visible() const {
    return isVisible;
}

void DmwMeshChunk::visible(const bool newVisible)  {
    isVisible = newVisible;
}
