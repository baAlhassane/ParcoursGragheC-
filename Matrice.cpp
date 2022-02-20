//
// Created by alhassaneba on 12/10/2021.
//

#include <iostream>
#include "Matrice.h"


void Matrice::initMatrice(int rows, int columns) {
    nbColumns=columns;
    nbRows=rows;
    deleteMatrice();
    matrice.resize(nbRows*nbColumns);

    for (int i = 0; i <nbRows ; ++i) {
        for (int j = 0; j <nbColumns ; ++j) {
            if(i==j) matrice[i*nbColumns+j]=0;
            else {
                matrice[nbColumns*i+j]=infini;
            }

        }

    }
}





double Matrice::getElement(int row, int column) const {

    return matrice[nbColumns*row+column];

}



void Matrice::setElement(int row, int column, int val) {

    matrice[nbColumns*row+column]=val;

}

void Matrice::display() {

    for(int i=0;i<nbRows;i++){
        for (int j = 0; j <nbColumns ; ++j) {
        std::cout<<getElement(i,j)<< "  " ;
        }
        std::cout<<"  "<<std::endl;
    }


}

Matrice::Matrice(int row, int col) {
    nbColumns=col;
    nbRows=row;
    //deleteMatrice();
    matrice.resize(nbRows*nbColumns);


    for (int i = 0; i <nbRows ; ++i) {
        for (int j = 0; j <nbColumns ; ++j) {
            if(i==j) matrice[i*nbColumns+j]=0;
            else {
                matrice[nbColumns*i+j]=infini;
            }

        }

    }

}






