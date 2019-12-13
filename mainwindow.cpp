#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "interface1.h"
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


void MainWindow::on_login_2_clicked()
{

  interface1 c;
 MainWindow w;
 hide();
c.exec();
}

void MainWindow::on_pushButton_clicked()
{
    close();
}
