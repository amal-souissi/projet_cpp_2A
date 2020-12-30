#include "integration.h"
#include "ui_integration.h"
#include<QToolBar>
integration::integration(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::integration)
{
    ui->setupUi(this);
    QBoxLayout *toolLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    toolLayout->addWidget(ui->toolBar);
    ui->Grades->setLayout(toolLayout);

    QBoxLayout *toolLayout1 = new QBoxLayout(QBoxLayout::TopToBottom, this);
    toolLayout1->addWidget(ui->toolBar_2);
    ui->Employes->setLayout(toolLayout1);

    QBoxLayout *toolLayout2 = new QBoxLayout(QBoxLayout::TopToBottom, this);
    toolLayout2->addWidget(ui->toolBar_3);
    ui->tab_3->setLayout(toolLayout2);

    QBoxLayout *toolLayout3 = new QBoxLayout(QBoxLayout::TopToBottom, this);
    toolLayout3->addWidget(ui->toolBar_4);
    ui->tab_4->setLayout(toolLayout3);


    int result=A.connect_arduino(); // lancer la connexion � arduino
        switch(result){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
        }
         QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
         //le slot update_label suite � la reception du signal readyRead (reception des donn�es).

}

integration::~integration()
{
    delete ui;
}


void integration::update_label()
{

    if(data.length()<11){
        data+=A.read_from_arduino();
    }else{
        //A.write_to_arduino(tmpemploye.getEntrepriseLocation(data).getNom().toStdString().c_str());
        data="";
    }
    qDebug()<<data;

}

void integration::on_actionajoutergrade_triggered()
{
    grade G(ui->id_grade->text().toInt(),ui->sal_gr->text().toInt(),ui->status_grade->text(),ui->nbr_heures->text().toInt());
    bool test=G.ajouter();
    if(test){
        QMessageBox::information(nullptr,QObject::tr("GRADE"),QObject::tr("grade ajouté\n" "click ok to exit"),QMessageBox::Ok);
        ui->id_grade->setText("");//bech ba3ed mankamel l ajout yarja3 a 0
        ui->sal_gr->setText("");
        ui->status_grade->setText("");
        ui->nbr_heures->setText("");

        ui->table_grade->setModel(tmpgrade.afficher());//actualisation

        ui->comboBox_idgrade_2->clear();
        ui->comboBox_idgrade_2->addItems(tmpgrade.listegrade());
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("GRADE"),QObject::tr("Erreur!\n" "click ok to exit"),QMessageBox::Ok);
    }
}

void integration::on_actionsupprimergrade_triggered()
{
    bool test=tmpgrade.supprimer(ui->id_grade->text().toInt());
    if(test){
        QMessageBox::information(nullptr,QObject::tr("GRADE"),QObject::tr("Grade supprimé\n" "click ok to exit"),QMessageBox::Ok);
        ui->id_grade->setText("");
        ui->table_grade->setModel(tmpgrade.afficher());
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("GRADE"),QObject::tr("Erreur!\n" "click ok to exit"),QMessageBox::Ok);
    }
}

void integration::on_actionmodifiergrade_triggered()
{
    grade G(ui->id_grade->text().toInt(),ui->sal_gr->text().toInt(),ui->status_grade->text(),ui->nbr_heures->text().toInt());
    bool test=G.modifier(ui->id_grade->text().toInt());
    if(test){
        QMessageBox::information(nullptr,QObject::tr("GRADE"),QObject::tr("grade modifié\n" "click ok to exit"),QMessageBox::Ok);
        ui->id_grade->setText("");//bech ba3ed mankamel l ajout yarja3 a 0
        ui->sal_gr->setText("");
        ui->status_grade->setText("");
        ui->nbr_heures->setText("");

        ui->table_grade->setModel(tmpgrade.afficher());//actualisation

        ui->comboBox_idgrade->clear();
        ui->comboBox_idgrade->addItems(tmpgrade.listegrade());
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("GRADE"),QObject::tr("Erreur!\n" "click ok to exit"),QMessageBox::Ok);
    }
}

void integration::on_actionrecherchergrade_triggered()
{
    grade G=tmpgrade.recherche_Id(ui->id_grade->text().toInt());
    ui->status_grade->setText(G.Getstatut());
    ui->sal_gr->setText(QString::number(G.Getsalaire()));
    ui->nbr_heures->setText(QString::number(G.Getnb_heures()));
}

