//
// Created by alhassaneba on 12/10/2021.
//

#ifndef PARCOURSGRAPHE_MATRICE_H
#define PARCOURSGRAPHE_MATRICE_H
#include <vector>
#include <limits>

class Matrice{
private:
    std::vector<double> matrice;
    int nbRows;
    int nbColumns;
public:
    Matrice(int row,int col);
    double *operator[](int row){return & matrice[row*nbColumns];};
   // double const operator[](int row) const {return matrice[row*nbColumns];};
    //double operator[](int row){return   matrice[row*nbColumns];}
    void initMatrice (int rows,int columns);
    Matrice()=default;
    void deleteMatrice(){matrice.clear();}
    double getElement(int  row, int column) const;
    void setElement(int rows, int column , int val);
    int getSizeMatrice(){return nbRows*nbColumns;};
    //Matrice(const Matrice &m);
    int getRows() const  {return  nbRows;};
    int getColumns() const {return nbColumns;}
    std::vector<double> getMatrice() const {return matrice;};
    double infini = std::numeric_limits<double>::infinity();


    void display();




};
#endif //PARCOURSGRAPHE_MATRICE_H
