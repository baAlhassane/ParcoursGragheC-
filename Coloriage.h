//
// Created by alhassaneba on 25/10/2021.
//

#ifndef PARCOURSGRAPHE_COLORIAGE_H
#define PARCOURSGRAPHE_COLORIAGE_H

#include <vector>
#include "Matrice.h"
#include <map>
#include <set>
class Coloriage{


    //    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% les attributs pour la Colorations  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
private:
    std::vector<double> graphe_non_oriente;
    std::vector<int>  sommets;
    int c =0;// nombre de couleurs; Pas forcemenet le nobre de couleurs minimum car l'algo est glouton
    int k=0; // pour le nombre de couleur minimum
    std::vector<int>liste_color;
    std::vector<int> sommets_tries;
    std::vector<int> degres;
    std::vector<bool> colored;
    int n=0;
public:
    //    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% les methode pour la Colorations  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    void colorier_c();//attribut un nombre de couleur quelquelque paa forcement minimal
    void colorier_k();//attribut un nombre de couleur minimal

    Coloriage(const Matrice & m);
    double infini = std::numeric_limits<double>::infinity();
    void tri(std::vector<int> &degres, std::vector<int>  &sommets);
    void printGraph_Color();
    int select_sommet( const std::vector<int> &lisTColor, const std::vector<int> &nColor_voisins,const std::vector<int> & degres );
    int couleurMin(  int sommet , std::map<int, std::set<int>  > &map) ;
    int select_sommet_a();
   void colore_a();
   void color_b();
   void color_seq();
   void coloriage_cours();








};
#endif //PARCOURSGRAPHE_COLORIAGE_H
