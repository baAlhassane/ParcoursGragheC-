#include <iostream>
#include "Matrice.h"
#include "Parcours.h"
#include "Coloriage.h"
#include <algorithm>


int main() {
    std::cout << "Hello, World!" << std::endl;
//
//    Matrice matrice(5,5);
//   // matrice.initMatrice(5, 5);
//    matrice.setElement(3, 4, 1);
//    matrice.setElement(2, 3, 2);
//    matrice.setElement(1, 4, 6);
//    //matrice.setElement(2, 2, 2);
//    //matrice.setElement(3, 3, 3);
//    matrice.setElement(0, 1, 10);
//    //matrice.setElement(0, 0, 100);
//    matrice.setElement(4, 0, 100);
//    matrice.setElement(0, 2, 100);


Matrice matrice(11,11);
    matrice.setElement(0,1,7);
    matrice.setElement(0,2,6);
    matrice.setElement(0,3,3);

    matrice.setElement(1,4,2);

    matrice.setElement(2,4,5);
    matrice.setElement(2,5,4);

    matrice.setElement(3,5,7);
    matrice.setElement(3,6,3);

    matrice.setElement(4,7,9);




    matrice.setElement(5,7,2);
    matrice.setElement(5,8,5);

    matrice.setElement(6,8,2);
    matrice.setElement(6,9,7);

    matrice.setElement(7,10,3);
    matrice.setElement(8,10,6);
    matrice.setElement(9,10,4);




    matrice.display();
    Parcours p(matrice);
//p.dijsktra();
   // matrice.setElement(0, 0, 100);
//p.dijsktra();
    //p.printGraph();
    p.dijsktra();//

Coloriage c(matrice);
c.printGraph_Color();
//c.colorier_k();// un autre algorithe de coriage plus optimal.
//c.colore_a();
//c.color_b();
c.color_seq();



    return 0;
}


