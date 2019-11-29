#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetLogin(QString login)
    {
        this->login=login;
    }
    QString getLogin()
    {
        return  this->login;
    }
    void SetMdp(QString mdp)
    {
        this->mdp=mdp;
    }

private slots:
    void on_login_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString login;
    QString mdp;
};
#endif // MAINWINDOW_H
