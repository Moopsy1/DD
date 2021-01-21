#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbhandler.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(!OpenDB()){
        qDebug() << "Database did not open";
    }
    else {
        qDebug() << "Database DID open";
    }

    //set table to view this sql Query
    this-> view_model = new QSqlQueryModel;
    ui->tableView->setModel(view_model);
    this->view_model->setQuery("SELECT * from STYLES");


}

MainWindow::~MainWindow()
{
    stylesDB.close();
    delete ui;
}

void MainWindow::on_Add_Style_clicked()
{
    qDebug() << "Add Style Clicked";
}

void MainWindow::on_Del_Style_clicked()
{
    qDebug() << "Del Style Clicked";
}

bool MainWindow::OpenDB()
{
    stylesDB = QSqlDatabase::addDatabase("QSQLITE");
    stylesDB.setDatabaseName("myDB.db");
    if(stylesDB.open()){
        ui->statusBar->showMessage("DBOpened",1000);
        stylesDB.exec("PRAGMA foreign_keys = ON;");
        return true;
    }
    else{
        ui->statusBar->showMessage("DB Failed To Open",10000);
        qWarning() << "DBOpened: " << stylesDB.lastError();
        return false;
    }
}
