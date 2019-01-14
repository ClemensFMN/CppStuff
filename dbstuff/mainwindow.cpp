#include "mainwindow.h"
#include <QSqlDatabase>
#include <QtSql>
#include <QTableView>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    /* init the database */
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    // store in memory
    // db.setDatabaseName(":memory:");
    // store in file
    db.setDatabaseName("dbfile.db");
    db.open();
    // in case of memory storage, we need to always setup the db; in case of file storage, only once
    //QSqlQuery q;
    //q.exec(QLatin1String("create table books(id integer primary key, title varchar, author varchar, year integer, rating integer)"));
    /* insert into db way one (easier for programmatical setup)
    q.prepare(QLatin1String("insert into books(title, year, author, rating) values(?, ?, ?, ?)"));
    q.addBindValue("Book A");
    q.addBindValue(1980);
    q.addBindValue("Author A");
    q.addBindValue(3);
    q.exec();
    */
    /* insert into db way two ("Manual" insert statements)
    q.prepare(QLatin1String("insert into books(title, year, author, rating) values('Book A', 1980, 'Author A', 2)"));
    q.exec();
    q.prepare(QLatin1String("insert into books(title, year, author, rating) values('Book B', 1984, 'Author B', 4)"));
    q.exec();
    */
    /* init db finished */

    /* execute "random" sql query */
    QSqlQuery q("select * from books;");
    while(q.next()) {
        qDebug() << q.value(0).toString() << q.value(1).toString() << q.value(2).toString() << q.value(3).toString();
    }

    /* connect SqlTableModel to table and display on mainwindow */
    QSqlTableModel *model = new QSqlTableModel(parent, db);
    model->setTable("books");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();

    QTableView *view = new QTableView();
    view->setModel(model);
    setCentralWidget(view);
}

MainWindow::~MainWindow() {

}
