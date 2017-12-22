#include "databasesqlite.h"

DatabaseSqlite::DatabaseSqlite() : SERVER_NAME("QSQLITE"), DATABASE_NAME("./baza.db")
{
    db = QSqlDatabase::addDatabase(SERVER_NAME);
    db.setDatabaseName(DATABASE_NAME);

    if (!db.open())
    {
        qDebug() << "Blad komunikacji z baza danych!";
        qDebug() << db.lastError();
    }
    else
    {
        qDebug() << "Polaczono z baza danych -> " << DATABASE_NAME;
    }
}

DatabaseSqlite* DatabaseSqlite::getInstance()
{
    if (!instance)
    {
        instance = new DatabaseSqlite();
    }
    return instance;
}
void DatabaseSqlite::createTables()
{
    if (db.isOpen())
    {
        QSqlQuery query;
        query.prepare("PRAGMA foreign_keys = ON;");
        query.exec();

        QString sqlTableLekarz = "CREATE TABLE IF NOT EXISTS Lekarz "
                                  "( "
                                  " id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                  " imie VARCHAR(50) NOT NULL, "
                                  " nazwisko VARCHAR(50) NOT NULL, "
                                  " specjalizacja VARCHAR(50) NOT NULL, "
                                  " pensja DOUBLE NOT NULL"
                                  ");";        
        query.prepare(sqlTableLekarz);
        if (query.exec())
        {
            qDebug() << "POPRAWNIE UTWORZONO TABELE Lekarz!";
        }
        else
        {
            qDebug() << "createTable - tabela Lekarz - blad!\n";
            qDebug() << db.lastError();
        }


        QString sqlTablePacjent = "CREATE TABLE IF NOT EXISTS Pacjent "
                                  "( "
                                  " id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                  " imie VARCHAR(50) NOT NULL, "
                                  " nazwisko VARCHAR(50) NOT NULL, "
                                  " wiek INTEGER NOT NULL,"
                                  " rodzajChoroby VARCHAR(50)NOT NULL, "
                                  " wzrost INTEGER NOT NULL,"
                                  " waga INTEGER NOT NULL"
                                  ");";

        query.prepare(sqlTablePacjent);
        if (query.exec())
        {
            qDebug() << "POPRAWNIE UTWORZONO TABELE Pacjent!";
        }
        else
        {
            qDebug() << "createTable - tabela Pacjent - blad!\n";
            qDebug() << db.lastError();
        }
        QString sqlTableWizyta = "CREATE TABLE IF NOT EXISTS Wizyta "
                                  "( "
                                  " id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                  " idL INTEGER NOT NULL, "
                                  " idP INTEGER NOT NULL, "
                                  " cena INTEGER NOT NULL, "
                                  " miejscowosc VARCHAR(50) NOT NULL, "
                                  " FOREIGN KEY (idL) REFERENCES Lekarz(id) ON DELETE CASCADE ON UPDATE CASCADE, "
                                  " FOREIGN KEY (idP) REFERENCES Pacjent(id) ON DELETE CASCADE ON UPDATE CASCADE "
                                  ");";

        query.prepare(sqlTableWizyta);
        if (query.exec())
        {
            qDebug() << "POPRAWNIE UTWORZONO TABELE Wizyta!";
        }
        else
        {
            qDebug() << "createTable - tabela Wizyta - blad!\n";
            qDebug() << db.lastError();
        }

    }
    else
    {
        qDebug() << "createTables - brak komunikacji z baza danych";
    }
}

void DatabaseSqlite::insertLekarz(Lekarz lekarz)
{
    if(db.isOpen())
    {
        QString insertLekarzSql ="INSERT INTO Lekarz (imie, nazwisko, specjalizacja, pensja) VALUES (:imie, :nazwisko, :specjalizacja, :pensja)";
        QSqlQuery query;
        query.prepare(insertLekarzSql);
        query.bindValue(":imie", lekarz.getImie());
        query.bindValue(":nazwisko",lekarz.getNazwisko());
        query.bindValue(":specjalizacja",lekarz.getSpecjalizacja());
        query.bindValue(":pensja",lekarz.getPensja());

        if (query.exec())
        {
            qDebug() << "POPRAWNIE WSTAWIONO DO TABELI Lekarz!";
        }
        else
        {
            qDebug() << "INSERT LEKARZ - blad!\n";
            qDebug() << db.lastError();
        }
    }
}

void DatabaseSqlite::updateLekarz(Lekarz lekarz)
{
    if(db.isOpen())
    {
        QString updateLekarzSql ="UPDATE Lekarz SET imie=:imie, nazwisko=:nazwisko, specjalizacja=:specjalizacja, pensja=:pensja WHERE id = :id";
        QSqlQuery query;
        query.prepare(updateLekarzSql);
        query.bindValue(":id",lekarz.getIdLekarz());
        query.bindValue(":imie",lekarz.getImie());
        query.bindValue(":nazwisko",lekarz.getNazwisko());
        query.bindValue(":specjalizacja",lekarz.getSpecjalizacja());
        query.bindValue(":pensja",lekarz.getPensja());
        if (query.exec())
        {
            qDebug() << "POPRAWNIE ZMIENIONO W TABELI Lekarz!";
        }
        else
        {
            qDebug() << "UPDATE LEKARZ - blad!\n";
            qDebug() << db.lastError();
        }
    }
}
void DatabaseSqlite::deleteLekarz(int id)
{
    if(db.isOpen())
    {
        QString deleteLekarzSql ="DELETE FROM Lekarz WHERE id=:id";
        QSqlQuery query;
        query.prepare(deleteLekarzSql);
        query.bindValue(":id",id);

        if (query.exec())
        {
            qDebug() << "POPRAWNIE USUNIETO Z TABELI Lekarz!";
        }
        else
        {
            qDebug() << "DELETE LEKARZ - blad!\n";
            qDebug() << db.lastError();
        }
    }
}

