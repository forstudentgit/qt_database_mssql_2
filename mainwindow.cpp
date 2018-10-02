#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    logwin = new login();
    logwin->show();
}

void MainWindow::on_pushButton_clicked()
{
    model = new QSqlQueryModel();
    model->setQuery("SELECT name, post FROM primer");

    model->setHeaderData(0, Qt::Horizontal,"Название товара");
    model->setHeaderData(1, Qt::Horizontal,"Поставщик");

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}
