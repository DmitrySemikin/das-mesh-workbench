#ifndef DmwText3dGenerator_hxx
#define DmwText3dGenerator_hxx

class DmwText3dGenerator {

public:
    explicit DmwText3dGenerator();
    ~DmwText3dGenerator() noexcept;

    vtkSmartPointer<vtkPolyData> generate3dText(char const * const text);
};

#endif //DmwText3dGenerator_hxx
