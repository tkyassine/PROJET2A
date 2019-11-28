#include "gerer_emploi.h"
#include "ui_gerer_emploi.h"
#include <QMessageBox>
#include<QString>
#include<QDebug>
#include "emploi.h"
gerer_emploi::gerer_emploi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gerer_emploi)
{
    ui->setupUi(this);
}

gerer_emploi::~gerer_emploi()
{
    delete ui;
}


void gerer_emploi::on_inserer_clicked()
{
    int id=ui->id->text().toInt();
    QString heure_debut=ui->heure_deb->text();
    QString heure_sortie=ui->heure_sort->text();
    QString heure_pause=ui->heure_pause->text();
    QString duree_pause=ui->duree_pause->text();

    //condition de saisie sur id nom et date
      if( id<100000||id>999999 || id==0 ){

             { if(id==0 )
                     ui->id->setText("   *champ obligatoire");
                 else{
                     ui->id->setText("   id non valide");


                     QMessageBox::critical(nullptr, QObject::tr("Ajouter un emploi"),
                                 QObject::tr("Erreur d'ajout !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

                 }
             }
      }
             else
             {    emploi e (id,heure_debut,heure_sortie,heure_pause,duree_pause);
                  bool test=e.ajouter_emploi();
                  if(test)
                  {
                      ui->message->setText(" emploi  ajouté");
                      QMessageBox::information(nullptr, QObject::tr("Ajouter un emploi"),
                                        QObject::tr("emploi ajouté.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
                  }
                  else
                  {
                      ui->message->setText("Erreur : emploi non  ajouté");
                             QMessageBox::critical(nullptr, QObject::tr("Ajouter un emploi"),
                                         QObject::tr("Erreur d'ajout !.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
                  }

             }
}


void gerer_emploi::on_afficher_clicked()
{
    emploi *em=new emploi();
    ui->tableView->setModel(em->afficher());
}

void gerer_emploi::on_retour_clicked()
{
    hide();
}

void gerer_emploi::on_modifier_clicked()
{

    int id = ui->id->text().toInt();
    QString heure_debut=ui->heure_deb->text();
    QString heure_sortie=ui->heure_sort->text();
    QString heure_pause=ui->heure_pause->text();
    QString duree_pause=ui->duree_pause->text();

emploi e (id,heure_debut,heure_sortie,heure_pause,duree_pause);
bool test=e.update();

  if(test)
{


      QMessageBox::information(nullptr, QObject::tr("modifier un emploi"),
                        QObject::tr("emploi modifier.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un emploi"),
                  QObject::tr("Erreur de modification !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void gerer_emploi::on_supprimer_clicked()
{
    int id=ui->id->text().toInt();
     bool var=tmpemploi.rechercher(id);
    if(var)
     {
         bool test=tmpemploi.supprimer_emploi(id);
          if(test)
          {
              ui->tableView->setModel(tmpemploi.afficher());//refresh
               QMessageBox::information(nullptr, QObject::tr("Supprimer un emploi"),
                     QObject::tr("emploi supprimé.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

          }
        else{
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un emploi"),
                     QObject::tr("Erreur de suppression  !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
           }
     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer une convention"),
                     QObject::tr("Erreur ! id not found.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}
