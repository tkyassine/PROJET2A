#ifndef PROMOTIONS_H
#define PROMOTIONS_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QVariant>

class promotions
{
public:
    promotions();
    promotions(QString,float,int,int);
    QString get_code();
    float get_taux();
    int get_validite();
    int get_id_client();
    bool ajouter();
    bool modifier(promotions);
    QSqlQueryModel * afficher();
    bool supprimer(QString);
private:
    int validite,id_client;
    float taux;
    QString code;
};

#endif // PROMOTIONS_H
