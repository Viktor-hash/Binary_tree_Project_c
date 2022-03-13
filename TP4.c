#include"TP4.h"

int chevauchement(T_Noeud *existant,T_Noeud *nouveau)
{
    if(existant->inter.borne_sup < nouveau->inter.borne_inf)
        return 0;
    if(existant->inter.borne_inf > nouveau->inter.borne_sup)
        return 0;
    return 1;
}

int verifier_intervalle(T_Inter intervalle){

    if(intervalle.borne_sup < 0 || intervalle.borne_sup < 0 ){
        printf("Erreur l'unde des borne de l'intervalle ne peut pas etre negative.\n");
        return 0;
    }

    if(intervalle.borne_sup < intervalle.borne_inf){
        printf("Erreur les bornes min et max de l'intervalle sont inversees.\n");
        return 0;
    }

    int mois_min = intervalle.borne_inf / 100;
    int jours_min = intervalle.borne_inf % 100;

    if(mois_min < 1 || mois_min > 12){
        printf("Erreur sur l'intervalle minimum, le mois dois etre compris entre 1 et 12.\n");
        return 0;
    }

    if(jours_min == 0 || jours_min > 31){
        printf("Erreur sur l'intervalle minimum, le mois dois etre compris entre 1 et 31.\n");
        return 0;
    }

    if(mois_min == 2 && jours_min > 29){
        printf("Erreur sur l'intervalle minimum, le nombre de jours pour le mois de Fevrier ne peut pas depasser 29.\n");
        return 0;
    }

    if((mois_min == 4 || mois_min == 6 || mois_min == 9 || mois_min == 11) && jours_min > 30){
        printf("Erreur sur l'intervalle minimum, le nombre de jours pour les mois Avril, Juin, Septembre et Nombre ne peut pas depasser 30.\n");
        return 0;
    }

    int mois_max = intervalle.borne_sup / 100;
    int jours_max = intervalle.borne_sup % 100;

    if(mois_max < 1 || mois_max > 12){
        printf("Erreur sur l'intervalle maximum, le mois dois etre compris entre 1 et 12.\n");
        return 0;
    }

    if(jours_max == 0 || jours_max > 31){
        printf("Erreur sur l'intervalle maximum, le mois dois etre compris entre 1 et 31.\n");
        return 0;
    }

    if(mois_max == 2 && jours_max > 29){
        printf("Erreur sur l'intervalle maximum, le nombre de jours pour le mois de Fevrier ne peut pas depasser 29.\n");
        return 0;
    }

    if((mois_max == 4 || mois_max == 6 || mois_max == 9 || mois_max == 11) && jours_max > 30){
        printf("Erreur sur l'intervalle maximum, le nombre de jours pour les mois Avril, Juin, Septembre et Nombre ne peut pas depasser 30.\n");
        return 0;
    }

    return 1;
}
T_Noeud* creer_noeud(int Id_entreprise,T_Inter intervalle)
{
    T_Noeud* nouveau = malloc(sizeof(T_Noeud));
    if (nouveau==NULL)
        exit(EXIT_FAILURE);
    nouveau->id = Id_entreprise;
    nouveau->inter = intervalle;
    nouveau->fils_d=NULL;
    nouveau->fils_g=NULL;
    return nouveau;
}

void ajouter_noeud(T_Arbre* abr,T_Noeud* noeud)
{
    T_Noeud *x=*abr;
    T_Noeud *y=NULL;

    while(x!=NULL)
    {
        y=x;
        if (noeud->inter.borne_inf == x->inter.borne_sup || noeud->inter.borne_inf==x->inter.borne_inf)// || noeud->inter.borne_inf == x->inter.borne_sup)
        {
            x=NULL;

        }
        else if(noeud->inter.borne_inf > x->inter.borne_inf)
        {
            x=x->fils_d;
        }
        else if (noeud->inter.borne_inf < x->inter.borne_inf)
        {
            x=x->fils_g;
        }



    }
    if(y==NULL)
    {
        *abr=noeud;
    }
    else
    {
        if(chevauchement(y,noeud))
        {
            printf("conflit d'intervalle\n");
        }
        else if(y->inter.borne_inf > noeud->inter.borne_inf)
        {
            y->fils_g=noeud;
        }
        else
        {
            y->fils_d=noeud;
        }
    }
}


