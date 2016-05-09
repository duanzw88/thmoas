#include <stdio.h>
#include <gtk/gtk.h>

static void active(GtkApplication,gpointer user_data)
{
	GtkWidget *window;

	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window),"Window");
	gtk_window_set_default_size(GTK_WINDOW(window),200,200);
	gtk_window_show_all(window)
}
int main(int argc,char *argv[])
{
	GtkApplication *app;
	int status;

	app = gtk_application_new("宿舍管理系统",G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app,"active",G_CALLBACK(active),NULL);
	status = g_application_run(G_APPLICATION(app),argc,argv);

	g_object_unref(app);

	return status;
}
