#include "facture.h"

facture::facture()
{
    num_fact=0;
    montant=0;
    date_f=QDate(2000,01,01);
    id_client=0;

  }

  facture::facture(int num_fact,double montant,QDate date_f,int id_client )
  {
      this->num_fact=num_fact;
      this->montant=montant;
      this->date_f=date_f;
      this->id_client=id_client;
  }

  facture::~facture()
  {

  }

  int facture::getnum_fact(){
      return num_fact;
  }

  void facture::setnum_fact(int num_fact){
      this->num_fact=num_fact;
  }

  double facture::getmontant()
  {
      return montant;
  }

  void facture::setmontant(double montant){
      this->montant=montant;
  }

  QDate facture::getdate_f(){
      return date_f;
  }

  void facture::setdate_f(QDate date_f){
      this->date_f=date_f;
  }
  int facture::getid_client(){
      return id_client;
  }

  void facture::setid_client(int id_client){
      this->id_client=id_client;
  }

  bool facture::ajouter(){
      QSqlQuery query;
      query.prepare("insert into facture (num_fact,montant,date_f,id_client) values (:num_fact,:montant,:date_f,:id_client)");
      query.bindValue(":num_fact",num_fact);
      query.bindValue(":montant",montant);
      query.bindValue(":date_f",date_f);
      query.bindValue(":id_client",id_client);

      return query.exec();
  }


  bool facture::supprimer(int num_fact){
      QSqlQuery q;
      q.prepare("select * from facture where num_fact=:id");
      q.bindValue(":id",num_fact);
      q.exec();
      int total=0;//calculer nbr de ligne
      while(q.next()){
          total++;
      }

      if(total==1){
          QSqlQuery query;
          query.prepare("delete from facture where num_fact=:num_fact");
          query.bindValue(":num_fact",num_fact);

          return query.exec();
      }
      else{
          return false;
      }

  }


  bool facture::modifier(int numero){
      QSqlQuery query;
      query.prepare("update facture set num_fact=:num_fact,montant=:montant, id_client=:id_client where num_fact=:numero");
      query.bindValue(":num_fact",num_fact);
      query.bindValue(":montant",montant);
      query.bindValue(":id_client",id_client);
      query.bindValue(":numero",numero);

      return query.exec();
  }




  facture facture::trouver(int num_fact){
      QSqlQuery query;
      query.prepare("select * from facture where num_fact=:num_fact");
      query.bindValue(":num_fact",num_fact);
      query.exec();
      facture f;
      while(query.next()){
          f.setnum_fact(query.value(0).toInt());
          f.setmontant(query.value(1).toDouble());
          f.setdate_f(query.value(2).toDate());
          f.setid_client(query.value(3).toInt());
      }

      return f;
  }

  QSqlQueryModel * facture::afficher(){
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select num_fact,montant,date_f,nom from facture inner join client on client.id=facture.id_client ");
      model->setHeaderData(0,Qt::Horizontal, QObject::tr("num_fact"));
      model->setHeaderData(1,Qt::Horizontal, QObject::tr("montant"));
      model->setHeaderData(2,Qt::Horizontal, QObject::tr("date_f"));
      model->setHeaderData(3,Qt::Horizontal, QObject::tr("Client"));


      return model;
  }

  QSqlQueryModel* facture::rechercher(const QString &str){
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select num_fact,montant,date_f,nom from facture inner join client on client.id=facture.id_client where nom like '"+str+"%' or id like '"+str+"%' or prenom like '"+str+"%'");
      model->setHeaderData(0,Qt::Horizontal, QObject::tr("Id"));
      model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom"));
      model->setHeaderData(2,Qt::Horizontal, QObject::tr("Prenom"));
      model->setHeaderData(3,Qt::Horizontal, QObject::tr("Date naissance"));


      return model;
  }

  int facture::calculer(int mois){
      QSqlQuery q;
      q.prepare("select * from facture where extract(month from date_f)=:mois");
      q.bindValue(":mois",mois);
      q.exec();
      int total=0;//calculer nbr de ligne
      while(q.next()){
          total++;
      }
      return total;
  }
