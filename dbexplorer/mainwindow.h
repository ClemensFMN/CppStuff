#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QFileDialog>
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
    void on_tablesView_clicked(const QModelIndex &index);

    void on_execButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *data, *tables;
};

#endif // MAINWINDOW_H
