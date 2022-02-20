//
// Created by alhassaneba on 25/10/2021.
//

#include "Coloriage.h"
#include "Matrice.h"
#include "cassert"
#include <iostream>
#include <set>
#include "algorithm"
#include <map>


Coloriage::Coloriage(const Matrice &m) {
    int nbLigne = m.getRows();
//    std::cout << nbLigne << std::endl;
    int nbColonnes = m.getColumns();
    n=nbColonnes;
    assert((" on doit avoir une matrice carree ", nbLigne == nbColonnes));

// on a construit  la matrice en tenant compte des graphe oriente. On casse cette orienattion en faisant graphe[i][j]=graphe[j][i]
    graphe_non_oriente.resize( nbLigne*nbColonnes);
    graphe_non_oriente = m.getMatrice();
    for (int i = 0; i < nbLigne; ++i) {
        for (int j = 0; j <nbColonnes ; ++j) {

            if(graphe_non_oriente[n*j+i]>0 && (graphe_non_oriente[n*i+j]!=infini || graphe_non_oriente[n*j+i]!=infini) ){
                graphe_non_oriente[n*j+i]=1;
                graphe_non_oriente[n*i+j]=1;
            }
        }



    }
    degres.resize(n);
    colored.resize(n);
    sommets.resize(n);
    liste_color.resize(n);


    for (int i = 0; i <n ; ++i) {
        sommets[i]=i+1;
        colored[i]=false;
        liste_color[i]=0;


        for (int j = 0; j <n ; ++j) {
            if(graphe_non_oriente[n*i+j]==1) {
                degres[i]++;

            }
        }

    }



}


void Coloriage::printGraph_Color() {

    std::cout << "  printGraph_Color " << n << std::endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            //std::cout<<"  pri std::cout<<"graph size before: "<<graphe.size()<<std::endl;

            //std::cout << "graph size after: " << graphe.size() << std::endl;

            //graphe;
            std::cout << graphe_non_oriente[ n* i + j] << "  ";

        }
        std::cout<< std::endl;


    }

    std::cout << " degres[j] " << "  ";
    for(int j = 0; j < n; ++j) {
        std::cout<< degres[j]<<" ";
    }

std::cout<<std::endl;

}

void Coloriage::tri(std::vector<int> &degres, std::vector<int> &sommets) {
    int n=degres.size();
    int i=0;
    while(i<n){
        int j=i;
        for(int k=i+1;k<n;k++){
            if(degres[k]>degres[j]) j=k;

        }
        std::swap(degres[j],degres[i]);
        std::swap(degres[j],degres[i]);
        i++;



    }
}



int Coloriage::select_sommet(  const std::vector<int> &valColor,const std::vector<int> &nColor_voisins,
                             const std::vector<int> &degres_max) {

  int maxNb_coolor_voisin=0;
  int indx_nb_voisin=-1;
  int s=-1;
    for (int i = 0; i <n ; ++i) {
      if((maxNb_coolor_voisin<nColor_voisins[i]) && (valColor[i]==0)){
          maxNb_coolor_voisin=nColor_voisins[i];
          indx_nb_voisin=i;

      } //end if


    }//end  for  i =

 auto  max_iter=std::max_element(nColor_voisins.begin(),nColor_voisins.end());
 int indic_max_nb_c=std::distance(nColor_voisins.begin(), max_iter);
s=indic_max_nb_c;
 if( liste_color[indic_max_nb_c]==0){
       int nbMax=0;// le nobre de max de nombre de couleur differentes. Sil ya plusieur on cherche le celuis qui le plus grand degres
     for (int i = 0; i <n ; ++i) {
         if( nColor_voisins[indic_max_nb_c]==nColor_voisins[i]){
             nbMax++;
         }


     }//end for

    if(nbMax>1){
           // on chet le degre max car plusieur max
           int indice_max=0;
           int maxDeg=0;
        for (int i = 0; i <n ; ++i) {
            if( nColor_voisins[indic_max_nb_c]==nColor_voisins[i] ){

                if(maxDeg<degres_max[i]){
                    maxDeg=degres_max[i];
                    indice_max=i;
                }



            }

        }

        s= indice_max;
    }
     s=indic_max_nb_c;
 }







    s= valColor[indx_nb_voisin];

    // recherche si on a plusieurs valeur de me maxNb_coolor_voisins.

    int nb_elem_max=0;

    std::vector<int> sameMax(n,0);
    for (int i = 0; i <n ; ++i) {
         if(maxNb_coolor_voisin==nColor_voisins[i]) {
             nb_elem_max++;
             sameMax[i]=nColor_voisins[i];

         }
    }

    if(nb_elem_max>1){// selection celui de degres max
        int maxDegres=0;
        int indiceDegres=0;
        for (int i = 0; i <n ; ++i) {
            if((sameMax[i]!=0)  && (maxDegres< degres_max[i]) ){
                maxDegres=degres_max[i];
                indiceDegres=i;

            }

        }

        s=nColor_voisins[indiceDegres];

    }




///int s=0;

//auto iterMax_degre=std::max_element(degres.begin(),degres.end());
//int valmaxSommet=*iterMax_degre;
//int indice=std::distance(degres.begin(),iterMax_degre);



//s=indice;
   return s;

}


