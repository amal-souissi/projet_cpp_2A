#include "client.h"

client::client()
{
    id=0;
    nom="";
    prenom="";
    date_n=QDate(2000,01,01);
}

client::client(int id,QString nom,QString prenom,QDate date_n){
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->date_n=date_n;
}

client::~client(){

}



int client::getId(){
    return id;
}

void client::setId(int id){
    this->id=id;
}

QString client::getNom(){
    return nom;
}

void client::setNom(QString nom){
    this->nom=nom;
}

QString client::getPrenom(){
    return prenom;
}

void client::setPrenom(QString prenom){
    this->prenom=prenom;
}

QDate client::getDate_n(){
    return date_n;
}

void client::setDate_n(QDate date_n){
    this->date_n=date_n;
}

bool client::ajouter(){
    QSqlQuery query;
    query.prepare("insert into client (id,nom,prenom,date_n) values (:id,:nom,:prenom,:date_n)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date_n",date_n);

    return query.exec();
}

bool client::supprimer(int id){
    QSqlQuery q;
    q.prepare("select * from client where id=:id");
    q.bindValue(":id",id);
    q.exec();
    int total=0;
    while(q.next()){
        total++;
    }

    if(total==1){
        QSqlQuery qry;
        qry.prepare("select * from facture where id_client=:id_client");
        qry.bindValue(":id_client",id);
        qry.exec();

        while(qry.next()){
            tmpfacture.supprimer(qry.value(0).toInt());
        }


        QSqlQuery query;
        query.prepare("delete from client where id=:id");
        query.bindValue(":id",id);

        return query.exec();
    }
    else{
        return false;
    }


}

bool client::modifier(int idc){
    QSqlQuery query;
    query.prepare("update client set id=:id,nom=:nom,prenom=:prenom, date_n=:date_n where id=:idc");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date_n",date_n);
    query.bindValue(":idc",idc);

    return query.exec();
}

client client::trouver(int id){
    QSqlQuery query;
    query.prepare("select * from client where id=:id");
    query.bindValue(":id",id);
    query.exec();
    client c;
    while(query.next()){
        c.setId(query.value(0).toInt());
        c.setNom(query.value(1).toString());
        c.setPrenom(query.value(2).toString());
        c.setDate_n(query.value(3).toDate());
    }

    return c;
}

QSqlQueryModel * client::afficher(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from client");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Date naissance"));


    return model;
}

QSqlQueryModel* client::rechercher(const QString &str){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from client where nom like '"+str+"%' or id like '"+str+"%'");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Date naissance"));


    return model;
}

QStringList client::listeClients(){
    QSqlQuery query;
    query.prepare("select id from client");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;
}
