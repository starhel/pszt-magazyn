#include "view/userwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UserWindow w;
    w.show();

    return a.exec();
}