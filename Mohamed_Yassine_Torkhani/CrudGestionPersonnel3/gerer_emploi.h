#ifndef GERER_EMPLOI_H
#define GERER_EMPLOI_H

#include <QDialog>
#include "emploi.h"
namespace Ui {
class gerer_emploi;
}

class gerer_emploi : public QDialog
{
    Q_OBJECT

public:
    explicit gerer_emploi(QWidget *parent = nullptr);
    ~gerer_emploi();

private slots:


    void on_inserer_clicked();

    void on_afficher_clicked();

    void on_retour_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

private:
    Ui::gerer_emploi *ui;
    emploi tmpemploi;

};

#endif // GERER_EMPLOI_H
