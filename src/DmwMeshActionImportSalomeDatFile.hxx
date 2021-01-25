#ifndef DmwMeshActionImportSalomeDatFile_hxx
#define DmwMeshActionImportSalomeDatFile_hxx

#include <memory>

#include <QString> // private use

#include "DmwMeshAction.hxx"

class DmwModel;

class DmwMeshActionImportSalomeDatFile :
        public DmwMeshAction
{
    Q_OBJECT

public:
    explicit DmwMeshActionImportSalomeDatFile(std::shared_ptr<DmwModel> model);
    ~DmwMeshActionImportSalomeDatFile() noexcept override;

public slots:
    void call() override;

private:
    void importSalomeDatFile();
    void importSalomeDatFile(QString const & filePath);
    QString requestSalomeDatFilePath();

private:
    std::shared_ptr<DmwModel> model;

};

#endif //DmwMeshActionImportSalomeDatFile_hxx
