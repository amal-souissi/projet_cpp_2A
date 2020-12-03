#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIntValidator *id_validator=new QIntValidator(1,99999);
    ui->id_client->setValidator(id_validator);
    ui->num_fact->setValidator(id_validator);

    QDoubleValidator *montant_validator=new QDoubleValidator(99999,99999, 99999, ui->montant_fac);
    ui->montant_fac->setValidator(montant_validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_client_triggered()
{
    int id=ui->id_client->text().toInt();
    QString nom=ui->nom_client->text();
    QString prenom=ui->prenom_client->text();
    QDate date_n=ui->date_n_client->date();
    QString email=ui->email_client->text();
    int num_tel=ui->tel_client->text().toInt();




    client c(id,nom,prenom,date_n,email,num_tel);
    bool test=c.ajouter();
    if(test){
        QMessageBox::information(nullptr,QObject::tr("client"),QObject::tr("Client ajouté avec succés"),QMessageBox::Ok);
        ui->table_client->setModel(tmpclient.afficher());
        ui->id_client->setText("");
        ui->nom_client->setText("");
        ui->prenom_client->setText("");
        ui->date_n_client->setDate(QDate(2000,01,01));
        ui->email_client->setText("");
        ui->tel_client->setText("");

        ui->combo_client->clear();
        ui->combo_client->addItems(tmpclient.listeClients());
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("client"),QObject::tr("erreur"),QMessageBox::Ok);
    }
}

void MainWindow::on_trouver_client_triggered()
{
    int id=ui->id_client->text().toInt();
    client c=tmpclient.trouver(id);
    ui->nom_client->setText(c.getNom());
    ui->prenom_client->setText(c.getPrenom());
    ui->date_n_client->setDate(c.getDate_n());
    ui->email_client->setText(c.getemail());
    ui->num_tel->setNum(c.getnum_tel());

}

void MainWindow::on_supprimer_client_triggered()
{
    int id=ui->id_client->text().toInt();
    bool test=tmpclient.supprimer(id);
    if(test){
        QMessageBox::information(nullptr,QObject::tr("client"),QObject::tr("Client supprimé avec succés"),QMessageBox::Ok);
        ui->table_client->setModel(tmpclient.afficher());
        ui->id_client->setText("");
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("client"),QObject::tr("erreur"),QMessageBox::Ok);
    }
}

void MainWindow::on_modifier_client_triggered()
{
    int id=ui->id_client->text().toInt();
    QString nom=ui->nom_client->text();
    QString prenom=ui->prenom_client->text();
    QDate date_n=ui->date_n_client->date();
    QString email=ui->email_client->text();
    int num_tel=ui->tel_client->text().toInt();

    client c(id,nom,prenom,date_n,email,num_tel);
    bool test=c.modifier(id);
    if(test){
        QMessageBox::information(nullptr,QObject::tr("client"),QObject::tr("Client modifié avec succés"),QMessageBox::Ok);
        ui->table_client->setModel(tmpclient.afficher());
        ui->id_client->setText("");
        ui->nom_client->setText("");
        ui->prenom_client->setText("");
        ui->date_n_client->setDate(QDate(2000,01,01));
        ui->email_client->setText("");
        ui->tel_client->setText("");
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("client"),QObject::tr("erreur"),QMessageBox::Ok);
    }
}

void MainWindow::on_recherche_client_textChanged(const QString &arg1)
{
    ui->table_client->setModel(tmpclient.rechercher(ui->recherche_client->text()));
}

void MainWindow::on_suprimer_fac_triggered()
{
    int num_fact=ui->num_fact->text().toInt();
    bool test=tmpfacture.supprimer(num_fact);
    if(test){
        QMessageBox::information(nullptr,QObject::tr("facture"),QObject::tr("facture supprimé avec succés"),QMessageBox::Ok);
        ui->table_fac->setModel(tmpfacture.afficher());
        ui->num_fact->setText("");
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("facture"),QObject::tr("erreur"),QMessageBox::Ok);
    }
}

void MainWindow::on_trouver_fac_triggered()
{
    int num_fact=ui->num_fact->text().toInt();
    facture f=tmpfacture.trouver(num_fact);
    QString montant=QString::number(f.getmontant());
    ui->montant_fac->setText(montant);
    //ui->date_fac->setDate(f.getdate_f());
    ui->type->setText(QString::number(f.getid_client()));
}

