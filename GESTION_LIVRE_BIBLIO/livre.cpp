#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "QMessageBox"
#include <QDebug>
#include "livre.h"

livre::livre(){
    codL = libL = autL = catL = "";
    nBL = 0;
}

livre::livre(QString codL, QString libL, QString autL, QString catL, int nBL){
    this->codL = codL;
    this->libL = libL;
    this->autL = autL;
    this->catL = catL;
    this->nBL = nBL;
}

QString livre::getCodL(){
    return codL;
}

QString livre::getLibL(){
    return libL;
}

QString livre::getAutL(){
    return autL;
}

QString livre::getCatL(){
    return catL;
}

int livre::getNBL(){
    return nBL;
}

QSqlQueryModel * livre::afficher(QString triTxt, QString rechTxt, QString rechValue){
    if(triTxt == "Code Barre"){
        triTxt = "code";
    }
    if(triTxt == "Numero Rayon"){
        triTxt = "numbiblio";
    }
    if(triTxt == "Numero Commande"){
        triTxt = "numcommande";
    }
    if(rechTxt == "Code Barre"){
        rechTxt = "code";
    }
    if(rechTxt == "Numero Rayon"){
        rechTxt = "numbiblio";
    }
    if(rechTxt == "Numero Commande"){
        rechTxt = "numcommande";
    }
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM livre WHERE " + rechTxt + " LIKE '%" + rechValue + "%' ORDER BY (" + triTxt + ")");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("Code Barre"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Libelle"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Auteur"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("Categorie"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Numero Rayon"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("Numero Commande"));
    return model;
}

bool livre::modifier(QString codL, QString nouv, QString col){
        if(col == "Categorie" || col == "Auteur" || col == "Libelle"){
            if(nouv.size() > 20){
                QMessageBox::critical(nullptr, QObject::tr("CONTROLE DE SAISIE"),
                            QObject::tr("Erreur - La taille du champs séléctionné ne doit\n"
                                        "pas dépasser 20 caractères!"), QMessageBox::Cancel);
                return false;
            }
        }
        if(col == "Code Barre"){
            col = "code";
            if(nouv.size() > 30){
                QMessageBox::critical(nullptr, QObject::tr("CONTROLE DE SAISIE"),
                            QObject::tr("Erreur - La taille du code barre ne doit\n"
                                        "pas dépasser 30 caractères!"), QMessageBox::Cancel);
                return false;
            }
        }
        if(col == "Numero Rayon"){
            QSqlQuery query;
            col = "numbiblio";
            query.prepare("SELECT num FROM biblio");
            bool test = false;
            if(query.exec()){
                while(query.next()){
                    if(query.value(0).toString() == nouv){
                        test = true;
                    }
                }
            }
            if(!test){
                QMessageBox::critical(nullptr, QObject::tr("ERREUR DE REFERENCIATION"),
                            QObject::tr("Erreur - La numero du rayon est introuvable\n"
                                        "dans la liste des Rayons!"), QMessageBox::Cancel);
                return false;
            }
            QSqlQuery query1, query2, query3;
            query1.prepare("SELECT COUNT(*) FROM livre WHERE numbiblio = :nouv");
            query1.bindValue(":nouv", nouv);
            if(query1.exec()){
                query2.prepare("SELECT capacite FROM biblio WHERE num = " + nouv);
                if(query2.exec()){
                    while(query2.next() && query1.next()){
                        if(query1.value(0).toInt() + 1 > query2.value(0).toInt()){
                            QMessageBox::critical(nullptr, QObject::tr("ERREUR D'AJOUT"),
                                        QObject::tr("Erreur - La capacité du Rayon selectionné\n"
                                                    "à atteint ses limites!"), QMessageBox::Cancel);
                            return false;
                        }
                    }
                }
            }
        }
        if(col == "Numero Commande"){
            col = "numcommande";
            QSqlQuery query;
            query.prepare("SELECT num FROM commande");
            bool test = false;
            if(query.exec()){
                while(query.next()){
                    if(query.value(0).toString() == nouv){
                        test = true;
                    }
                }
            }
            if(!test){
                QMessageBox::critical(nullptr, QObject::tr("ERREUR DE REFERENCIATION"),
                            QObject::tr("Erreur - Le numero de commande est introuvable\n"
                                        "dans la liste des commandes!"), QMessageBox::Cancel);
                return false;
            }
        }
        QSqlQuery query;
        query.prepare("UPDATE livre SET " + col + " = :nouv WHERE code = :codL");
        query.bindValue(":nouv", nouv);
        query.bindValue(":codL", codL);
        int test = query.exec();
        if(!test){
            QMessageBox::critical(nullptr, QObject::tr("[MODIFICATION D'UN CHAMPS"),
                        QObject::tr("Erreur - Le code barre du livre doit etre unique\n"
                                    ""), QMessageBox::Cancel);
        }
        return test;
}

bool livre::supprimer(QString codL){
    QSqlQuery query;
    query.prepare("DELETE FROM livre WHERE code = :codL");
    query.bindValue(":codL", codL);
    return query.exec();
}

bool livre::ajouter(QString numRayon){
    QSqlQuery query1, query2, query3;
    bool test = false;
    QString num1, num2, num3;
    num1 = num2 = num3 = numRayon;
    query1.prepare("SELECT COUNT(*) FROM livre WHERE numbiblio = :num1");
    query1.bindValue(":num1", num1);
    if(query1.exec()){
        query2.prepare("SELECT capacite FROM biblio WHERE num = " + num2);
        if(query2.exec()){
            while(query2.next() && query1.next()){
                if(query1.value(0).toInt() + 1 > query2.value(0).toInt()){
                    QMessageBox::critical(nullptr, QObject::tr("[ERREUR D'AJOUT"),
                                QObject::tr("Erreur - La capacité du Rayon selectionné\n"
                                            "à atteint ses limites!"), QMessageBox::Cancel);
                    return false;
                }else{
                    query3.prepare("INSERT INTO livre(code, libelle, auteur, categorie, numbiblio) VALUES('CODE', 'LIBELLE', 'AUTEUR', 'CATEGORIE', " + num3 +")");
                    test = query3.exec();
                    if(!test){
                        QMessageBox::critical(nullptr, QObject::tr("ERREUR D'AJOUT"),
                                    QObject::tr("Erreur - Objet déja ajouté\n"
                                                "Veuillez modifier l'objet existant"), QMessageBox::Cancel);
                    }
                }
            }
        }
    }
    return test;
}

