#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QDate>
#include<QSqlQuery>
#include<QVariant>
#include<QSqlQueryModel>
#include"facture.h"
class client
{
private:
    int id;
    QString nom;
    QString prenom;
    QDate date_n;
    QString email;
    int num_tel;


    facture tmpfacture;

public:
    client();
    client(int,QString,QString,QDate,QString,int);
    ~client();

    int getId();
    void setId(int);
    QString getNom();
    void setNom(QString);
    QString getPrenom();
    void setPrenom(QString);
    QDate getDate_n();
    void setDate_n(QDate);
    QString getemail();
    void setemail(QString);
    int getnum_tel();
    void setnum_tel(int);


    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    client trouver(int);
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercher(const QString&);
    QStringList listeClients();
};

#endif // CLIENT_H
