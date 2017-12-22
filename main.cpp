#include <QCoreApplication>
#include "databasesqlite.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DatabaseSqlite* dbsqlite = DatabaseSqlite::getInstance();
    dbsqlite->createTables();
    Lekarz l;
    dbsqlite->insertLekarz(l);
    dbsqlite->insertLekarz(Lekarz (0, "Adam","Nowak","Ortopeda",2000));
    //dbsqlite->updateLekarz(Lekarz(3, "Kazik", "Popiel", "kardiolog", 3200));
    //dbsqlite->deleteLekarz(2);
    QVector<Lekarz> lekarze = dbsqlite->selectLekarz();
    for(const auto& l : lekarze)
    {
        qDebug() << l;
    }
    dbsqlite->insertPacjent(Pacjent());
    dbsqlite->insertPacjent(Pacjent());
    dbsqlite->insertPacjent(Pacjent(1,"Jan","Kowalski",50,"Przezebienie",180,75));
    //dbsqlite->updatePacjent(Pacjent(3,"Kamil","Kowalski",50,"Przezebienie",180,75));
    //dbsqlite->deletePacjent(2);

    QVector<Pacjent> pacjenci = dbsqlite->selectPacjent();
    for(const auto& p : pacjenci)
    {
        qDebug() << p;
    }
    dbsqlite->insertWizyta(Wizyta(2,1,300,"Warszawa"));
    return a.exec();
}
