#include "client.h"
#include <QDebug>
client::client()
{
    id="";
    nom="";
    prenom="";
    sexe="";
    dateDeNaissance="";
    adressemail="";
}

client::client(QString id,QString nom,QString prenom,QString sexe,QString dateDeNaissance, QString adressemail)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->sexe=sexe;
    this->dateDeNaissance=dateDeNaissance;
    this->adressemail=adressemail;
}


QString client::getNom(){return nom;}
QString client::getPrenom(){return this->prenom;}
QString client::getDateDeNaissance(){return dateDeNaissance;}
QString client::getSex(){return sexe;}
QString client::getID(){return id;}
QString client::getmail(){return adressemail;}

void client::setNom(QString value){this->nom=value;}
void client::setPrenom(QString value){this->prenom=value;}
void client::setDateDeNaissance(QString value){this->dateDeNaissance=value;}
void client::setSex(QString value){this->sexe= value;}
void client::setID(QString value){this->id=value;}
void client::setmail(QString adressemail){this->adressemail=adressemail;}

bool client::ajouter(client C)
{
QSqlQuery query;
// QString res= QString::number(C.getID());
query.prepare("INSERT INTO CLIENT (ID, NOM, PRENOM, SEXE, DATE_DE_NAISSANCE ,ADRESSEMAIL) "
                    "VALUES (:id, :nom, :prenom, :sexe, :date_de_naissance, :adressemail)");
query.bindValue(":id",C.getID());
query.bindValue(":nom",C.getNom());
query.bindValue(":prenom",C.getPrenom());
query.bindValue(":sexe",C.getSex());
query.bindValue(":date_de_naissance",C.getDateDeNaissance());
 query.bindValue(":adressemail",C.getmail());
return query.exec();
}

QSqlQueryModel *client::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_de_naissance"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("adressemail"));
return model;
}


bool client::supprimer(QString idd)
{
QSqlQuery query;
//QString res= QString::number(idd);
query.prepare("DELETE from client where ID = :id ");
query.bindValue(":id", idd);
return    query.exec();
}


bool client::modifier(client C)
{
QSqlQuery query;

   query.prepare("UPDATE CLIENT SET NOM =:nom , PRENOM =:prenom , SEXE= :sexe , DATE_DE_NAISSANCE= :DateDeNaissance , ADRESSEMAIL =:adressemail  WHERE ID =:id ");
   query.bindValue(":id", C.getID());
   query.bindValue(":nom", C.getNom());
   query.bindValue(":prenom", C.getPrenom());
   query.bindValue(":sexe", C.getSex());
   query.bindValue(":DateDeNaissance", C.getDateDeNaissance());
    query.bindValue(":adressemail", C.getmail());
return query.exec();
}




QSqlQueryModel *client::tri()
{
QSqlQuery *q = new QSqlQuery();
QSqlQueryModel *model = new QSqlQueryModel();
q->prepare("SELECT * FROM CLIENT ORDER BY NOM");
q->exec();
model->setQuery(*q);
return model;
}


QSqlQueryModel *client::recherchernomcient(QString nomc)
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select id,nom,prenom,sexe,date_de_naissance,adressemail from client where id like '"+nomc+"%' or nom like '"+nomc+"%'  or prenom like '"+nomc+"%' or sexe like '"+nomc+"%' or date_de_naissance like '"+nomc+"%' or adressemail like '"+nomc+"%';");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_de_naissance"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("adressemail"));
return model;
}


QSqlQueryModel *client::showid()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select ID from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    return model;

}
QSqlQueryModel *client::shownomclient()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select NOM from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom "));
    return model;

}
