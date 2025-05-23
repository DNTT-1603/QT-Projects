/*

  What
  QSharedPointer

  Why
  Manual memory management is error prone

  How
  See below
*/

#include <QCoreApplication>
#include <QSharedPointer>
#include "test.h"

QSharedPointer<Test> getObject(QString name)
{
    QSharedPointer<Test> sp(new Test());
    sp->setObjectName(name);
    //Do other things here
    qInfo() << "SharedPointer 00" << &sp;
    return sp;
}

void doWork(QSharedPointer<Test> sp)
{
    //We are using a copy of the sharedpointer
    qInfo() << "Work" << sp.data();
    qInfo() << "SharedPointer 02" << &sp;
}

void test()
{
    qInfo() << "Getting the object";
    QSharedPointer<Test> ptr = getObject("My Object");
    qInfo() << "SharedPointer 01" << &ptr;
    qInfo() << "Object" << ptr.data();

    doWork(ptr);


    //Reference count is zero
    qInfo() << "Complete";
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test();
    return a.exec();
}
