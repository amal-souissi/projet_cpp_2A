#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <QMainWindow>
#include"employe.h"
#include"grade.h"
#include <QMessageBox>
#include"grade.h"
#include<QValidator>
#include"statistiques.h"
#include"client.h"
#include"facture.h"
#include<QMessageBox>
#include<QValidator>
#include "statistiquesfact.h"
#include<QPrinter>
#include<QPrintDialog>
#include"arduino.h"

namespace Ui {
class integration;
}

class integration : public QMainWindow
{
    Q_OBJECT

public:
    explicit integration(QWidget *parent = nullptr);
    ~integration();

private slots:
    void on_actionajoutergrade_triggered();

    void on_actionsupprimergrade_triggered();

    void on_actionmodifiergrade_triggered();

    void on_actionrecherchergrade_triggered();

    void on_actionajouteremploye_triggered();

    void on_actionsupprimeremploye_triggered();

    void on_actionmodifieremploye_triggered();

    void on_actionrechercheremploye_triggered();

    void on_actionstatistiqueemploye_triggered();

    void on_tabWidget_2_currentChanged(int index);

    void on_actionajouterclient_triggered();

    void on_actionsupprimerclient_triggered();

    void on_actionmodifierclient_triggered();

    void on_actionrechercherclient_triggered();

    void on_actionajouterfacture_triggered();

    void on_actionsupprimerfacture_triggered();

    void on_actionmodifierfacture_triggered();

    void on_actionrechercherfacture_triggered();

    void on_actionstatistiquefacture_triggered();

    void on_actionimprimerfacture_triggered();

    void on_tabWidget_4_currentChanged(int index);

    void on_lineEdit_rechercher_emp_2_textChanged(const QString &arg1);

    void on_checkBox_salaire_stateChanged(int arg1);

    void on_checkBox_grade2_stateChanged(int arg1);

    void on_checkBox_nombre_stateChanged(int arg1);

    void on_recherche_client_textChanged(const QString &arg1);

    void on_filtrer_client_textChanged(const QString &arg1);

    void update_label();

private:
    Ui::integration *ui;
    employe tmpemploye;//bech nesta3melha par defaut
    grade    tmpgrade;
    client tmpclient;
    facture tmpfacture;
    arduino A;
    QString data;
};

#endif // INTEGRATION_H
