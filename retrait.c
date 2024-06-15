#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int retrait()
{
    system("cls");//balayer l'ecran

    Compte compte;//declaration de la structure compte de type Compte
    Date date;//declaration de la structure date de type Date

    long long num;//declarer une variable de type long long

    FILE* fichier,*F;//declaration de variable de type pointeur vers la structure FILE

    fichier=fopen("password.txt","r");//ouverture du fichier password.txt en mode lecture
    F=fopen("brouillon.txt","a");//ouverture du nouveau fichier brouillon.txt en mode ajout

    char projet[]="AGENT FRONT OFFICE";
    printf("\t\t\t%s\n\t\t\t",projet);

    for(int i=0;i<sizeof(projet)-1;i++)
        printf("*");

    printf("===================RETRAIT D'ARGENT========================\n");
    printf("\n\tEntrez le Numero de Compte : ");
    scanf("%lld", &num);

    int i=0,sld, s, pass, a;

    //boucle do while qui va pparcourir le fichier password.txt jusqu'a la derniere ligne
    do
    {
        fscanf(fichier,"%lld || %d || %d || %d / %d / %d\n", &compte.numero_cmpt, &compte.password, &compte.solde, &date.jour, &date.mois, &date.annee);

        s=compte.solde;//affectation du solde a la variable s
        pass=compte.password;//affectation du mot de pass a la variable pass

        if(num==compte.numero_cmpt)//si en parcourant le fichier on trouve un numero de compte egal a num on entre dans la structure conditionnel
        {

            // la boucle qui va permettre de saisir un montant pour que le solde restant soit superieur ou egal a 5

            do
            {

                printf("\n\tEntrez le Montant à Retirer : ");
                scanf("%d",&sld);//lire le montant a retirer

                compte.solde=s-sld;//le nouveau solde sera dans la variable compte.solde
                if(compte.solde<5)// si le solde est inferieur a 5 on affiche le message dans la structure conditionnel
                {
                    printf("\n\tSolde Insuffisant!");
                }

            }while(compte.solde<5);// si le solde est inferieur a 5 la boucle continue jusqu'a ce qu'on

            //bpoucle qui va permettre de saisir le mot de passe qui convient

            do
            {
                printf("\n\tEntrez votre Mot de Passe : ");
                scanf("%d", &compte.password);

                if(compte.password!=pass)printf("\n\tMot de passe incorrecte! \n");
            }while(compte.password!=pass);//si le mot de passe est incorrecte, la boucle tourne jusqu'a ce le mot de passe soit correcte

            a=compte.solde;//affecter le solde a la variable a
            i=1;//donner a la variable i la valeur 1
        }
        fprintf(F,"%lld || %d || %d || %d / %d / %d\n", compte.numero_cmpt, compte.password, compte.solde, date.jour, date.mois, date.annee);//ecrire  les donnees dans le fichier brouillon.txt

    }while(!feof(fichier));//la boucle s'arrete lorsqu'il n'ya plus de donnees

    if(i==0)//si i=0, le compte n'existe pas
    {
        printf("\n\tCe Numero De Compte N'existe Pas");
    }
    else// si i=1 le compte existe
    {
        printf("\n\tvous avez effectué un retrait de %d$\n\tNouveau solde -> %d$",sld,a);
    }

    fclose(fichier);//fermeture du fichier password.txt
    fclose(F);

    remove("password.txt");//supprimer le fichier password.txt

    rename("brouillon.txt","password.txt");//renomer le fichier brouillon.txt et il devient password.txt

}


