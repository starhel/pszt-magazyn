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

private:
    Ui::UserWindow *ui;

    enum View
    {
        INPUT = 0,
        OUTPUT = 1
    };

    View currView;
    std::vector<QDoubleSpinBox*> freqSpinboxes;
    std::vector<QDoubleSpinBox*> timeSpinboxes;

};

#endif // USERWINDOW_H
