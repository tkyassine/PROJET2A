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
    promotions(QString,float,QString);
    QString get_code();
    float get_taux();
    QString get_validite();
    bool ajouter();
    bool modifier(promotions);
    QSqlQueryModel * afficher();
    bool supprimer(QString);
private:
    QString validite;
    float taux;
    QString code;
};

#endif // PROMOTIONS_H
