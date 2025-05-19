#ifndef TEST_H
#define TEST_H
#include <QObject>
#include <QDebug>
#include <QString>


class Test : public QObject
{
    Q_OBJECT
public:
    // explicit constructor to prevent implicit conversions
    explicit Test(QObject *parent = nullptr,QString name="Unknown");

    ~Test();

};


#endif // TEST_H