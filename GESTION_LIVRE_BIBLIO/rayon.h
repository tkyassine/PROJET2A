#ifndef RAYON_H
#define RAYON_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class Rayon{
    public:
        Rayon();
        Rayon(QString, QString);
        QString getNR();
        QString getCR();
        bool ajouter();
        bool supprimer(QString);
        bool modifier(QString, QString, QString);
        QSqlQueryModel * afficher(QString, QString, QString);
    private:
        QString nR, cR;
};

#endif // RAYON_H
