#include <QCoreApplication>
#include <QList>
#include <QDebug>
#include <QMap>
#include <QSharedPointer>

#include "test.h"

void test_delete_all() {
    QList<test*> list;

    for(int i =0; i< 5; i++) {
        list.append(new test(nullptr,"Item" + QString::number(i)));
    }
    foreach(test*item,list) {
        qInfo() << item;
    }
    qInfo() << list.count();
    qDeleteAll(list);
    list.clear();
    qInfo() << list.count();
}
typedef QMap<QString,QSharedPointer<test>> TestQsMap;

void test_QSharePrt_QMap() {

    TestQsMap map;
    for (int i = 0; i < 5; i++)
    {
        QString id = "ID-" + QString::number(i);
        QSharedPointer<test> item(new test(nullptr, "Item" + QString::number(i)));
        map.insert(id, item);
    }
    foreach (const QString &key, map.keys())
    {
        qInfo() << key << map.value(key).data()->objectName();
    }
}

int main(int argc, char *argv[])
{
    test_QSharePrt_QMap();
    return 0;
}
