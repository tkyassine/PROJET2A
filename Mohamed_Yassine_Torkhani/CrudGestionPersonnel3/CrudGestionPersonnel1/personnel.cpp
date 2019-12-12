#include "personnel.h"
#include <QSqlQuery>

personnel::personnel()
{
     nom="";
     prenom="";
     adresse="";
     tel=0;
     cin=0;
     statut_familiale="";
     age=0;
     idposte="";
}
personnel::personnel(int cin,QString nom,QString prenom,QString adresse,int tel,int age,QString statut_familiale){
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->tel=tel;
    this->age=age;
    this->statut_familiale=statut_familiale;
}
QSqlQueryModel *personnel::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("select * from personnel" );
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("age"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("telephone"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("statut familiale"));
        model->setHeaderData(7,Qt::Horizontal,QObject::tr("identifiant"));
        return (model);
}
QSqlQueryModel * personnel::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from personnel order by cin ASC ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("telephone"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("statut familiale"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("identifiant"));
    return model;
}
bool personnel::supprimerPers(int cin)
{
QSqlQuery query;
query.prepare("delete from personnel where cin= :cin ");
query.bindValue(":cin", cin);
return    query.exec();
}
QSqlQueryModel * personnel::chercher(int cin)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from personnel WHERE cin=:cin"));

     query.bindValue(":cin",cin);

      query.exec();
     model->setQuery(query);
     model->setQuery("Select * from personnel order by cin ASC ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("age"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("telephone"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("statut familiale"));
     model->setHeaderData(7,Qt::Horizontal,QObject::tr("identifiant"));
return model;
 }
bool personnel::update()
{

      QSqlQuery query;
        int first=0 ;
            QString res= QString::number(tel);
            QString res1=QString::number(cin);
            QString res3=QString::number(age);
              QString editer ="Update personnel set" ;
            query.bindValue(":nom",nom);
            if(nom!="")
            {
                editer+=" NOM = :nom" ;
                first=1 ;
            }

            query.bindValue(":prenom",prenom);
            if(prenom!=""&& first!=0)
                editer+=" ,PRENOM= :prenom" ;
            else if (prenom!=""&&first==0)
              {
                editer+=" PRENOM= :prenom" ;
                first=1 ;
              }
                 query.bindValue(":adresse",adresse);
                 if(adresse!=""&& first!=0)
                     editer+=" ,ADRESSE= :adresse" ;
                 else if (adresse!="" && first==0)
                 {
                    editer+=" ADRESSE = :adresse" ;
                    first=1 ;
                 }
                 query.bindValue(":age",age);
                 if(res3!=""&& first!=0)
                     editer+=" ,AGE= :age" ;
                 else if (res3!="" && first==0)
                 {
                    editer+=" AGE = :age" ;
                    first=1 ;
                 }
                 query.bindValue(":tel",tel);
                 if(res!=""&& first!=0)
                     editer+=" ,NUMTEL= :tel" ;
                 else if (res!="" && first==0)
                 {
                    editer+=" TEL = :tel" ;
                    first=1 ;
                 }
                 query.bindValue(":statut_familiale",statut_familiale);
                 if(statut_familiale!=""&& first!=0)
                     editer+=" ,STATUT= :statut_familiale" ;
                 else if (statut_familiale!="" && first==0)
                 {
                    editer+=" STATUT = :statut_familiale" ;
                    first=1 ;
                 }

                   editer+=" where CIN = :cin" ;



                   QByteArray chaine = editer.toLocal8Bit();
                   const char *final = chaine.data();


                query.prepare(final);


                query.bindValue(":cin",QVariant(res1).toInt());



                query.bindValue(":nom",nom);
                query.bindValue(":prenom",prenom);
                query.bindValue(":adresse",adresse);
                query.bindValue(":age",age);
                query.bindValue(":tel",tel);
                query.bindValue(":statut",statut_familiale);


             return query.exec();
}

/*
bool personnel :: modifier(QString nv, int cin,int nc){
    QSqlQuery q ;
    q.prepare(" ");

}
*/
