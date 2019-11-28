#include "liste_personnel.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
using namespace std;

liste_personnel::liste_personnel()
{

}
int liste_personnel::ajouter_personnel(int cin,QString nom,QString prenom,QString adresse,int age,int tel,QString statut_familiale , QString idposte)
{

    QSqlQuery query;
    QString res=QString::number(cin);
    QString res1=QString::number(age);
    QString res2=QString::number(tel);
        query.prepare("INSERT INTO PERSONNEL (CIN,NOM,PRENOM,ADRESSE,AGE,TEL,STATUT_FAMILIALE,IDPOSTE) VALUES (:cin,:nom,:prenom, :adresse,:age,:tel,:statut_familiale,:idposte)");
        query.bindValue(":cin",res);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":adresse",adresse);
        query.bindValue(":age",res1);
        query.bindValue(":tel",res2);
        query.bindValue(":idposte",idposte);
        query.bindValue(":statut_familiale",statut_familiale);

if(query.exec())
    return 1;
else return 0;

}
bool liste_personnel::ajouter_personnel(const securite &sec)
{
    QSqlQuery query;
    QString res=QString::number(sec.get_cin());
    QString res2=QString::number(sec.get_numtel());
    QString res3=QString::number(sec.getage());
    query.prepare("INSERT INTO PERSONNEL_SECURITE (CIN,NOM,PRENOM,ADRESSE,AGE,TEL,STATUT_FAMILIALE,IDPOSTE,FORMATION) VALUES (:cin,:nom,:prenom, :adresse,:age,:tel,:statut_familiale,:idposte,:formation)");
    query.bindValue(":cin",res);
    query.bindValue(":tel",res2);
    query.bindValue(":idposte",sec.get_idposte());
    query.bindValue(":nom",sec.get_nom());
    query.bindValue(":prenom",sec.get_prenom());
    query.bindValue(":adresse",sec.get_adresse());
    query.bindValue(":formation",sec.getformation());
    query.bindValue(":age",res3);
    query.bindValue(":statut_familiale",sec.getstatut());


   return( query.exec());

}
