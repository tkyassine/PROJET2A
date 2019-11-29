#ifndef BAR_H
#define BAR_H
#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QDialog>

QT_CHARTS_USE_NAMESPACE
namespace Ui {
class bar;
}

class bar : public QDialog
{
    Q_OBJECT

public:
    explicit bar(QWidget *parent = nullptr);
    ~bar();
    void bar_b(QMainWindow*,QString);

private:
    Ui::bar *ui;
};

#endif // BAR_H
