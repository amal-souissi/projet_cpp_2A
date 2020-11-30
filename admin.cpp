#include "admin.h"

admin::admin()
{

}

bool admin::login(QString identifiant,QString motdepasse){
    QSqlQuery query;
    query.prepare("select * from login where identifiant=:identifiant and motdepasse=:motdepasse ");
    query.bindValue(":identifiant",identifiant);
    query.bindValue(":motdepasse",motdepasse);

    query.exec();

    int total=0;
    while(query.next()){
        total++;
    }
    if(total!=0){
        return true;
    }
    else{
        return false;
    }
}
