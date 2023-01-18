#include <stdio.h>
#include <stdlib.h>



typedef struct _produit
{
    int ref;                        //valeur de référence produit
    int eq;                         //valeur de facteur d'equilibre
    struct _produit *fg, *fd;       //pointeurs vers les noeuds fils
}Produit, *AVL;

void afficher(AVL a, int n)
{
    int i;
    if(a){
        afficher(a->fd, n+1);
        for(i=1; i<=n; i++){
            printf("--");
        }
        printf("%d (%d)\n" , a->ref,a->eq);
        afficher(a->fg, n+1);

    }
}

AVL creer(int n)
{
    AVL nouveau = (AVL)malloc(sizeof(Produit));
    if(nouveau)
    {
        nouveau->ref=n;
        nouveau->fg=NULL;
        nouveau->fd=NULL;
    }
    return nouveau;
}

AVL ajouterVal(int n, AVL a)
{
    if(a == NULL){a=creer(n);}
    else
    {
        if(n<=a->ref){a->fg=ajouterVal(n,a->fg);}
        else{a->fd=ajouterVal(n,a->fd);}
    }
    return a;
}
int Hauteur(AVL a){
    if (a){
        if(a->fd==NULL && a->fg==NULL){
            return 0;

        }
        else if (Hauteur(a->fg)>= Hauteur(a->fd)){
            return 1+ Hauteur(a->fg);
        }
        else{
            return 1+ Hauteur(a->fd);
        }
    }
    else return -1;

}

void maj_eq(AVL a)
{
    if(a){
        maj_eq(a->fd);
        a->eq=Hauteur(a->fg)- Hauteur(a->fd);
        maj_eq(a->fg);
    }
}
AVL rd(AVL a)
{
    AVL fgr = NULL, fdfgr = NULL;
    fgr=a->fg;
    if(fgr)
    {
        fdfgr=fgr->fd;
        fgr->fd=a;
    }
    fgr->fd->fg=fdfgr;
    return fgr;
}

// rotation à gauche(rg)
AVL rg(AVL a)
{
    AVL fdr=NULL,fgfdr=NULL;
     fdr=a->fd;
    if(fdr)
    {
        fgfdr=fdr->fg;
        fdr->fg=a;
    }
    fdr->fg->fd=fgfdr;
    return fdr;
}

// rotation à gauche suivie de rotation à droite(rgd)
AVL rgd(AVL a)
{
    if(a){
        a->fg=rg(a->fg);
        a=rd(a);
        return a;
    }
}

// rotation à droite suivie de rotation à (rdg)
AVL rdg(AVL a)
{
    if(a){
        a->fd=rd(a->fd);
        a=rg(a);
        return a;
    }
}


AVL reequilibre(AVL a){
    if(a->eq == -2){
        if(a->fd->eq == 0 || a->fd->eq == -1){
            rg(a);
        }
        else if(a->fd->eq == 1){
            rdg(a);
        }
    }
    else if(a->eq == 2){
        if(a->fg->eq == -1){
            rgd(a);
        }
        else if(a->fg->eq == 0 || a->fg->eq == 1){
            rd(a);
        }
    }
}

AVL inserer_reeq(AVL a, int n)
{
    AVL p=NULL;
    if (a)
    {

        if (n <=a->ref)
        {
            a->fg=inserer_reeq(a->fg,n);
        }
        else
        {
            a->fd=inserer_reeq(a->fd,n);
        }

        maj_eq(a);

        if ((a->eq < -1)||(a->eq > 1))
        {
            a= reequilibre(a);
        }
        return a;
    }
    else
    {
        p=creer(n);
        return p;
    }
}



int main()
{
    int i=0;
    AVL a = NULL;
    int t[] = {4, 2, 1, 8, 6, 7, 3, 9, 5};
    while(t[i]){
        a=inserer_reeq(a,t[i]);
        i++;
    }
    afficher(a, 0);
    return 0;
}
