//MERACHI Aymeric
//GIRARD Axel

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Max_LENGHT 10

typedef char Chaine[15];

typedef struct _Tache{
    Chaine ip; //L'adresse de l'expediteur
    Chaine doc; // le document à imprimer represente de façon simplifié
    int taille; //taille du document
    struct _Tache *suiv, *prec;
}Tache, *List;

typedef struct {
    List debut, fin;
}File;

//1)
List creerTache(Chaine Ipv,Chaine Docu,int ta)
{
    File *f=NULL;
    f=fopen(Docu,"r");
    List t;
    t=(List)malloc(sizeof(Tache));
    strcpy(t->doc,Docu);
    strcpy(t->ip,Ipv);
    t->taille=ta;
    t->suiv=t->prec=NULL;
    fclose(f);
    return t;
}

//2)
void ajouterTacheFile(List t,File *maFile)
{
    if (maFile->debut==NULL){
        maFile->debut=maFile->fin=t;
    }
    else{
        maFile->fin->suiv=t;
        t->prec=maFile->fin;
        maFile->fin=t;
    }
}

//3)
void afficherIpAttenteFile(File *maFile){
    List tmp = maFile->debut;
    while (tmp != NULL){
        printf("Ip: %s\n",tmp->ip);
        tmp=tmp->suiv;
    }

}
void supprimeObjet(File *maListe){
    List tmp=maListe->debut;
    if(tmp){
        if(tmp->prec){
            (tmp->prec)->suiv=tmp->suiv;
        }
        else{
            maListe->debut=tmp->suiv;
        }
        if(tmp->suiv){
            (tmp->suiv)->prec=tmp->prec;
        }
        else{
            maListe->fin-tmp->prec;
        }
    }
    free(tmp);
}

//4)
void imprimer(File *mafile){
    printf("Debut d'impression :\n");
    for (int i=0; i<(mafile->debut->taille); i++){
        printf(" . ");
        Sleep(500);
    }
    printf("\n");
    File *f=NULL;
    Chaine c;
    f=fopen(mafile->debut->doc,"r");
    if (!f){
        printf("Erreur ouverture fichier");
        exit(1);
    }
    while (!feof(f)){
        fgets(c,Max_LENGHT,f);
        printf("%s",c);
    }
    supprimeObjet(mafile);
}

int afficherEtatFile(File *mafile)
{
    int i=1;
    List tmp = mafile->debut;
    while (tmp->suiv != NULL){
        tmp=tmp->suiv;
        i++;
    }

    free(tmp);
    return i;
}

void supprimerTachesUser(Chaine ipv4, File *maListe){
    List tmp=maListe->debut;
    while ((tmp) && (strcmp(tmp->ip,ipv4))){
        if(tmp){
            if(tmp->prec){
                (tmp->prec)->suiv=tmp->suiv;
            }
            else{
                maListe->debut=tmp->suiv;
            }
            if(tmp->suiv){
                (tmp->suiv)->prec=tmp->prec;
            }
            else{
                maListe->fin-tmp->prec;
            }

        }
        tmp=tmp->suiv;
    }
    free(tmp);

}

int main()
{
    Tache *t, *t2,*t3;
    File f;
    int a;
    Chaine c1="192.168.1.4";
    f.debut=NULL;
    t=creerTache("192.168.1.254","1234.txt", 5);
    t2=creerTache("192.168.1.1","oui",6);
    t3=creerTache("192.168.1.4","non",8);
    ajouterTacheFile(t, &f);
    ajouterTacheFile(t2, &f);
    ajouterTacheFile(t3, &f);
    afficherIpAttenteFile(&f);
    imprimer(&f);
    a=afficherEtatFile(&f);
    printf("\nNombre de taches a executer :%d\n", a);
    supprimerTachesUser(c1,&f);
    return 0;
}
