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
    /**
    * Obsługa przycisku "Znajdź rozwiązanie"
    * Sprawdza wprowadzone dane oraz uruchamia ewolucję
    */
    void on_getSolutionButton_clicked();

    /**
    * Wyświetla autorów
    */
    void on_actionAuthors_triggered();

    /**
    * Zamyka program
    */
    void on_actionQuit_triggered();

    /**
    * Obsługa przycisku "Wprowadź nowe dane"
    */
    void on_newTaskButton_clicked();

    /**
    * Obsługa suwaka współczynnika mutacji
    */
    void on_mutationSlider_valueChanged(int value);

    /**
    * Wprowadza losowe dane towarów
    */
    void on_randomDataButton_clicked();

private:
    Ui::UserWindow *ui;

    enum View
    {
        INPUT = 0,
        OUTPUT = 1,
        LOADING = 2
    };

    View currView; /**< Aktualny widok okna */
    std::vector<QDoubleSpinBox*> freqSpinboxes; /**< Wektor SpinBoxów z danymi o częstotliwościach */
    std::vector<QDoubleSpinBox*> timeSpinboxes; /**< Wektor SpinBoxów z danymi o czasach */

    /**
    * Przygotowuje dane dla algorytmu ewolucyjnego i go rozpoczyna
    */
    void startEvolution();

};

#endif // USERWINDOW_H
