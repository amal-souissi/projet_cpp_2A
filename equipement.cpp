#include "equipement.h"
#include "QSqlRecord"
#include<QMessageBox>
#include<QSqlRecord>
#include <QString>
#include <QSqlQuery>
equipement :: equipement()
{

}
   equipement:: equipement( int ide  , QString marke,QString fonction )
{

    this->ide = ide;
    this->marke = marke;
    this->fonction =fonction;


 }

bool equipement ::ajouter()
{
        QSqlQuery query;
        query.prepare("INSERT INTO EQUIPEMENT(ide,marke,fonction) "
                      "VALUES (:ide,:marke,:fonction)");
        query.bindValue(":ide",ide);
        query.bindValue(":marke",marke);
        query.bindValue(":fonction",fonction);





        return    query.exec();



}
QSqlQueryModel * equipement ::afficher()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from EQUIPEMENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDE"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("MARKE "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("FONCTION "));

  return model;
}

bool equipement :: supprimer(int ide )
{
    QSqlQuery query;
    query.prepare("Delete from EQUIPEMENT where ide = :ide");
    query.bindValue(":ide",ide);
    return    query.exec();

}

bool equipement ::modifier(int ide, QString fonction)
{
    QSqlQuery query;



    query.prepare("UPDATE EQUIPEMENT SET fonction= :fonction where ide= :ide ");

    query.bindValue(":ide",ide);
    query.bindValue(":fonction",fonction);


       return    query.exec();

}

QSqlQueryModel * equipement::trier_ide()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from EQUIPEMENT ORDER BY ide");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ide"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("fonction "));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("marke "));
        return model;
}
QSqlQueryModel *  equipement::rechercher(int ide)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(ide);
    model->setQuery("select * from EQUIPEMENT where (ide LIKE '"+res+"%' ) ");


            return  model;


}








