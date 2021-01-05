#ifndef DmwActionCallback_hxx
#define DmwActionCallback_hxx

#include <QObject>

class DmwActionCallback : QObject {

    Q_OBJECT

public slots:
    // Maybe we will need to add non-const version of action callback
    virtual void call() const = 0;

};

#endif //DmwActionCallback_hxx
