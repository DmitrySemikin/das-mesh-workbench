#include "DmwText3dGenerator.hxx"

#include "DmwText3dGeneratorActionCallback.hxx"

DmwText3dGeneratorActionCallback::DmwText3dGeneratorActionCallback(DmwText3dGenerator & text3DGenerator)
: text3DGenerator(text3DGenerator)
{
    // Nothing to do here
}

DmwText3dGeneratorActionCallback::~DmwText3dGeneratorActionCallback() noexcept {
    //  Nothing to do here
}

void DmwText3dGeneratorActionCallback::call() {
    text3DGenerator.generate3dTextWithGuiAndUpdateModel();
}
