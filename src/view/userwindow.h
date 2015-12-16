/**
 * \file   userwindow.h
 * \author Michał Kamiński
 * \date   13-12-2015
 * \brief  Okno programu
 */
#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QDoubleSpinBox>
#include <vector>


namespace Ui {
class UserWindow;
}

/**
 * \brief Okno programu
 */
class UserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = 0);
    ~UserWindow();

private slots:
    void on_getSolutionButton_clicked();

    void on_actionAuthors_triggered();

    void on_actionQuit_triggered();

    void on_newTaskButton_clicked();

    void on_mutationSlider_valueChanged(int value);

    void on_randomDataButton_clicked();

private:
    Ui::UserWindow *ui;

    enum View
    {
        INPUT = 0,
        OUTPUT = 1,
        LOADING = 2
    };

    View currView;
    std::vector<QDoubleSpinBox*> freqSpinboxes;
    std::vector<QDoubleSpinBox*> timeSpinboxes;
    void startEvolution();

};

#endif // USERWINDOW_H
