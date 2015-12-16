#include "userwindow.h"
#include "ui_userwindow.h"
#include "../model/Product.h"
#include "../model/Creature.h"
#include "../model/algorithm.h"
#include <memory>

UserWindow::UserWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(INPUT);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    {
        freqSpinboxes.push_back(ui->freqSpinBox1);
        freqSpinboxes.push_back(ui->freqSpinBox2);
        freqSpinboxes.push_back(ui->freqSpinBox3);
        freqSpinboxes.push_back(ui->freqSpinBox4);
        freqSpinboxes.push_back(ui->freqSpinBox5);
        freqSpinboxes.push_back(ui->freqSpinBox6);
        freqSpinboxes.push_back(ui->freqSpinBox7);
        freqSpinboxes.push_back(ui->freqSpinBox8);
        freqSpinboxes.push_back(ui->freqSpinBox9);
        freqSpinboxes.push_back(ui->freqSpinBox10);
        freqSpinboxes.push_back(ui->freqSpinBox11);
        freqSpinboxes.push_back(ui->freqSpinBox12);
        freqSpinboxes.push_back(ui->freqSpinBox13);
        freqSpinboxes.push_back(ui->freqSpinBox14);
        freqSpinboxes.push_back(ui->freqSpinBox15);

        timeSpinboxes.push_back(ui->timeSpinBox1);
        timeSpinboxes.push_back(ui->timeSpinBox2);
        timeSpinboxes.push_back(ui->timeSpinBox3);
        timeSpinboxes.push_back(ui->timeSpinBox4);
        timeSpinboxes.push_back(ui->timeSpinBox5);
        timeSpinboxes.push_back(ui->timeSpinBox6);
        timeSpinboxes.push_back(ui->timeSpinBox7);
        timeSpinboxes.push_back(ui->timeSpinBox8);
        timeSpinboxes.push_back(ui->timeSpinBox9);
        timeSpinboxes.push_back(ui->timeSpinBox10);
        timeSpinboxes.push_back(ui->timeSpinBox11);
        timeSpinboxes.push_back(ui->timeSpinBox12);
        timeSpinboxes.push_back(ui->timeSpinBox13);
        timeSpinboxes.push_back(ui->timeSpinBox14);
        timeSpinboxes.push_back(ui->timeSpinBox15);
    }

}

UserWindow::~UserWindow()
{
    delete ui;
}


void UserWindow::on_getSolutionButton_clicked()
{
    for(QDoubleSpinBox* i : timeSpinboxes)
        if(i->value()==0)
        {
            QMessageBox::warning(this,"Błąd","Parametry towarów muszą być większe od 0!");
            return;
        }

    for(QDoubleSpinBox* i : freqSpinboxes)
        if(i->value()==0)
        {
            QMessageBox::warning(this,"Błąd","Parametry towarów muszą być większe od 0!");
            return;
        }
    ui->stackedWidget->setCurrentIndex(LOADING);
    startEvolution();
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
    Product::productCounter = 0;
}

void UserWindow::on_mutationSlider_valueChanged(int value)
{
        ui->mutationLabel->setText(QString::number(((double)value)/100, 'f', 2));
}

void UserWindow::startEvolution()
{
    std::vector<std::shared_ptr<Product>> products;
    QTableWidgetItem *newItem;
    std::shared_ptr<Product> p;
    for (int i=0; i<15;++i)
    {
        products.emplace_back(new Product(std::to_string(i)
                                          ,freqSpinboxes[i]->value()
                                          ,timeSpinboxes[i]->value()));
    }

    Creature best = algorithm(products, ui->generationsNoSpinBox->value(), ((double)ui->mutationSlider->value())/100);

    for(int row=0;row<15;++row)
    {
        p = best.getProduct(row);
        newItem = new QTableWidgetItem(QString::number(p->getNumber()+1));
        ui->tableWidget->setItem(row, 0, newItem);

        newItem = new QTableWidgetItem(QString::number(p->getLoadingTime(),'f',2));
        ui->tableWidget->setItem(row, 1, newItem);

        newItem = new QTableWidgetItem(QString::number(p->getFrequency(),'f',2));
        ui->tableWidget->setItem(row, 2, newItem);
    }

    ui->generationsNoLabel->setText(QString::number(ui->generationsNoSpinBox->value()));
    ui->averageTimeLabel->setText(QString::number(fitnessFunction(best),'f',2));

    ui->stackedWidget->setCurrentIndex(OUTPUT);
}
