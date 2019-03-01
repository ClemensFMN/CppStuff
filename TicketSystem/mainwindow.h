#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QtSql>
#include <QTableView>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_insertButton_clicked();

    void on_storeButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlRelationalTableModel *model;
};

#endif // MAINWINDOW_H
