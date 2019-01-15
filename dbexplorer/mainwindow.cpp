#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString filename = QFileDialog::getOpenFileName(this, "open db file", ".", "*.db");

    db.setDatabaseName(filename);
    db.open();

    tables = new QSqlTableModel(parent, db);
    tables->setTable("sqlite_master");
    tables->select();

    ui->tablesView->setModel(tables);
    // hide everything but the table name
    ui->tablesView->hideColumn(0);
    ui->tablesView->hideColumn(2);
    ui->tablesView->hideColumn(3);
    ui->tablesView->hideColumn(4);
    ui->tablesView->setSelectionBehavior(QAbstractItemView::SelectRows);

    setWindowTitle("All Tables");

    data = new QSqlTableModel(parent, db);
}

MainWindow::~MainWindow() {
    delete ui;
}

// we selected a table
void MainWindow::on_tablesView_clicked(const QModelIndex &index) {
    // we need to retrieve the name of the selected table
    QString tname = tables->data(index).toString();
    // and set table's model to this table name
    data->setTable(tname);
    data->select();
    // update the view
    ui->dataView->setModel(data);
    ui->dataView->show();
    // and window title
    setWindowTitle(tname);
    // and are done :-)
}

// create table micki(id integer primary key, title varchar);
// select * from sqlite_master;
// insert into micki values(1,'dklfdlkjf');
// select * from micki;

void MainWindow::on_execButton_clicked() {
    QString contents = ui->queryField->toPlainText();
    QStringList lines = contents.split("\n");

    qDebug() << contents;

    QStringListIterator itlines(lines);
    while(itlines.hasNext()) {

        auto query = itlines.next();
        qDebug() << query;

        QSqlQuery q;
        auto res = q.exec(query);
        qDebug() << res;
    }
}
