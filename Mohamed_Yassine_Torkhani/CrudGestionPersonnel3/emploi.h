#ifndef EMPLOI_H
#define EMPLOI_H
#include <QSqlQueryModel>
#include <QString>
class emploi
{
public:
    emploi();
    emploi(int,QString,QString,QString,QString);
    int get_id(){return  id ;}
    QString get_heure_debut(){return  heure_debut ;}
     QString get_heure_sortie(){return  heure_sortie ;}
    QString get_heure_pause(){return  heure_pause ;}
     QString get_duree_pause(){return  duree_pause ;}
     void set_heure_debut(QString heure_debut){this->heure_debut=heure_debut ;}
     void set_heure_sortie(QString heure_sortie){this->heure_sortie=heure_sortie ;}
     void set__heure_pause(QString heure_pause){this->heure_pause=heure_pause ;}
     void set__duree_pause(QString duree_pause){this->duree_pause=duree_pause ;}
     void set_id(int id){this->id=id ;}
    bool ajouter_emploi();
    QSqlQueryModel *afficher();
    bool supprimer_emploi(int);
    bool rechercher(int);
 QSqlQueryModel *chercher(int);
 bool update();
private:
    int id;
    QString heure_debut,heure_sortie,heure_pause,duree_pause;
};

#endif // EMPLOI_H
