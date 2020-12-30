#include "grade.h"

grade::grade()
{
    id_G=0;
    salaire=0;
    statut="";
    nb_heures=0;
}
grade::grade(int id_G,double salaire,QString statut,int nb_heures)
{
    this->id_G=id_G;
    this->salaire=salaire;
    this->statut=statut;
    this->nb_heures=nb_heures;
}

grade::~grade(){}

bool grade::ajouter(){

    QSqlQuery query;
    QString id_g=QString::number(id_G);
    QString sal=QString::number(salaire);
    QString nb=QString::number(nb_heures);

    query.prepare("insert into GRADE (id_G,salaire,statut,nb_heures) values (:id_G,:salaire,:statut,:nb_heures)");
    query.bindValue(":id_G",id_g);//injection
    query.bindValue(":salaire",sal);
    query.bindValue(":statut",statut);
    query.bindValue(":nb_heures",nb);
    return query.exec();
}

bool grade::supprimer(int id_G){
    QSqlQuery query;
    QString id_g=QString::number(id_G);
    query.prepare("delete from GRADE where id_G=:id_G");
    query.bindValue(":id_G",id_g);
    return query.exec();
}
bool grade::modifier(int idgr){
    QSqlQuery query;
    QString id_gr=QString::number(idgr);
    QString id_g=QString::number(id_G);
    QString sal=QString::number(salaire);
    QString nb=QString::number(nb_heures);
    query.prepare("update GRADE set id_G=:id_G,salaire=:salaire,statut=:statut,nb_heures=:nb_heures where id_G=:idgr");
    query.bindValue(":idgr",id_gr);
    query.bindValue(":id_G",id_g);
    query.bindValue(":salaire",sal);
    query.bindValue(":statut",statut);
    query.bindValue(":nb_heures",nb);
    return query.exec();
}
QSqlQueryModel * grade::afficher(){
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from GRADE");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_G"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("SALAIRE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("STATUT"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_HEURES"));
        return model;
}

grade grade::recherche_Id(int id_G){
    QSqlQuery query;
    QString id_g=QString::number(id_G);
    query.prepare("select * from GRADE where id_G=:id_G");
    query.bindValue(":id_G",id_g);
    query.exec();
    grade G;
    while(query.next()){
        G.Setid(id_G);
        G.Setsalaire(query.value(1).toDouble());
        G.Setnb_heures(query.value(3).toInt());
        G.Setstatut(query.value(2).toString());
    }
    return G;
}

QStringList grade::listegrade(){
    QSqlQuery query;
    query.prepare("select id_g from grade");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }


    return list;
}

QStringList grade::listStatuts(){
    QSqlQuery query;
    query.prepare("select statut from grade");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }


    return list;
}

QList<qreal>  grade::nombreEmp(){
    QList<qreal> list;

    QSqlQuery query;
    query.prepare("select id_g from grade");
    query.exec();

    while(query.next()){
        QSqlQuery q;
        q.prepare("select * from employe where id_grade=:id");
        q.bindValue(":id",query.value(0).toInt());
        q.exec();
        int total=0;
        while(q.next()){
            total++;
        }
        list.append(total);
    }

    return list;

}
    QSqlQueryModel * grade::tri(){
        QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery(" select * from grade order by id_g,salaire,nb_heures");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_G"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("SALAIRE"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("STATUT"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_HEURES"));


            return model;

    }
    QSqlQueryModel * grade::tri_g(){
        QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery(" select * from grade order by id_g");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_G"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("SALAIRE"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("STATUT"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_HEURES"));
            return model;
    }


    QSqlQueryModel * grade::tri_N(){

        QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery(" select * from grade order by nb_heures");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_G"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("SALAIRE"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("STATUT"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_HEURES"));
            return model;

    }
    QSqlQueryModel * grade::tri_S(){
        QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery(" select * from grade order by salaire");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_G"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("SALAIRE"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("STATUT"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_HEURES"));
            return model;
    }
    QSqlQueryModel *grade:: tri_g_N(){


        QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery(" select * from grade order by id_g,nb_heures");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_G"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("SALAIRE"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("STATUT"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_HEURES"));
            return model;

    }
    QSqlQueryModel *grade:: tri_g_S(){

        QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery(" select * from grade order by id_g,salaire");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_G"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("SALAIRE"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("STATUT"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_HEURES"));
            return model;
    }
    QSqlQueryModel *grade::  tri_S_N(){

        QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery(" select * from grade order by salaire,nb_heures");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_G"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("SALAIRE"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("STATUT"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_HEURES"));
            return model;
    }
