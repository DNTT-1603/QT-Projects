#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QString>
#include <QDebug>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent, QString name);
    ~test();

};

#endif // TEST_H
