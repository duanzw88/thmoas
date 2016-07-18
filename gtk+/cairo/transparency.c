#include <gtk/gtk.h>
#include <math.h>

static void do_drawingRect(cairo_t *cr);
static void do_drawingPuffEffect(cairo_t *cr,GtkWidget *widget);
static gboolean time_handle(GtkWidget *widget);
static void do_drawingWatting(GtkWidget *widget,cairo_t *cr);

struct{
    gboolean timer;
    gdouble alpha;
    gdouble size;
}glob;

struct{
    gushort count;
}wait_glob;

static gboolean rect_callback(GtkWidget *widget,cairo_t *cr,gpointer data)
{
    do_drawingRect(cr);
    return FALSE;
}
static gboolean puff_effect_callback(GtkWidget *widget,cairo_t *cr,gpointer data)
{
    do_drawingPuffEffect(cr,widget);
    return FALSE;
}
static gboolean waitting_callback(GtkWidget *widget,cairo_t *cr,gpointer data)
{
    do_drawingWatting(widget,cr);
    return FALSE;
}
static void do_drawingRect(cairo_t *cr)
{
    gint i;
    for(i = 1;i <= 10;i++)
    {
        cairo_set_source_rgba(cr,0,0,1,i*0.1);
        cairo_rectangle(cr,30*i,20,20,20);
        cairo_fill(cr);
    }
}
static void do_drawingPuffEffect(cairo_t *cr,GtkWidget *widget)
{
    cairo_text_extents_t extents;
    gint width;
    gint height;
    gtk_widget_get_size_request(widget,&width,&height);

    gint x = width / 2;
    gint y = height / 2;

    cairo_set_source_rgb(cr,0.5,0,0);
    cairo_paint(cr);

    cairo_select_font_face(cr,"Courier",CAIRO_FONT_SLANT_NORMAL,CAIRO_FONT_WEIGHT_BOLD);
    glob.size += 0.8;
    if(glob.size > 20)
    {
        glob.alpha -= 0.01;
    }
    g_print("size = %.2f alpha = %.2f\n",glob.size,glob.alpha);
    cairo_set_font_size(cr,glob.size);
    cairo_set_source_rgb(cr,1,1,0);

    cairo_text_extents(cr,"ZetCode",&extents);
    cairo_move_to(cr, x - extents.width/2, y);
    cairo_text_path(cr,"ZetCode");
    cairo_clip(cr);

    cairo_paint_with_alpha(cr,glob.alpha);
    if(glob.alpha <= 0)
    {
        glob.timer = FALSE;
    }
}
static gboolean time_handle(GtkWidget *widget)
{
    if(!glob.timer)
    {
        return FALSE;
    }

    gtk_widget_queue_draw(widget);

    return TRUE;
}
static void do_drawingWatting(GtkWidget *widget,cairo_t *cr)
{
    static gdouble const trs[8][8] = {
        { 0.0, 0.15, 0.30, 0.5, 0.65, 0.80, 0.9, 1.0 },
      { 1.0, 0.0,  0.15, 0.30, 0.5, 0.65, 0.8, 0.9 },
      { 0.9, 1.0,  0.0,  0.15, 0.3, 0.5, 0.65, 0.8 },
      { 0.8, 0.9,  1.0,  0.0,  0.15, 0.3, 0.5, 0.65},
      { 0.65, 0.8, 0.9,  1.0,  0.0,  0.15, 0.3, 0.5 },
      { 0.5, 0.65, 0.8, 0.9, 1.0,  0.0,  0.15, 0.3 },
      { 0.3, 0.5, 0.65, 0.8, 0.9, 1.0,  0.0,  0.15 },
      { 0.15, 0.3, 0.5, 0.65, 0.8, 0.9, 1.0,  0.0, }
    };

    gint width,height;
    gtk_widget_get_size_request(widget,&width,&height);

    cairo_translate(cr,width/2,height/2);
    gint i = 0;
    for(i = 0;i < 8;i++)
    {
        cairo_set_line_width(cr,3);
        cairo_set_line_cap(cr,CAIRO_LINE_CAP_ROUND);
        cairo_set_source_rgba(cr,0,0,0,trs[wait_glob.count % 8][i]);

        cairo_move_to(cr,0.0,-10.0);
        cairo_line_to(cr,0.0,-40.0);
        cairo_rotate(cr,M_PI/4);

        cairo_stroke(cr);
    }
}
int main(int argc,char **argv)
{
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *darea;

    glob.timer = TRUE;
    glob.alpha = 1.0;
    glob.size = 1.0;
    gtk_init(&argc,&argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window),600,600);
    gtk_window_set_title(GTK_WINDOW(window),"Transparency");
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window),grid);

    darea = gtk_drawing_area_new();
    gtk_widget_set_size_request(darea,600,300);
    g_signal_connect(G_OBJECT(darea),"draw",G_CALLBACK(rect_callback),NULL);
    gtk_grid_attach(GTK_GRID(grid),darea,0,0,2,1);

    darea = gtk_drawing_area_new();
    gtk_widget_set_size_request(darea,300,300);
    g_signal_connect(G_OBJECT(darea),"draw",G_CALLBACK(puff_effect_callback),NULL);
    g_timeout_add(14,(GSourceFunc)time_handle,(gpointer)darea);
    gtk_grid_attach(GTK_GRID(grid),darea,0,1,1,1);

    darea = gtk_drawing_area_new();
    gtk_widget_set_size_request(darea,300,300);
    g_signal_connect(G_OBJECT(darea),"draw",G_CALLBACK(waitting_callback),NULL);
    gtk_grid_attach(GTK_GRID(grid),darea,1,1,1,1);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
