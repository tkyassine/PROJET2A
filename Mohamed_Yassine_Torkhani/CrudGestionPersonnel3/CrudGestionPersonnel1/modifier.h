#ifndef MODIFIER_H
#define MODIFIER_H
#include "personnel.h"

#include <QDialog>

namespace Ui {
class modifier;
}

class modifier : public QDialog
{
    Q_OBJECT

public:
void setid(int a){cin=a ;}
    explicit modifier(QWidget *parent = nullptr);
    ~modifier();
personnel ptmp ;

private slots:
void on_pushButton_clicked();

private:
    int cin ;
    Ui::modifier *ui;
};

#endif // MODIFIER_H
