#ifndef DATABASESQLITE_H
#define DATABASESQLITE_H

#include <QString>
#include <QDebug>
#include <QVector>

#include "lekarz.h"
#include "pacjent.h"
#include "wizyta.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class DatabaseSqlite
{
private:
    DatabaseSqlite();
    static DatabaseSqlite* instance;
    const QString SERVER_NAME;
    const QString DATABASE_NAME;
    QSqlDatabase db;
public:
    static DatabaseSqlite* getInstance();

    void createTables();
    void insertLekarz(Lekarz lekarz);
    void updateLekarz(Lekarz lekarz);
    void deleteLekarz(int id);
    QVector<Lekarz> selectLekarz();
    void insertPacjent(Pacjent pacjent);
    void updatePacjent(Pacjent pacjent);
    void deletePacjent(int id);
    QVector<Pacjent> selectPacjent();
    void insertWizyta(Wizyta wizyta);
};

#endif
