#ifndef DmwMeshActionText3dGeneratorGui_hxx
#define DmwMeshActionText3dGeneratorGui_hxx

#include <memory>
#include <string>

#include <QDialog>

class Ui_DmwMeshActionText3dGeneratorGui;

class DmwMeshActionText3dGeneratorGui : public QDialog {

    Q_OBJECT

public:
    // TODO: Add parent to the constructor as argument
    explicit DmwMeshActionText3dGeneratorGui();
    ~DmwMeshActionText3dGeneratorGui() noexcept override;

    std::string getText() const;

private:
    std::unique_ptr<Ui_DmwMeshActionText3dGeneratorGui> ui;

};

#endif //DmwMeshActionText3dGeneratorGui_hxx
