#include "connexion.h"

connexion::connexion()
{

}
bool connexion::ouvrirconnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet_2A");


db.setUserName("eya");//inserer nom de l'utilisateur
db.setPassword("eya2018");
if (db.open())
test=true;





    return  test;
}
void connexion::fermerconnection()
{db.close();}
