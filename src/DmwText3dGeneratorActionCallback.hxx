#ifndef DmwText3dGeneratorActionCallback_hxx
#define DmwText3dGeneratorActionCallback_hxx

#include "DmwActionCallback.hxx"

class DmwText3dGenerator;

class DmwText3dGeneratorActionCallback : public DmwActionCallback {

    Q_OBJECT

public:
    explicit DmwText3dGeneratorActionCallback(DmwText3dGenerator & text3DGenerator);
    ~DmwText3dGeneratorActionCallback() noexcept override;

public slots:
    // Maybe we will need to add non-const version of action callback
    virtual void call() override;

private:
    DmwText3dGenerator & text3DGenerator;

};

#endif //DmwText3dGeneratorActionCallback_hxx
