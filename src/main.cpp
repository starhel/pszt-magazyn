#include "view/userwindow.h"
#include <QtWidgets/QApplication>
#include "model/Creature.h"
#include "model/Product.h"
#include "model/RandInt.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UserWindow w;
    w.show();

    return a.exec();
}
