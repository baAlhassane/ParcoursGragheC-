//
// Created by alhassaneba on 12/10/2021.
//

#include <iostream>
#include "Parcours.h"
#include <algorithm>
#include <limits>


Parcours::Parcours(const Matrice &m) {
    int nbLigne = m.getRows();
//    std::cout << nbLigne << std::endl;
    int nbColonnes = m.getColumns();
    assert((" on doit avoir une matrice carree ", nbLigne == nbColonnes));
    n = nbColonnes;
    distance_origine.resize(n,0);
    predecesseurs.resize(n);
//    graphe.resize(n * n);
    visited.resize(n, false);
    //std::cout << "graph size before: " << graphe.size() << std::endl;

//    for (auto el:m.getMatrice()) graphe.push_back(el);
    graphe = m.getMatrice();
    std::cout << "graph size after: " << graphe.size() << std::endl;

}


void Parcours::printGraph() {
    std::cout << "  print graphe" << n << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            //std::cout<<"  pri std::cout<<"graph size before: "<<graphe.size()<<std::endl;

            //std::cout << "graph size after: " << graphe.size() << std::endl;

            graphe;
            std::cout << graphe[n * i + j] << "  ";

        }
        std::cout<< std::endl;

    }
}


void Parcours::dijsktra() {

    //std::vector<int>
    //std::cout<< "helloo dijsk.  "<<std::endl;
    //std::vector<int> pred;
    //std::vector<double> dist_origine;
    //distance_origine.resize(n);
    //predecesseurs.resize(n);
    //visited.resize(n);

    //std::vector<int> suivants;
    int origine = 0;
    for (int i = 0; i < n; ++i) {
        //if (graphe[n * origine + i] < infini)
            predecesseurs[i] = i;
        distance_origine[i]= infini;//graphe[origine*n+i];
        visited[i]= false;
    }

    distance_origine[origine]=0;

    for (int i = 0; i < n; ++i) {
        int proche = plus_proche();
        std::cout<<" proche =  " <<proche<< "   ";
        visited[proche] = true;// c'st sommet. Les sommet sont numerote  apartir de 1.
        // On regarde ses sommet adjacentes. Ces suivnat sont donnes par la matrice graphe.
        // cest les j ou graphe[i][j]!=infini.

        for (int adj = 0; adj < n; ++adj) {
            if ( (graphe[n * proche + adj] != infini) &&
            (distance_origine[adj] >distance_origine[proche] + graphe[n * (proche) + adj]) ) {
                distance_origine[adj] = distance_origine[proche] + graphe[n * proche + adj];
                predecesseurs[adj] = proche;
                //std::cout<<" int test "<< std::endl;
            }
        }


    }

    std::cout<<  "  les predesseurs    "<<std::endl;
    for (int i = 0; i <n ; ++i) {
        std::cout<< " le predeccessurs du sommet "<< i+1 << "  est <<  ---->  " << predecesseurs[i] +1;
        std::cout<<std::endl;
        
    }
    std::cout<<std::endl;
    std::cout<<  "  distance_origine   "<<std::endl;
    std::cout<<std::endl;
    for (int i = 0; i <n ; ++i) {
        std::cout<< " distance de  " << i+1 << "-->  "<<distance_origine[i]<< std::endl;

    }



}




int Parcours::plus_proche() {

     auto min_d = infini;
    int min_s = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && distance_origine[i] < min_d) {
            min_d = distance_origine[i];
            min_s = i ;

        }
    }

    return min_s;
}




template<typename T>
void Parcours::print_vector(std::vector<T> v) {

    for (int i = 0; i <n ; ++i) {
        std::cout<<v[i]<<" ";

    }
}



