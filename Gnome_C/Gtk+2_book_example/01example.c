#include <gtk/gtk.h>
/**
 *  Author : Mihai Cornel mhcrnl@gmail.com
 *  Aceasta este prima aplicatie Gtk+2 cu interfata grafica
 *  Compile : gcc -Wall -g 01example.c -o 01example `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0` 
 */
static void destroy(GtkWidget*, gpointer);
static gboolean delete_event(GtkWidget*, GdkEvent*, gpointer);

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *label;
    /** Initializare Gtk+ si toate librariile necesare aplicatiei */
    gtk_init(&argc, &argv);

    /**
     *  Crearea unei ferestre, adaugarea unui titlu si afisarea acesteia.
     */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Salut din GTK+2");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 200, 100);
    /**
     *  Conectarea ferestrei la evenimentele destroy si delete_event.
     */
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);
    /**
     *  Crearea unei GtkLabel selectabile
     */
    label = gtk_label_new("Salut!");
    gtk_label_set_selectable(GTK_LABEL(label), TRUE);
    /**
     *  Adaugarea label in window
     */
    gtk_container_add(GTK_CONTAINER(window), label);
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

