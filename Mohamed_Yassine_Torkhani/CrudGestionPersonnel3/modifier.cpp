#include "modifier.h"
#include "ui_modifier.h"
#include "mainwindow.h"

Modifier::Modifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modifier)
{
    ui->setupUi(this);
}

Modifier::~Modifier()
{
    delete ui;
}
