#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQueryModel>

class personnel
{
public:
    personnel();
    personnel(int,QString,QString,QString,int,int,QString);
    void set_cin(int cin){this->cin=cin;}
    void set_nom(QString nom){this->nom=nom;}
    void set_prenom(QString prenom){this->prenom=prenom;}
    void set_adresse(QString adresse){this->adresse=adresse;}
    void setage(int age){this->age=age;}
    void set_numtel(int tel){this->tel=tel;}
    void setstatut(QString statut_familiale){this->statut_familiale=statut_familiale;}
    void set_idposte(QString idposte){this->idposte=idposte;}
    int get_cin()const{return cin;}
    int get_numtel()const{return tel;}
    QString get_idposte()const{return idposte;}
    QString get_nom()const{return nom;}
    QString get_prenom()const{return prenom;}
    QString get_adresse()const{return adresse;}
    QString getstatut()const{return statut_familiale;}
    int getage()const{return age;}
    QSqlQueryModel *afficher();
    QSqlQueryModel * tri();
    bool supprimerPers(int);
    bool modifier(QString,int,int);
    bool update();
    QSqlQueryModel *chercher(int);
protected :
     int cin,tel,age;
     QString nom,prenom,adresse,idposte,statut_familiale;
};

#endif // PERSONNEL_H
