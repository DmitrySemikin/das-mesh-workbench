#ifndef core_DmwApplication_hxx
#define core_DmwApplication_hxx

#include <memory>

class QApplication;

class DmwApplication {

public:
    explicit DmwApplication(int argc, char ** argv);
    ~DmwApplication() noexcept;

    int exec();

private:
    std::unique_ptr<QApplication> qApplication;
};

#endif // core_DmwApplication_hxx
