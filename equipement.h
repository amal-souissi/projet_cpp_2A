#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QString>

class equipement
{
    QString marke , fonction;
          int ide ;
    public:
         equipement();
             //constructor

                equipement(int ,QString,QString);
                int getide(){return ide; }
                QString getmarke(){return  marke;}
                QString getfonction(){return fonction;}


                // methodes
                bool ajouter();
                QSqlQueryModel * afficher();
                bool supprimer(int);
                bool modifier(int,QString);

                QSqlQueryModel * trier_ide();
                    QSqlQueryModel * rechercher(int);
         };


#endif // EQUIPEMENT_H
