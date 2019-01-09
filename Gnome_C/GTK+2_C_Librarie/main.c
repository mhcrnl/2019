#include <stdlib.h>
#include <gtk/gtk.h>
/* ----------------------------------------------------------------------------------------------------------------
 *  Create the widgets
 *
 *-----------------------------------------------------------------------------------------------------------------*/
GtkWidget *vbox = NULL;

GtkWidget *hbox_titlu = NULL;
GtkWidget *lb_titlu = NULL;
GtkWidget *en_titlu = NULL;
GtkWidget *bt_adauga = NULL;

GtkWidget *hbox_autor = NULL;
GtkWidget *lb_autor = NULL;
GtkWidget *en_autor = NULL;
GtkWidget *bt_cauta = NULL;

static void helloWorld (GtkWidget *wid, GtkWidget *win)
{
  GtkWidget *dialog = NULL;

  dialog = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Hello World!");
  gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);
}

int main (int argc, char *argv[])
{
  GtkWidget *button = NULL;
  GtkWidget *win = NULL;
  //GtkWidget *vbox = NULL;

  /* Initialize GTK+ */
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
  gtk_init (&argc, &argv);
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);

  /* Create the main window */
  win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width (GTK_CONTAINER (win), 8);
  gtk_window_set_title (GTK_WINDOW (win), "Hello World");
  gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
  gtk_widget_realize (win);
  g_signal_connect (win, "destroy", gtk_main_quit, NULL);

  /* Create a vertical box with buttons */
  vbox = gtk_vbox_new (TRUE, 6);
  hbox_titlu = gtk_hbox_new(TRUE, 6);
  /* ----------------------------------------------------hbox_titlu widgets
  */
  gtk_container_add(vbox, hbox_titlu);
  lb_titlu = gtk_label_new("Titlu");
  gtk_container_add(GTK_CONTAINER(hbox_titlu), lb_titlu);
  en_titlu = gtk_entry_new();
  gtk_container_add(GTK_CONTAINER(hbox_titlu), en_titlu);
  bt_adauga = gtk_button_new_with_label("Adauga");
  gtk_container_add(GTK_CONTAINER(hbox_titlu), bt_adauga);
  /* -----------------------------------------------------hbox_autor widgets
  */
  hbox_autor = gtk_hbox_new(TRUE, 6);
  gtk_container_add(vbox, hbox_autor);
  lb_autor = gtk_label_new("Autor");
  gtk_container_add(hbox_autor, lb_autor);
  en_autor = gtk_entry_new();
  gtk_container_add(hbox_autor, en_autor);
  bt_cauta = gtk_button_new_with_label("Cauta");
  gtk_container_add(hbox_autor, bt_cauta);

  gtk_container_add (GTK_CONTAINER (win), vbox);

  button = gtk_button_new_from_stock (GTK_STOCK_DIALOG_INFO);
  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (helloWorld), (gpointer) win);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

  button = gtk_button_new_from_stock (GTK_STOCK_CLOSE);
  g_signal_connect (button, "clicked", gtk_main_quit, NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

  /* Enter the main loop */
  gtk_widget_show_all (win);
  gtk_main ();
  return 0;
}
