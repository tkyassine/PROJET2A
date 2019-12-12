#ifndef GESTION_H
#define GESTION_H
#include "personnel.h"
#include "securite.h"
#include <QDialog>
#include <QSystemTrayIcon>

namespace Ui {
class gestion;
}
class QSystemTrayIcon;
class gestion : public QDialog
{
    Q_OBJECT

public:
    explicit gestion(QWidget *parent = nullptr);
    ~gestion();

private slots:
    void on_ajouter_clicked();

    void on_resaisir_clicked();

    void on_radioButtonSecurite_clicked();

    void on_radioButtonPersonnel_clicked();

    void on_nom_returnPressed();

    void on_cin_returnPressed();

    void on_prenom_returnPressed();

    void on_adresse_returnPressed();

    void on_telephone_returnPressed();

    void on_age_returnPressed();

    void on_s_familiale_returnPressed();



    void on_retour_clicked();

    void on_afficherSec_clicked();
    void on_afficherPers_clicked();

    QString GetRandomString() const;

    void on_trierSec_clicked();

    void on_trierPers_clicked();

    void on_supprimer_clicked();


    void on_confirme_clicked();

    void on_modifier_clicked();

   // void on_pushButton_2_clicked();

    //void on_tableView_2_doubleClicked(const QModelIndex &index);

private:
    Ui::gestion *ui;
    personnel tmppersonnel;
    securite tmpsecurite;
    QSystemTrayIcon * mysysteme;
};

#endif // GESTION_H