void integration::on_actionajouteremploye_triggered()
{
    employe e(ui->id_e_2->text().toInt(),ui->nom_e_2->text(),ui->prenom_e_2->text(),ui->date_n_e_2->date(),ui->email_e_2->text(),ui->lineEdit_tele_2->text().toInt(),ui->comboBox_idgrade_2->currentText().toInt());
    bool test=e.ajouter();
    if(test){
        QMessageBox::information(nullptr,QObject::tr("Employe"),QObject::tr("employe ajouté\n" "click ok to exit"),QMessageBox::Ok);
        ui->id_e_2->setText("");//bech ba3ed mankamel l ajout yarja3 a 0
        ui->nom_e_2->setText("");
        ui->prenom_e_2->setText("");
        ui->email_e_2->setText("");

        ui->table_employe_2->setModel(tmpemploye.afficher());//actualisation
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("Employe"),QObject::tr("Erreur!\n" "click ok to exit"),QMessageBox::Ok);
    }

}


void integration::on_actionsupprimeremploye_triggered()
{
    bool test=tmpemploye.supprimer(ui->id_e_2->text().toInt());
    if(test){
        QMessageBox::information(nullptr,QObject::tr("Employe"),QObject::tr("employe supprimé\n" "click ok to exit"),QMessageBox::Ok);
        ui->id_e_2->setText("");
        ui->table_employe_2->setModel(tmpemploye.afficher());
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("Employe"),QObject::tr("Erreur!\n" "click ok to exit"),QMessageBox::Ok);
    }
}


void integration::on_actionmodifieremploye_triggered()
{
    employe e(ui->id_e_2->text().toInt(),ui->nom_e_2->text(),ui->prenom_e_2->text(),ui->date_n_e_2->date(),ui->email_e_2->text(),ui->lineEdit_tele_2->text().toInt(),ui->comboBox_idgrade_2->currentText().toInt());
    bool test=e.modifier(ui->id_e->text().toInt());
    if(test){
        QMessageBox::information(nullptr,QObject::tr("Employe"),QObject::tr("employe modifié\n" "click ok to exit"),QMessageBox::Ok);
        ui->id_e_2->setText("");
        ui->nom_e_2->setText("");
        ui->prenom_e_2->setText("");
        ui->email_e_2->setText("");

        ui->table_employe_2->setModel(tmpemploye.afficher());
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("Employe"),QObject::tr("Erreur!\n" "click ok to exit"),QMessageBox::Ok);
    }
}

void integration::on_actionrechercheremploye_triggered()
{
    employe e=tmpemploye.recherche_Id(ui->id_e_2->text().toInt());
    ui->nom_e_2->setText(e.Getnom());
    ui->prenom_e_2->setText(e.Getprenom());
    ui->email_e_2->setText(e.Getemail());
    ui->date_n_e_2->setDate(e.Getdate_naissance());
    ui->lineEdit_tele_2->setText(QString::number(e.Gettel()));
}

void integration::on_actionstatistiqueemploye_triggered()
{
    statistiques *s=new statistiques();
    s->show();
}

void integration::on_tabWidget_2_currentChanged(int index)
{
    ui->table_employe_2->setModel(tmpemploye.afficher());
    ui->table_grade->setModel(tmpgrade.afficher());//actualisation
    ui->comboBox_idgrade_2->clear();
    ui->comboBox_idgrade_2->addItems(tmpgrade.listegrade());
}

void integration::on_actionajouterclient_triggered()
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

void integration::on_actionsupprimerclient_triggered()
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

void integration::on_actionmodifierclient_triggered()
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

void integration::on_actionrechercherclient_triggered()
{

    ui->table_client->setModel(tmpclient.rechercher(ui->recherche_client->text()));
}

