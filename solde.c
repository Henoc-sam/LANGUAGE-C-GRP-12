#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOM 100

//structure du compte
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

//structure de l'adresse
typedef struct{

    char pays[MAX_NOM];
    char ville[MAX_NOM];
    char avenue[MAX_NOM];
    char comm[MAX_NOM];
    char quart[MAX_NOM];
    int numparc;

}Informatiion;

int solde()
{
    system("cls");//balayer l'ecran

    Compte compte;//declaration de la structure compte de type Compte
    Informatiion Info;//declaration de la structure info de type Information
    Date date;//declaration de la structure date de type Date

    int option;//declarationn de la fonction option

    char projet[]="AGENT FRONT OFFICE";
    printf("\t\t\t%s\n\t\t\t",projet);

    for(int i=0;i<sizeof(projet)-1;i++)
        printf("*");

    long long num;//declarration de la variable num de type long long

    FILE* fichier,*F;//declaration de variable de type pointeur vers la structure FILE

    fichier=fopen("password.txt","r");//ouverture du fichier password.txt en mode lectrure
    F=fopen("comptes.txt","r");//ouverture du fichier comptes.txt en mode lecture

    printf("\n\t===================VERIFIER MON SOLDE========================\n");

    printf("\n\tEntrez le Numero de Compte : ");//demander le numero de compte
    scanf("%lld", &num);//lire le numero de compte

    int i=0,sld, s, pass;

    //cette boucle va parcourir le fichier comptes.txt jusqu'a sa derniere ligne
    do
    {
        fscanf(fichier,"%lld || %d || %d || %d / %d / %d\n", &compte.numero_cmpt, &compte.password, &compte.solde, &date.jour, &date.mois, &date.annee);//lire les contenus du fichier password.txt

        //lecture du contenu de comptes.txt
        fscanf(F,"%lld || %s || %s || %s || %d || %s , %d - %d - %d || %d, %s , %s , %s , %s , %s\n", &compte.numero_cmpt, &compte.nom, &compte.postnom, &compte.prenom, &compte.numtel, &compte.lieuNaiss,&compte.jour, &compte.mois, &compte.annee, &Info.numparc, &Info.avenue, &Info.quart, &Info.comm, &Info.ville, &Info.pays);

        pass=compte.password;//affectation du mot de pass a la variable pass de type int

        if(num==compte.numero_cmpt)
        {
            do
            {
                printf("\n\tEntrez le Mot de Passe : ");
                scanf("%d", &compte.password);
                if(pass!=compte.password)
                {
                    printf("\n\tMot de passe incorrecte!");
                }
            }while(pass!=compte.password);

            system("cls");//balayer l'ecran
            printf("\t\t\t\t%s\n\t\t\t\t",projet);

            for(int i=0;i<sizeof(projet)-1;i++)
                printf("*");

            printf("\n\t===================VERIFIER MON SOLDE========================\n");

            // afficher les informations du compte

            printf("\n\tBonjour Mr.(Mme) %s %s %s, ", compte.nom, compte.postnom, compte.prenom);// afficher le numero de compte

            printf("Votre solde actuel est de %d$\n", compte.solde);// afficher le solde du compte

            i=1;//affecter à i la valeur 1

        }

    }while(!feof(F));//la boucle va tourner jusqu'a la derniere ligne du fichier

    if(i==0)//si le numero de compte existe, on affichera le message ci-dessous
    {
        printf("\n\tCe Numero De Compte N'existe Pas\n");
    }
    fclose(fichier);//fermeture du fichier password.txt
    fclose(F);//fermeture du fichier comptes.txt

}
