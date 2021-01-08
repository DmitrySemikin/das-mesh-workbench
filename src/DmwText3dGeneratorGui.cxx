#include <memory>

#include "ui_DmwText3dGeneratorGui.h"

#include "DmwText3dGeneratorGui.hxx"

using std::make_unique;

DmwText3dGeneratorGui::DmwText3dGeneratorGui()
: ui(nullptr)
{
    ui = make_unique<Ui_DmwText3dGeneratorGui>();
    ui->setupUi(this);
}

DmwText3dGeneratorGui::~DmwText3dGeneratorGui() noexcept {
    // Nothing to do here.
}

std::string DmwText3dGeneratorGui::getText() const {
    return ui->lineEditText->text().toStdString();
}
