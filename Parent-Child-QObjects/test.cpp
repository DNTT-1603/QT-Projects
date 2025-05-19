#include "test.h"

Test::Test(QObject *parent,QString name) : QObject(parent)
{
    setObjectName(name);
    qDebug() << name + " object created";
}

Test::~Test()
{

    qDebug() << "Destructor called for " << objectName();
}

