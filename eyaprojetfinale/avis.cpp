#include "avis.h"
#include <QDebug>
#include <QString>
#include "avis.h"
#include "client.h"
avis::avis()
{   numavis=0;
    dateavis="";
    etatavis=0;
    idclients="";

}



 avis::avis(int numavis ,QString dateavis, int etatavis , QString idclients)
 {
     this->numavis=numavis;
     this->dateavis=dateavis;
     this->etatavis=etatavis;
     this->idclients =idclients;
 }




int avis::get_etat()
{
    return etatavis;
}
QString avis::get_dateavis()
{
    return dateavis;
}
int avis::get_numavis()
{
    return numavis;
}
QString avis::get_idclient()
{
    return idclients;
}



void avis::set_etatavis(int etatavis)
{
    this->etatavis=etatavis;
}
void avis::set_dateavis(QString dateavis)
{
    this->dateavis=dateavis;
}

void avis::set_numavis(int numavis)
{
    this->numavis=numavis;
}
void avis::set_idclient( QString idclient)
{
    this->idclients=idclient;
}





bool avis::ajouter_avis(avis a)
{
    QSqlQuery query;
  ////  QString res= QString::number(id);
    query.prepare("INSERT INTO avis (NUMAVIS, DATEAVIS, ETATAVIS,IDCLIENT) VALUES (:numavis, :dateavis, :etatavis , :idclient )");
    query.bindValue(":numavis",a.get_numavis());
    query.bindValue(":dateavis",a.get_dateavis());
    query.bindValue(":etatavis",a.get_etat());
     query.bindValue(":idclient",a.get_idclient());

 return query.exec();
}


bool avis::modifier_avis(avis a)
{
    QSqlQuery query;

       query.prepare("UPDATE AVIS SET DATEAVIS =:dateavis , ETATAVIS =:etatavis , IDCLIENT =:idclient WHERE NUMAVIS =:numavis ");
       query.bindValue(":numavis", a.get_numavis());
       query.bindValue(":dateavis", a.get_dateavis());
       query.bindValue(":etatavis", a.get_etat());
        query.bindValue(":idclient", a.get_idclient());

    return query.exec();
}


QSqlQueryModel *avis::afficher_avis()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from avis");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMAVIS"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEAVIS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETATAVIS"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("IDCLIENT"));

    return model;
}

bool avis::supprimer_avis(int numavis)
{
    QSqlQuery query;
    QString res= QString::number(numavis);
    query.prepare("DELETE from avis where NUMAVIS = :numavis ");
    query.bindValue(":numavis", res);
    return    query.exec();
}


QSqlQueryModel *avis::tri()
{
QSqlQuery *q = new QSqlQuery();
QSqlQueryModel *model = new QSqlQueryModel();
q->prepare("SELECT * FROM AVIS ORDER BY ETATAVIS");
q->exec();
model->setQuery(*q);
return model;
}

QSqlQueryModel* avis::shownumavis()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select NUMAVIS from AVIS");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        return model;
}
