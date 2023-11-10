/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_dashboard (void)
{
  GtkWidget *dashboard;
  GtkWidget *fixed1;
  GtkWidget *button1;
  GtkWidget *button2;
  GtkWidget *button3;
  GtkWidget *button4;
  GtkWidget *button5;

  dashboard = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (dashboard, 600, 650);
  gtk_window_set_title (GTK_WINDOW (dashboard), _("Gestion des capteurs"));
  gtk_window_set_position (GTK_WINDOW (dashboard), GTK_WIN_POS_CENTER);
  gtk_window_set_resizable (GTK_WINDOW (dashboard), FALSE);

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (dashboard), fixed1);

  button1 = gtk_button_new_with_mnemonic (_("Ajouter un capteur"));
  gtk_widget_show (button1);
  gtk_fixed_put (GTK_FIXED (fixed1), button1, 168, 72);
  gtk_widget_set_size_request (button1, 296, 72);

  button2 = gtk_button_new_with_mnemonic (_("Modifier un capteur"));
  gtk_widget_show (button2);
  gtk_fixed_put (GTK_FIXED (fixed1), button2, 160, 192);
  gtk_widget_set_size_request (button2, 304, 80);

  button3 = gtk_button_new_with_mnemonic (_("Afficher les capteurs"));
  gtk_widget_show (button3);
  gtk_fixed_put (GTK_FIXED (fixed1), button3, 160, 312);
  gtk_widget_set_size_request (button3, 304, 72);

  button4 = gtk_button_new_with_mnemonic (_("Liste des capteurs d\303\251fectueux"));
  gtk_widget_show (button4);
  gtk_fixed_put (GTK_FIXED (fixed1), button4, 160, 432);
  gtk_widget_set_size_request (button4, 304, 72);

  button5 = gtk_button_new_with_mnemonic (_("Ajouter une mesure"));
  gtk_widget_show (button5);
  gtk_fixed_put (GTK_FIXED (fixed1), button5, 160, 544);
  gtk_widget_set_size_request (button5, 304, 72);

  g_signal_connect ((gpointer) button1, "clicked",
                    G_CALLBACK (on_button1_clicked),
                    NULL);
  g_signal_connect ((gpointer) button2, "clicked",
                    G_CALLBACK (on_button2_clicked),
                    NULL);
  g_signal_connect ((gpointer) button3, "clicked",
                    G_CALLBACK (on_button3_clicked),
                    NULL);
  g_signal_connect ((gpointer) button4, "clicked",
                    G_CALLBACK (on_button4_clicked),
                    NULL);
  g_signal_connect ((gpointer) button5, "clicked",
                    G_CALLBACK (on_button5_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (dashboard, dashboard, "dashboard");
  GLADE_HOOKUP_OBJECT (dashboard, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (dashboard, button1, "button1");
  GLADE_HOOKUP_OBJECT (dashboard, button2, "button2");
  GLADE_HOOKUP_OBJECT (dashboard, button3, "button3");
  GLADE_HOOKUP_OBJECT (dashboard, button4, "button4");
  GLADE_HOOKUP_OBJECT (dashboard, button5, "button5");

  return dashboard;
}

GtkWidget*
create_mod (void)
{
  GtkWidget *mod;
  GtkWidget *fixed2;
  GtkWidget *mod1;
  GtkWidget *label4;
  GtkWidget *label7;
  GtkWidget *mod3;
  GtkWidget *button_mod;
  GtkWidget *alignment1;
  GtkWidget *hbox1;
  GtkWidget *image1;
  GtkWidget *label5;
  GtkWidget *check_id;
  GtkWidget *alignment2;
  GtkWidget *hbox2;
  GtkWidget *image2;
  GtkWidget *label6;
  GtkWidget *mod2;
  GtkObject *mod4_adj;
  GtkWidget *mod4;
  GtkWidget *label8;
  GtkWidget *label27;

  mod = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (mod, 784, 720);
  gtk_window_set_title (GTK_WINDOW (mod), _("Modifier un capteur"));
  gtk_window_set_position (GTK_WINDOW (mod), GTK_WIN_POS_CENTER);
  gtk_window_set_resizable (GTK_WINDOW (mod), FALSE);

  fixed2 = gtk_fixed_new ();
  gtk_widget_show (fixed2);
  gtk_container_add (GTK_CONTAINER (mod), fixed2);

  mod1 = gtk_entry_new ();
  gtk_widget_show (mod1);
  gtk_fixed_put (GTK_FIXED (fixed2), mod1, 312, 48);
  gtk_widget_set_size_request (mod1, 144, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (mod1), 8226);

  label4 = gtk_label_new (_("ID :"));
  gtk_widget_show (label4);
  gtk_fixed_put (GTK_FIXED (fixed2), label4, 208, 56);
  gtk_widget_set_size_request (label4, 40, 16);

  label7 = gtk_label_new (_("Type :"));
  gtk_widget_show (label7);
  gtk_fixed_put (GTK_FIXED (fixed2), label7, 56, 232);
  gtk_widget_set_size_request (label7, 80, 24);

  mod3 = gtk_entry_new ();
  gtk_widget_show (mod3);
  gtk_fixed_put (GTK_FIXED (fixed2), mod3, 184, 312);
  gtk_widget_set_size_request (mod3, 168, 40);
  gtk_entry_set_invisible_char (GTK_ENTRY (mod3), 8226);

  button_mod = gtk_button_new ();
  gtk_widget_show (button_mod);
  gtk_fixed_put (GTK_FIXED (fixed2), button_mod, 336, 520);
  gtk_widget_set_size_request (button_mod, 120, 48);

  alignment1 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (button_mod), alignment1);

  hbox1 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox1);
  gtk_container_add (GTK_CONTAINER (alignment1), hbox1);

  image1 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image1);
  gtk_box_pack_start (GTK_BOX (hbox1), image1, FALSE, FALSE, 0);

  label5 = gtk_label_new_with_mnemonic (_("Valider"));
  gtk_widget_show (label5);
  gtk_box_pack_start (GTK_BOX (hbox1), label5, FALSE, FALSE, 0);

  check_id = gtk_button_new ();
  gtk_widget_show (check_id);
  gtk_fixed_put (GTK_FIXED (fixed2), check_id, 568, 40);
  gtk_widget_set_size_request (check_id, 104, 48);

  alignment2 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment2);
  gtk_container_add (GTK_CONTAINER (check_id), alignment2);

  hbox2 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox2);
  gtk_container_add (GTK_CONTAINER (alignment2), hbox2);

  image2 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image2);
  gtk_box_pack_start (GTK_BOX (hbox2), image2, FALSE, FALSE, 0);

  label6 = gtk_label_new_with_mnemonic (_("V\303\251rifier"));
  gtk_widget_show (label6);
  gtk_box_pack_start (GTK_BOX (hbox2), label6, FALSE, FALSE, 0);

  mod2 = gtk_combo_box_new_text ();
  gtk_widget_show (mod2);
  gtk_fixed_put (GTK_FIXED (fixed2), mod2, 184, 224);
  gtk_widget_set_size_request (mod2, 168, 40);
  gtk_combo_box_append_text (GTK_COMBO_BOX (mod2), _("Temp\303\251rature"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (mod2), _("D\303\251bit d'eau"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (mod2), _("Mouvement"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (mod2), _("Fum\303\251e"));

  mod4_adj = gtk_adjustment_new (1, 0, 1000, 1, 10, 10);
  mod4 = gtk_spin_button_new (GTK_ADJUSTMENT (mod4_adj), 1, 0);
  gtk_widget_show (mod4);
  gtk_fixed_put (GTK_FIXED (fixed2), mod4, 184, 408);
  gtk_widget_set_size_request (mod4, 60, 27);

  label8 = gtk_label_new (_("Marque :"));
  gtk_widget_show (label8);
  gtk_fixed_put (GTK_FIXED (fixed2), label8, 56, 320);
  gtk_widget_set_size_request (label8, 64, 16);

  label27 = gtk_label_new (_("Quantit\303\251 :"));
  gtk_widget_show (label27);
  gtk_fixed_put (GTK_FIXED (fixed2), label27, 48, 408);
  gtk_widget_set_size_request (label27, 80, 24);

  g_signal_connect ((gpointer) button_mod, "clicked",
                    G_CALLBACK (on_button_mod_clicked),
                    NULL);
  g_signal_connect ((gpointer) check_id, "clicked",
                    G_CALLBACK (on_check_id_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (mod, mod, "mod");
  GLADE_HOOKUP_OBJECT (mod, fixed2, "fixed2");
  GLADE_HOOKUP_OBJECT (mod, mod1, "mod1");
  GLADE_HOOKUP_OBJECT (mod, label4, "label4");
  GLADE_HOOKUP_OBJECT (mod, label7, "label7");
  GLADE_HOOKUP_OBJECT (mod, mod3, "mod3");
  GLADE_HOOKUP_OBJECT (mod, button_mod, "button_mod");
  GLADE_HOOKUP_OBJECT (mod, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (mod, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (mod, image1, "image1");
  GLADE_HOOKUP_OBJECT (mod, label5, "label5");
  GLADE_HOOKUP_OBJECT (mod, check_id, "check_id");
  GLADE_HOOKUP_OBJECT (mod, alignment2, "alignment2");
  GLADE_HOOKUP_OBJECT (mod, hbox2, "hbox2");
  GLADE_HOOKUP_OBJECT (mod, image2, "image2");
  GLADE_HOOKUP_OBJECT (mod, label6, "label6");
  GLADE_HOOKUP_OBJECT (mod, mod2, "mod2");
  GLADE_HOOKUP_OBJECT (mod, mod4, "mod4");
  GLADE_HOOKUP_OBJECT (mod, label8, "label8");
  GLADE_HOOKUP_OBJECT (mod, label27, "label27");

  return mod;
}

GtkWidget*
create_af (void)
{
  GtkWidget *af;
  GtkWidget *fixed3;
  GtkWidget *scrolledwindow1;
  GtkWidget *alignment4;
  GtkWidget *treeview;
  GtkWidget *button_af;
  GtkWidget *alignment5;
  GtkWidget *hbox3;
  GtkWidget *image3;
  GtkWidget *label11;
  GtkWidget *label10;

  af = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (af, 824, 600);
  gtk_window_set_title (GTK_WINDOW (af), _("Liste des capteurs"));
  gtk_window_set_position (GTK_WINDOW (af), GTK_WIN_POS_CENTER);
  gtk_window_set_resizable (GTK_WINDOW (af), FALSE);

  fixed3 = gtk_fixed_new ();
  gtk_widget_show (fixed3);
  gtk_container_add (GTK_CONTAINER (af), fixed3);

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow1);
  gtk_fixed_put (GTK_FIXED (fixed3), scrolledwindow1, 56, 104);
  gtk_widget_set_size_request (scrolledwindow1, 744, 368);

  alignment4 = gtk_alignment_new (0.5, 0.5, 1, 1);
  gtk_widget_show (alignment4);
  gtk_container_add (GTK_CONTAINER (scrolledwindow1), alignment4);

  treeview = gtk_tree_view_new ();
  gtk_widget_show (treeview);
  gtk_container_add (GTK_CONTAINER (alignment4), treeview);
  gtk_tree_view_set_rules_hint (GTK_TREE_VIEW (treeview), TRUE);
  gtk_tree_view_set_reorderable (GTK_TREE_VIEW (treeview), TRUE);

  button_af = gtk_button_new ();
  gtk_widget_show (button_af);
  gtk_fixed_put (GTK_FIXED (fixed3), button_af, 360, 504);
  gtk_widget_set_size_request (button_af, 112, 48);

  alignment5 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment5);
  gtk_container_add (GTK_CONTAINER (button_af), alignment5);

  hbox3 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox3);
  gtk_container_add (GTK_CONTAINER (alignment5), hbox3);

  image3 = gtk_image_new_from_stock ("gtk-refresh", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image3);
  gtk_box_pack_start (GTK_BOX (hbox3), image3, FALSE, FALSE, 0);

  label11 = gtk_label_new_with_mnemonic (_("Afficher"));
  gtk_widget_show (label11);
  gtk_box_pack_start (GTK_BOX (hbox3), label11, FALSE, FALSE, 0);

  label10 = gtk_label_new (_("Liste des capteurs"));
  gtk_widget_show (label10);
  gtk_fixed_put (GTK_FIXED (fixed3), label10, 280, 16);
  gtk_widget_set_size_request (label10, 280, 56);

  g_signal_connect ((gpointer) treeview, "row_activated",
                    G_CALLBACK (on_treeview_row_activated),
                    NULL);
  g_signal_connect ((gpointer) button_af, "clicked",
                    G_CALLBACK (on_button_af_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (af, af, "af");
  GLADE_HOOKUP_OBJECT (af, fixed3, "fixed3");
  GLADE_HOOKUP_OBJECT (af, scrolledwindow1, "scrolledwindow1");
  GLADE_HOOKUP_OBJECT (af, alignment4, "alignment4");
  GLADE_HOOKUP_OBJECT (af, treeview, "treeview");
  GLADE_HOOKUP_OBJECT (af, button_af, "button_af");
  GLADE_HOOKUP_OBJECT (af, alignment5, "alignment5");
  GLADE_HOOKUP_OBJECT (af, hbox3, "hbox3");
  GLADE_HOOKUP_OBJECT (af, image3, "image3");
  GLADE_HOOKUP_OBJECT (af, label11, "label11");
  GLADE_HOOKUP_OBJECT (af, label10, "label10");

  return af;
}

GtkWidget*
create_aj (void)
{
  GtkWidget *aj;
  GtkWidget *fixed4;
  GtkWidget *ajc;
  GtkWidget *aj3;
  GtkWidget *aj1;
  GtkWidget *label13;
  GtkWidget *button_aj;
  GtkWidget *alignment6;
  GtkWidget *hbox4;
  GtkWidget *image4;
  GtkWidget *label12;
  GtkWidget *aeg;
  GtkWidget *aj2;
  GtkWidget *label16;
  GtkWidget *label14;
  GtkObject *aj4_adj;
  GtkWidget *aj4;
  GtkWidget *label26;

  aj = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (aj, 784, 750);
  gtk_window_set_title (GTK_WINDOW (aj), _("Ajouter un capteur"));
  gtk_window_set_position (GTK_WINDOW (aj), GTK_WIN_POS_CENTER);
  gtk_window_set_resizable (GTK_WINDOW (aj), FALSE);

  fixed4 = gtk_fixed_new ();
  gtk_widget_show (fixed4);
  gtk_container_add (GTK_CONTAINER (aj), fixed4);

  ajc = gtk_calendar_new ();
  gtk_widget_show (ajc);
  gtk_fixed_put (GTK_FIXED (fixed4), ajc, 184, 336);
  gtk_widget_set_size_request (ajc, 216, 184);
  gtk_calendar_display_options (GTK_CALENDAR (ajc),
                                GTK_CALENDAR_SHOW_HEADING
                                | GTK_CALENDAR_SHOW_DAY_NAMES);

  aj3 = gtk_entry_new ();
  gtk_widget_show (aj3);
  gtk_fixed_put (GTK_FIXED (fixed4), aj3, 176, 176);
  gtk_widget_set_size_request (aj3, 168, 40);
  gtk_entry_set_invisible_char (GTK_ENTRY (aj3), 8226);

  aj1 = gtk_entry_new ();
  gtk_widget_show (aj1);
  gtk_fixed_put (GTK_FIXED (fixed4), aj1, 176, 40);
  gtk_widget_set_size_request (aj1, 144, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (aj1), 8226);

  label13 = gtk_label_new (_("ID :"));
  gtk_widget_show (label13);
  gtk_fixed_put (GTK_FIXED (fixed4), label13, 72, 48);
  gtk_widget_set_size_request (label13, 40, 16);

  button_aj = gtk_button_new ();
  gtk_widget_show (button_aj);
  gtk_fixed_put (GTK_FIXED (fixed4), button_aj, 312, 568);
  gtk_widget_set_size_request (button_aj, 120, 48);

  alignment6 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment6);
  gtk_container_add (GTK_CONTAINER (button_aj), alignment6);

  hbox4 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox4);
  gtk_container_add (GTK_CONTAINER (alignment6), hbox4);

  image4 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image4);
  gtk_box_pack_start (GTK_BOX (hbox4), image4, FALSE, FALSE, 0);

  label12 = gtk_label_new_with_mnemonic (_("Valider"));
  gtk_widget_show (label12);
  gtk_box_pack_start (GTK_BOX (hbox4), label12, FALSE, FALSE, 0);

  aeg = gtk_label_new (_("Type :"));
  gtk_widget_show (aeg);
  gtk_fixed_put (GTK_FIXED (fixed4), aeg, 32, 104);
  gtk_widget_set_size_request (aeg, 112, 24);

  aj2 = gtk_combo_box_new_text ();
  gtk_widget_show (aj2);
  gtk_fixed_put (GTK_FIXED (fixed4), aj2, 176, 104);
  gtk_widget_set_size_request (aj2, 168, 40);
  gtk_combo_box_append_text (GTK_COMBO_BOX (aj2), _("Temp\303\251rature"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (aj2), _("D\303\251bit d'eau"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (aj2), _("Mouvement"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (aj2), _("Fum\303\251e"));

  label16 = gtk_label_new (_("Date d'achat :"));
  gtk_widget_show (label16);
  gtk_fixed_put (GTK_FIXED (fixed4), label16, 8, 336);
  gtk_widget_set_size_request (label16, 152, 32);

  label14 = gtk_label_new (_("Marque :"));
  gtk_widget_show (label14);
  gtk_fixed_put (GTK_FIXED (fixed4), label14, 48, 184);
  gtk_widget_set_size_request (label14, 80, 24);

  aj4_adj = gtk_adjustment_new (1, 0, 1000, 1, 10, 10);
  aj4 = gtk_spin_button_new (GTK_ADJUSTMENT (aj4_adj), 1, 0);
  gtk_widget_show (aj4);
  gtk_fixed_put (GTK_FIXED (fixed4), aj4, 184, 264);
  gtk_widget_set_size_request (aj4, 60, 27);

  label26 = gtk_label_new (_("Quantit\303\251 :"));
  gtk_widget_show (label26);
  gtk_fixed_put (GTK_FIXED (fixed4), label26, 48, 264);
  gtk_widget_set_size_request (label26, 80, 24);

  g_signal_connect ((gpointer) button_aj, "clicked",
                    G_CALLBACK (on_button_aj_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (aj, aj, "aj");
  GLADE_HOOKUP_OBJECT (aj, fixed4, "fixed4");
  GLADE_HOOKUP_OBJECT (aj, ajc, "ajc");
  GLADE_HOOKUP_OBJECT (aj, aj3, "aj3");
  GLADE_HOOKUP_OBJECT (aj, aj1, "aj1");
  GLADE_HOOKUP_OBJECT (aj, label13, "label13");
  GLADE_HOOKUP_OBJECT (aj, button_aj, "button_aj");
  GLADE_HOOKUP_OBJECT (aj, alignment6, "alignment6");
  GLADE_HOOKUP_OBJECT (aj, hbox4, "hbox4");
  GLADE_HOOKUP_OBJECT (aj, image4, "image4");
  GLADE_HOOKUP_OBJECT (aj, label12, "label12");
  GLADE_HOOKUP_OBJECT (aj, aeg, "aeg");
  GLADE_HOOKUP_OBJECT (aj, aj2, "aj2");
  GLADE_HOOKUP_OBJECT (aj, label16, "label16");
  GLADE_HOOKUP_OBJECT (aj, label14, "label14");
  GLADE_HOOKUP_OBJECT (aj, aj4, "aj4");
  GLADE_HOOKUP_OBJECT (aj, label26, "label26");

  return aj;
}

GtkWidget*
create_aj_mesure (void)
{
  GtkWidget *aj_mesure;
  GtkWidget *fixed5;
  GtkWidget *ajmc;
  GtkWidget *label20;
  GtkWidget *button_ajm;
  GtkWidget *alignment7;
  GtkWidget *hbox5;
  GtkWidget *image5;
  GtkWidget *label18;
  GtkWidget *ajm5;
  GtkWidget *label22;
  GtkWidget *label21;
  GtkWidget *label23;
  GtkWidget *label17;
  GtkWidget *label19;
  GtkWidget *ajm3;
  GtkWidget *ajm2;
  GtkWidget *ajm1;
  GtkWidget *ajm4;

  aj_mesure = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (aj_mesure, 784, 750);
  gtk_window_set_title (GTK_WINDOW (aj_mesure), _("Ajouter une mesure"));
  gtk_window_set_position (GTK_WINDOW (aj_mesure), GTK_WIN_POS_CENTER);
  gtk_window_set_resizable (GTK_WINDOW (aj_mesure), FALSE);

  fixed5 = gtk_fixed_new ();
  gtk_widget_show (fixed5);
  gtk_container_add (GTK_CONTAINER (aj_mesure), fixed5);

  ajmc = gtk_calendar_new ();
  gtk_widget_show (ajmc);
  gtk_fixed_put (GTK_FIXED (fixed5), ajmc, 176, 440);
  gtk_widget_set_size_request (ajmc, 216, 184);
  gtk_calendar_display_options (GTK_CALENDAR (ajmc),
                                GTK_CALENDAR_SHOW_HEADING
                                | GTK_CALENDAR_SHOW_DAY_NAMES);

  label20 = gtk_label_new (_("Marque :"));
  gtk_widget_show (label20);
  gtk_fixed_put (GTK_FIXED (fixed5), label20, 48, 184);
  gtk_widget_set_size_request (label20, 80, 24);

  button_ajm = gtk_button_new ();
  gtk_widget_show (button_ajm);
  gtk_fixed_put (GTK_FIXED (fixed5), button_ajm, 352, 672);
  gtk_widget_set_size_request (button_ajm, 120, 48);

  alignment7 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment7);
  gtk_container_add (GTK_CONTAINER (button_ajm), alignment7);

  hbox5 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox5);
  gtk_container_add (GTK_CONTAINER (alignment7), hbox5);

  image5 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image5);
  gtk_box_pack_start (GTK_BOX (hbox5), image5, FALSE, FALSE, 0);

  label18 = gtk_label_new_with_mnemonic (_("Valider"));
  gtk_widget_show (label18);
  gtk_box_pack_start (GTK_BOX (hbox5), label18, FALSE, FALSE, 0);

  ajm5 = gtk_entry_new ();
  gtk_widget_show (ajm5);
  gtk_fixed_put (GTK_FIXED (fixed5), ajm5, 176, 352);
  gtk_widget_set_size_request (ajm5, 168, 40);
  gtk_entry_set_invisible_char (GTK_ENTRY (ajm5), 8226);

  label22 = gtk_label_new (_("Etage :"));
  gtk_widget_show (label22);
  gtk_fixed_put (GTK_FIXED (fixed5), label22, 48, 272);
  gtk_widget_set_size_request (label22, 80, 24);

  label21 = gtk_label_new (_("Date :"));
  gtk_widget_show (label21);
  gtk_fixed_put (GTK_FIXED (fixed5), label21, 16, 440);
  gtk_widget_set_size_request (label21, 152, 32);

  label23 = gtk_label_new (_("Valeur :"));
  gtk_widget_show (label23);
  gtk_fixed_put (GTK_FIXED (fixed5), label23, 48, 352);
  gtk_widget_set_size_request (label23, 80, 24);

  label17 = gtk_label_new (_("ID :"));
  gtk_widget_show (label17);
  gtk_fixed_put (GTK_FIXED (fixed5), label17, 64, 120);
  gtk_widget_set_size_request (label17, 40, 16);

  label19 = gtk_label_new (_("Type :"));
  gtk_widget_show (label19);
  gtk_fixed_put (GTK_FIXED (fixed5), label19, 24, 48);
  gtk_widget_set_size_request (label19, 112, 24);

  ajm3 = gtk_label_new ("");
  gtk_widget_show (ajm3);
  gtk_fixed_put (GTK_FIXED (fixed5), ajm3, 184, 184);
  gtk_widget_set_size_request (ajm3, 144, 32);

  ajm2 = gtk_combo_box_new_text ();
  gtk_widget_show (ajm2);
  gtk_fixed_put (GTK_FIXED (fixed5), ajm2, 176, 112);
  gtk_widget_set_size_request (ajm2, 168, 40);

  ajm1 = gtk_combo_box_new_text ();
  gtk_widget_show (ajm1);
  gtk_fixed_put (GTK_FIXED (fixed5), ajm1, 176, 40);
  gtk_widget_set_size_request (ajm1, 168, 40);
  gtk_combo_box_append_text (GTK_COMBO_BOX (ajm1), _("Temp\303\251rature"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (ajm1), _("D\303\251bit d'eau"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (ajm1), _("Mouvement"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (ajm1), _("Fum\303\251e"));

  ajm4 = gtk_entry_new ();
  gtk_widget_show (ajm4);
  gtk_fixed_put (GTK_FIXED (fixed5), ajm4, 176, 264);
  gtk_widget_set_size_request (ajm4, 168, 40);
  gtk_entry_set_invisible_char (GTK_ENTRY (ajm4), 8226);

  g_signal_connect ((gpointer) button_ajm, "clicked",
                    G_CALLBACK (on_button_ajm_clicked),
                    NULL);
  g_signal_connect ((gpointer) ajm2, "changed",
                    G_CALLBACK (on_ajm2_changed),
                    NULL);
  g_signal_connect ((gpointer) ajm1, "changed",
                    G_CALLBACK (on_ajm1_changed),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (aj_mesure, aj_mesure, "aj_mesure");
  GLADE_HOOKUP_OBJECT (aj_mesure, fixed5, "fixed5");
  GLADE_HOOKUP_OBJECT (aj_mesure, ajmc, "ajmc");
  GLADE_HOOKUP_OBJECT (aj_mesure, label20, "label20");
  GLADE_HOOKUP_OBJECT (aj_mesure, button_ajm, "button_ajm");
  GLADE_HOOKUP_OBJECT (aj_mesure, alignment7, "alignment7");
  GLADE_HOOKUP_OBJECT (aj_mesure, hbox5, "hbox5");
  GLADE_HOOKUP_OBJECT (aj_mesure, image5, "image5");
  GLADE_HOOKUP_OBJECT (aj_mesure, label18, "label18");
  GLADE_HOOKUP_OBJECT (aj_mesure, ajm5, "ajm5");
  GLADE_HOOKUP_OBJECT (aj_mesure, label22, "label22");
  GLADE_HOOKUP_OBJECT (aj_mesure, label21, "label21");
  GLADE_HOOKUP_OBJECT (aj_mesure, label23, "label23");
  GLADE_HOOKUP_OBJECT (aj_mesure, label17, "label17");
  GLADE_HOOKUP_OBJECT (aj_mesure, label19, "label19");
  GLADE_HOOKUP_OBJECT (aj_mesure, ajm3, "ajm3");
  GLADE_HOOKUP_OBJECT (aj_mesure, ajm2, "ajm2");
  GLADE_HOOKUP_OBJECT (aj_mesure, ajm1, "ajm1");
  GLADE_HOOKUP_OBJECT (aj_mesure, ajm4, "ajm4");

  return aj_mesure;
}

GtkWidget*
create_def (void)
{
  GtkWidget *def;
  GtkWidget *fixed6;
  GtkWidget *scrolledwindow2;
  GtkWidget *alignment8;
  GtkWidget *treeview_def;
  GtkWidget *label25;
  GtkWidget *button_def;
  GtkWidget *alignment9;
  GtkWidget *hbox6;
  GtkWidget *image6;
  GtkWidget *label24;

  def = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (def, 824, 600);
  gtk_window_set_title (GTK_WINDOW (def), _("Mesures hors norme"));
  gtk_window_set_position (GTK_WINDOW (def), GTK_WIN_POS_CENTER);
  gtk_window_set_resizable (GTK_WINDOW (def), FALSE);

  fixed6 = gtk_fixed_new ();
  gtk_widget_show (fixed6);
  gtk_container_add (GTK_CONTAINER (def), fixed6);

  scrolledwindow2 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow2);
  gtk_fixed_put (GTK_FIXED (fixed6), scrolledwindow2, 56, 104);
  gtk_widget_set_size_request (scrolledwindow2, 744, 368);

  alignment8 = gtk_alignment_new (0.5, 0.5, 1, 1);
  gtk_widget_show (alignment8);
  gtk_container_add (GTK_CONTAINER (scrolledwindow2), alignment8);

  treeview_def = gtk_tree_view_new ();
  gtk_widget_show (treeview_def);
  gtk_container_add (GTK_CONTAINER (alignment8), treeview_def);
  gtk_tree_view_set_rules_hint (GTK_TREE_VIEW (treeview_def), TRUE);
  gtk_tree_view_set_reorderable (GTK_TREE_VIEW (treeview_def), TRUE);

  label25 = gtk_label_new (_("Liste des capteurs d\303\251fectueux"));
  gtk_widget_show (label25);
  gtk_fixed_put (GTK_FIXED (fixed6), label25, 280, 16);
  gtk_widget_set_size_request (label25, 280, 56);

  button_def = gtk_button_new ();
  gtk_widget_show (button_def);
  gtk_fixed_put (GTK_FIXED (fixed6), button_def, 360, 504);
  gtk_widget_set_size_request (button_def, 112, 48);

  alignment9 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment9);
  gtk_container_add (GTK_CONTAINER (button_def), alignment9);

  hbox6 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox6);
  gtk_container_add (GTK_CONTAINER (alignment9), hbox6);

  image6 = gtk_image_new_from_stock ("gtk-refresh", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image6);
  gtk_box_pack_start (GTK_BOX (hbox6), image6, FALSE, FALSE, 0);

  label24 = gtk_label_new_with_mnemonic (_("Afficher"));
  gtk_widget_show (label24);
  gtk_box_pack_start (GTK_BOX (hbox6), label24, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) button_def, "clicked",
                    G_CALLBACK (on_button_def_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (def, def, "def");
  GLADE_HOOKUP_OBJECT (def, fixed6, "fixed6");
  GLADE_HOOKUP_OBJECT (def, scrolledwindow2, "scrolledwindow2");
  GLADE_HOOKUP_OBJECT (def, alignment8, "alignment8");
  GLADE_HOOKUP_OBJECT (def, treeview_def, "treeview_def");
  GLADE_HOOKUP_OBJECT (def, label25, "label25");
  GLADE_HOOKUP_OBJECT (def, button_def, "button_def");
  GLADE_HOOKUP_OBJECT (def, alignment9, "alignment9");
  GLADE_HOOKUP_OBJECT (def, hbox6, "hbox6");
  GLADE_HOOKUP_OBJECT (def, image6, "image6");
  GLADE_HOOKUP_OBJECT (def, label24, "label24");

  return def;
}

