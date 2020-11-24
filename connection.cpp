#include "connection.h"

connection::connection()
{

}

bool connection::createconnection(){
   bool test=false;
   QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

   db.setDatabaseName("esprit");
   db.setUserName("system");
   db.setPassword("amal");

   if(db.open())
       test=true;
   return test;
}