void MainWindow::on_ajouter_fac_triggered()
{
    int num_fact=ui->num_fact->text().toInt();
    double montant=ui->montant_fac->text().toDouble();
    QDate date_f=date_f.currentDate();
    int id_client=ui->combo_client->currentText().toInt();

    facture f(num_fact,montant,date_f,id_client);
    bool test=f.ajouter();
    if(test){
        QMessageBox::information(nullptr,QObject::tr("facture"),QObject::tr("facture ajouté avec succés"),QMessageBox::Ok);
        ui->table_fac->setModel(tmpfacture.afficher());
        ui->num_fact->setText("");
        ui->montant_fac->setText("");
        //ui->date_fac->setDate(QDate(2000,01,01));
        ui->type->setText("");
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("facture"),QObject::tr("erreur"),QMessageBox::Ok);
    }
}

void MainWindow::on_modifier_fac_triggered()
{
    int num_fact=ui->num_fact->text().toInt();
    double montant=ui->montant_fac->text().toDouble();
    QDate date_f;
    int id_client=ui->combo_client->currentText().toInt();
   facture f (num_fact,montant,date_f,id_client);
    bool test=f.modifier(num_fact);
    if(test){
        QMessageBox::information(nullptr,QObject::tr("facture"),QObject::tr("facture modifié avec succés"),QMessageBox::Ok);
        ui->table_fac->setModel(tmpfacture.afficher());
        ui->num_fact->setText("");
        ui->montant_fac->setText("");
        //ui->date_fac->setDate(QDate(2000,01,01));
        ui->type->setText("");
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("facture"),QObject::tr("erreur"),QMessageBox::Ok);
    }
}

void MainWindow::on_stat_facture_triggered()
{
    statistiquesFact *s=new statistiquesFact();
    s->show();
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->table_fac->setModel(tmpfacture.afficher());
    ui->table_client->setModel(tmpclient.afficher());

    ui->combo_client->clear();
    ui->combo_client->addItems(tmpclient.listeClients());
}

void MainWindow::on_combo_client_currentTextChanged(const QString &arg1)
{
    int id_client =ui->combo_client->currentText().toInt();
    client c=tmpclient.trouver(id_client);
    ui->nom_prenom_client->setText(c.getNom()+" "+c.getPrenom());
}

void MainWindow::on_filtrer_client_textChanged(const QString &arg1)
{
    ui->table_fac->setModel(tmpfacture.rechercher(ui->filtrer_client->text()));
}

void MainWindow::on_id_client_textChanged(const QString &arg1)
{
    client c=c.trouver(ui->id_client->text().toInt());
    if(c.getNom()!=""){
        ui->test_client->setText("Ce client existe");
    }
    else{
        ui->test_client->setText("");
    }
}

void MainWindow::on_imprim_fact_triggered()
{
    QPrinter printer;
    QPrintDialog dialog(&printer,this);
    dialog.setWindowTitle("Imprimer facture");
    dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    if(dialog.exec()!=QDialog::Accepted){
        return;
    }
}

void MainWindow::on_imprimer_fact_triggered()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->table_fac->model()->rowCount();
    const int columnCount = ui->table_fac->model()->columnCount();

    out <<  "<html>\n"
    <<"<head>\n"
    <<"<meta Content=\"Text/html; charset=Windows-1251\">\n"
    <<  QString("<title>%1</title>\n").arg("strTitle")
    <<  "</head>\n"
    <<"<body bgcolor=#ffffff link=#5000A0>\n"
    <<"<center> <H1>Facture</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++){
        if (!ui->table_fac->isColumnHidden(column)){
            out << QString("<th>%1</th>").arg(ui->table_fac->model()->headerData(column, Qt::Horizontal).toString());
        }
    }
        out << "</tr></thead>\n";
        for (int row = 0; row < rowCount; row++) {
            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->table_fac->isColumnHidden(column)) {
                    QString data = ui->table_fac->model()->data(ui->table_fac->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table> </center>\n"
        <<"</body>\n"
        <<"</html>\n";

        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
        QPrinter printer (QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        doc.setHtml(strStream);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}
