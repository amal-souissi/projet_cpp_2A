#ifndef GRADE_H
#define GRADE_H
#include <QString>
#include<QDate>
#include<QSqlQuery>
#include <QSqlDatabase>
#include<QSql>
#include"connection.h"
#include<QVariant>
#include<QSqlQueryModel>

class grade
{
    int id_G;
    double salaire;
    QString statut;
    int nb_heures;

public:

    grade();
    grade(int,double,QString,int);
    ~grade();

    int Getid_G() { return id_G; }
    void Setid(int id_G) { this->id_G=id_G; }
    double Getsalaire() { return salaire; }
    void Setsalaire(double salaire) { this->salaire=salaire; }
    QString Getstatut() { return statut; }
    void Setstatut(QString statut) { this->statut=statut; }
    int Getnb_heures() { return nb_heures; }
    void Setnb_heures(int nb_heures) { this->nb_heures=nb_heures; }



    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * afficher();
    grade recherche_Id(int);

    QStringList listegrade();
    QStringList listStatuts();
    QList<qreal> nombreEmp();

    QSqlQueryModel * tri();
    QSqlQueryModel * tri_g();
    QSqlQueryModel * tri_N();
    QSqlQueryModel * tri_S();

    QSqlQueryModel * tri_g_N();
    QSqlQueryModel * tri_g_S();
    QSqlQueryModel * tri_S_N();

};

#endif // GRADE_H
