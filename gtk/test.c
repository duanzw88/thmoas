#include <gtk/gtk.h>

gint n = 1;
gint function();

int main (int argc,char **argv)
{
    GtkWindow *window;
    gint sign;
    gtk_init(&argc,&argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"窗口Demo");
    //设置窗口默认大小
    gtk_window_set_default_size(GTK_WINDOW(window),500,400);

    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_widget_show(window);

    // sign = g_timeout_add(500,function,NULL);


    gtk_main();
  return FALSE;
}

gint function()
{
    g_print("hello");
    if(++n > 5)
    {
        return 0;
    }

    return 1;
}
