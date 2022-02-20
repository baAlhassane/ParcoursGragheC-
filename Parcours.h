//
// Created by alhassaneba on 12/10/2021.
//

#ifndef PARCOURSGRAPHE_PARCOURS_H
#define PARCOURSGRAPHE_PARCOURS_H

#include <iostream>
#include <vector>
#include "Matrice.h"
#include <cassert>

class Parcours {
private:
    std::vector<double> graphe;
    std::vector<double> distance_origine;
    std::vector<int> predecesseurs;
    std::vector<bool> visited;


    int n;
    //int origine;
    double infini = std::numeric_limits<double>::infinity();

    int plus_proche();



public:
    Parcours(const Matrice &m);

    void dijsktra();

    void printGraph();

    template<typename T>
    void print_vector(std::vector<T>);




};

#endif //PARCOURSGRAPHE_PARCOURS_H
