#ifndef CLIENT_H
#define CLIENT_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>

class client
{

private:
        QString nom;
        QString prenom;
        QString dateDeNaissance;
        QString sexe;
        QString id;
        QString adressemail;

    public:
        //cnstr
        client();
        client (QString,QString,QString,QString,QString,QString);

        QString getNom();
        QString getPrenom();
        QString getDateDeNaissance();
        QString getSex();
        QString getID();
        QString getmail();

        void setNom(QString);
        void setPrenom(QString);
        void setDateDeNaissance(QString);
        void setSex(QString);
        void setID(QString);
        void setmail(QString);


        bool ajouter(client);
        bool supprimer(QString);
        bool modifier(client);
        QSqlQueryModel * afficher();
        QSqlQueryModel *showid();
         QSqlQueryModel *shownomclient();



      QSqlQueryModel *recherchernomcient(QString );
       QSqlQueryModel *tri();
};

#endif // CLIENTT_H
