#ifndef LEKARZ_H
#define LEKARZ_H
#include "libs.h"



class Lekarz
{
private:
    int id;
    QString imie;
    QString nazwisko;
    QString specjalizacja;
    double pensja;
public:
    Lekarz();
    Lekarz(int id,QString noweImie,QString noweNazwisko,QString nowaSpecjalizacja,double nowaPensja);
    QString getImie();
    QString getNazwisko();
    QString getSpecjalizacja();
    double getPensja();
    int getIdLekarz();
    void setIdLekarz(int noweId);
    void setImie(QString noweImie);
    void setNazwisko(QString noweNazwisko);
    void setSpecjalizacja(QString nowaSpecjalizacja);
    void setPensja(double nowaPensja);
    friend QDebug operator<<(QDebug out, const Lekarz& l);
    ~Lekarz();
};

#endif // LEKARZ_H
