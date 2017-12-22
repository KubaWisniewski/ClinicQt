#include "pacjent.h"

Pacjent::Pacjent()
{
    imie="Adam";
    nazwisko="Nowak";
    wiek=50;
    rodzajChoroby="Goraczka";
    wzrost=175;
    waga=76;
}
Pacjent::Pacjent(int id,QString noweImie,QString noweNazwisko,int nowyWiek,QString nowyRodzajChoroby,int nowyWzrost,int nowaWaga)
{
    this->id=id;
    imie=noweImie;
    nazwisko=noweNazwisko;
    wiek=nowyWiek;
    rodzajChoroby=nowyRodzajChoroby;
    wzrost=nowyWzrost;
    waga=nowaWaga;
}
int Pacjent::getIdPacjent()
{
    return id;
}
void Pacjent::setIdPacjent(int noweIdPacjent)
{
    id=noweIdPacjent;
}
QString Pacjent::getImie()
{
    return imie;
}
QString Pacjent::getNazwisko()
{
    return nazwisko;
}
int Pacjent::getWiek()
{
    return wiek;
}
QString Pacjent::getRodzajChoroby()
{
    return rodzajChoroby;
}
int Pacjent::getWaga()
{
    return waga;
}
int Pacjent::getWzrost()
{
    return wzrost;
}
void Pacjent::setImie(QString noweImie)
{
    imie=noweImie;
}

void Pacjent::setNazwisko(QString noweNazwisko)
{
    nazwisko=noweNazwisko;
}
void Pacjent::setWiek(int nowyWiek)
{
    wiek=nowyWiek;
}
void Pacjent::setRodzajChoroby(QString nowyRodzaj)
{
    rodzajChoroby=nowyRodzaj;
}
void Pacjent::setWaga(int nowaWaga)
{
    waga=nowaWaga;
}
QDebug operator <<(QDebug out, const Pacjent& p)
{
    out<<"Imie:"<<p.imie<<endl;
    out<<"Nazwisko:"<<p.nazwisko<<endl;
    out<<"Wiek:"<<p.wiek<<endl;
    out<<"Rodzaj Choroby:"<<p.rodzajChoroby<<endl;
    out<<"Waga:"<<p.waga<<endl;
    out<<"Wzrost:"<<p.wzrost<<endl;
    return out;

}
Pacjent::~Pacjent()
{

}
