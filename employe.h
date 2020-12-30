#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include<QDate>
#include<QSqlQuery>
#include <QSqlDatabase>
#include<QSql>
#include"connection.h"
#include<QVariant>
#include<QSqlQueryModel>
class employe
{
  int id;
  QString nom;
  QString prenom;
  QDate date_naissance;
  QString email;
  int telephone;
  int id_grade;
public:
    employe();
    employe(int,QString,QString,QDate,QString,int,int);
    ~employe();

    int Getid() { return id; }
    void Setid(int id) { this->id=id; }
    QString Getnom() { return nom; }
    void Setnom(QString nom) { this->nom=nom; }
    QString Getprenom() { return prenom; }
    void Setprenom(QString prenom) { this->prenom=prenom; }
    QDate Getdate_naissance() { return date_naissance; }
    void Setdate_naissance(QDate date_naissance) { this->date_naissance=date_naissance; }
    QString Getemail() { return email; }
    void Setemail(QString email) { this->email=email; }
    int Gettel() { return telephone; }
    void Settel(int telephone) { this->telephone=telephone; }
    int Getid_grade() { return id_grade; }
    void Setid_grade(int id_grade) { this->id_grade=id_grade; }



    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * afficher();
    employe recherche_Id(int);
    QSqlQueryModel * recherche(const QString&);
    QSqlQueryModel * recherche_n(const QString&);
    QSqlQueryModel * recherche_p(const QString&);
    QSqlQueryModel * recherche_g(const QString&);

    QSqlQueryModel * recherche_n_p(const QString&);
    QSqlQueryModel * recherche_n_g(const QString&);
    QSqlQueryModel * recherche_p_g(const QString&);



};

#endif // EMPLOYE_H
