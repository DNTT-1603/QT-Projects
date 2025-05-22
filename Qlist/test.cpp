#include "test.h"

test::test(QObject *parent = nullptr, QString name = "test")
{
    setObjectName(name);
    qInfo() << "test constructor" << this->objectName();
};

test::~test()
{
    qInfo() << "test destructor" << this->objectName();
}
