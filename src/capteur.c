#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "capteur.h"
#include "callbacks.h"
#include <gtk/gtk.h>

enum
{
	ID,
	TYPE,
	MARQUE,
	QTE,
	DATE,
	COLUMNS
};

enum
{
	ID1,
	TYPE1,
	MARQUE1,
	ETAGE,
	VALEUR,
	DATE1,
	STATUT,
	COLUMNS1
};

void ajouter(capteur u, char *fname){
GtkWidget *pQuestion, *pInfo;
FILE *f;
int b=0;
gpointer user_data;
capteur p;
f=fopen(fname,"a+");
if(f!=NULL)
{	while(fscanf(f,"%s %d %s %d %d %d %d\n",p.id,&(p.type),p.marque,&(p.qte),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{	
		if(strcmp(u.id,p.id)==0)
		b++;
	}
	if(b==0){
	fprintf(f,"%s %d %s %d %d %d %d\n",u.id,u.type,u.marque,u.qte,u.d.j,u.d.m,u.d.a);
	pQuestion=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Capteur ajouté avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pQuestion);
	break;
	}
	}
	if(b!=0){
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"Capteur déja existant !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	fclose(f);
}
}

void modifier(capteur u, char *fname){
capteur p;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(fname,"r");
g=fopen("dump.txt","w");
if(f==NULL||g==NULL)
{
	return;
}
else{
	while(fscanf(f,"%s %d %s %d %d %d %d\n",p.id,&(p.type),p.marque,&(p.qte),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
		if(strcmp(p.id,u.id)!=0)
			fprintf(g,"%s %d %s %d %d %d %d\n",p.id,p.type,p.marque,p.qte,p.d.j,p.d.m,p.d.a);
		else
			fprintf(g,"%s %d %s %d %d %d %d\n",p.id,u.type,u.marque,u.qte,p.d.j,p.d.m,p.d.a);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Capteur modifié avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(fname);
rename("dump.txt",fname);
}
}

void afficher(GtkWidget *liste, char *fname)
{
capteur p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
gchar date_achat[50], type[20];
FILE *f;


store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" ID", renderer,"text",ID, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Type", renderer,"text",TYPE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Marque", renderer,"text",MARQUE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_resizable(column,TRUE);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Quantité", renderer,"text",QTE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Date d'achat", renderer,"text",DATE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);



store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING);
f=fopen(fname,"r");
if(f!=NULL)

{ f = fopen(fname,"a+");
		while(fscanf(f,"%s %d %s %d %d %d %d\n",p.id,&(p.type),p.marque,&(p.qte),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
sprintf(date_achat,"%d/%d/%d",p.d.j,p.d.m,p.d.a);
sprintf(type,p.type==0?"Température":p.type==1?"Débit d'eau":p.type==2?"Mouvement":"Fumée");
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,p.id,TYPE,type,MARQUE,p.marque,QTE,p.qte,DATE,date_achat,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
gtk_tree_view_set_reorderable(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_rules_hint(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_search_column(GTK_TREE_VIEW(liste),0);
gtk_tree_view_set_enable_tree_lines(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_grid_lines(GTK_TREE_VIEW(liste),GTK_TREE_VIEW_GRID_LINES_BOTH);
}

void supprimer(capteur u, char *fname)
{
capteur p;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen(fname,"r");
g=fopen("dump.txt","w");
if(f!=NULL&&g!=NULL){
	while(fscanf(f,"%s %d %s %d %d %d %d\n",p.id,&(p.type),p.marque,&(p.qte),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
		if(strcmp(p.id,u.id)!=0)
			fprintf(g,"%s %d %s %d %d %d %d\n",p.id,p.type,p.marque,p.qte,p.d.j,p.d.m,p.d.a);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Capteur supprimé avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove(fname);
rename("dump.txt",fname);
}
}
void ajouter_mesure(mesure u, char *fname){
GtkWidget *pQuestion, *pInfo;
FILE *f;
int b=0;
gpointer user_data;
mesure p;
f=fopen(fname,"a+");
if(f!=NULL)
{	while(fscanf(f,"%s %d %s %s %f %d %d %d\n",p.id,&(p.type),p.marque,p.etage,&(p.valeur),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{	
		if(strcmp(u.id,p.id)==0&&p.d.j==u.d.j&&p.d.m==u.d.m&&p.d.a==u.d.a)
		b++;
	}
	if(b==0){
	fprintf(f,"%s %d %s %s %.2f %d %d %d\n",u.id,u.type,u.marque,u.etage,u.valeur,u.d.j,u.d.m,u.d.a);
	pQuestion=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Mesure ajoutée avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pQuestion);
	break;
	}
	}
	if(b!=0){
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"Mesure déja existante !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	fclose(f);
}
}

void capteur_defectueux(GtkWidget *liste, char *fname)
{
mesure p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
gchar date_mesure[50], type[20], statut[20], val[20];
FILE *f;


store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" ID", renderer,"text",ID1, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Type", renderer,"text",TYPE1, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Marque", renderer,"text",MARQUE1, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_resizable(column,TRUE);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Etage", renderer,"text",ETAGE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Valeur", renderer,"text",VALEUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Date de mesure", renderer,"text",DATE1, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Statut", renderer,"text",STATUT, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);


store=gtk_list_store_new(COLUMNS1, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen(fname,"r");
if(f!=NULL)

{ f = fopen(fname,"a+");
		while(fscanf(f,"%s %d %s %s %f %d %d %d\n",p.id,&(p.type),p.marque,p.etage,&(p.valeur),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
if(p.valeur>50||p.valeur<-10){
sprintf(statut,"Défectueux");
sprintf(val,"%.2f",p.valeur);
sprintf(date_mesure,"%d/%d/%d",p.d.j,p.d.m,p.d.a);
sprintf(type,p.type==0?"Température":p.type==1?"Débit d'eau":p.type==2?"Mouvement":"Fumée");
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID1,p.id,TYPE1,type,MARQUE1,p.marque,ETAGE,p.etage,VALEUR,val,DATE1,date_mesure,STATUT,statut,-1);
}
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
gtk_tree_view_set_reorderable(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_rules_hint(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_search_column(GTK_TREE_VIEW(liste),0);
gtk_tree_view_set_enable_tree_lines(GTK_TREE_VIEW(liste),TRUE);
gtk_tree_view_set_grid_lines(GTK_TREE_VIEW(liste),GTK_TREE_VIEW_GRID_LINES_BOTH);
}

