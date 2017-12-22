#include "wizyta.h"

Wizyta::Wizyta()
{
    cena=100;
    miejscowosc="Warszawa";
}
Wizyta::Wizyta(int idL,int idP,int nowaCena,QString nowaMiejscowosc)
{

    this->idL=idL;
    this->idP=idP;
    cena=nowaCena;
    miejscowosc=nowaMiejscowosc;
}
int Wizyta::getCena()
{
    return cena;
}
QString Wizyta::getMiejscowosc()
{
    return miejscowosc;
}
void Wizyta::setCena(int nowaCena)
{
    cena=nowaCena;
}
void Wizyta::setMiejscowosc(QString nowaMiejscowosc)
{
    miejscowosc=nowaMiejscowosc;
}
QDebug operator <<(QDebug out, const Wizyta& w)
{
    out<<"Cena:"<<w.cena;
    out<<"Miejscowosc"<<w.miejscowosc;
    return out;
}
int Wizyta::getId()
{
    return id;
}
int Wizyta::getIdP()
{
    return idP;
}
int Wizyta::getIdL()
{
    return idL;
}
Wizyta::~Wizyta()
{

}
