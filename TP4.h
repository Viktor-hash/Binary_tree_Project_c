#ifndef TP4_H_INCLUDED
#define TP4_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// implémenter successeur et pred
// fonction pour chevauchement, comparaison

typedef struct Intervalle
{
    int borne_inf;
    int borne_sup;
} T_Inter;

//typedef struct Intervalle T_Inter;

typedef struct Noeud
{
    int id;
    T_Inter inter;
    struct Noeud* fils_g;
    struct Noeud* fils_d;

} T_Noeud;


typedef T_Noeud* T_Arbre;

int chevauchement(T_Noeud *existant,T_Noeud *nouveau);
int verifier_intervalle(T_Inter intervalle);
T_Noeud* creer_noeud(int Id_entreprise,T_Inter intervalle);
void ajouter_noeud(T_Arbre* abr,T_Noeud* noeud);
T_Noeud* recherche(T_Arbre abr, T_Inter intervalle,int Id_entreprise);
T_Noeud* recherche_pere(T_Arbre abr, T_Inter intervalle,int Id_entreprise );
void Supp_noeud(T_Arbre *abr, T_Inter intervalle, int Id_entreprise);
void modif_noeud(T_Arbre *abr, T_Inter intervalle,int Id_entreprise,T_Inter Nouvelntervalle);
T_Noeud *minimum(T_Arbre abr);
void parcours_infixeTri(T_Noeud *abr);
void affiche_abr(T_Arbre abr);
void parcours_infixeId(T_Noeud *abr,int Id_entreprise);
void affiche_entr(T_Arbre abr,int Id_entreprise);
void detruire_arbre(T_Arbre *abr);




#endif // TP4_H_INCLUDED