T_Noeud* recherche(T_Arbre abr, T_Inter intervalle,int Id_entreprise)
{
    T_Noeud* curseur;
    curseur = abr;
    while(curseur != NULL && (intervalle.borne_inf != curseur->inter.borne_inf || Id_entreprise!=curseur->id))
    {
        if (intervalle.borne_inf < curseur->inter.borne_inf)
        {
            curseur = curseur->fils_g;
        }
        else
        {
            curseur=curseur->fils_d;
        }
    }
    return curseur;
}

T_Noeud* recherche_pere(T_Arbre abr, T_Inter intervalle,int Id_entreprise )
{
    T_Noeud* pere;
    T_Noeud* curseur;
    curseur = abr;
    while(curseur != NULL && (intervalle.borne_inf != curseur->inter.borne_inf || Id_entreprise!=curseur->id))
    {
        if (intervalle.borne_inf < curseur->inter.borne_inf)
        {
            pere=curseur;
            curseur = curseur->fils_g;
        }
        else
        {
            pere=curseur;
            curseur=curseur->fils_d;
        }
    }
    return pere;
}



void Supp_noeud(T_Arbre *abr, T_Inter intervalle, int Id_entreprise)
{
    T_Noeud *pere=NULL;
    T_Noeud *z=NULL;
    T_Noeud *tempo=NULL;
    T_Noeud *tempo2=NULL;
    int inf=0;
    int sup=0;
    int id=0;

    int cote=0;
    if(*abr!=NULL)
    {
        if(intervalle.borne_inf!=(*abr)->inter.borne_inf)
        {
            pere=recherche_pere(*abr,intervalle,Id_entreprise);

            if(pere->fils_d!=NULL && Id_entreprise==pere->fils_d->id)
            {
                z=pere->fils_d;
                cote=1;//droite
            }
            else if(pere->fils_g!=NULL && Id_entreprise==pere->fils_g->id)
            {
                z=pere->fils_g;
                cote=2;//gauche
            }
        }
        else
            z=*abr;
    }

    if(z!=NULL)
    {
        //cas 1 : le noeud a supprimer n'a pas de fils
        if (z->fils_d==NULL && z->fils_g==NULL)
        {
            if(cote==1)
                pere->fils_d=NULL;
            else if(cote==2)
                pere->fils_g=NULL;
            else *abr=NULL;
            free(z);
        }
        //cas 2 : le noeud a supprimer a un fils
        else if (z->fils_d==NULL||z->fils_g==NULL)
        {
            if(z->fils_d==NULL)
            {
                if(cote==1)
                    pere->fils_d=z->fils_g;
                else if(cote==2)
                    pere->fils_g=z->fils_g;
                else *abr=z->fils_g;
            }
            else
            {
                if(cote==1)
                    pere->fils_d=z->fils_d;
                else if(cote==2)
                    pere->fils_g=z->fils_d;
                else *abr=z->fils_d;
            }
            free(z);
        }
        //cas 3 : le noeud  supprimer a deux fils
        //on va sur son fils droit forcément supérieur à lui
        //si le fils droit à un fils gauche aller à gauche jusu'à NULL
        //on supprime avec appel récursif
        else
        {
            if(z->fils_d->fils_g==NULL)
            {
                inf=z->fils_d->inter.borne_inf;
                sup=z->fils_d->inter.borne_sup;
                id=z->fils_d->id;
                Supp_noeud(abr,z->fils_d->inter,z->fils_d->id);
                z->id=id;
                z->inter.borne_inf=inf;
                z->inter.borne_sup=sup;
            }
            else
            {
                tempo=z->fils_d;
                while(tempo!=NULL)
                {
                    tempo2=tempo;
                    tempo=tempo->fils_g;
                }
                inf=tempo2->inter.borne_inf;
                sup=tempo2->inter.borne_sup;
                id=tempo2->id;
                Supp_noeud(abr,tempo2->inter,tempo2->id);
                z->id=id;
                z->inter.borne_inf=inf;
                z->inter.borne_sup=sup;
            }
        }
    }

}

