#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "livre.h"
#include "rayon.h"
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
        void on_modifierButtonR_clicked();
        void on_supprimerButtonR_clicked();
        void on_rafraichirR_clicked();
        void on_triComboR_currentIndexChanged();
        void on_rechComboR_currentIndexChanged();
        void on_rechTxtR_textEdited();
        void on_ajouterButtonR_clicked();
        void setAjoutComboL();
        void on_modifierButtonLiv_clicked();
        void on_supprimerButtonLiv_clicked();
        void on_rafraichirLiv_clicked();
        void on_triComboLiv_currentIndexChanged();
        void on_rechComboLiv_currentIndexChanged();
        void on_rechTxtLiv_textEdited();
        void on_ajouterButtonLiv_clicked();
        void on_recommander_clicked();
        void on_tabW_currentChanged(int);
private:
        Ui::MainWindow *ui;
        livre tmpL;
        Rayon tmpR;
};

#endif // MAINWINDOW_H
