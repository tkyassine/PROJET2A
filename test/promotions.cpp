#include "promotions.h"

promotions::promotions()
{
    code="";
    taux=0;
    validite=0;
    id_client=0;
}

promotions::promotions(QString c,float t,int v,int id)
{
    code=c;
    taux=t;
    validite=v;
    id_client=id;
}

QString promotions::get_code()
{
    return code;
}

float promotions::get_taux()
{
    return taux;
}

int promotions::get_validite()
{
    return validite;
}

int promotions::get_id_client()
{
    return id_client;
}

bool promotions::ajouter()
{
    QSqlQuery query;
    QString taux2;
    taux2.setNum(taux);
    QString validite2=QString::number(validite);
    QString id_client2=QString::number(id_client);
    query.prepare("INSERT INTO promotions (code,taux,validite,id_client)VALUES(:code,:taux,:validite,:id_client)");
    query.bindValue(":code",code);
    query.bindValue(":taux",taux2);
    query.bindValue(":validite",validite2);
    query.bindValue(":id_client",id_client2);
    return query.exec();
}

QSqlQueryModel * promotions::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select code,taux,validite,id_client from promotions");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CODE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TAUX"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("VALIDITE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_CLIENT"));
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
    QString validite2=QString::number(p.get_validite());
    QString id_client2=QString::number(p.get_id_client());
    query.prepare("UPDATE promotions SET taux= :taux, validite= :validite, id_client= :id_client WHERE code= :code");
    query.bindValue(":code",p.get_code());
    query.bindValue(":taux",taux2);
    query.bindValue(":validite",validite2);
    query.bindValue(":id_client",id_client2);
    return query.exec();
}
