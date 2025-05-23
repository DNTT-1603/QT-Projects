#include <QCoreApplication>
#include <QSettings>
#include <QDebug>
#include <QString>
#include <QStringList>


void testQsetting() {

    QSettings setting;
    qInfo() << setting.fileName();
    if (setting.allKeys().length() == 0) {
        qInfo() << "No setting...saving....";
    }
    setting.setValue("interval",30);
    qInfo() << "Setting status" << setting.status();

    setting.setValue("SNR",31);
    qInfo() << "Setting status" << setting.status();

    setting.setValue("ID Number",32);
    qInfo() << "Setting status" << setting.status();

    QString b,b1,b2;

    b = setting.value("interval").toString();
    qInfo() << b;
    b1 = setting.value("SNR").toString();
    qInfo() << b1;
    b2 = setting.value("ID Number").toString();
    qInfo() << b2;

}

void testQsettingGroup() {
    QSettings setting;
    setting.clear();

    qInfo() << setting.fileName();

    setting.beginGroup("Test01");
    setting.setValue("size", 1024);
    setting.setValue("fullScreen", "yes");
    setting.endGroup();

    setting.beginGroup("Test02");
    setting.setValue("visible", 1);
    setting.setValue("dost", "aaa");
    setting.endGroup();

    // Take value in each group
    QStringList lst_key_gp1 = setting.allKeys();
    QStringList lst_filter = lst_key_gp1.filter("Test01");
    qInfo() << lst_key_gp1;
    qInfo() << lst_filter;

    setting.beginGroup("Test01");



    //int size = setting.value("size").toUInt();
    setting.endGroup();

}

void save_to_group(QSharedPointer<QSettings> pSetting, QString group, QString key,QVariant value) {
    pSetting.data()->beginGroup(group);
    pSetting.data()->setValue(key,value);
    pSetting.data()->endGroup();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("qtOgnName");
    QCoreApplication::setOrganizationDomain("qtOgnDomain");
    QCoreApplication::setApplicationName("QSettingLearn");
    QString settingPath = a.applicationDirPath() + "/testSetting.init";


//    testQsettingGroup();
    QStringList lst_grp_test01;
    lst_grp_test01 << "resolution" << "dual-screen" << "brighten";
    int index =0;
    QSharedPointer<QSettings> qsh_setting(new QSettings(settingPath,QSettings::IniFormat,nullptr));

    qInfo() << qsh_setting.data()->fileName();

    foreach(QString lst,lst_grp_test01) {
        index ++;
        save_to_group(qsh_setting,"Test01",lst,QVariant(index));
    }

    return 0;
}
