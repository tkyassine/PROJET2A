#include "ventilateur.h"
#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

ventilateur::ventilateur(){
    num = 0;
    etat = 0;
}

ventilateur::ventilateur(int num,int etat){
    this->num = num;
    this->etat = etat;
}

int ventilateur::getNum(){
    return num;
}

int ventilateur::getEtat(){
    return etat;
}
bool ventilateur::ajouter(){
    QSqlQuery query;
    QString numS = QString::number(num);
    QString etatS = QString::number(etat);
    query.prepare("INSERT INTO ventilateur(num, etat) VALUES (:numS, :etatS)");
    query.bindValue(":numS", numS);
    query.bindValue(":etatS", etatS);
    return query.exec();
}

QSqlQueryModel *  ventilateur::afficher(QString rechTxt){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM ventilateur WHERE num LIKE '%" + rechTxt + "%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numero"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Etat"));
    return model;
}

bool ventilateur::supprimer(int num){
    QSqlQuery query;
    QString numS = QString::number(num);
    query.prepare("DELETE FROM ventilateur WHERE num = :numS");
    query.bindValue(":numS", numS);
    return query.exec();
}

bool ventilateur::modifier(ventilateur p){
    QSqlQuery query;
    QString numS = QString::number(p.getNum());
    QString etatS = QString::number(p.getEtat());
    query.prepare("UPDATE ventilateur SET etat = :etatS WHERE num = :numS");
    query.bindValue(":numS", numS);
    query.bindValue(":etatS", etatS);
    return query.exec();
}
