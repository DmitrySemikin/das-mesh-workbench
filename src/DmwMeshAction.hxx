#ifndef DmwMeshAction_hxx
#define DmwMeshAction_hxx

#include <QObject>

class DmwMeshAction : public QObject {

    Q_OBJECT

public slots:
    // Maybe we will need to add non-const version of action callback
    virtual void call() = 0;

};

#endif //DmwMeshAction_hxx
