#ifndef FACTURE_H
#define FACTURE_H
#include<QString>
#include<QDate>
#include<QSqlQuery>
#include<QVariant>
#include<QSqlQueryModel>

class facture
{
private:
    int num_fact;
    double montant;
    QDate date_f;
    int id_client;

public:
    facture();
    facture(int,double,QDate,int);
    ~facture();

    int getnum_fact();
    void setnum_fact(int);
    double getmontant();
    void setmontant(double);
    QDate getdate_f();
    void setdate_f(QDate);
    int getid_client();
    void setid_client(int);

    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    facture trouver (int);
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercher(const QString&);
    int calculer(int mois);
};

#endif // FACTURE_H
