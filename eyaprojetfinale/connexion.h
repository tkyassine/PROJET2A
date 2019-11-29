#ifndef CONNEXION_H
#define CONNEXION_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

class connexion
{


private:
   QSqlDatabase db;
public:
        connexion();
    bool ouvrirconnection();
    void fermerconnection();
};

#endif // CONNEXION_H
