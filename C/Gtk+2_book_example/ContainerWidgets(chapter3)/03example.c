#include <gtk/gtk.h>
/**
 *  Author : Mihai Cornel mhcrnl@gmail.com
 *  Aceasta este prima aplicatie Gtk+2 cu interfata grafica
 *  Compile : gcc -Wall -g 03example.c -o 03example `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0` 
 */
#define AGENDA 4
const gchar *nume[]  = {"Mihai Cornel 0722270796", "Alexandru 09389927492", "Vasile 23450500", "Radu 8308298592"};
/**
 *  FUNCTIONS:
 */
static void destroy(GtkWidget*, gpointer);
static gboolean delete_event(GtkWidget*, GdkEvent*, gpointer);

int main(int argc, char *argv[])
{
    gint i;
    GtkWidget *window;
    /**
     *  GtkContainer vbox
     */
    GtkWidget *vbox;
    GtkWidget *label;
    GtkWidget *bt_close;
    /** Initializare Gtk+ si toate librariile necesare aplicatiei */
    gtk_init(&argc, &argv);

    /**
     *  Crearea unei ferestre, adaugarea unui titlu si afisarea acesteia.
     */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Salut din GTK+2");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 300, -1);
    /**
     *  Conectarea ferestrei la evenimentele destroy si delete_event.
     */
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);
    /**
     *  Crearea vbox
     */
    vbox = gtk_vbox_new(TRUE, 5);
    /**
     *  Adaugarea butoanelor in vbox
    */
    for(i=0; i<AGENDA; i++){
        GtkWidget *bt_close = gtk_button_new_with_label(nume[i]);
        gtk_box_pack_start_defaults(GTK_BOX(vbox), bt_close);

        g_signal_connect_swapped(G_OBJECT(bt_close), "clicked", G_CALLBACK(gtk_widget_destroy), (gpointer) bt_close);
    }
    /**
     *  Crearea unei GtkLabel selectabile
     */
    label = gtk_label_new("Salut!");
    gtk_label_set_selectable(GTK_LABEL(label), TRUE);
    /**
     *  Crearea unui button si adaugarea unui semnal
     */
    bt_close = gtk_button_new_with_mnemonic("_Close");
    gtk_button_set_relief(GTK_BUTTON(bt_close), GTK_RELIEF_NONE);
    g_object_set(bt_close, "relief", GTK_RELIEF_NORMAL, NULL);
    /**
     *  Conectarea butonului la semnal
     */
    g_signal_connect_swapped(G_OBJECT(bt_close), "clicked", G_CALLBACK(gtk_widget_destroy), (gpointer) window);
    /**
     *  Adaugarea label in window
     */
    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}
/**
 *  Stop GTK+ main loop
 */
static void destroy(GtkWidget *window, gpointer data)
{
    gtk_main_quit();
}
/**
 *  Return FALSE pentru distrugerea widgetului. Returnarea TRUE poate anula evenimentul.
 */
static gboolean delete_event(GtkWidget *window, GdkEvent *event, gpointer data)
{
    return FALSE;
}

