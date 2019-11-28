#ifndef MODIFIER_H
#define MODIFIER_H
#include "personnel.h"
#include <QDialog>

namespace Ui {
class Modifier;
}

class Modifier : public QDialog
{
    Q_OBJECT

public:
    explicit Modifier(QWidget *parent = nullptr);
    ~Modifier();
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
    personnel mtmp;
    QString id ;
    int c ;
    Ui::Modifier *ui;
};

#endif // MODIFIER_H
