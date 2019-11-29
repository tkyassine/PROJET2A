#include <string>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include "rayon.h"

Rayon::Rayon(){
    nR = cR = "";
}

Rayon::Rayon(QString nR, QString cR){
    this->nR = nR;
    this->cR = cR;
}

QString Rayon::getNR(){
    return nR;
}

QString Rayon::getCR(){
    return cR;
}

QSqlQueryModel * Rayon::afficher(QString triCombo, QString rechCombo, QString rechTxt){
    if(rechCombo == "Numero"){
        rechCombo = "num";
    }
    if(triCombo == "Numero"){
        triCombo = "num";
    }
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM biblio WHERE " + rechCombo + " LIKE '%" + rechTxt + "%' ORDER BY (" + triCombo + ")");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numero"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Capacite"));
    return model;
}

bool Rayon::modifier(QString nR, QString nouv, QString col){
    if(col == "Numero"){
        col = "num";
        if(nouv < "0" || nouv > "99999"){
            QMessageBox::critical(nullptr, QObject::tr("CONTROLE DE SAISIE"),
                        QObject::tr("Erreur - Le numero du rayon doit etre\n"
                                    "compris entre 0 et 99999!"), QMessageBox::Cancel);
            return false;
        }
    }
    if(col == "Capacite"){
        if(nouv < "0" || nouv > "99999"){
            QMessageBox::critical(nullptr, QObject::tr("CONTROLE DE SAISIE"),
                        QObject::tr("Erreur - La capacite du rayon doit etre\n"
                                    "comprise entre 0 et 99999!"), QMessageBox::Cancel);
            return false;
        }
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM livre WHERE numbiblio = :nR");
        query.bindValue(":nR", nR);
        if(query.exec()){
            while(query.next()){
                if(query.value(0).toString() > nouv){
                    QMessageBox::critical(nullptr, QObject::tr("ERREUR DE MODIFICATION"),
                                QObject::tr("Erreur - La capacité du rayon doit etre supérieure\n"
                                            "au nombre de livres qui lui appartiennent!"), QMessageBox::Cancel);
                    return false;
                }
            }
        }
    }
    QSqlQuery query;
    query.prepare("UPDATE biblio SET " + col + " = :nouv WHERE num = :nR");
    query.bindValue(":nouv", nouv);
    query.bindValue(":nR", nR);
    int test = query.exec();
    if(!test){
        QSqlQuery query2;
        query2.prepare("SELECT COUNT(*) FROM livre WHERE numbiblio = " + nR);
        if(query2.exec()){
            while(query2.next()){
                if(query2.value(0).toString() != "0"){
                    QMessageBox::critical(nullptr, QObject::tr("[MODIFICATION D'UN CHAMPS"),
                                QObject::tr("Erreur - Le rayon n'est pas vide\n"
                                            "Impossible de modifier le numero du rayon sans le vider"), QMessageBox::Cancel);
                }else{
                    QMessageBox::critical(nullptr, QObject::tr("[MODIFICATION D'UN CHAMPS"),
                                QObject::tr("Erreur - Le numero du rayon doit etre unique\n"
                                            ""), QMessageBox::Cancel);
                }
            }
        }
    }
    return test;
}

bool Rayon::supprimer(QString nR){
    QSqlQuery query;
    query.prepare("DELETE FROM biblio WHERE num = :nR");
    query.bindValue(":nR", nR);
    return query.exec();
}

bool Rayon::ajouter(){
    QSqlQuery query;
    query.prepare("INSERT INTO biblio VALUES(-1, 0)");
    return query.exec();
}
