#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // clientInt = new ClientInterface(this);
    // qDebug() << "0" << clientInt;
    // clientInt = ClientInterface::getInstance();
    // qDebug() << "1" << clientInt;
    // clientInt = ClientInterface::getInstance();

    clientInt = ClientInterface::getInstance();
     // qDebug() << "3" << clientInt;
}


MainWindow::~MainWindow()
{
    delete ui;
    clientInt->deleteLater();
}

void MainWindow::on_btnGet_clicked()
{
    const int id = ui->spinBox->value();
    clientInt->getCloth(id);
}

void MainWindow::on_btnList_clicked()
{
    clientInt->getCloths();
}

void MainWindow::on_btnDelete_clicked()
{
    const int id = ui->spinBox_2->value();
    clientInt->deleteCloth(id);
}

void MainWindow::on_btnUpdate_clicked()
{
    const int id = ui->spinBox_3->value();
    clientInt->updateCloth(id);
}

void MainWindow::on_btnCreate_clicked()
{
    clientInt->createCloth();
}




