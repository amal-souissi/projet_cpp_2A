#ifndef INTERVENANT_H
#define INTERVENANT_H
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QString>
class intervenant
{
    QString nom , prenom ;
          int id , numero;
    public:
          intervenant();
             //constructor

                intervenant(int,int,QString,QString);
                int getid(){return id;}
                int getnumero(){return numero;}
                QString getprenom(){return  prenom;}
                QString getnom(){return nom;}


                // methodes
                bool ajouter();
                QSqlQueryModel * afficher();
                bool supprimer(int);
                bool modifier(int,int);
                QSqlQueryModel * trier_id();
                    QSqlQueryModel * rechercher(int);
         };


#endif // INTERVENANT_H
