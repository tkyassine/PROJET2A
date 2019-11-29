#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "porte.h"
#include "ventilateur.h"
#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
    private slots:
        void on_ajouterButtonP_clicked();
        void on_suppButtonP_clicked();
        void on_modifButtonP_clicked();
        void on_rechTxtP_textEdited();
        void on_ajouterButtonV_clicked();
        void on_suppButtonV_clicked();
        void on_modifButtonV_clicked();
        void on_rechTxtV_textEdited();
        void on_tabWidget_4_currentChanged();
        void on_tabWidget_5_currentChanged();

private:
        Ui::MainWindow *ui;
        porte tmpP;
        ventilateur tmpV;
};

#endif // MAINWINDOW_H
