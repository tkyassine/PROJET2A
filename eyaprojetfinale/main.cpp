#include "mainwindow.h"
#include <QApplication>
#include "connexion.h"
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connexion c;
    w.show();

    bool test=c.ouvrirconnection();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("Database is opened"),
                    QObject::tr("Connection Successful.\n"
                                "Click OK to continue."), QMessageBox::Ok);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("Connection Failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}
