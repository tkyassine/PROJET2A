#include "stat.h"
#include "ui_bar.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

bar::bar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bar)
{
    ui->setupUi(this);
}

bar::~bar()
{
    delete ui;
}

void bar::bar_b(QMainWindow* window,QString titre)
{
        QString nb_romans,nb_bouquins,nb_enfants,nb_magazines,nb_bd;
        QSqlQuery  query;
        query.prepare("select * from statistique where titre='"+titre+"'");

        if (query.exec())
        {
            while (query.next())
            {
                nb_romans=query.value(1).toString();
                nb_bouquins=query.value(2).toString();
                nb_bd=query.value(3).toString();
                nb_enfants=query.value(4).toString();
                nb_magazines=query.value(5).toString();
            }
        }

        QBarSet *set0=new QBarSet("Romans");
        QBarSet *set1=new QBarSet("Bouquins");
        QBarSet *set2=new QBarSet("BD");
        QBarSet *set3=new QBarSet("Livres d'enfants");
        QBarSet *set4=new QBarSet("Magazines");

        *set0 <<nb_romans.toInt();
        *set1 <<nb_bouquins.toInt();
        *set2 <<nb_bd.toInt();
        *set3 <<nb_enfants.toInt();
        *set4 <<nb_magazines.toInt();

        QBarSeries *series =new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        series->append(set4);

        QChart *chart= new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistiques des ventes des livres");

        chart->setAnimationOptions(QChart::AllAnimations);
        QStringList categories;
        categories <<titre;
        QBarCategoryAxis *axis=new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis,series);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        QChartView *chartview =new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        QPalette pal=qApp->palette();
        pal.setColor(QPalette::Window,QRgb(0xffffff));
        pal.setColor(QPalette::WindowText,QRgb(0x121212));
        qApp->setPalette(pal);

        window->setCentralWidget(chartview);
        window->resize(420,300);
        window->show();

        //ui->box->set(chart);

}
