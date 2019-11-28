#ifndef MODIFICATION_H
#define MODIFICATION_H
#include "personnel.h"
#include <QDialog>

namespace Ui {
class modification;
}

class modification : public QDialog
{
    Q_OBJECT

public:
    explicit modification(QWidget *parent = nullptr);
    ~modification();
    void setc(int x){
        c=x ;
    }
    void setid(QString x){
        id=x ;
    }
    void control(int c);

private slots:
    void on_confirme_clicked();

    void on_retour2_clicked();

private:
    Ui::modification *ui;
    personnel mtmp;
    QString id ;
    int c ;
};

#endif // MODIFICATION_H
