#ifndef AVIIS_H
#define AVIIS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class avis
{

private:
    int numavis;
    QString dateavis;
    int etatavis;
    QString idclients;

public:
    //cnstr
    avis();
    avis (int ,QString,int,QString);

    int get_numavis();
    QString get_dateavis();
    int get_etat();
   QString get_idclient();



    void set_numavis(int);
    void set_dateavis(QString);
    void set_etatavis(int);
    void set_idclient(QString);


    bool ajouter_avis(avis);
    bool supprimer_avis(int);
    bool modifier_avis(avis);
    QSqlQueryModel * afficher_avis();

    QSqlQueryModel *tri();
     QSqlQueryModel *shownumavis();
};

#endif // AVIIS_H
