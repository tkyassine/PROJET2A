#ifndef LIVRE_H
#define LIVRE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class livre{
    public:
        livre();
        livre(QString, QString, QString, QString, int);
        QString getCodL();
        QString getLibL();
        QString getAutL();
        QString getCatL();
        int getNBL();
        bool ajouter(QString);
        bool supprimer(QString);
        bool modifier(QString, QString, QString);
        QSqlQueryModel * afficher(QString, QString, QString);
    private:
        int nBL;
        QString codL, libL, autL, catL;
};

#endif // LIVRE_H
