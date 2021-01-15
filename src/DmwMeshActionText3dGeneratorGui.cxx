#include <memory>

#include "ui_DmwMeshActionText3dGeneratorGui.h"

#include "DmwMeshActionText3dGeneratorGui.hxx"

using std::make_unique;

DmwMeshActionText3dGeneratorGui::DmwMeshActionText3dGeneratorGui()
: ui(nullptr)
{
    ui = make_unique<Ui_DmwMeshActionText3dGeneratorGui>();
    ui->setupUi(this);
}

DmwMeshActionText3dGeneratorGui::~DmwMeshActionText3dGeneratorGui() noexcept {
    // Nothing to do here.
}

std::string DmwMeshActionText3dGeneratorGui::getText() const {
    return ui->lineEditText->text().toStdString();
}
