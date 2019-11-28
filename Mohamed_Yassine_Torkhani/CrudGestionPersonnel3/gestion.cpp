#include "gestion.h"
#include "ui_gestion.h"
#include "personnel.h"
#include "liste_personnel.h"
#include <QDebug>
#include"securite.h"
#include <QSqlQueryModel>
#include "mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include "stati.h"
#include "QPainter"
#include "QPdfWriter"
#include "QDesktopServices"
#include "QtPrintSupport/QPrinter"
#include "QImage"
#include "mailing/SmtpMime"

gestion::gestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion)
{
    ui->setupUi(this);
    mysysteme=new QSystemTrayIcon(this);
    mysysteme->setIcon(QIcon(":/icon.png"));
    mysysteme->setVisible(true);
}

gestion::~gestion()
{
    delete ui;
}
QString gestion::GetRandomString() const{

    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int randomStringLength = 10; // assuming you want random strings of 12 characters

    QString randomString;
    for(int i=0; i<randomStringLength; ++i)
    {
        int index = qrand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    return randomString;
}
void gestion::on_ajouter_clicked()
{
    /////////////////////////////////////////////////

    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    smtp.setUser("houaidafatma.karoui@esprit.tn");
    smtp.setPassword("fatma23703032");

    MimeMessage message;

    message.setSender(new EmailAddress("houaidafatma.karoui@esprit.tn", "HAMDY"));
    message.addRecipient(new EmailAddress("mohamedyassine.torkhani@esprit.tn", "yassine"));
    message.setSubject("SmtpClient for Qt - Demo");

    MimeText text;

    text.setText("Hi,\n SALAM FRERE.\n");

    message.addPart(&text);

    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();
    ///////////////////////////////////////////////////
    personnel e;
         liste_personnel liste;
         //condition de saisie sur cin
              if( ui->cin->text().toInt()<100000|| ui->cin->text().toInt()>999999 || ui->cin->text().toInt()==0 || ui->cin->text()=="   *champ obligatoire")
              { if(ui->cin->text().toInt()==0)
                      ui->cin->setText("   *champ obligatoire");
                  else
                      ui->cin->setText("   age non valide");}
               else
                  e.set_cin(ui->cin->text().toInt());

        //condition de saisie sur nom
          if(ui->nom->text()=="" || ui->nom->text()=="   *champ obligatoire")
              ui->nom->setText("   *champ obligatoire");
           else
              e.set_nom(ui->nom->text());

        //condition de saisie sur prenom
          if(ui->prenom->text()=="" || ui->prenom->text()=="   *champ obligatoire")
              ui->prenom->setText("   *champ obligatoire");
           else
              e.set_prenom(ui->prenom->text());

        //condition de saisie sur adresse
          if(ui->adresse->text()=="" || ui->adresse->text()=="   *champ obligatoire")
              ui->adresse->setText("   *champ obligatoire");
           else
              e.set_adresse(ui->adresse->text());
          //condition de saisie sur age
            if( ui->age->text().toInt()<21 || ui->age->text().toInt()>60| ui->age->text().toInt()==0 || ui->age->text()=="   *champ obligatoire")
            { if(ui->age->text().toInt()==0)
                    ui->age->setText("   *champ obligatoire");
                else
                    ui->age->setText("   age non valide");}
             else
                e.setage(ui->age->text().toInt());
          //condition de saisie sur telephone
               if( ui->telephone->text().toInt()<100000 || ui->telephone->text().toInt()>999999 || ui->telephone->text().toInt()==0 || ui->telephone->text()=="   *champ obligatoire")
               { if(ui->telephone->text().toInt()==0)
                       ui->telephone->setText("   *champ obligatoire");
                   else
                       ui->telephone->setText("   age non valide");}
                else
                   e.set_numtel(ui->telephone->text().toInt());

               //condition de saisie sur statutfamilial
                          if(ui->s_familiale->text()=="" || ui->s_familiale->text()=="   *champ obligatoire")
                              ui->s_familiale->setText("   *champ obligatoire");
                           else
                              e.setstatut(ui->s_familiale->text());

          if(false==ui->formation->isVisible()){

              int cin=ui->cin->text().toInt();
              int age=ui->age->text().toInt();
              int tel=ui->telephone->text().toInt();
              QString nom=ui->nom->text();
              QString statut_familiale=ui->s_familiale->text();
              QString prenom=ui->prenom->text();
              QString adresse=ui->adresse->text();
              QString idposte=GetRandomString();

              if(liste.ajouter_personnel(cin,nom,prenom,adresse,age,tel,statut_familiale,idposte)==1){
                  mysysteme->showMessage(tr("notification"),tr("ajout avec succes"));
                  QMessageBox::information(nullptr, QObject::tr("Ajouter un personnel"),
                                    QObject::tr("personnel ajouté.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                  qDebug()<<"personnel ajoute";
//impression
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/Users/lenovo/Desktop/CrudGestionPersonnel3/pdf1");
    QPainter painter;
    painter.begin(&printer);

    QFont font;
    font.setPixelSize(35);
    painter.setFont(font);
    painter.setPen(Qt::blue);
    painter.drawText(20,300,"cin: ");
    painter.drawText(20,500,"nom:");
    painter.drawText(20,650,"prenom:");
    painter.drawText(20,800,"adresse:");
    painter.drawText(20,1000,"age:");
    painter.drawText(20,1250,"telephone:");
    painter.drawText(20,1450,"statut familiale:");
    painter.drawText(20,1650,"identifiant:");
    int cin=ui->cin->text().toInt();
    QString cin_pdf=QString::number(cin);

    int age=ui->age->text().toInt();
    QString age_pdf=QString::number(age);

    int tel=ui->telephone->text().toInt();
    QString tel_pdf=QString::number(tel);

    QString nom_pdf=ui->nom->text();
    QString prenom_pdf=ui->prenom->text();
    QString adresse_pdf=ui->adresse->text();
    QString statut_pdf=ui->s_familiale->text();

    font.setPixelSize(15);
    painter.setFont(font);
    painter.setPen(Qt::black);
    painter.drawText(20,350,cin_pdf);
    painter.drawText(20,550,nom_pdf);
    painter.drawText(20,700,prenom_pdf);
    painter.drawText(20,850,adresse_pdf);
    painter.drawText(20,1050,age_pdf);
    painter.drawText(20,1300,tel_pdf);
    painter.drawText(20,1700,statut_pdf);


    QImage image("C:/Users/lenovo/Desktop/CrudGestionPersonnel3");
    painter.drawImage(100,50,image);

    painter.end();

    qDebug()<<"le pdf a ete cree";
    QMessageBox::information(this,"pdf cree","ce pdf a ete cree");

                  ui->message->setText("PDF CREER");
//fin impression
              }
              else {
                  ui->message->setText("Erreur : personnel non  ajoute");
                  qDebug()<<"personnel  pas ajoute";}


          }
          else if(true==ui->formation->isVisible())
         {//securite
             securite sec;
             sec=e;
             //condition de saisie sur formation
                        if(ui->formation->text()=="" || ui->formation->text()=="   *champ obligatoire")
                            ui->formation->setText("   *champ obligatoire");
                         else
                            sec.set_formation(ui->formation->text());

             if(liste.ajouter_personnel(sec))
                { ui->message->setText("securite ajoute avec succes");
                 mysysteme->showMessage(tr("notification"),tr("ajout avec succes"));
                 QMessageBox::information(nullptr, QObject::tr("Ajouter un agent securite"),
                                   QObject::tr("securite ajouté.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                 //impression sec
                 QPrinter printer;
                 printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setOutputFileName("C:/Users/lenovo/Desktop/CrudGestionPersonnel3/pdf1");
                 QPainter painter;
                 painter.begin(&printer);

                 QFont font;
                 font.setPixelSize(35);
                 painter.setFont(font);
                 painter.setPen(Qt::blue);
                 painter.drawText(20,300,"cin: ");
                 painter.drawText(20,500,"nom:");
                 painter.drawText(20,650,"prenom:");
                 painter.drawText(20,800,"adresse:");
                 painter.drawText(20,1000,"age:");
                 painter.drawText(20,1250,"telephone:");
                 painter.drawText(20,1450,"statut familiale:");
                 painter.drawText(20,1650,"formation:");
                 int cin_=ui->cin->text().toInt();
                 QString cin_pdf=QString::number(cin_);

                 int age_=ui->age->text().toInt();
                 QString age_pdf=QString::number(age_);

                 int tel_=ui->telephone->text().toInt();
                 QString tel_pdf=QString::number(tel_);

                 QString nom_pdf=ui->nom->text();
                 QString prenom_pdf=ui->prenom->text();
                 QString adresse_pdf=ui->adresse->text();
                 QString statut_pdf=ui->s_familiale->text();
                 QString formation_pdf=ui->s_familiale->text();

                 font.setPixelSize(15);
                 painter.setFont(font);
                 painter.setPen(Qt::black);
                 painter.drawText(20,350,cin_pdf);
                 painter.drawText(20,550,nom_pdf);
                 painter.drawText(20,700,prenom_pdf);
                 painter.drawText(20,850,adresse_pdf);
                 painter.drawText(20,1050,age_pdf);
                 painter.drawText(20,1300,tel_pdf);
                 painter.drawText(20,1700,statut_pdf);
                 painter.drawText(20,1800,formation_pdf);


                 QImage image("C:/Users/lenovo/Desktop/CrudGestionPersonnel3");
                 painter.drawImage(100,50,image);

                 painter.end();

                 qDebug()<<"le pdf a ete cree";
                 QMessageBox::information(this,"pdf cree","ce pdf a ete cree");

                               ui->message->setText("PDF CREER");
                 int cin=ui->cin->text().toInt();
                 int age=ui->age->text().toInt();
                 int tel=ui->telephone->text().toInt();
                 QString nom=ui->nom->text();
                 QString statut_familiale=ui->s_familiale->text();
                 QString prenom=ui->prenom->text();
                 QString adresse=ui->adresse->text();
                 QString idposte=GetRandomString();
             if(liste.ajouter_personnel(cin,nom,prenom,adresse,age,tel,statut_familiale,idposte)==1)
                 qDebug()<<"securite ajoute";
             else qDebug()<<"securite  pas ajoute";
             }
             else
                 ui->message->setText("Erreur : securite non ajoute");
    }



}
void gestion::on_resaisir_clicked()
{
        //reset champ
        ui->cin->clear();
        ui->nom->clear();
        ui->prenom->clear();
        ui->adresse->clear();
        ui->telephone->clear();
        ui->age->clear();
        ui->s_familiale->clear();
        ui->formation->clear();

}
void gestion::on_radioButtonPersonnel_clicked()
{
        ui->formation->setVisible(false);
}
void gestion::on_radioButtonSecurite_clicked()
{
        ui->formation->setVisible(true);
}
void  gestion::on_nom_returnPressed()
{if("   *champ obligatoire"==ui->nom->text() || "   cin non valide"==ui->nom->text())
    ui->nom->clear();
}

void  gestion::on_cin_returnPressed()
{if("   *champ obligatoire"==ui->cin->text() || "   id non valide"==ui->cin->text())
    ui->cin->clear();
}

void  gestion::on_prenom_returnPressed()
{if("   *champ obligatoire"==ui->prenom->text())
    ui->prenom->clear();
}

void  gestion::on_adresse_returnPressed()
{if("   *champ obligatoire"==ui->adresse->text())
        ui->adresse->clear();
}

void  gestion::on_telephone_returnPressed()
{if("   *champ obligatoire"==ui->telephone->text())
        ui->telephone->clear();
}

void  gestion::on_age_returnPressed()
{if("   *champ obligatoire"==ui->age->text())
        ui->age->clear();
}
void  gestion::on_s_familiale_returnPressed()
{if("   *champ obligatoire"==ui->s_familiale->text())
        ui->s_familiale->clear();
}

void gestion::on_retour_clicked()
{
    hide();
}


void gestion::on_afficherSec_clicked()
{
    securite *S=new securite();
    ui->tableView->setModel(S->afficher());
}


void gestion::on_afficherPers_clicked()
{
    personnel *P=new personnel();
    ui->tableView_2->setModel(P->afficher());
}

void gestion::on_trierSec_clicked()
{
    bool test = tmpsecurite.tri();
           if (test){
           ui->tableView->setModel(tmpsecurite.tri());}//refresh
}

void gestion::on_trierPers_clicked()
{
    bool test = tmppersonnel.tri();
           if (test){
           ui->tableView_2->setModel(tmppersonnel.tri());}//refresh
}

void gestion::on_supprimer_clicked()
{

    int cin=ui->recherchercin->text().toInt();
    bool test=tmppersonnel.supprimerPers(cin);
     if(test)
     {
         ui->tableView->setModel(tmppersonnel.afficher());//refresh
         bool test1=tmpsecurite.supprimerSec(cin);
     if(test1){
         ui->tableView_2->setModel(tmppersonnel.afficher());//refresh
        }
     qDebug()<<"supression faite";
     }
      else qDebug()<<"erreur";
}

void gestion::on_confirme_clicked()
{
    int cin = ui->recherchercin->text().toInt();

bool test=true;
if(test==(true))
{

ui->tableView_2->setModel(tmppersonnel.chercher(cin));
QMessageBox::information(nullptr, QObject::tr("chercher un personnel"),
                  QObject::tr("client existe.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
}

void gestion::on_pushButton_clicked()
{
    int cin = ui->cin->text().toInt();
    QString nom= ui->nom->text();
    QString prenom= ui->prenom->text();
    QString adresse=ui->adresse->text();
    int age = ui->age->text().toInt();
    int tel = ui->telephone->text().toInt();
    QString statut_familiale=ui->s_familiale->text();

  personnel p(cin,nom,prenom,adresse,age,tel,statut_familiale);
  bool test=p.update();

  if(test)
{


QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                  QObject::tr("client modifie.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un client "),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);




}

void gestion::on_commandLinkButton_2_clicked()
{
    statistik= new stati(this);
    statistik->show();
}