void modif_noeud(T_Arbre *abr, T_Inter intervalle,int Id_entreprise,T_Inter Nouvelntervalle)
{
    T_Noeud *tempo=recherche(*abr,intervalle,Id_entreprise);

    T_Noeud *nouveau=malloc(sizeof(nouveau));
    T_Inter *nouve=malloc(sizeof(nouve));
    nouve->borne_inf=Nouvelntervalle.borne_inf;
    nouve->borne_sup=Nouvelntervalle.borne_sup;
    nouveau=creer_noeud(Id_entreprise,*nouve);

    if(tempo!=NULL)
    {
        Supp_noeud(abr,tempo->inter,Id_entreprise);
        ajouter_noeud(abr,nouveau);
    }
    else
    printf("ce noeud n existe pas\n");
}

T_Noeud *minimum(T_Arbre abr)
{
    T_Noeud *tempo=abr;
    if(tempo!=NULL)
    {
        while(tempo->fils_g!=NULL)
        {
            tempo=tempo->fils_g;
        }
    }
    return tempo;
}

void parcours_infixeTri(T_Noeud *abr)
{
    if(abr!=NULL)
    {
        parcours_infixeTri(abr->fils_g);
        printf("Id_entreprise : %d -- [%d,%d]\n",abr->id,abr->inter.borne_inf,abr->inter.borne_sup);
        parcours_infixeTri(abr->fils_d);
    }
}

void affiche_abr(T_Arbre abr)
{
    /*int inf[1000];
    int sup[1000];
    int id[1000];
    int i=0,j=0;
    T_Noeud *affiche=minimum(*abr);

    while((*abr)!=NULL){
    affiche=minimum(*abr);
    inf[i]=affiche->inter.borne_inf;
    sup[i]=affiche->inter.borne_sup;
    id[i]=affiche->id;
    printf("Id_entreprise : %d -- [%d,%d]\n",affiche->id,affiche->inter.borne_inf,affiche->inter.borne_sup);
    Supp_noeud(abr,affiche->inter,affiche->id);
    i++;
    }
    for(j=0;j<i;j++){
        T_Noeud *nouveau=malloc(sizeof(nouveau));
        T_Inter *nouve=malloc(sizeof(nouve));
        nouve->borne_inf=inf[j];
        nouve->borne_sup=sup[j];
        nouveau=creer_noeud(id[j],*nouve);
        ajouter_noeud(abr,nouveau);
    }*/
    if(abr==NULL) printf("l arbre est vide\n");
    else parcours_infixeTri(abr);

}

void parcours_infixeId(T_Noeud *abr,int Id_entreprise)
{
    if(abr!=NULL)
    {
        parcours_infixeId(abr->fils_g,Id_entreprise);
        if(abr->id==Id_entreprise)
            printf("Id_entreprise : %d -- [%d,%d]\n",abr->id,abr->inter.borne_inf,abr->inter.borne_sup);
        parcours_infixeId(abr->fils_d,Id_entreprise);
    }
}

void affiche_entr(T_Arbre abr,int Id_entreprise)
{
    parcours_infixeId(abr,Id_entreprise);
}

void detruire_arbre(T_Arbre *abr)
{
    T_Noeud *affiche=minimum(*abr);

    while((*abr)!=NULL)
    {
        affiche=minimum(*abr);
        Supp_noeud(abr,affiche->inter,affiche->id);
    }
}
