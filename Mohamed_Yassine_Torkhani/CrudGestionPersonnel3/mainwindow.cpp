#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion.h"
#include "gerer_emploi.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    gestion g;
    g.exec();
}

void MainWindow::on_emploi_clicked()
{
    gerer_emploi em;
    em.exec();
}
