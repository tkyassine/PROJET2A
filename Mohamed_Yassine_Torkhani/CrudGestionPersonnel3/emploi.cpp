#include "emploi.h"
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
emploi::emploi()
{
    heure_debut="";
    heure_sortie="";
    heure_pause="";
    duree_pause="";
    id=0;
}
emploi::emploi(int id,QString heure_debut,QString heure_sortie,QString heure_pause,QString duree_pause)
{
    this->id=id;
    this->heure_debut=heure_debut;
    this->heure_sortie=heure_sortie;
    this->heure_pause=heure_pause;
    this->duree_pause=duree_pause;

}
bool emploi:: ajouter_emploi()
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("INSERT INTO emploi(id,heure_debut,heure_sortie,heure_pause,duree_pause) VALUES(:id,:heure_debut,:heure_sortie,:heure_pause,:duree_pause)");
    query.bindValue(":id",res);
    query.bindValue(":heure_debut",heure_debut);
    query.bindValue(":heure_sortie",heure_sortie);
    query.bindValue(":heure_pause",heure_pause);
    query.bindValue(":duree_pause",duree_pause);
    if(id=  NULL || heure_debut.isEmpty() || heure_sortie.isEmpty() || heure_pause.isEmpty() || duree_pause.isEmpty() )
    {
        QMessageBox::critical(nullptr, QObject::tr("Verification d'ajout"),
             QObject::tr("Erreur champ vide!.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

    return query.exec();
}
QSqlQueryModel* emploi:: afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("select * from emploi " );
        return (model);
}
bool emploi::rechercher(int id)
{
    QSqlQuery query;
    int count=0;
    bool test=0;
    QString res=QString::number(id);
    if(query.exec("select * from emploi where id='"+res+"'"))
    {
        while (query.next()) {
            count++;
        }
        if(count>=1){
            test=1;
        return test;
        }
    }
    return test;

}
bool emploi ::supprimer_emploi(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("delete from emploi where id= :id");
    query.bindValue(":id", res);
    return    query.exec();
}
QSqlQueryModel * emploi::chercher(int id)
 {
    bool queryresult ;
     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
      QString res=QString::number(id);
     query.prepare("select * from emploi WHERE id=:id");

     query.bindValue(":id",res);

      queryresult = query.exec();
      if ( queryresult ){
    model->setQuery(query);
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("heure de debut"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("heure de sortie"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("heure de pause"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("duree de pause"));

     return model;

          }
      else {
          model = nullptr;
          return model;

            }
}
bool emploi::update()
{

      QSqlQuery query;
        int first=0 ;
            QString res1=QString::number(id);

              QString editer ="Update emploi set" ;
            query.bindValue(":heure_debut",heure_debut);
            if(heure_debut!="")
            {
                editer+=" HEURE_DEBUT = :heure_debut" ;
                first=1 ;
            }

            query.bindValue(":heure_sortie",heure_sortie);
            if(heure_sortie!=""&& first!=0)
                editer+=" ,HEURE_SORTIE= :heure_sortie" ;
            else if (heure_sortie!=""&&first==0)
              {
                editer+=" HEURE_SORTIE= :heure_sortie" ;
                first=1 ;
              }
            query.bindValue(":heure_pause",heure_pause);
                            if(heure_pause!=""&& first!=0)
                               editer+=" ,HEURE_PAUSE= :heure_pause" ;
                               else if (heure_pause!="" && first==0)
                               {
                                   editer+=" HEURE_PAUSE = :heure_pause" ;
                                   first=1 ;
                                }
           query.bindValue(":duree_pause",duree_pause);
                              if(duree_pause!=""&& first!=0)
                                  editer+=" ,DUREE_PAUSE= :duree_pause" ;
                                  else if (duree_pause!="" && first==0)
                                      {
                                          editer+=" DUREE_PAUSE = :duree_pause" ;
                                          first=1 ;
                                       }

                   editer+=" where ID = :id" ;



                   QByteArray chaine = editer.toLocal8Bit();
                   const char *final = chaine.data();


                query.prepare(final);


                query.bindValue(":id",QVariant(res1).toInt());



                query.bindValue(":heure_debut",heure_debut);
                query.bindValue(":heure_sortie",heure_sortie);
                query.bindValue(":heure_pause",heure_pause);
                query.bindValue(":duree_pause",duree_pause);


             return query.exec();
}

