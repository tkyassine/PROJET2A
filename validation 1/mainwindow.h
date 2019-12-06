#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "evenements.h"
#include "promotions.h"
#include "connection.h"
#include "stat.h"
#include <QDebug>
#include "QMessageBox"
#include "QPainter"
#include "QPdfWriter"
#include "QDesktopServices"
#include "QtPrintSupport/QPrinter"
#include "QImage"
#include "QPixmap"
#include "mailing/SmtpMime"
QT_CHARTS_USE_NAMESPACE


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_ajouter_p_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_modifier_p_clicked();

    void on_BAR_clicked();

    void on_pushButton_imprimer_clicked();

    void on_pushButton_actualiser_clicked();

    void on_pushButton_actualiser_2_clicked();

    void on_comboBox_em_currentIndexChanged(const QString &arg1);

    void on_comboBox_pm_currentIndexChanged(const QString &arg1);

    void on_pushButton_envoyer_clicked();

    void on_comboBox_ps_currentIndexChanged(const QString &arg1);

    void on_pushButton_test_clicked();

private:
    Ui::MainWindow *ui;
    evenements tmp_evenements;
    promotions tmp_promotions;
};
#endif // MAINWINDOW_H
