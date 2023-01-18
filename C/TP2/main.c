#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 1000
//type Chaine
typedef char Chaine[52];

//typedef Mot
typedef struct _Mot{
    Chaine mot;                 //Mot
    int occ;                    //occurence
    struct _Mot *fg, *fd;       //pointeurs vers fils gauche et fils droite
}MOT, *ABR;
ABR a=NULL;


ABR creerMot(Chaine msg)
{
    ABR paquet=(ABR)malloc(sizeof(MOT));
    strcpy(paquet->mot,msg);
    paquet->occ=1;
    paquet->fg=paquet->fd=NULL;
    return paquet;
}

ABR ajouterMot(ABR arbre, Chaine msg)
{

    if(arbre==NULL){
        printf("l'arbre est vide\n");
        arbre=creerMot(msg);
        return arbre;
    }
    else{

        if(strcmp(arbre->mot,msg)==0){
            arbre->occ++;
        }
        if (strcmp(arbre->mot,msg)>0){
            if(arbre->fd){
                ajouterMot(arbre->fd,msg);

            }
            else{
                arbre->fd=creerMot(msg);
            }

        }

        if (strcmp(arbre->mot,msg)<0){
            if(arbre->fg){
                ajouterMot(arbre->fg,msg);

            }
            else{
                arbre->fg=creerMot(msg);
            }

        }
    }
    return arbre;

}

char* ViderChaine(Chaine ch){//Utiliser pour la fonction RemplirArbre Question 2
    int i=0;
    while(ch[i]!='\0'){
        ch[i]='\0';
        i++;
    }
    return ch;

}

char* TrierChaine(Chaine ch){//Utiliser pour la fonction RemplirArbre Question 2
    int i=0;
    Chaine m;
    while(ch[i]!='\0'){

        if (ch[i]>=0 && ch[i]<=63 || ch[i]>=91 &&ch[i]<=96 || ch[i]>=123 &&ch[i]<=127){

        }
        else{
            m[i]=ch[i];
        }
        i++;
    }
    strcpy(ch,m);
    return ch;

}

void afficherArbre(ABR Arbre){

    if(Arbre){

        afficherArbre(Arbre->fd);
        printf("\n%s  %d fois",Arbre->mot,Arbre->occ);
        afficherArbre(Arbre->fg);
    }


}

ABR RemplirArbre(ABR Arbre, FILE *f){//Question 2
    Chaine mot;
    while(fscanf (f, "%s", mot) ==1){
        strcpy(mot,TrierChaine(mot));
        Arbre=ajouterMot(Arbre,mot);
        strcpy(mot,ViderChaine(mot));
    }
    return Arbre;

}

void afficherPlusOcc(ABR Arbre, int n){//Question 3
    if(Arbre){

        afficherPlusOcc(Arbre->fd,n);
        if (Arbre->occ>=n){
            printf("\n%s  %d fois",Arbre->mot,Arbre->occ);
        }
        afficherPlusOcc(Arbre->fg,n);
    }

}


int main()
{
    FILE *f;
    f=fopen("donee.txt","r");
    ABR Arbre=NULL;
    Arbre=RemplirArbre(Arbre,f);


    //afficherArbre(Arbre);
    afficherPlusOcc(Arbre,100);
    fclose(f);
    return 0;
}
