#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"client.h"
#include"facture.h"
#include<QMessageBox>
#include<QValidator>
#include"statistiquesfact.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_client_triggered();

    void on_trouver_client_triggered();

    void on_supprimer_client_triggered();

    void on_modifier_client_triggered();

    void on_recherche_client_textChanged(const QString &arg1);

    void on_suprimer_fac_triggered();

    void on_trouver_fac_triggered();

    void on_ajouter_fac_triggered();

    void on_modifier_fac_triggered();

    void on_stat_facture_triggered();

    void on_tabWidget_currentChanged(int index);

    void on_combo_client_currentTextChanged(const QString &arg1);

    void on_filtrer_client_textChanged(const QString &arg1);

    void on_id_client_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    client tmpclient;
    facture tmpfacture;
};
#endif // MAINWINDOW_H