int Coloriage::couleurMin( int sommet,   std::map<int, std::set<int>> &map) {
// les coleurs voisins du sommet
int c=0;
std::set<int> c_voisin_sommet;
c_voisin_sommet=map[sommet];
std::vector<int> choice;
std::set<int> setCouleur;
    for (int i = 0; i < n; ++i) {
        setCouleur.insert(i+1);

    }


    for(auto c:c_voisin_sommet) {//
        for(auto el : setCouleur ){
            if(el!=c ) choice.push_back(el);//choisir une couleur min parmis les sets de couleurs.
        }

    }

    c=*std::min_element(choice.begin(),choice.end());








    return c;
}


void Coloriage::colorier_k() { //attribut un nombre de couleur minimal. Un autre algorithme de coloriage plus optimal
// tri des sommets par degres decroissant
   std::vector<int> degres_cp(n,0);//copy de degres car doit etre passe par reffrence
   std::vector <int> sommet_tries(n,0);//
   std::vector<int> degeres_not_color(n,0);
   //sommet_tries=sommets;
    degres_cp=degres;
    degeres_not_color=degres;
    std::map<int,std::set<int> >map_ensColor_voisins;//ensemble des coileurs differentes voisins d'un sommet .
  std::vector<int> nbColor_voisins(n,0);// chaque case contien le nombre de couleur != des voisin de
  //  nColor_voisins co,ntient  le cardinal de l'ensemble de couleur de chaque element.



    tri(degeres_not_color,sommet_tries);// cette methode modifie ces vectors.

    liste_color.resize(n,0);// la liste des couleurs attribué a chaque sommets.

    // choisir un sommet i de degre max
    int i0=sommet_tries[0];// les sommet sont numertes de 1 a zeos pour simplifier . Car ils sirviront d'indice des
    liste_color[i0]=1;// le tableau est de tri decroissant suivant les degres ;
    map_ensColor_voisins[i0].insert(i0);
    //ensColor_voisins
    k=1;

    //pour tous les voisin de de i0 faire
    for (int j = 0; j <n ; ++j) {
     if( graphe_non_oriente[n*i0+j]!=infini){
         degeres_not_color[j]--;
     }

     while(k<n){

         int s=select_sommet( liste_color, nbColor_voisins,degeres_not_color);
         if(s==-1) break;// on a plus de sommets non colorie
         int sommet_c=sommet_tries[s];
         int c_min=couleurMin(sommet_c,map_ensColor_voisins);

         liste_color[sommet_c-1]=c_min;
         k++; // a chaque fois on attribut une couleur ont increment k qui indique le nombre de couleur choisi.;
         // maintenant pour les voisins de s on decrement
         for (int j = 0; j <n ; ++j) {
             if(graphe_non_oriente[n*s+j]){
                 degeres_not_color[j]--;
                 nbColor_voisins[j]=map_ensColor_voisins[j].size();//

             }


         }



     }



    }
    std::cout<<"liste couleur "<< std::endl;
    for (int i = 0; i <n ; ++i) {

        std::cout<< liste_color[i]<< " ";
    }


}

void Coloriage::colore_a() {

    auto iter_val_degre_max=std::max_element(degres.begin(),degres.end());
    int val_degre_max=*iter_val_degre_max;
    int pos_degre_max=std::distance( degres.begin(),iter_val_degre_max);
    int init_s= sommets[pos_degre_max];
    colored[init_s-1]=true;
    k=1;
    liste_color[init_s-1]=k;
  int n1=n;


    while(n1!=0){
        //std::vector<int> J(n,0);//voisins du sommet courant non encore coloriel
        std::vector<int> J(n,0);
        int nj=0;;
        while(n1!=nj){
        int indice_s=select_sommet_a();
          int s= sommets[indice_s];
        //std::cout<< indice_s<< ;
           liste_color[s-1]=k;
         colored[s-1]=true;
        n1--;

        //sommets[indice_s]=0;
            for (int j = 0; j <n ; ++j) {
               if(graphe_non_oriente[n*(s-1)+j]!=infini &&sommets[j]==J[j] &&(j!=s-1)){
                std::cout<<" ssss";
                    degres[j]--;
                    J[j]=j;
                    nj++;
                    //colore
                    //sommets[j]=0;


                }

            }

        }
        k=k+1;
    }
    //std::cout<<"liste couleur "<< std::endl;
    for (int i = 0; i <n ; ++i) {

       // std::cout<< liste_color[i]<< " ";
    }


}



