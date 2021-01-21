#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//private var
private slots:
    void on_Add_Style_clicked();

    void on_Del_Style_clicked();

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *view_model;


//private methods
private:
    bool OpenDB();
};

#endif // MAINWINDOW_H
