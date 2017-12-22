#ifndef PACJENT_H
#define PACJENT_H
#include "libs.h"

class Pacjent
{
private:
    int id;
    QString imie;
    QString nazwisko;
    int wiek;
    QString rodzajChoroby;
    int wzrost;
    int waga;

public:
    Pacjent();
    Pacjent(int id,QString noweImie,QString noweNazwisko,int nowyWiek,QString nowyRodzajChoroby,int nowyWzrost,int nowaWaga);
    QString getImie();
    QString getNazwisko();
    int getWiek();
    QString getRodzajChoroby();
    int getWaga();
    int getWzrost();
    void setImie(QString noweImie);
    void setNazwisko(QString noweNazwisko);
    void setWiek(int nowyWiek);
    void setRodzajChoroby(QString nowyRodzaj);
    void setWaga(int nowaWaga);
    int getIdPacjent();
    void setIdPacjent(int noweId);
    friend QDebug operator <<(QDebug out, const Pacjent& p);
    ~Pacjent();

};

#endif
