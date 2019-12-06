#include "evenements.h"


evenements::evenements()
{
    code="";
    libelle="";
    dates="";
    duree=0;
    prix_ticket=0;
}

evenements::evenements(QString c,QString li,QString dat,float d,float px)
{
    code=c;
    libelle=li;
    dates=dat;
    duree=d;
    prix_ticket=px;
}

QString evenements::get_code()
{
    return code;
}

QString evenements::get_libelle()
{
    return libelle;
}

QString evenements::get_dates()
{
    return dates;
}

float evenements::get_duree()
{
    return duree;
}

float evenements::get_prix_ticket()
{
    return prix_ticket;
}

bool evenements::ajouter()
{
    QSqlQuery query;
    QString duree2;
    duree2.setNum(duree);
    QString prix_ticket2;
    prix_ticket2.setNum(prix_ticket);
    query.prepare("INSERT INTO evenements (code,libelle,dates,duree,prix_ticket)VALUES(:code,:libelle,:dates,:duree,:prix_ticket)");
    query.bindValue(":code",code);
    query.bindValue(":libelle",libelle);
    query.bindValue(":dates",dates);
    query.bindValue(":duree",duree2);
    query.bindValue(":prix_ticket",prix_ticket2);
    return query.exec();
}

QSqlQueryModel * evenements::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from evenements");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CODE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("LIBELLE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATES"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DUREE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX_TICKET"));
    return model;
}

bool evenements::supprimer(QString code)
{
    QSqlQuery query;
    query.prepare("DELETE FROM evenements WHERE CODE= :code");
    query.bindValue(":code",code);
    return query.exec();
}

bool evenements::modifier(evenements e)
{
    QSqlQuery query;
    QString duree2;
    duree2.setNum(e.get_duree());
    QString prix_ticket2;
    prix_ticket2.setNum(e.get_prix_ticket());
    query.prepare("UPDATE evenements SET libelle= :libelle, dates= :dates, duree= :duree, prix_ticket= :prix_ticket WHERE code= :code");
    query.bindValue(":code",e.get_code());
    query.bindValue(":libelle",e.get_libelle());
    query.bindValue(":dates",e.get_dates());
    query.bindValue(":duree",duree2);
    query.bindValue(":prix_ticket",prix_ticket2);
    return query.exec();
}
