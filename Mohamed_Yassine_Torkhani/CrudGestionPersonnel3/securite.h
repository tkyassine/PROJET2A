#ifndef SECURITE_H
#define SECURITE_H
#include <QString>
#include "personnel.h"
#include <QSqlQueryModel>
class securite:public personnel
{
    protected:
        QString formation;
    public:
        securite();
        securite& operator=(personnel&);
        bool ajouter_employe(const securite&);
        void set_formation(QString formation){this->formation=formation;}
        QString getformation()const{return formation;}
        QSqlQueryModel * tri();
        QSqlQueryModel *afficher();
        bool supprimerSec(int);

};

#endif // SECURITE_H
