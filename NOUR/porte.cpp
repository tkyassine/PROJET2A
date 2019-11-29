#include "porte.h"
#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

porte::porte(){
    num = 0;
    etat = 0;
}

porte::porte(int num,int etat){
    this->num = num;
    this->etat = etat;
}

int porte::getNum(){
    return num;
}

int porte::getEtat(){
    return etat;
}
bool porte::ajouter(){
    QSqlQuery query;
    QString numS = QString::number(num);
    QString etatS = QString::number(etat);
    query.prepare("INSERT INTO porte(num, etat) VALUES (:numS, :etatS)");
    query.bindValue(":numS", numS);
    query.bindValue(":etatS", etatS);
    return query.exec();
}

QSqlQueryModel *  porte::afficher(QString rechTxt){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM porte WHERE num LIKE '%" + rechTxt + "%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numero"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Etat"));
    return model;
}

bool porte::supprimer(int num){
    QSqlQuery query;
    QString numS = QString::number(num);
    query.prepare("DELETE FROM porte WHERE num = :numS");
    query.bindValue(":numS", numS);
    return query.exec();
}

bool porte::modifier(porte p){
    QSqlQuery query;
    QString numS = QString::number(p.getNum());
    QString etatS = QString::number(p.getEtat());
    query.prepare("UPDATE porte SET etat = :etatS WHERE num = :numS");
    query.bindValue(":numS", numS);
    query.bindValue(":etatS", etatS);
    return query.exec();
}
