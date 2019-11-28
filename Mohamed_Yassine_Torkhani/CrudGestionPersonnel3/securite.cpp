#include "securite.h"
#include "personnel.h"
#include <QString>
#include <QSqlQuery>
securite::securite():personnel()
{
    statut_familiale="";
    age=0;
}

securite& securite:: operator=(personnel& s)
{
    this->cin=s.get_cin();
    this->nom=s.get_nom();
    this->prenom=s.get_prenom();
    this->adresse=s.get_adresse();
    this->age=s.getage();
    this->tel=s.get_numtel();
    this->statut_familiale=s.getstatut();
    this->idposte=s.get_idposte();
    return *this;

}

QSqlQueryModel *securite::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("select * from personnel_securite" );
        return (model);
}
QSqlQueryModel * securite::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from personnel_securite order by age ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("tel"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("statut_familiale"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("idposte"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("formation"));



    return model;
}
bool securite::supprimerSec(int cin)
{

QSqlQuery query;
query.prepare("delete from personnel_securite where cin= :cin ");
query.bindValue(":cin", cin);
return    query.exec();
}
