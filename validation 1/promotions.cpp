#include "promotions.h"

promotions::promotions()
{
    code="";
    taux=0;
    validite="";
}

promotions::promotions(QString c,float t,QString v)
{
    code=c;
    taux=t;
    validite=v;
}

QString promotions::get_code()
{
    return code;
}

float promotions::get_taux()
{
    return taux;
}

QString promotions::get_validite()
{
    return validite;
}


bool promotions::ajouter()
{
    QSqlQuery query;
    QString taux2;
    taux2.setNum(taux);
    query.prepare("INSERT INTO promotions (code,taux,validite)VALUES(:code,:taux,:validite)");
    query.bindValue(":code",code);
    query.bindValue(":taux",taux2);
    query.bindValue(":validite",validite);
    return query.exec();
}

QSqlQueryModel * promotions::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select code,taux,validite from promotions");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CODE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TAUX"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("VALIDITE"));
    return model;
}

bool promotions::supprimer(QString code)
{
    QSqlQuery query;
    query.prepare("DELETE FROM promotions WHERE CODE= :code");
    query.bindValue(":code",code);
    return query.exec();
}

bool promotions::modifier(promotions p)
{
    QSqlQuery query;
    QString taux2;
    taux2.setNum(p.get_taux());
    query.prepare("UPDATE promotions SET taux= :taux, validite= :validite WHERE code= :code");
    query.bindValue(":code",p.get_code());
    query.bindValue(":taux",taux2);
    query.bindValue(":validite",p.get_validite());
    return query.exec();
}
