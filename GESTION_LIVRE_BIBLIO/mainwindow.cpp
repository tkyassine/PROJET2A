#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "livre.h"
#include "rayon.h"
#include "QMessageBox"
#include <QDebug>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "mailing/SmtpMime"

void MainWindow::setAjoutComboL(){
    QSqlQuery query;
    query.prepare("SELECT num FROM biblio");
    QString num;
    ui->ajoutComboLiv->clear();
    if(query.exec()){
        while(query.next()){
            num = query.value(0).toString();
            ui->ajoutComboLiv->addItem(num);
        }
    }
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    setAjoutComboL();
    ui->tabLiv->setModel(tmpL.afficher(ui->triComboLiv->currentText(), ui->rechComboLiv->currentText(), ui->rechTxtLiv->text()));
    ui->tabR->setModel(tmpR.afficher(ui->triComboR->currentText(), ui->rechComboR->currentText(), ui->rechTxtR->text()));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_modifierButtonR_clicked(){
    QString nR;
    QString col;
    QModelIndex index;
    QModelIndexList selection = ui->tabR->selectionModel()->selectedIndexes();
    for(int i = 0; i < selection.count(); i++){
        index = selection.at(i);
        nR = QVariant(ui->tabR->model()->index(index.row(), 0).data()).toString();
        col = ui->tabR->model()->headerData(index.column(), Qt::Horizontal).toString();
        tmpR.modifier(nR, ui->modifTxtR->text(), col);
        ui->tabR->setModel(tmpR.afficher(ui->triComboR->currentText(), ui->rechComboR->currentText(), ui->rechTxtR->text()));
    }
}

void MainWindow::on_supprimerButtonR_clicked(){
    QString nR;
    bool test = true;
    QModelIndex index;
    QModelIndexList selection = ui->tabR->selectionModel()->selectedIndexes();
    for(int i = 0; i < selection.count(); i++){
        index = selection.at(i);
        nR = QVariant(ui->tabR->model()->index(index.row(), 0).data()).toString();
        test = tmpR.supprimer(nR);
        ui->tabR->setModel(tmpR.afficher(ui->triComboR->currentText(), ui->rechComboR->currentText(), ui->rechTxtR->text()));
    }
    if(!test){
        QMessageBox::critical(nullptr, QObject::tr("ERREUR DE SUPPRESSION"),
                QObject::tr("Erreur - Le rayon n'est pas vide\n"
                        "Impossible d'effectuer la suppression sans vider le rayon"), QMessageBox::Cancel);
    }
}

void MainWindow::on_rafraichirR_clicked(){
    ui->tabR->setModel(tmpR.afficher(ui->triComboR->currentText(), ui->rechComboR->currentText(), ui->rechTxtR->text()));
}

void MainWindow::on_triComboR_currentIndexChanged(){
    ui->tabR->setModel(tmpR.afficher(ui->triComboR->currentText(), ui->rechComboR->currentText(), ui->rechTxtR->text()));
}

void MainWindow::on_rechComboR_currentIndexChanged(){
    ui->tabR->setModel(tmpR.afficher(ui->triComboR->currentText(), ui->rechComboR->currentText(), ui->rechTxtR->text()));
}

void MainWindow::on_rechTxtR_textEdited(){
    ui->tabR->setModel(tmpR.afficher(ui->triComboR->currentText(), ui->rechComboR->currentText(), ui->rechTxtR->text()));
}

void MainWindow::on_ajouterButtonR_clicked(){
    if(tmpR.ajouter()){
        ui->tabR->setModel(tmpR.afficher(ui->triComboR->currentText(), ui->rechComboR->currentText(), ui->rechTxtR->text()));
    }else{
        QMessageBox::critical(nullptr, QObject::tr("ERREUR D'AJOUT"),
                    QObject::tr("Erreur - Objet déja ajouté\n"
                                "Veuillez modifier l'objet existant"), QMessageBox::Cancel);
    }
}

void MainWindow::on_modifierButtonLiv_clicked(){
    QString codL;
    QString col;
    QModelIndex index;
    QModelIndexList selection = ui->tabLiv->selectionModel()->selectedIndexes();
    for(int i = 0; i < selection.count(); i++){
        index = selection.at(i);
        codL = QVariant(ui->tabLiv->model()->index(index.row(), 0).data()).toString();
        col = ui->tabLiv->model()->headerData(index.column(), Qt::Horizontal).toString();
        tmpL.modifier(codL, ui->modifTxtLiv->text(), col);
        ui->tabLiv->setModel(tmpL.afficher(ui->triComboLiv->currentText(), ui->rechComboLiv->currentText(), ui->rechTxtLiv->text()));
    }
}

void MainWindow::on_supprimerButtonLiv_clicked(){
    QString codL;
    QModelIndex index;
    QModelIndexList selection = ui->tabLiv->selectionModel()->selectedIndexes();
    for(int i = 0; i < selection.count(); i++){
        index = selection.at(i);
        codL = QVariant(ui->tabLiv->model()->index(index.row(), 0).data()).toString();
        tmpL.supprimer(codL);
        ui->tabLiv->setModel(tmpL.afficher(ui->triComboLiv->currentText(), ui->rechComboLiv->currentText(), ui->rechTxtLiv->text()));
    }
}

void MainWindow::on_rafraichirLiv_clicked(){
    QSqlQuery q;
    setAjoutComboL();
    ui->tabLiv->setModel(tmpL.afficher(ui->triComboLiv->currentText(), ui->rechComboLiv->currentText(), ui->rechTxtLiv->text()));
}

void MainWindow::on_triComboLiv_currentIndexChanged(){
    ui->tabLiv->setModel(tmpL.afficher(ui->triComboLiv->currentText(), ui->rechComboLiv->currentText(), ui->rechTxtLiv->text()));
}

void MainWindow::on_rechComboLiv_currentIndexChanged(){
    ui->tabLiv->setModel(tmpL.afficher(ui->triComboLiv->currentText(), ui->rechComboLiv->currentText(), ui->rechTxtLiv->text()));
}

void MainWindow::on_rechTxtLiv_textEdited(){
    ui->tabLiv->setModel(tmpL.afficher(ui->triComboLiv->currentText(), ui->rechComboLiv->currentText(), ui->rechTxtLiv->text()));
}

void MainWindow::on_ajouterButtonLiv_clicked(){
    if(ui->ajoutComboLiv->currentText() != ""){
        if(tmpL.ajouter(ui->ajoutComboLiv->currentText())){
            ui->tabLiv->setModel(tmpL.afficher(ui->triComboLiv->currentText(), ui->rechComboLiv->currentText(), ui->rechTxtLiv->text()));
        }
    }else{
        QMessageBox::critical(nullptr, QObject::tr("ERREUR D'AJOUT"),
                    QObject::tr("Erreur - Aucun rayon existant pour y ajouter le livre\n"
                                "Veuillez ajouter un rayon"), QMessageBox::Cancel);
    }
}

void MainWindow::on_recommander_clicked(){
    bool test = false;
    QSqlQuery queryMNP, queryLib;
    QString codL = "";
    QModelIndex index;
    QModelIndexList selection = ui->tabLiv->selectionModel()->selectedIndexes();
    for(int i = 0; i < selection.count(); i++){
        index = selection.at(i);
        codL = QVariant(ui->tabLiv->model()->index(index.row(), 0).data()).toString();
        MimeMessage message;
        if(codL == ""){
            QMessageBox::critical(nullptr, QObject::tr("ERREUR DE RECOMMANDATION"),
                        QObject::tr("Erreur - Veuillez selectionner le livre à recommander\n"
                                    ""), QMessageBox::Cancel);
        }else{
            qDebug() << "1";
            queryLib.prepare("SELECT * FROM livre WHERE code = :codL");
            queryLib.bindValue(":codL", codL);
            if(queryLib.exec()){
                if(queryLib.next()){
                    queryMNP.prepare("SELECT mail, nom, prenom FROM client WHERE abonne = 1");
                    if(queryMNP.exec()){
                        while(queryMNP.next()){
                            SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
                            smtp.setUser("mariem.ayadi@esprit.tn");
                            smtp.setPassword("marioumaayadi27..");
                            message.setSender(new EmailAddress("mariem.ayadi@esprit.tn", "Biblio-Tec Newsletter"));
                            message.addRecipient(new EmailAddress(queryMNP.value(0).toString(), queryMNP.value(1).toString() + " " + queryMNP.value(2).toString()));
                            message.setSubject("Recommandation: Découvrez le livre "+ queryLib.value(1).toString());
                            MimeText text;
                            text.setText("\nLe livre " + queryLib.value(1).toString() + " vous à été recommandé\n Auteur : " + queryLib.value(2).toString() + "\n Categorie : " + queryLib.value(3).toString() + "\n Code Barre : " + codL + "\n - Biblio-Tec vous souhaite une joyeuse lecture!\n");
                            message.addPart(&text);
                            smtp.connectToHost();
                            smtp.login();
                            if(smtp.sendMail(message)){
                                test = true;
                            }else{
                                test = false;
                            }
                            smtp.quit();
                        }
                    }
                }
            }
        }
    }
    if(test){
        QMessageBox::information(this, "RECOMMANDATION EFFECTUEE", "Le livre " + queryLib.value(1).toString() + " vient d'étre recommandé aux abonnés");
    }else{
        QMessageBox::critical(this, "RECOMMANDATION NON EFFECTUEE", "Erreur - Mails non envoyés");
    }
}

void MainWindow::on_tabW_currentChanged(int index){
    setAjoutComboL();
    ui->tabLiv->setModel(tmpL.afficher(ui->triComboLiv->currentText(), ui->rechComboLiv->currentText(), ui->rechTxtLiv->text()));
    ui->tabR->setModel(tmpR.afficher(ui->triComboR->currentText(), ui->rechComboR->currentText(), ui->rechTxtR->text()));
    if(index == 2){
        QSqlQuery query, queryCount, queryTotal;
        QBarSet* tab[50];
        QBarSeries * series = new QBarSeries();
        QChart * chart;
        QStringList categories;
        queryTotal.prepare("SELECT COUNT(*) FROM livre");
        queryTotal.exec();
        while(queryTotal.next()){
            query.prepare("SELECT DISTINCT(categorie) FROM livre");
            query.exec();
            int nbCat = 0, nb;
            while(query.next()){
                queryCount.prepare("SELECT COUNT(*) FROM livre WHERE categorie = :cat");
                queryCount.bindValue(":cat", query.value(0).toString());
                queryCount.exec();
                while(queryCount.next()){
                    nb = queryCount.value(0).toInt() * 100 / queryTotal.value(0).toInt();
                    QString nbS = QString::number(nb);
                    tab[nbCat] = new QBarSet(query.value(0).toString() + "\n" + queryCount.value(0).toString() + " (" + nbS + "%)");
                    *tab[nbCat] << nb;
                    series->append(tab[nbCat]);
                    nbCat++;
                }
            }
            chart = new QChart();
            chart->addSeries(series);
            chart->setTitle("Statistique des livres par catégorie");

            chart->setAnimationOptions(QChart::AllAnimations);
            categories << "Nombre de livres total " + queryTotal.value(0).toString();
        }
        QBarCategoryAxis *axis=new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis,series);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        QChartView *chartview =new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        QPalette pal=qApp->palette();
        pal.setColor(QPalette::Window,QRgb(0xffffff));
        pal.setColor(QPalette::WindowText,QRgb(0x121212));
        qApp->setPalette(pal);
        ui->statBox->setChart(chart);
    }
}
