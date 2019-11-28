#ifndef CONN_H
#define CONN_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


class conn
{
public:
    conn();
     bool createconnect();
};

#endif // CONN_H
