#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
Ticket system with customers & events which have a many-to-many relationship. This is the application for the admin
This relationship is modeled via a third table (booking) with foreign keys into the customer and event table, respectively.

This requires a QSqlRelationalTableModel and corresponding calls to setRelation to connect to the customer and event tables

TODO:
  - CRUD users (deletion with handling of booked courses), display upcoming / visited events
  - CRUD events (add start / end date to events)
  - CRUD upcoming bookings (+ check that event is not fully booked)
*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* init the database */
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    // store in file
    db.setDatabaseName("dbfile.db");
    db.open();

    /*
        sqlite> create table customer(cid integer primary key, name varchar);
        sqlite> create table event(eid integer primary key, name varchar);
        sqlite> create table booking(bid integer primary key, cid integer, eid integer, foreign key(cid) references customer(cid), foreign key(eid) references event(eid));

        sqlite> insert into customer values(null, 'Clemens');
        sqlite> insert into customer values(null, 'Susi');

        sqlite> insert into event values(null, 'Mathe 1');
        sqlite> insert into event values(null, 'Physik');

        Clemens is visting Mathe 1 + Physik
        sqlite> insert into booking values(null, 1,1);
        sqlite> insert into booking values(null, 1,2);

        Susi is visting Mathe 1
        sqlite> insert into booking values(null, 2,1);

        What courses does Clemens visit?
        select event.name from event inner join booking on event.eid=booking.eid where booking.cid=1;

        Who is visting Mathe 1?
        select customer.name from customer inner join booking on customer.cid=booking.cid where booking.eid=1;
    */

       model = new QSqlRelationalTableModel(parent, db);
       model->setTable("booking");
       model->setEditStrategy(QSqlTableModel::OnManualSubmit);
       model->setRelation(1, QSqlRelation("customer", "cid", "name"));
       model->setRelation(2, QSqlRelation("event", "eid", "name"));
       model->select();

       ui->tableView->setModel(model);
       ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
       ui->tableView->hideColumn(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// make a booking -> new entry in booking
void MainWindow::on_insertButton_clicked()
{
    model->insertRow(model->rowCount());
}

// Due to the FK constraints, the editStrategy must be OnManualSubmit -> we need to excplicitely store changes
void MainWindow::on_storeButton_clicked()
{
    model->submitAll();
}
