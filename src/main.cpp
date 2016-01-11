/**
 * \file   main.cpp
 * \author Adrian Stachlewski
 * \author Michał Kamiński
 * \author Emilia Sokół
 * \date   13-12-2015
 * \brief  Start programu
 */

#include "view/userwindow.h"
#include <QtWidgets/QApplication>

/**
 * \brief Funkcja odpowiedzialna za uruchomienie programu.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UserWindow w;
    w.show();

    return a.exec();
}
