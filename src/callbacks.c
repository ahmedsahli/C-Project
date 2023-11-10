#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capteur.h"


void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *aj, *dashboard;
dashboard=lookup_widget(objet,"dashboard");
aj=lookup_widget(objet,"aj");
aj=create_aj();
gtk_widget_show(aj);


}


void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod, *dashboard;
dashboard=lookup_widget(objet,"dashboard");
mod=lookup_widget(objet,"mod");
mod=create_mod();
gtk_widget_show(mod);
}


void
on_button3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af;
af=lookup_widget(objet,"af");
af=create_af();
gtk_widget_show(af);
treeview=lookup_widget(af,"treeview");
afficher(treeview,"capteurs.txt");
}


void
on_button4_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *def, *treeview;
def=lookup_widget(objet,"def");
def=create_def();
gtk_widget_show(def);
treeview=lookup_widget(def,"treeview_def");
capteur_defectueux(treeview,"mesures.txt");
}


void
on_button_mod_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *pInfo, *mod4;
capteur u;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"mod4");
strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(mod1)));
u.type=gtk_combo_box_get_active(GTK_COMBO_BOX(mod2));
strcpy(u.marque,gtk_entry_get_text(GTK_ENTRY(mod3)));
u.qte=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mod4));
modifier(u,"capteurs.txt");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Capteur modifié avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}


void
on_check_id_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *pInfo, *mod4;
capteur p;
int a=0;
char id[50];
FILE *f;
mod1=lookup_widget(objet,"mod1");
mod2=lookup_widget(objet,"mod2");
mod3=lookup_widget(objet,"mod3");
mod4=lookup_widget(objet,"mod4");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(mod1)));
f = fopen("capteurs.txt","r");
if(f!=NULL){
while(fscanf(f,"%s %d %s %d %d %d %d\n",p.id,&(p.type),p.marque,&(p.qte),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
	{
		if(strcmp(p.id,id)==0){
			a=1;
			break;
                 }
	}
fclose(f);
}
if(a==1){
gtk_combo_box_set_active(GTK_COMBO_BOX(mod2),p.type);
gtk_entry_set_text(GTK_ENTRY(mod3),p.marque);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mod4),p.qte);
}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Capteur introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}


void
on_button_af_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *af;
af=lookup_widget(objet,"af");
gtk_widget_destroy(af);
af=lookup_widget(objet,"af");
af=create_af();
gtk_widget_show(af);
treeview=lookup_widget(af,"treeview");
afficher(treeview,"capteurs.txt");
}


void
on_button_aj_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj1, *aj2, *aj3, *aj4;
GtkCalendar *ajc;
capteur u;
guint day, month, year;
aj1=lookup_widget(objet,"aj1");
aj2=lookup_widget(objet,"aj2");
aj3=lookup_widget(objet,"aj3");
aj4=lookup_widget(objet,"aj4");
ajc=lookup_widget(objet,"ajc");
strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(aj1)));
u.type=gtk_combo_box_get_active(GTK_COMBO_BOX(aj2));
strcpy(u.marque,gtk_entry_get_text(GTK_ENTRY(aj3)));
u.qte=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aj4));
gtk_calendar_get_date(GTK_CALENDAR(ajc), &day, &month, &year);
u.d.j=year;
u.d.m=month+1;
u.d.a=day;
ajouter(u,"capteurs.txt");
}


void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar *id;
	capteur u;
	GtkWidget *pInfo;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,-1);
	strcpy(u.id,id);
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer ce capteur?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo);
	supprimer(u,"capteurs.txt");
	afficher(treeview,"capteurs.txt");
	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pInfo);
	break;
}	
}
}


void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj_mesure, *dashboard;
dashboard=lookup_widget(objet,"dashboard");
aj_mesure=lookup_widget(objet,"aj_mesure");
aj_mesure=create_aj_mesure();
gtk_widget_show(aj_mesure);
}


void
on_button_ajm_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *aj1, *aj2, *aj3, *aj4, *aj5;
GtkCalendar *ajc;
mesure u;
guint day, month, year;
aj1=lookup_widget(objet,"ajm1");
aj2=lookup_widget(objet,"ajm2");
aj3=lookup_widget(objet,"ajm3");
aj4=lookup_widget(objet,"ajm4");
aj5=lookup_widget(objet,"ajm5");
ajc=lookup_widget(objet,"ajmc");
u.type=gtk_combo_box_get_active(GTK_COMBO_BOX(aj1));
strcpy(u.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(aj2)));
strcpy(u.marque,gtk_label_get_text(GTK_LABEL(aj3)));
strcpy(u.etage,gtk_entry_get_text(GTK_ENTRY(aj4)));
u.valeur=atof(gtk_entry_get_text(GTK_ENTRY(aj5)));
gtk_calendar_get_date(GTK_CALENDAR(ajc), &day, &month, &year);
u.d.j=year;
u.d.m=month+1;
u.d.a=day;
ajouter_mesure(u,"mesures.txt");
}


void
on_button_def_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview, *def;
def=lookup_widget(objet,"def");
gtk_widget_destroy(def);
def=lookup_widget(objet,"def");
def=create_def();
gtk_widget_show(def);
treeview=lookup_widget(def,"treeview_def");
capteur_defectueux(treeview,"mesures.txt");
}


void
on_ajm2_changed                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajm2, *ajm3;
capteur p;
FILE *f;
ajm2=lookup_widget(objet,"ajm2");
ajm3=lookup_widget(objet,"ajm3");
f=fopen("capteurs.txt","r");
if(f){
while(fscanf(f,"%s %d %s %d %d %d %d\n",p.id,&(p.type),p.marque,&(p.qte),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF){
if(strcmp(p.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ajm2)))==0)
gtk_label_set_text(GTK_LABEL(ajm3),p.marque);
}
fclose(f);
}
}


void
on_ajm1_changed                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajm1, *ajm2;
capteur p;
FILE *f;
ajm1=lookup_widget(objet,"ajm1");
ajm2=lookup_widget(objet,"ajm2");
f=fopen("capteurs.txt","r");
if(f){
while(fscanf(f,"%s %d %s %d %d %d %d\n",p.id,&(p.type),p.marque,&(p.qte),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF){
if(p.type==gtk_combo_box_get_active(GTK_COMBO_BOX(ajm1)))
gtk_combo_box_append_text (GTK_COMBO_BOX (ajm2), _(p.id));
}
fclose(f);
}
}

