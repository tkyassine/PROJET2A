#include "interface1.h"
#include "ui_interface1.h"
#include "mainwindow.h"
#include "client.h"
#include"avis.h"
#include"interface1.h"

#include <QDebug>

#include"QMessageBox"
#include<QPropertyAnimation>
#include<random>

interface1::interface1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interface1)
{
    ui->setupUi(this);
ui->id3->setModel(c.showid());
ui->id2->setModel(c.showid());
ui->idc->setModel(c.showid());
ui->x1->setModel(a.shownumavis());
ui->x2->setModel(a.shownumavis());
ui->tableView->setModel(c.afficher());
}

interface1::~interface1()
{
    delete ui;
}







void interface1::on_pb_ajouter_clicked()
{


    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
       const int randomStringLength = 6; // assuming you want random strings of 12 characters
       QString randomString;
       for(int i=2; i<randomStringLength; ++i)
       {
           int index = qrand() % possibleCharacters.length();
           QChar nextChar = possibleCharacters.at(index);
           randomString.append(nextChar);
       }
       QString  id =randomString;



      //QString id = ui->id->text();
        QString nom= ui->nom->text();
        QString prenom= ui->prenom->text();
         QString sexe= ui->sexe->text();
          QString date_de_naissance= ui->datenaissance->text();
          QString adressemail=ui->adressemail->text();
  client c(id,nom,prenom,sexe,date_de_naissance,adressemail);
     if((sexe=="masculin")||(sexe=="feminin")){

      bool test= c.ajouter(c);
      if(test)
    {
    QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                      QObject::tr("client ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

   // Smtp* smtp= new Smtp("hajmoussa2368@gmail.com","Hm123456","smtp.gmail.com",465);
    //       smtp->sendMail("hajmoussa2368@gmail.com","amina.mtiri@esprit.tn","le client est ajouté","le client est ajouté");
   }
     else
         QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);}
     else   QMessageBox::critical(nullptr, QObject::tr("non"),
                                  QObject::tr("verifier le sexe !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}



void interface1::on_afficher_clicked()
{
    client c;
        ui->tableView->setModel(c.afficher());
}

void interface1::on_pb_modifier_clicked()
{
    QString id = ui->id3->currentText();
         QString nom= ui->nom_2->text();
         QString prenom= ui->prenom_2->text();
          QString sexe= ui->sexe_2->text();
           QString date_de_naissance= ui->datenaissance_2->text();
           QString adressemail=ui->adressemail_2->text();


     client c(id,nom,prenom,sexe,date_de_naissance,adressemail);


      bool test=c.modifier(c);

      if (test)
      {
      QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                        QObject::tr(" client modifié .\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
 }
}

void interface1::on_pb_supprimer_clicked()
{
    QString id = ui->id2->currentText();
        client c;
        bool test;

                test=c.supprimer(id);

        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                        QObject::tr("client supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (!test)
           { QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
}



void interface1::on_pushButton_clicked()
{
    avis a;
        ui->tableView_avis->setModel(a.afficher_avis());
}

void interface1::on_pushButton_2_clicked()
{
    int numavis = ui->numavis->text().toInt();
        QString dateavis = ui->dateavis->text();
        int etatavis = ui->etat->text().toInt();
       QString idclient = ui->idc->currentText();

       avis a (numavis,dateavis,etatavis,idclient);
         bool test= a.ajouter_avis(a);
         if(test)
       {
       QMessageBox::information(nullptr, QObject::tr("Ajouter un avis"),
                         QObject::tr("avis ajouté.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
     //  smtp_rec* smtp= new smtp_rec("hajmoussa2368@gmail.com","Hm123456","smtp.gmail.com",465);
         //   smtp->sendMail("hajmoussa2368@gmail.com","amina.mtiri@esprit.tn","l'avis est ajouté","l'avis est ajouté");

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Ajouter un avis"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void interface1::on_pushButton_3_clicked()
{

client c;
   ui->tableView->setModel(c.tri());
}

/*void interface1::on_pushButton_4_clicked()
{

        int numavis= ui->numavis_2->text().toInt();
        int numavis=ui->
        QString dateavis = ui->dateavis->text();
        int etatavis = ui->etat->text().toInt();
        QString idclient ;

       avis a (numavis,dateavis,etatavis,idclient);

     bool test= a.modifier_avis(a);
             if (test)
     {
     QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                       QObject::tr(" client modifié .\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);


     }
       else
           QMessageBox::critical(nullptr, QObject::tr("modifier un client"),
                       QObject::tr("erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}



*/




void interface1::on_supprimer_clicked()
{

    int numavis = ui->x2->currentText().toInt();
        avis a;
        bool test;

                test=a.supprimer_avis(numavis);

        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                        QObject::tr("client supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (!test)
           { QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void interface1::on_trier_clicked()
{
    avis a;
        ui->tableView_avis->setModel(a.tri());
}



void interface1::on_Actualiser_clicked()
{ int i;
    ui->tableView->setModel(c.afficher());
    qDebug()<<ui->tableView->model()->rowCount();
    for (i=0;i<ui->tableView->model()->rowCount();i++){
    ui->idc->addItem(ui->tableView->model()->index(i,0).data().toString());
    }
    /*
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery(("select id from client"));
    ui->id2->setModel(model);
    ui->id3->setModel(model);
    */
    }


void interface1::on_Actualiser_2_clicked()
{
    ui->tableView_avis->setModel(a.afficher_avis());
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery(("select numavis from avis"));
    ui->x1->setModel(model);
    ui->x2->setModel(model);
}





/*void interface1::on_combo1_currentTextChanged(const QString &arg1)
{
    client c;
    if(arg1 == "NOM")

          { ui->tableView->setModel(c.tri());}
}
*/




//void interface1::on_statis_clicked()
//{
  //  statis c;
   //interface1 w;
 //  hide();
 // c.exec();
//}

void interface1::on_pushButton_4_clicked()
{  int numavis= ui->x1->currentText().toInt();

    QString dateavis = ui->dateavis->text();
    int etatavis = ui->etat->text().toInt();
    QString idclient ;

   avis a (numavis,dateavis,etatavis,idclient);

 bool test= a.modifier_avis(a);
         if (test)
 {
 QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                   QObject::tr(" client modifié .\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);


 }
   else
       QMessageBox::critical(nullptr, QObject::tr("modifier un client"),
                   QObject::tr("erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}

void interface1::on_idc_activated(const QString &arg1)
{

}

void interface1::on_pushButton_pdf_clicked()
{
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("C:/Users/OMEN/Documents/pdf.pdf");
        QPainter painter;
        painter.begin(&printer);

        QFont font;
        QString nom_complet=ui->lineEdit_nom_complet->text();
        QString inscription=ui->lineEdit_inscription->text();
        font.setPixelSize(35);
        painter.setFont(font);
        painter.setPen(Qt::blue);
        painter.drawText(20,300,"nom complet :");
        painter.drawText(20,500,"inscription :");

        font.setPixelSize(22);
        painter.setFont(font);
        painter.setPen(Qt::black);
        painter.drawText(250,300,nom_complet);
        painter.drawText(250,500,inscription);
        painter.end();
}

void interface1::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tableView->setModel(c.recherchernomcient(arg1));
}
