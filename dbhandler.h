#ifndef DBHANDLER_H
#define DBHANDLER_H
#include <QtSql>
#include <QtDebug>

class DBHandler
{
public:
    DBHandler();
    bool CreateDB();
    QSqlDatabase *OpenDB();

private:
    QSqlDatabase stylesDB;

};

#endif // DBHANDLER_H
