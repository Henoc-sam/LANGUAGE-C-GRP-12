#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NOM 100

// Structure pour stocker les informations d'un compte

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

//Strucuture de l'adresse

typedef struct{
    char pays[MAX_NOM];
    char ville[MAX_NOM];
    char avenue[MAX_NOM];
    char comm[MAX_NOM];
    char quart[MAX_NOM];
    int numparc;
}Informatiion;


//fonction de compte

int compte()
{
    Informatiion Info;//declaration de la structure info de type Information
    Compte compte;//declaration de la structure compte de type Compte

    system("cls");//balayer l'ecran

    FILE *fichier,*F;//declaration de variable de type pointeur vers la structure FILE

    int pass;//declaration de la variable pass qui vas stocker le mot de pass entrer pour la premiere fois
    int nb;//nb va permettre de compter le nomre de chiffre saisi par l'utlisteur

    compte.solde=0;//INITIALISER LE SOLDE A 0

    char nom_fichier[] = "comptes.txt"; // Nom du fichier texte

    // Ouvrir le fichier en mode écriture

    fichier = fopen(nom_fichier,"a");//ouverture du fichier comptes.txt en mode ajout
    F = fopen("password.txt","a");//ouverture du fichier password.txt en mode ajout

    // Saisie des informations pour chaque compte
    while (1) {
        system("cls");//balayer l'ecran
        char projet[]="AGENT FRONT OFFICE";
        printf("\t\t\t%s\n\t\t\t",projet);

        for(int i=0;i<sizeof(projet)-1;i++)
            printf("*");

        printf("\n\t=====================================================\n");
        printf("\n\t============CREATION DE COMPTE==============\n");

        printf("\n\tNom : ");//demander le nom
        scanf("%s", &compte.nom);//lire le nom

        printf("\n\tPostnom : ");//demander le postnom
        scanf("%s", &compte.postnom);//lire le postnom

        printf("\n\tPrénom : ");//demander le prenom
        scanf("%s", &compte.prenom);//lire le prenom

        do  // cette boucle permettra de verifier si le numero de telephone saisi est complet ou tros grand
        {
            nb=0;
            printf("\n\tNumero de telephone : (+243)");//demander le numero de telephone
            scanf("%d", &compte.numtel);//lire le numero de telephone

            long long nbre;//declarer une variable qui permettra de stocker le numero de telephone saisi

            nbre=compte.numtel;//affecter la valeur du numero de telephone a la variable nbre

            while(nbre!=0)//la boucle va tourne jusqu'a ce que la valeur de nbre soit egale a 0
            {
                nbre=nbre/10;//a chaque fois il vas diviser le nombre par 10 pour trouver

                nb=nb+1;//a chaque tour, on fera nb+1 pour trouver le nbre de chiffe que contient le numero
            }

            if(nb!=9)printf("\n\tNumero incorrecte, Entrez un numero de 10 chiffres!");


        }while(nb!=9);//et si le nombre de chiffre est egal a 9 plus (+243) qui fait 10, le programme vas quitter la boucle

        printf("\n\tLieu de Naissance (PAYS): ");//demander le Lieu de naissance
        scanf("%s", &compte.lieuNaiss);

        printf("\n\tDate de Naissance: ");//demande la date de naissance

        do
        {
            printf("\n\t\tJour : ");//demander le jour
            scanf("%d", &compte.jour);//lire le jour

            if(compte.jour>30)printf("\n\t Jour Incorrecte");

        }while(compte.jour>30 || compte.jour<1);//la boucle tourne si 30<mois<1

        do
        {
            printf("\n\t\tMois : ");//demander le mois
            scanf("%d", &compte.mois);//lire le mois

            if(compte.mois>12)printf("\n\t Mois Incorrecte");

        }while(compte.mois>12 || compte.mois<1);//la boucle tourne si 12<mois<1


        do
        {
            printf("\n\t\tAnnee : ");//demander l'annee
            scanf("%d", &compte.annee);//lire l'annee

            if(compte.annee>2024)printf("\n\t Année incorrecte");

        }while(compte.annee>2024 || compte.annee<1900);//la boucle tourne si 1900>annee>2024

        printf("\n\tAdresse Actuel :\n\t\tPays : ");
        scanf("%s", &Info.pays);//lire le pays

        printf("\n\t\tVille : ");
        scanf("%s", &Info.ville);//lire la ville

        printf("\n\t\tCommune : ");
        scanf("%s", &Info.comm);//lire la commune

        printf("\n\t\tQuartier : ");
        scanf("%s", &Info.quart);//lire le quartier

        printf("\n\t\tAvenue : ");
        scanf("%s", &Info.avenue);//lire l'avenue

        printf("\n\t\tNumero de Parcelle : ");
        scanf("%d", &Info.numparc);//lire le numero de la parcelle

        //----Nombre de chiffre du numero de compte

        srand(time(NULL));// Initialisation de la graine pour les nombres aléatoires

        // Génération d'un nombre aléatoire de 14 chiffres
        long long numeroAleatoire = 0;

        for (int i = 0; i < 14; i++)//la boucle for va aller de 0 a 13 en faisant +1 a chaque fois
        {
            numeroAleatoire = numeroAleatoire * 10 + rand() % 10;//grace a la fonction rand(), le numero de compte sera automatique et aleatoire
        }

        printf("\n\tEntrez votre nouveau Mot de Passe (chiffres) : ");//demander le mot de passe
        scanf("%d", &compte.password);//lire le mote de passe
        pass=compte.password;//stocker le mot de passe a la variable pass

        //boucle do while  pour le mot de passe si le mot de passe est correcte
        do
        {
            printf("\n\tEntrez à nouveau le Mot de Passe : ");//redemander le mot de passe pour confirmer si c'est le bom
            scanf("%d", &compte.password);//lire mot de passe
            if(compte.password!=pass)printf("\n\tMot de passe incorrecte! \n");
        }while(compte.password!=pass);//la boucle continue de tournez jusqu'a ce que le mot de passe soit egal a celui entrez avant


        char reponse;//declaration de la variable reponse

        //obternir la date et l'heure actuelles
        time_t t=time(NULL);
        struct tm tm=*localtime(&t);

        //afficher la date formatee
        //printf("date du jour : %d / %d / %d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);

        printf("\nVoulez-vous creer ce Compte ? (O/N) :");
        scanf(" %c", &reponse);//lire reponse

        if (reponse == 'O' || reponse == 'o') //si la reponse est oui, la condition est respectee
        {

            system("cls");//balayer l'ecran

            compte.numero_cmpt=numeroAleatoire;//affecter au numero de compte le nombre aleatoire generé
            printf("\n\n\tLe Compte de Mr.(Mme.) %s a été enregistré avec succès !\n\n\tNumero de compte : %lld\n", compte.prenom, compte.numero_cmpt);

            // Écriture des informations dans les fichiers password.txt et comptes.txt
            fprintf(F,"%lld || %d || %d || %d / %d / %d\n",compte.numero_cmpt, compte.password, compte.solde, tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
            fprintf(fichier, "%lld || %s || %s || %s || %d || %s , %d - %d - %d || %d, %s , %s , %s , %s , %s\n", compte.numero_cmpt, compte.nom, compte.postnom, compte.prenom, compte.numtel, compte.lieuNaiss,compte.jour, compte.mois, compte.annee, Info.numparc, Info.avenue, Info.quart, Info.comm, Info.ville, Info.pays);

            break; // Sortir de la boucle si la réponse n'est pas 'O' ou 'o'
        }
        else //si la reponse est different de oui, le message ci-dessous sera affiché
        {
            printf("\n\t\tCreation de compte annulé\n");
            break;// Sortir de la boucle si la réponse n'est pas 'O' ou 'o'
        }

    }close(fichier); //fermeture du fichier comptes.txt
    close(F);//fermeture du fichier password.txt

    // Fermer le fichier

    return 0;
}