QVector<Lekarz> DatabaseSqlite::selectLekarz()
{
    QVector<Lekarz> lekarze;
    QString selectLekarzStr = "SELECT * FROM Lekarz";
    QSqlQuery query(selectLekarzStr); //jezeli nie chcesz nic bindowac to od razu mozesz dac zapytanie
    while(query.next())
    {
        int id = query.value("id").toInt();
        QString imie=query.value("imie").toString();
        QString nazwisko=query.value("nazwisko").toString();
        QString specjalizacja=query.value("specjalizacja").toString();
        double pensja=query.value("pensja").toDouble();
        lekarze.push_back(Lekarz(id, imie, nazwisko, specjalizacja, pensja));
    }
    return lekarze;
}
void DatabaseSqlite::insertPacjent(Pacjent pacjent)
{
    if(db.isOpen())
    {
        QString insertPacjentSql ="INSERT INTO Pacjent (imie, nazwisko, wiek, rodzajChoroby, wzrost ,waga) VALUES (:imie, :nazwisko, :wiek, :rodzajChoroby, :wzrost, :waga)";
        QSqlQuery query;
        query.prepare(insertPacjentSql);
        query.bindValue(":imie", pacjent.getImie());
        query.bindValue(":nazwisko",pacjent.getNazwisko());
        query.bindValue(":wiek",pacjent.getWiek());
        query.bindValue(":rodzajChoroby",pacjent.getRodzajChoroby());
        query.bindValue(":wzrost",pacjent.getWzrost());
        query.bindValue(":waga",pacjent.getWaga());

        if (query.exec())
        {
            qDebug() << "POPRAWNIE WSTAWIONO DO TABELI Pacjent!";
        }
        else
        {
            qDebug() << "INSERT Pacjent - blad!\n";
            qDebug() << db.lastError();
        }
    }
}
void DatabaseSqlite::updatePacjent(Pacjent pacjent)
{
    if(db.isOpen())
    {
        QString updatePacjentSql ="UPDATE Pacjent SET imie=:imie, nazwisko=:nazwisko, wiek=:wiek, rodzajChoroby=:rodzajChoroby, wzrost=:wzrost, waga=:waga WHERE id = :id";
        QSqlQuery query;
        query.prepare(updatePacjentSql);
        query.bindValue(":id",pacjent.getIdPacjent());
        query.bindValue(":imie", pacjent.getImie());
        query.bindValue(":nazwisko",pacjent.getNazwisko());
        query.bindValue(":wiek",pacjent.getWiek());
        query.bindValue(":rodzajChoroby",pacjent.getRodzajChoroby());
        query.bindValue(":wzrost",pacjent.getWzrost());
        query.bindValue(":waga",pacjent.getWaga());

        if (query.exec())
        {
            qDebug() << "POPRAWNIE ZMIENIONO W TABELI Pacjent!";
        }
        else
        {
            qDebug() << "UPDATE Pacjent - blad!\n";
            qDebug() << db.lastError();
        }
    }
}
void DatabaseSqlite::deletePacjent(int id)
{
    if(db.isOpen())
    {
        QString deletePacjentSql ="DELETE FROM Pacjent WHERE id=:id";
        QSqlQuery query;
        query.prepare(deletePacjentSql);
        query.bindValue(":id",id);

        if (query.exec())
        {
            qDebug() << "POPRAWNIE USUNIETO Z TABELI Pacjent!";
        }
        else
        {
            qDebug() << "DELETE Pacjent - blad!\n";
            qDebug() << db.lastError();
        }
    }
}
QVector<Pacjent> DatabaseSqlite::selectPacjent()
{
    QVector<Pacjent> pacjenci;
    QString selectPacjentStr = "SELECT * FROM Pacjent";
    QSqlQuery query(selectPacjentStr);
    while(query.next())
    {
        int id = query.value("id").toInt();
        QString imie=query.value("imie").toString();
        QString nazwisko=query.value("nazwisko").toString();
        int wiek=query.value("wiek").toInt();
        QString rodzajChoroby=query.value("rodzajChoroby").toString();
        int wzrost=query.value("wzrost").toInt();
        int waga=query.value("waga").toInt();
        pacjenci.push_back(Pacjent(id, imie, nazwisko,wiek, rodzajChoroby, wzrost,waga));
    }
    return pacjenci;
}
void DatabaseSqlite::insertWizyta(Wizyta wizyta)
{
    if(db.isOpen())
    {
        QString insertWizytaSql ="INSERT INTO Wizyta (id,idL,idP,cena,miejscowosc) VALUES (:id, :idL, :idP, :cena,:miejscowosc)";
        QSqlQuery query;

        query.prepare(insertWizytaSql);

        query.bindValue(":idL", wizyta.getIdL());
        query.bindValue(":idP", wizyta.getIdP());
        query.bindValue(":cena",wizyta.getCena());
        query.bindValue(":miejscowosc",wizyta.getMiejscowosc());

        if (query.exec())
        {
            qDebug() << "POPRAWNIE WSTAWIONO DO TABELI Wizyta!";
        }
        else
        {
            qDebug() << "INSERT Wizyta - blad!\n";
            qDebug() << db.lastError();
        }
    }
    else
    {
        qDebug()<<"BAZA ZAMKNIETA";

    }
}
DatabaseSqlite* DatabaseSqlite::instance = NULL;
