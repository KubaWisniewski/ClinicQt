#ifndef WIZYTA_H
#define WIZYTA_H
#include "libs.h"

class Wizyta
{
private:
    int id;
    int idL;
    int idP;
    int cena;
    QString miejscowosc;
public:
    Wizyta();
    Wizyta(int idL,int idP,int nowaCena,QString nowaMiejscowosc);
    void setCena(int nowaCena);
    void setMiejscowosc(QString nowaMiejscowosc);
    int getCena();
    QString getMiejscowosc();
    friend QDebug operator <<(QDebug out, const Wizyta& w);
    int getId();
    int getIdP();
    int getIdL();
    ~Wizyta();


};

#endif
