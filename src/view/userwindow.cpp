#include "userwindow.h"
#include "ui_userwindow.h"

UserWindow::UserWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(INPUT);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

UserWindow::~UserWindow()
{
    delete ui;
}


void UserWindow::on_getSolutionButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(OUTPUT);
}

void UserWindow::on_actionAuthors_triggered()
{
    QMessageBox::about(this,"Autorzy","<b>Problem Magazyniera</b><br><br><b>Autorzy:</b><br>Adrian Stachlewski<br>Michał Kamiński"
                                      "<br>Emilia Sokół");
}

void UserWindow::on_actionQuit_triggered()
{
    close();
}

void UserWindow::on_newTaskButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(INPUT);
}
