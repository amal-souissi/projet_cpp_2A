#include "intervenant.h"
#include "QSqlRecord"
#include<QMessageBox>
#include<QSqlRecord>
#include <QString>
#include <QSqlQuery>
intervenant :: intervenant()
{

}
  intervenant::intervenant( int id ,int numero , QString prenom,QString nom)
{

    this->id = id;
    this->numero = numero;
    this->prenom = prenom;
    this->nom = nom;


 }

bool intervenant::ajouter()
{
        QSqlQuery query;
        query.prepare("INSERT INTO INTERVENANT(id,numero,prenom,nom) "
                      "VALUES (:id,:numero,:prenom,:nom)");
        query.bindValue(":id",id);
        query.bindValue(":numero",numero);
        query.bindValue(":prenom",prenom);
         query.bindValue(":nom",nom);




        return    query.exec();



}
QSqlQueryModel * intervenant ::afficher()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from INTERVENANT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMERO "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM "));








        return model;
}
bool intervenant :: supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from INTERVENANT where id = :id");
    query.bindValue(":id",id);
    return    query.exec();

}

bool intervenant::modifier(int id,int numero)
{
    QSqlQuery query;
    QString r = QString::number(numero);


    query.prepare("UPDATE INTERVENANT SET numero= :numero where id= :id ");

    query.bindValue(":id",id);
    query.bindValue(":numero",r);


       return    query.exec();

}
QSqlQueryModel * intervenant::trier_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from INTERVENANT ORDER BY id");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom"));
        return model;
}
QSqlQueryModel *  intervenant::rechercher(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(id);
    model->setQuery("select * from INTERVENANT where (id LIKE '"+res+"%' ) ");


            return  model;


}
