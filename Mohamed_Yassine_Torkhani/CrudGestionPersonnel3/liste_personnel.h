#ifndef LISTE_PERSONNEL_H
#define LISTE_PERSONNEL_H
#include "securite.h"
#include <QString>
#include <QSystemTrayIcon>
class liste_personnel
{
public:
    liste_personnel();
    bool ajouter_personnel(const securite&);
    int ajouter_personnel(int,QString ,QString,QString ,int,int ,QString,QString);

};

#endif // LISTE_PERSONNEL_H