void integration::on_actionajouterfacture_triggered()
{

    int num_fact=ui->num_fact->text().toInt();
    double montant=ui->montant_fac->text().toDouble();
    QDate date_f=date_f.currentDate();
    int id_client=ui->combo_client->currentText().toInt();
    qDebug()<<date_f;
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

void integration::on_actionsupprimerfacture_triggered()
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

void integration::on_actionmodifierfacture_triggered()
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

void integration::on_actionrechercherfacture_triggered()
{
    int num_fact=ui->num_fact->text().toInt();
    facture f=tmpfacture.trouver(num_fact);
    QString montant=QString::number(f.getmontant());
    ui->montant_fac->setText(montant);
    //ui->date_fac->setDate(f.getdate_f());
    ui->type->setText(QString::number(f.getid_client()));
}

void integration::on_actionstatistiquefacture_triggered()
{
    statistiquesfact *s=new statistiquesfact();
    s->show();
}

void integration::on_actionimprimerfacture_triggered()
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

void integration::on_tabWidget_4_currentChanged(int index)
{
    ui->table_fac->setModel(tmpfacture.afficher());
    ui->table_client->setModel(tmpclient.afficher());

    ui->combo_client->clear();
    ui->combo_client->addItems(tmpclient.listeClients());
}

void integration::on_lineEdit_rechercher_emp_2_textChanged(const QString &arg1)
{
    bool nom=ui->checkBox_nom_2->isChecked();
    bool prenom=ui->checkBox_prenom_2->isChecked();
    bool grade=ui->checkBox_grade_2->isChecked();

    if((nom && prenom && grade) ||(!nom && !prenom && !grade)){
        ui->table_employe_2->setModel(tmpemploye.recherche(ui->lineEdit_rechercher_emp_2->text()));
    }
    else if(nom){
        if(prenom){
           ui->table_employe_2->setModel(tmpemploye.recherche_n_p(ui->lineEdit_rechercher_emp_2->text()));
        }
        else if(grade){
            ui->table_employe_2->setModel(tmpemploye.recherche_n_g(ui->lineEdit_rechercher_emp_2->text()));
        }
        else{
            ui->table_employe_2->setModel(tmpemploye.recherche_n(ui->lineEdit_rechercher_emp_2->text()));
        }
    }
    else if(prenom){
        if(grade){
            ui->table_employe_2->setModel(tmpemploye.recherche_p_g(ui->lineEdit_rechercher_emp_2->text()));
        }
        else{
            ui->table_employe_2->setModel(tmpemploye.recherche_p(ui->lineEdit_rechercher_emp_2->text()));
        }
    }
    else{
        ui->table_employe_2->setModel(tmpemploye.recherche_g(ui->lineEdit_rechercher_emp_2->text()));
    }
}



void integration::on_checkBox_salaire_stateChanged(int arg1)
{
    bool grade=ui->checkBox_grade2->isChecked();
    bool salaire=ui->checkBox_salaire->isChecked();
    bool nombre=ui->checkBox_nombre->isChecked();
    if((grade && salaire && nombre) ||(!grade && !salaire && !nombre)){
        ui->table_grade->setModel(tmpgrade.tri());
    }
    else if(grade){
        if(salaire){
            ui->table_grade->setModel(tmpgrade.tri_g_S());
        }
        else if(nombre){
            ui->table_grade->setModel(tmpgrade.tri_g_N());
        }
        else{
            ui->table_grade->setModel(tmpgrade.tri_g());
        }
    }
    else if(salaire){
        if(nombre){
            ui->table_grade->setModel(tmpgrade.tri_S_N());
        }
        else{
            ui->table_grade->setModel(tmpgrade.tri_S());
        }
    }
    else{
        ui->table_grade->setModel(tmpgrade.tri_N());
    }
}

void integration::on_checkBox_grade2_stateChanged(int arg1)
{
    bool grade=ui->checkBox_grade2->isChecked();
    bool salaire=ui->checkBox_salaire->isChecked();
    bool nombre=ui->checkBox_nombre->isChecked();
    if((grade && salaire && nombre) ||(!grade && !salaire && !nombre)){
        ui->table_grade->setModel(tmpgrade.tri());
    }
    else if(grade){
        if(salaire){
            ui->table_grade->setModel(tmpgrade.tri_g_S());
        }
        else if(nombre){
            ui->table_grade->setModel(tmpgrade.tri_g_N());
        }
        else{
            ui->table_grade->setModel(tmpgrade.tri_g());
        }
    }
    else if(salaire){
        if(nombre){
            ui->table_grade->setModel(tmpgrade.tri_S_N());
        }
        else{
            ui->table_grade->setModel(tmpgrade.tri_S());
        }
    }
    else{
        ui->table_grade->setModel(tmpgrade.tri_N());
    }
}

void integration::on_checkBox_nombre_stateChanged(int arg1)
{
    bool grade=ui->checkBox_grade2->isChecked();
    bool salaire=ui->checkBox_salaire->isChecked();
    bool nombre=ui->checkBox_nombre->isChecked();
    if((grade && salaire && nombre) ||(!grade && !salaire && !nombre)){
        ui->table_grade->setModel(tmpgrade.tri());
    }
    else if(grade){
        if(salaire){
            ui->table_grade->setModel(tmpgrade.tri_g_S());
        }
        else if(nombre){
            ui->table_grade->setModel(tmpgrade.tri_g_N());
        }
        else{
            ui->table_grade->setModel(tmpgrade.tri_g());
        }
    }
    else if(salaire){
        if(nombre){
            ui->table_grade->setModel(tmpgrade.tri_S_N());
        }
        else{
            ui->table_grade->setModel(tmpgrade.tri_S());
        }
    }
    else{
           ui->table_grade->setModel(tmpgrade.tri_N());
    }
}

void integration::on_recherche_client_textChanged(const QString &arg1)
{
          ui->table_client->setModel(tmpclient.rechercher(ui->recherche_client->text()));
}


void integration::on_filtrer_client_textChanged(const QString &arg1)
{
    ui->table_fac->setModel(tmpfacture.rechercher(ui->filtrer_client->text()));
}
