#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
    create table city(cid integer primary key, name varchar);
    create table person(pid integer primary key, name varchar, cid integer, foreign key(cid) references city(cid));

    insert into city values(null, 'Wien');
    insert into city values(null, 'Linz');

    insert into person values(null, 'Clemens', 1);
    insert into person values(null, 'Susi', 1);
    insert into person values(null, 'Herbert', 2);
    */


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");
    db.open();

    QSqlQuery q("select person.name, city.name from person inner join city on person.cid=city.cid;");
        while(q.next()) {
            qDebug() << q.value(0).toString() << q.value(1).toString();
        }

    QTableView *view = new QTableView();
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select person.name, city.name from person inner join city on person.cid=city.cid;");
    model->setHeaderData(0, Qt::Horizontal, "Person Name");
    model->setHeaderData(1, Qt::Horizontal, "City Name");
    view->setModel(model);
    setCentralWidget(view);

}

MainWindow::~MainWindow()
{
    delete ui;
}
