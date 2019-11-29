#ifndef INTERFACE1_H
#define INTERFACE1_H
#include "mainwindow.h"
#include <QDialog>
#include"client.h"
#include "avis.h"
#include"QPainter"
#include"QPdfWriter"
#include"QDesktopServices"
#include"QtPrintSupport/QPrinter"
#include <QPropertyAnimation>
namespace Ui {
class interface1;
}

class interface1 : public QDialog
{
    Q_OBJECT

public:
    explicit interface1(QWidget *parent = nullptr);
    ~interface1();

private slots:
    void on_pushButton_clicked();


    void on_ajout_clicked();

    void on_pb_ajouter_avis_clicked();

    void on_pb_ajouter_clicked();

    void on_afficher_clicked();

    void on_pb_modifier_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    //void on_pushButton_4_clicked();

    void on_supprimer_clicked();

    void on_trier_clicked();

    void on_id_cursorPositionChanged(int arg1, int arg2);

    void on_Actualiser_clicked();

    void on_Actualiser_2_clicked();

    void on_combo1_activated(const QString &arg1);

    void on_combo1_currentIndexChanged(const QString &arg1);

    void on_combo1_currentTextChanged(const QString &arg1);

    ///void on_statis_clicked();

    void on_pushButton_4_clicked();

    void on_idc_activated(const QString &arg1);

    void on_pushButton_pdf_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_5_clicked();

private:
    Ui::interface1 *ui;
    client c;
    avis a;
      QPropertyAnimation *animation ;
};

#endif // INTERFACE1_H
