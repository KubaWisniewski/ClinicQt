#include "lekarz.h"

Lekarz::Lekarz()
{
    imie="Jan";
    nazwisko="Kowalski";
    specjalizacja="Kardiolog";
    pensja=5000;
}
Lekarz::Lekarz(int id,QString noweImie, QString noweNazwisko, QString nowaSpecjalizacja, double nowaPensja)
{
    this->id=id;
    imie=noweImie;
    nazwisko=noweNazwisko;
    specjalizacja=nowaSpecjalizacja;
    pensja=nowaPensja;
}
int Lekarz::getIdLekarz()
{
    return id;
}
void Lekarz::setIdLekarz(int noweId)
{
    id=noweId;
}

QString Lekarz::getImie()
{
    return imie;
}
QString Lekarz::getNazwisko()
{
    return nazwisko;
}
QString Lekarz::getSpecjalizacja()
{
    return specjalizacja;
}
double Lekarz::getPensja()
{
    return pensja;
}
void Lekarz::setImie(QString noweImie)
{
    imie=noweImie;
}
void Lekarz::setNazwisko(QString noweNazwisko)
{
    nazwisko=noweNazwisko;
}
void Lekarz::setSpecjalizacja(QString nowaSpecjalizacja)
{
    specjalizacja=nowaSpecjalizacja;
}
void Lekarz::setPensja(double nowaPensja)
{
    pensja=nowaPensja;
}


QDebug operator<<(QDebug out, const Lekarz & l)
{
    out <<"Imie:"<<l.imie;
    out<<"Nazwisko:"<<l.nazwisko;
    out<<"Specjalizacja:"<<l.specjalizacja;
    out<<"Pensja:"<<l.pensja;
    return out;


}

Lekarz::~Lekarz()
{

}
