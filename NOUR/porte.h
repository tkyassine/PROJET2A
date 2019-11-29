#ifndef PORTE_H
#define PORTE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class porte{
    public:
        porte();
        porte(int, int);
        int getNum();
        int getEtat();
        bool ajouter();
        bool supprimer(int);
        bool modifier(porte);
        QSqlQueryModel * afficher(QString);
    private:
        int num, etat;
};

#endif // PORTE_H
