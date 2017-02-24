#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <QString>
#include <QSettings>

static void configIn(QString hostName,QString databaseName,QString uid,QString pwd)
{
    QSettings *configIniWrite = new QSettings("..\\path/Config.ini", QSettings::IniFormat);

    configIniWrite->setValue("/ServerDatabaseParameter/ServerHostName", hostName);

    configIniWrite->setValue("ServerDatabaseParameter/DatabeseName", databaseName);

    configIniWrite->setValue("ServerDatabaseParameter/UID", uid);

    configIniWrite->setValue("ServerDatabaseParameter/PWD", pwd);

    delete configIniWrite;
}

static void configOut(QString &hostName,QString &databaseName,QString &uid,QString &pwd)
{
    QSettings *configOutiRead = new QSettings("..\\path/Config.ini", QSettings::IniFormat);
    hostName = configOutiRead->value("/ServerDatabaseParameter/ServerHostName").toString();
    databaseName = configOutiRead->value("ServerDatabaseParameter/DatabeseName").toString();
    uid = configOutiRead->value("ServerDatabaseParameter/UID").toString();
    pwd = configOutiRead->value("ServerDatabaseParameter/PWD").toString();

    delete configOutiRead;
}

#endif // CONFIGFILE_H