int  Coloriage::select_sommet_a() {
int indice_s=-1;

    std::vector<int> cp_degrs(n,0);
    cp_degrs=degres;
    std::vector<int> cp_sommets(n,0);
    cp_sommets=sommets;
    std::vector<int> degres_not_colored(n,0);
    for (int i = 0; i <n ; ++i) {
        if( !colored[i]  ){
            degres_not_colored[i]=cp_degrs[i];
        }

    }

    // on recuper parmi le max parmis des non colories.
    auto iter_pos=std::max_element(degres_not_colored.begin(),degres_not_colored.end());
    int pos= std::distance(degres_not_colored.begin(), iter_pos);// on recupere sa position
      indice_s=pos;


    return indice_s;


}

void Coloriage::color_b(){
    std::vector<int> sommets_sort(n,0);
    for (int i = 0; i <n ; ++i) {
        sommets_sort[i]=i;}
    //int k=0;

        std::vector<int> cp_degres(n,0);
        cp_degres=degres;
        //sommets_sort;
        tri(cp_degres,sommets_sort);

        for (int j= 0; j <n ; ++j){
            if(liste_color[j]==0){
                std::vector<int> degre_sat(n,0);
                int degre_sat_max=0;
                int sommet_choisi=sommets_sort[0];
                liste_color[sommet_choisi]=1;
                for (auto si : sommets_sort){
                   if(liste_color[si]==0){
                       std::set<int>  couleur_voisin;
                       for (int adj = 0; adj<n ; ++adj){
                         if(  graphe_non_oriente[n*si+adj]!=infini &&  graphe_non_oriente[n*si+adj] >0) {
                             if(liste_color[adj]>0) couleur_voisin.insert(liste_color[adj]);
                         }// end if voisin


                       }//en for adj

                       degre_sat[si]=couleur_voisin.size();
                       if(degre_sat[si]> degre_sat_max){
                           degre_sat_max=degre_sat[si];
                           sommet_choisi=si;
                       } // end if degre_sat > deg_sat_max



                   }// end if  liste_color[si]==0 du auto si
                }// end for auto si sommet ordonnee



                // on est dans for if(list_color[i]==0)

                int s_i=sommet_choisi;
                std::set<int> couleur_voisins;


                for (int l = 0; l <n ; ++l) {
                    if( graphe_non_oriente[n*s_i+l]!=infini &&  graphe_non_oriente[n*s_i+l] >0 ){
                        couleur_voisins.insert(liste_color[l]);
                    }// end if voisin

                }// end for l

                int min_c=1;
                for (int c: couleur_voisins) {
                   // if( c ==1 ) continue;
                    if(min_c==c ) min_c++;


                }


                liste_color[sommet_choisi]=min_c;

               //std::cout<< sommet_choisi<<" ";
















            } // end if liste_color[j]=0;




        }  // end for j






    for (int i = 0; i <n ; ++i) {
        std::cout<<liste_color[i]<<" ";

    }




}// color_b



void Coloriage::color_seq() {
    std::vector<int> cp_sommets(n,0);
    std::vector<int> cp_degres(n,0);
    std::vector<int> couleurs(n,0);


    cp_degres=degres;
    cp_sommets=sommets;
   tri(cp_degres,cp_sommets);
    int k=1;
 couleurs[0]=k;
//    couleurs[1]=k+1;
//    couleurs[2]=k+2;


std::cout<< " les sommets adjacent ua sommet 0 ;" <<std::endl;
for(int s: sommets){

    if(graphe_non_oriente[n*0+s]!=infini && graphe_non_oriente[n*0+s]>0) {
        couleurs[s-1]=k++;
    std::cout<< s << " --";
 }
}
graphe_non_oriente[11]=infini;


    std::cout<<  " end " << " "<<std::endl;
    for(int s:cp_sommets){

        if(couleurs[s]==0 ) {
            std::vector<int> couleur_voisins(n,0);
           for(int vois:cp_sommets){
            //   if(s!=vois){
                   if( (graphe_non_oriente[n*s+vois]!=infini && graphe_non_oriente[n*s+vois]>0)  ){
                       couleur_voisins[vois]=couleurs[vois];

                   }


               //}
           }



              // on a fini d'enumerer les voisins
            for (int i = 0; i < n; ++i) {

                if( couleur_voisins[i]==k)k++;

            }





            couleurs[s]=k;
        }

    }// en for cp_sommets

    std::cout<< " les couleurs de chaque sommets :" <<std::endl;
    for (int i = 0; i <n ; ++i) {
        std::cout<<couleurs[i]<<" ";

    }

}

