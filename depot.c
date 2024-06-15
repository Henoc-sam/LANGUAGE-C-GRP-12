#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOM 100

//la structure pour le compte
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

// la fonction de depot

int depot()
{
    system("cls"); //Balayer l'ecran

    char projet[]="AGENT FRONT OFFICE";
    printf("\t\t\t%s\n\t\t\t",projet);

    for(int i=0;i<sizeof(projet)-1;i++)
        printf("*");

    Compte compte;//declaration de la structure compte de type Compte
    Informatiion Info;//declaration de la structure info de type Information
    Date date;//declaration de la structure date de type Date

    long long num;//long long peut stocker des entier de (-2^63) a (2^63)

    FILE *fichier, *F, *info;//declaration de variable de type pointeur vers la structure FILE
    fichier=fopen("password.txt","r");//ouverture du fichier password.txt en mode lecture
    F=fopen("brouillon.txt","a");//cree et ouvre le fichier en mode ajout
    info=fopen("comptes.txt","r");

    printf("===================DEPOT D'ARGENT========================\n");

    printf("\n\tEntrez le Numero de Compte -> ");
    scanf("%lld", &num);//lire le numero entrez par l'utilisateur

    int i=0,sld, s;

    //boucle qui va parcourir le fichier

    do
    {
        fscanf(fichier,"%lld || %d || %d || %d / %d / %d\n", &compte.numero_cmpt, &compte.password, &compte.solde, &date.jour, &date.mois, &date.annee);//recuperation des donnes d'une ligne du fichier password.txt puis passe a la ligne suivante

        //lecture du contenu de comptes.txt
        fscanf(F,"%lld || %s || %s || %s || %d || %s , %d - %d - %d || %d, %s , %s , %s , %s , %s\n", &compte.numero_cmpt, &compte.nom, &compte.postnom, &compte.prenom, &compte.numtel, &compte.lieuNaiss,&compte.jour, &compte.mois, &compte.annee, &Info.numparc, &Info.avenue, &Info.quart, &Info.comm, &Info.ville, &Info.pays);

        s=compte.solde;//affecte la valeur du solde actuelle pour ne pas le perdre

        if(num==compte.numero_cmpt)
        {

            printf("\n\tEntrez le Montant à deposer : ");
            scanf("%d",&sld);//lire montant a deposer

            compte.solde=s+sld;//la nouvelle valeur du solde
            num=compte.numero_cmpt;//on affecte compte.numero_cmpt a num pour l'affichier dans le else de if(i==0)

            s=compte.solde;// stocker la valeur du nouveau solde pour l'afficher apres

            i=1;//on affecte i a 1 si il entre dans la structure et si il n'entre pas i restera egal a 0

            //printf("Num: %lld \nPass: %d \nSolde: %d\n", compte.numero_cmpt, compte.password, compte.solde);
        }
        fprintf(F,"%lld || %d || %d || %d / %d / %d\n", compte.numero_cmpt, compte.password, compte.solde, date.jour, date.mois, date.annee);//ecriture des donnes dans le nouveau fichier brouillon.txt

    }while(!feof(fichier));//parcourir le fichier jusqu'a la derniere ligne

    if(i==0)// si i=0 donc si i n'est pas entrez dans la condition if(num==compte.numeri_cmpt)
    {
        printf("\n\tCe Numero De Compte N'existe Pas");
    }
    else // et si i est entrez dans la condition
    {
        printf("\n\tvous avez effectué un depot de %d$ au Numero de Compte %lld\n\nNouveau solde: %d",sld, num, s);
    }

    fclose(fichier);// on ferme le fichier password.txt
    fclose(F);// on ferne le fichier brouillon.txt

    remove("password.txt");//on supprime le fichier password.txt
    rename("brouillon.txt","password.txt");// on renome le fichier brouillon.txt et il devient password.txt

}


