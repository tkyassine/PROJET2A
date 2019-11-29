#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stat.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_evenements->setModel(tmp_evenements.afficher());
    ui->tab_promotions->setModel(tmp_promotions.afficher());
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
    ui->comboBox_type_pdf->addItem("evenement");
    ui->comboBox_type_pdf->addItem("promotion");
    ui->comboBox_sujet->addItem("evenement");
    ui->comboBox_sujet->addItem("promotion");
    QPixmap pix("C:/Users/OneEffect007/Desktop/Validation sans m/icon");
    ui->img1->setPixmap(pix.scaled(130,130,Qt::KeepAspectRatio));
    ui->img2->setPixmap(pix.scaled(130,130,Qt::KeepAspectRatio));
    ui->img3->setPixmap(pix.scaled(130,130,Qt::KeepAspectRatio));
    ui->img4->setPixmap(pix.scaled(130,130,Qt::KeepAspectRatio));
    ui->img5->setPixmap(pix.scaled(130,130,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    bool test=false;
    //
    //
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    const int randomStringLength = 6; // assuming you want random strings of 12 characters
    QString randomString;
    randomString.append('E');
    randomString.append('V');
    for(int i=2; i<randomStringLength; ++i)
    {
        int index = qrand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    QString code=randomString;
    //
    //
    QString libelle=ui->lineEdit_libelle->text();
    QString date=ui->lineEdit_date->text();
    float duree=ui->lineEdit_duree->text().toFloat();
    float prix_ticket=ui->lineEdit_prix_ticket->text().toFloat();
    evenements e(code,libelle,date,duree,prix_ticket);
    if (duree>0 && prix_ticket>0)test=e.ajouter();
    if (test)
    {
        qDebug()<<"evenement ajoute";
        QMessageBox::information(this,"evenement ajoute","ce evenement a ete ajoute");
        ui->tab_evenements->setModel(tmp_evenements.afficher());
    }
    else
    {
        QMessageBox::critical(this,"ERROR","veuillez verifier vos informations");
    }
}

void MainWindow::on_pb_supprimer_clicked()
{
    QString code=ui->comboBox_es->currentText();
    bool test=tmp_evenements.supprimer(code);
    if (test)
    {
       ui->tab_evenements->setModel(tmp_evenements.afficher());
       qDebug()<<"evenement supprime";
       QMessageBox::information(this,"evenement supprime","ce evenement a ete supprime");
    }
    else
    {
        QMessageBox::critical(this,"ERROR","ce code n existe pas");
    }
}



void MainWindow::on_pb_modifier_clicked()
{
    bool test=false;
    QString code=ui->comboBox_em->currentText();
    QString libelle=ui->lineEdit_libelle_m->text();
    QString date=ui->lineEdit_date_m->text();
    float duree=ui->lineEdit_duree_m->text().toFloat();
    float prix_ticket=ui->lineEdit_prix_ticket_m->text().toFloat();
    evenements e(code,libelle,date,duree,prix_ticket);
    if (duree>0 && prix_ticket>0)test=tmp_evenements.modifier(e);
    if (test)
    {
        if (duree>0 && prix_ticket>0) ui->tab_evenements->setModel(tmp_evenements.afficher());
        qDebug()<<"evenement modife";
        QMessageBox::information(this,"evenement supprime","ce evenement a ete modifie");
    }
    else
    {
        QMessageBox::critical(this,"ERROR","veuillez verifier vos informations");
    }
}

void MainWindow::on_pb_ajouter_p_clicked()
{
    bool test=false;
    //
    //
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    const int randomStringLength = 6; // assuming you want random strings of 12 characters
    QString randomString;
    randomString.append('P');
    randomString.append('R');
    for(int i=2; i<randomStringLength; ++i)
    {
        int index = qrand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    QString code=randomString;
    //
    //
    float taux=ui->lineEdit_taux->text().toFloat();
    int validite=ui->lineEdit_validite->text().toInt();
    int id_client=ui->lineEdit_id_client->text().toInt();
    promotions p(code,taux,validite,id_client);
    if (taux>0 &&(validite==1 || validite==0))test=p.ajouter();
    if (test)
    {
         qDebug()<<"promotion ajoute";
         QMessageBox::information(this,"promotion ajoutee","cet promotion a ete ajoutee");
         ui->tab_promotions->setModel(tmp_promotions.afficher());
    }
    else
    {
        QMessageBox::critical(this,"ERROR","veuillez verifier vos informations");
    }
}

void MainWindow::on_pb_supprimer_2_clicked()
{
    QString code=ui->comboBox_ps->currentText();
    bool test=tmp_promotions.supprimer(code);
    if (test)
    {
       ui->tab_promotions->setModel(tmp_promotions.afficher());
       qDebug()<<"promotion supprimee";
       QMessageBox::information(this,"promotion supprimee","cet promotion a ete supprimee");
    }
    else
    {
         QMessageBox::critical(this,"ERROR","ce code n existe pas");
    }
}

void MainWindow::on_pb_modifier_p_clicked()
{
    bool test=false;
    QString code=ui->comboBox_pm->currentText();
    float taux=ui->lineEdit_taux_m->text().toFloat();
    int validite=ui->lineEdit_validite_m->text().toInt();
    int id_client=ui->lineEdit_id_client_m->text().toInt();
    promotions p(code,taux,validite,id_client);
    if (taux>0 && (validite==0 || validite==1))test=tmp_promotions.modifier(p);
    if (test)
    {
        ui->tab_promotions->setModel(tmp_promotions.afficher());
        qDebug()<<"promotion modifie";
        QMessageBox::information(this,"promotion modifiee","cet promotion a ete modifiee");
    }
    else
    {
        QMessageBox::critical(this,"ERROR","veuillez verifier vos informations");
    }
}


void MainWindow::on_BAR_clicked()
{
    bar b;
    QString titre=ui->lineEdit_titre->text();
    b.bar_b(this,titre);
    qDebug()<<"statistiques";
}


void MainWindow::on_pushButton_imprimer_clicked()
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/Users/OneEffect007/Desktop/test/pdf2.pdf");
    QPainter painter;
    painter.begin(&printer);

    QFont font;
    QString code=ui->lineEdit_code_pdf->text();
    QSqlQuery query;
    QString duree_pdf,libelle_pdf,date_pdf,prix_ticket_pdf,taux_pdf;
    if (ui->comboBox_type_pdf->currentText()=="evenement")
    {
        query.prepare("select * from evenements where code='"+code+"'");
        if (query.exec())
        {
            while (query.next())
            {
                duree_pdf=query.value(3).toString();
                libelle_pdf=query.value(1).toString();
                date_pdf=query.value(2).toString();
                prix_ticket_pdf=query.value(4).toString();
            }
        }
        font.setPixelSize(50);
        painter.setFont(font);
        painter.setPen(Qt::red);
        painter.drawText(350,150,"EVENEMENT");

        font.setPixelSize(35);
        painter.setFont(font);
        painter.setPen(Qt::blue);
        painter.drawText(20,300,"Titre: ");
        painter.drawText(20,500,"Duree:");
        painter.drawText(20,650,"date:");
        painter.drawText(20,800,"prix de ticket:");

        font.setPixelSize(22);
        painter.setFont(font);
        painter.setPen(Qt::black);
        painter.drawText(150,500,duree_pdf);
        painter.drawText(150,300,libelle_pdf);
        painter.drawText(150,650,date_pdf);
        painter.drawText(250,800,prix_ticket_pdf);
    }
    else
    {
        query.prepare("select * from promotions where code='"+code+"'");
        if (query.exec())
        {
            while (query.next())
            {
                taux_pdf=query.value(2).toString();
            }
        }
        font.setPixelSize(50);
        painter.setFont(font);
        painter.setPen(Qt::red);
        painter.drawText(350,150,"PROMOTION");
        font.setPixelSize(35);
        painter.setFont(font);
        painter.setPen(Qt::blue);
        painter.drawText(20,300,"promotion de: ");
        font.setPixelSize(22);
        painter.setFont(font);
        painter.setPen(Qt::black);
        painter.drawText(150,350,taux_pdf+"%");
    }

    QImage image("C:/Users/OneEffect007/Desktop/test/icon");
    painter.drawImage(-30,-100,image);

    painter.end();

    qDebug()<<"le pdf a ete cree";
    QMessageBox::information(this,"pdf cree","ce pdf a ete cree");
}

void MainWindow::on_pushButton_actualiser_clicked()
{
    ui->tab_evenements->setModel(tmp_evenements.afficher());
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select code from evenements");
    ui->comboBox_es->setModel(model);
    ui->comboBox_em->setModel(model);
    qDebug()<<"table actualise";
}

void MainWindow::on_pushButton_actualiser_2_clicked()
{
    ui->tab_promotions->setModel(tmp_promotions.afficher());
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select code from promotions");
    ui->comboBox_ps->setModel(model);
    ui->comboBox_pm->setModel(model);
    qDebug()<<"table actualise";
}


void MainWindow::on_comboBox_em_currentIndexChanged(const QString &arg1)
{
    QString code=ui->comboBox_em->currentText();
    QSqlQuery query;
    query.prepare("select * from evenements where code='"+code+"'");
    if (query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_duree_m->setText(query.value(3).toString());
            ui->lineEdit_libelle_m->setText(query.value(1).toString());
            ui->lineEdit_date_m->setText(query.value(2).toString());
            ui->lineEdit_prix_ticket_m->setText(query.value(4).toString());
        }
    }
}

void MainWindow::on_comboBox_pm_currentIndexChanged(const QString &arg1)
{
    QString code=ui->comboBox_pm->currentText();
    QSqlQuery query;
    query.prepare("select * from promotions where code='"+code+"'");
    if (query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_taux_m->setText(query.value(2).toString());
            ui->lineEdit_validite_m->setText(query.value(0).toString());
            ui->lineEdit_id_client_m->setText(query.value(1).toString());
        }
    }
}

