#ifndef EVENEMENTS_H
#define EVENEMENTS_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QVariant>

class evenements
{
public:
    evenements();
    evenements(QString,QString,QString,float,float);
    QString get_code();
    QString get_libelle();
    QString get_dates();
    float get_duree();
    float get_prix_ticket();
    bool ajouter();
    bool modifier(evenements);
    QSqlQueryModel * afficher();
    bool supprimer(QString);
private:
    QString code;
    QString libelle;
    QString dates;
    float duree;
    float prix_ticket;
};

#endif // EVENEMENTS_H
