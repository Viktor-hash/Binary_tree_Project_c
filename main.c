#include <stdio.h>
#include <stdlib.h>
#include"TP4.h"

int main()
{

    T_Arbre abr;
    int i=0;
    int id=0;
    int infnew=0;
    int supnew=0;
    int inf=0;
    int sup=0;
    int opt=0;
    while(opt!=8)
    {

        printf("\n\n----------Menu------------ \n");
        printf("1)	Creer un ABR\n");
        printf("2)	Afficher tous les reservations\n");
        printf("3)	Ajouter une reservation\n");
        printf("4)	Modifier une reservation\n");//pb avec ça je sais pas pk garde l'ancien modifie bizarrement
        printf("5)	Supprimer une reservation\n");
        printf("6)	Afficher les reservations d une entreprise\n");
        printf("7)	Supprimer l arbre\n");
        printf("8)  Quitter\n");

        scanf("%d",&opt);

        switch(opt)
        {
        case 1 :
            i++;
            abr=NULL;
            break;
        case 2 :
            if(i!=0) affiche_abr(abr);
            else printf("l arbre n a pas ete cree\n");
            break;
        case 3 :
            if (i!=0){
            printf("De quelle entreprise s agit-t-il? (rentrer son ID)\n>>> ");
            scanf("%d",&id);
            printf("Rentrer la date de debut de reservation(MMJJ) ex 602 pour 02/06\n>>> ");
            scanf("%d",&inf);
            printf("Rentrer la date de fin de reservation(MMJJ) ex 602 pour 02/06\n>>> ");
            scanf("%d",&sup);

            T_Inter inter;
            T_Noeud* noeud;
            inter.borne_inf=inf;
            inter.borne_sup=sup;
            if(verifier_intervalle(inter)){
            noeud = creer_noeud(id,inter);
            ajouter_noeud(&abr,noeud);
            }
            else printf("il y a eu une erreur dans les donnees rentrees\n");
            }
            else printf("l arbre n a pas ete cree\n");
            break;
        case 4 :
            if(i!=0){
            printf("De quelle entreprise s agit-t-il? (rentrer son ID)\n>>> ");
            scanf("%d",&id);
            printf("Rentrer la date de debut de reservation(MMJJ) ex 602 pour 02/06\n>>> ");
            scanf("%d",&inf);
            printf("Rentrer la date de fin de reservation(MMJJ) ex 602 pour 02/06\n>>> ");
            scanf("%d",&sup);
            printf("Rentrer la date de debut de reservation du nouvel intervalle(MMJJ) ex 602 pour 02/06\n>>> ");
            scanf("%d",&infnew);
            printf("Rentrer la date de fin de reservation du nouvel intervalle(MMJJ) ex 602 pour 02/06\n>>> ");
            scanf("%d",&supnew);

            T_Inter inter;
            T_Inter inter2;
            inter.borne_inf=inf;
            inter.borne_sup=sup;
            inter2.borne_inf=infnew;
            inter2.borne_sup=supnew;

            if(verifier_intervalle(inter)&&verifier_intervalle(inter2)){
            modif_noeud(&abr,inter,id,inter2);
            }
            else printf("il y a eu une erreur dans les donnees rentrees\n");
            }
            else printf("l arbre n a pas ete cree\n");
            break;
        case 5 :
            if (i!=0){
            printf("De quelle entreprise s agit-t-il? (rentrer son ID)\n>>> ");
            scanf("%d",&id);
            printf("Rentrer la date de debut de reservation(MMJJ) ex 602 pour 02/06\n>>> ");
            scanf("%d",&inf);
            printf("Rentrer la date de fin de reservation(MMJJ) ex 602 pour 02/06\n>>> ");
            scanf("%d",&sup);

            T_Inter inter;

            inter.borne_inf=inf;
            inter.borne_sup=sup;
            if(verifier_intervalle(inter)){

            Supp_noeud(&abr,inter,id);
            }
            else printf("il y a eu une erreur dans les donnees rentrees\n");
            }
            else printf("l arbre n a pas ete cree\n");
            break;
        case 6 :
            if(i!=0){
            printf("De quelle entreprise s agit-t-il? (rentrer son ID)\n>>> ");
            scanf("%d",&id);
            affiche_entr(abr,id);
            }
            else printf("l arbre n a pas ete cree\n");
            break;
        case 7 :
            if(i!=0){
            detruire_arbre(&abr);
            }
            else printf("l arbre n a pas ete cree\n");
            break;

            }}
   /*         T_Arbre abr;
            abr=NULL;
            T_Inter inter;
            T_Inter inter2;
            T_Inter inter3;
            T_Inter inter4;
            T_Inter inter5;
            T_Noeud* noeud;
            T_Noeud* noeud2;
            T_Noeud* noeud3;
            T_Noeud* noeud4;
            T_Noeud* noeud5;
            inter.borne_inf=4;
            inter.borne_sup=6;
            inter2.borne_inf=2;
            inter2.borne_sup=3;
            inter3.borne_inf=15;
            inter3.borne_sup=16;
            inter4.borne_inf=10;
            inter4.borne_sup=12;
            inter5.borne_inf=13;
            inter5.borne_sup=14;
            int a=1;
            int b=1;
            int c=3;
            int d=1;
            int e=5;
            noeud = creer_noeud(a,inter);
            noeud2 = creer_noeud(b,inter2);
            noeud3 = creer_noeud(c,inter3);
            noeud4 = creer_noeud(d,inter4);
            noeud5 = creer_noeud(e,inter5);
            ajouter_noeud(&abr,noeud);
            ajouter_noeud(&abr,noeud2);
            ajouter_noeud(&abr,noeud3);
            ajouter_noeud(&abr,noeud4);


            //modif_noeud(abr,inter,a,inter5);

            //printf("%d\n",abr->id);
            //printf("%d\n",abr->fils_d->fils_g->id);
            //printf("%d",minimum(abr)->inter.borne_inf);
            affiche_entr(abr,1);
            affiche_abr(abr);
            detruire_arbre(&abr);
            if(abr==NULL)
                printf("detruit");*/
            return 0;
        }