void MainWindow::on_pushButton_envoyer_clicked()
{
        SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
        smtp.setUser("houssem.ouerdiane@esprit.tn");
        smtp.setPassword("fallout3");
        MimeMessage message;
        message.setSender(new EmailAddress("houssem.ouerdiane@esprit.tn", "HoussemOuerdiane"));
        message.addRecipient(new EmailAddress(ui->lineEdit_mail->text(),"Client_de_BiblioTek"));
        message.setSubject(ui->comboBox_sujet->currentText());
        MimeText text;
        QString duree_mail,libelle_mail,date_mail,prix_ticket_mail,taux_mail;
        QSqlQuery query;
        QString code=ui->lineEdit_code_mail->text();
        if(ui->comboBox_sujet->currentText()=="evenement")
        {
            query.prepare("select * from evenements where code='"+code+"'");
            if (query.exec())
            {
                while (query.next())
                {
                duree_mail=query.value(3).toString();
                libelle_mail=query.value(1).toString();
                date_mail=query.value(2).toString();
                prix_ticket_mail=query.value(4).toString();
                }
            }
            text.setText("Bonjour Cher Client , il aura un evenement "+libelle_mail+"le"+date_mail+" ,le prix de ticket"+prix_ticket_mail+"et durera"+duree_mail+"minutes ,merci de venir nombreux.");
        }
        else
        {
            query.prepare("select * from promotions where code='"+code+"'");
            if (query.exec())
            {
                while (query.next())
                {
                taux_mail=query.value(2).toString();
                }
            }
            text.setText("Bonjour Cher Client , il aura une promotion de "+taux_mail+"% ,profitez bien.");
        }
        message.addPart(&text);
        smtp.connectToHost();
        smtp.login();
       if ( smtp.sendMail(message)){
       QMessageBox :: information(this,"mail envoye","mail envoye");
       qDebug()<<"mail envoye";
       }else {
           QMessageBox :: critical(this,"ERROR","ERROR");

       }
        smtp.quit();
}


void MainWindow::on_pushButton_test_clicked()
{
    QSqlQuery query;
    query.prepare("INSERT INTO statistique (titre,nb_romans,nb_bd,nb_enfants,nb_magazines,nb_bouquins)VALUES('test2',1,2,3,4,5)");
    query.exec();
}
