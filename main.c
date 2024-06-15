#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "depot.h"
#include "retrait.h"
#include "compte.h"
#include "InfoCompte.h"
#include "solde.h"

#define MAX_NOM 100
typedef struct {

    long long numero_cmpt;
    int solde;
    char nom[MAX_NOM];
    char postnom[MAX_NOM];
    char prenom[MAX_NOM];
    int password;
    int numtel;
    char lieuNaiss[MAX_NOM];
    int jour;
    int mois;
    int annee;

} Compte;

//structure pour la date du jour
typedef struct{
    int jour;
    int mois;
    int annee;
}Date;

typedef struct{

    char pays;
    char ville;
    char avenue;
    char comm;
    char quart;
    int numparc;

}Informatiion;

//fonction de recherche
int rech(int Numrech)
{
    Compte compte;//declaration de la structure compte de type Compte
    Date date;//declaration de la structure date de type Date

    FILE* fichier; //declarer le fichier texte
    fichier=fopen("password.txt","r");//ouverture du ficvhier en mode lecture

    //boucle qui va parcourir le fichier jusqu'a la derniere ligne
    do
    {
        fscanf(fichier,"%lld || %d || %d || %d / %d / %d\n", &compte.numero_cmpt, &compte.password, &compte.solde, &date.jour, &date.mois, &date.annee); //recuperation des donnes du fichier password.txt
        fflush(stdin);
        if(compte.numero_cmpt==Numrech)//si le nombre entrez
        {
            fclose(fichier);
            return 1;//retourne 1 si le numero esté
        }
    }while(!feof(fichier));

    fclose(fichier);//fermeture du fichier password.txt
    return -1;//retourne -1 si le numero n'est pas touvé
}

//la fonction principale

int main()
{
    int option;
    char projet[]="AGENT FRONT OFFICE";

    printf("\t\t%s\n\t\t",projet);

    for(int i=0;i<sizeof(projet)-1;i++)
        printf("*");

    printf("\n\n\t   *********** GROUPE N°12 ****************\n");

    printf("\n\t\t1. MUKEBO TSHIBANGU IL VIVRA");

    printf("\n\t\t2. PETI-AMITA BWALYA ELIEL");

    printf("\n\t\t3. RWESSI BAGULA JULIEN");

    printf("\n\t\t4. SAMWANDA MWABILAYI HENOC");

    sleep(5);//COMPTE 4 SECONDE PUIS AFFICHER LA SUITE
    system("cls");//balayer l'ecran

    printf("\t\t%s\n\t\t",projet);

    for(int i=0;i<sizeof(projet)-1;i++)
        printf("*");

    printf("\n\n\t==================MENU===================\n\n");

    printf("\t1. Creer Un Compte Bancaire");
    printf("\n\t2. Effectuer Un Depot");
    printf("\n\t3. Effectuer Un Retrait");
    printf("\n\t4. Solde");
    printf("\n\t5. Information sur Mon Compte\n\n\t->> ");
    scanf("%d",&option);// LIRE LE CHOIX

    if(option<1 || option>5)printf("code invalide.");// SI 1>option>4 affichie le message "code invalide" et arrete le programme

    switch(option)
    {
        case(1):compte();break;//SI L'UTILISATEUR TAPE 1 LA FONCTION compte SERA APPELE

        case(2):depot();break;//SI L'UTILISATEUR TAPE 2 LA FONCTION depot SERA APPELE

        case(3):retrait();break;//SI L'UTILISATEUR TAPE 3 LA FONCTION retrait SERA APPELE

        case(4):solde();break;//SI L'UTILISATEUR TAPE 4 LA FONCTION solde SERA APPELE

        case(5):InfoCompte();break;//SI L'UTILISATEUR TAPE 5 LA FONCTION InfoCompte SERA APPELE
    }
}

