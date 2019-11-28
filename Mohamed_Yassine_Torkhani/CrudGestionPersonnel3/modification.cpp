#include "modification.h"
#include "ui_modification.h"
#include "gestion.h"
modification::modification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modification)
{
    ui->setupUi(this);
}

modification::~modification()
{
    delete ui;
}

void modification::on_confirme_clicked()
{
    if (c!=4){
        mtmp.modifier(id,ui->lnm->text(),c);
    }else {
            mtmp.modifier(id,ui->datem->text(),c);
        }
            accept();
}

void modification::on_retour2_clicked()
{
     reject();
}
void modification :: control(int c){
    if (c==4)
        ui->nomModif->show();

}
