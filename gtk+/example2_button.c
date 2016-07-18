#include <gtk/gtk.h>

static void button_add(GtkApplication *app,gpointer data)
{
    GtkWidget *window;
    GtkWidget *button1;
    GtkWidget *grid;


    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window),"Grid");
    gtk_container_set_border_width(GTK_CONTAINER(window),10);

    grid = gtk_grid_new();
    //把grid空间添加到window中
    gtk_container_add(GTK_CONTAINER(window),grid);

    button1 = gtk_button_new_with_label("Button 1");
    gtk_grid_attach(GTK_GRID(grid),button1,0,0,1,1);

    button1 = gtk_button_new_with_label("Button 2");
    gtk_grid_attach(GTK_GRID(grid),button1,1,0,1,1);

    button1 = gtk_button_new_with_label("Quit");
    g_signal_connect_swapped(button1,"clicked",G_CALLBACK(gtk_widget_destroy),window);
    gtk_grid_attach(GTK_GRID(grid),button1,0,1,2,1);

    gtk_widget_show_all(window);
}
int main(int argc,char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.duanzw.gtk.button",G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app,"activate",G_CALLBACK(button_add),NULL);
    status = g_application_run(G_APPLICATION(app),argc,argv);
    g_object_unref(app);

    return status;
}
