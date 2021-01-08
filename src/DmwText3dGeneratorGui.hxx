#ifndef DmwText3dGeneratorGui_hxx
#define DmwText3dGeneratorGui_hxx

#include <memory>
#include <string>

#include <QDialog>

class Ui_DmwText3dGeneratorGui;

class DmwText3dGeneratorGui : public QDialog {

    Q_OBJECT

public:
    // TODO: Add parent to the constructor as argument
    explicit DmwText3dGeneratorGui();
    ~DmwText3dGeneratorGui() noexcept override;

    std::string getText() const;

private:
    std::unique_ptr<Ui_DmwText3dGeneratorGui> ui;

};

#endif //DmwText3dGeneratorGui_hxx
