#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct date
{
    int j;
    int m;
    int a;
}date;

typedef struct mesure
{
    char id[20];
    int type;
    char marque[20];
    char etage[5];
    float valeur;
    date d;
}mesure;


typedef struct capteur
{
    char id[20];
    int type;
    char marque[20];
    int qte;
    date d;
}capteur;

void ajouter(capteur u, char *fname);
void supprimer(capteur u, char *fname);
void modifier(capteur u, char *fname);
void afficher(GtkWidget *liste, char *fname);
//char* capteur_defectueux(char *fname);
void capteur_defectueux(GtkWidget *liste, char *fname);
void ajouter_mesure(mesure u, char *fname);

