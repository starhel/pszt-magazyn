#include "view/userwindow.h"
#include <QtWidgets/QApplication>
#include "model/Creature.h"
#include "model/Product.h"
#include "model/RandInt.h"
#include <iostream>

int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    UserWindow w;
    w.show();

    return a.exec();*/

    std::vector<std::shared_ptr<Product>> p1;
    std::vector<std::shared_ptr<Product>> p2;
    for(int i=0;i<=7;++i)
    {
        p1.push_back(std::shared_ptr<Product>(new Product("a",1,0.3)));
        p2.push_back(std::shared_ptr<Product>(new Product("a",1,0.3)));
    }

    p1[0]->setNumber(4);
    p1[1]->setNumber(5);
    p1[2]->setNumber(3);
    p1[3]->setNumber(1);
    p1[4]->setNumber(2);
    p1[5]->setNumber(0);
    p1[6]->setNumber(6);
    p1[7]->setNumber(7);

    p2[0]->setNumber(0);
    p2[1]->setNumber(1);
    p2[2]->setNumber(2);
    p2[3]->setNumber(3);
    p2[4]->setNumber(4);
    p2[5]->setNumber(5);
    p2[6]->setNumber(6);
    p2[7]->setNumber(7);

    Creature c1(p1);
    Creature c2(p2);
    Creature ch = c1.orderCrossover(c2);
    for (int i =0; i<=7;++i){
        std::cout<<ch.getProduct(i) ->getNumber() << std::endl;
    }
    return 0;
}
