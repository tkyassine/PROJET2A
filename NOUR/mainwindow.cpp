#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "porte.h"
#include "ventilateur.h"
#include "QMessageBox"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabP->setModel(tmpP.afficher(ui->rechTxtP->text()));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_ajouterButtonP_clicked(){
    int num = ui->numAjoutP->text().toInt();
    int etat = ui->etatAjoutP->text().toInt();
    porte p(num,etat);
    bool test = p.ajouter();
    if(test){
        ui->tabP->setModel(tmpP.afficher(ui->rechTxtP->text()));
        qDebug() <<"Porte ajoute";
    }else{
       qDebug() <<"Erreur d'ajout";
    }
}

void MainWindow::on_suppButtonP_clicked(){
    int num = ui->numSuppP->text().toInt();
    bool test = tmpP.supprimer(num);
    if(test){
        ui->tabP->setModel(tmpP.afficher(ui->rechTxtP->text()));
    }
}

void MainWindow::on_modifButtonP_clicked(){
    int num = ui->numModifP->text().toInt();
    int etat = ui->etatModifP->text().toInt();
    porte p(num,etat);
    bool test = tmpP.modifier(p);
    if(test){
        ui->tabP->setModel(tmpP.afficher(ui->rechTxtP->text()));
    }
}


void MainWindow::on_rechTxtP_textEdited(){
    ui->tabP->setModel(tmpP.afficher(ui->rechTxtP->text()));
}

void MainWindow::on_ajouterButtonV_clicked(){
    int num = ui->numAjoutV->text().toInt();
    int etat = ui->etatAjoutV->text().toInt();
    ventilateur v(num,etat);
    bool test = v.ajouter();
    if(test){
        ui->tabV->setModel(tmpV.afficher(ui->rechTxtV->text()));
        qDebug() <<"Porte ajoute";
    }else{
       qDebug() <<"Erreur d'ajout";
    }
}

void MainWindow::on_suppButtonV_clicked(){
    int num = ui->numSuppV->text().toInt();
    bool test = tmpV.supprimer(num);
    if(test){
        ui->tabV->setModel(tmpV.afficher(ui->rechTxtV->text()));
    }
}

void MainWindow::on_modifButtonV_clicked(){
    int num = ui->numModifV->text().toInt();
    int etat = ui->etatModifV->text().toInt();
    ventilateur v(num,etat);
    bool test = tmpV.modifier(v);
    if(test){
        ui->tabV->setModel(tmpV.afficher(ui->rechTxtV->text()));
    }
}


void MainWindow::on_rechTxtV_textEdited(){
    ui->tabV->setModel(tmpV.afficher(ui->rechTxtV->text()));
}

void MainWindow::on_tabWidget_4_currentChanged(){
    ui->tabP->setModel(tmpP.afficher(ui->rechTxtP->text()));
}

void MainWindow::on_tabWidget_5_currentChanged(){
    ui->tabV->setModel(tmpV.afficher(ui->rechTxtV->text()));
}

