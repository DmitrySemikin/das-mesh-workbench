#ifndef DmwActionCallback_hxx
#define DmwActionCallback_hxx

#include <QObject>

class DmwActionCallback : QObject {

    Q_OBJECT

public slots:
    // Maybe we will need to add non-const version of action callback
    void call() = 0 const;

};

#endif //DmwActionCallback_hxx
