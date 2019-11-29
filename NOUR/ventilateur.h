#ifndef VENTILATEUR_H
#define VENTILATEUR_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class ventilateur{
    public:
        ventilateur();
        ventilateur(int, int);
        int getNum();
        int getEtat();
        bool ajouter();
        bool supprimer(int);
        bool modifier(ventilateur);
        QSqlQueryModel * afficher(QString);
    private:
        int num, etat;
};

#endif // VENTILATEUR_H
