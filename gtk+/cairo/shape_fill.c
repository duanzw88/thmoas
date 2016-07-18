#include <gtk/gtk.h>
#include <math.h>


static void do_drawing_basicshapes(cairo_t *cr);
static void do_drawing_othershapes(cairo_t *cr);
static void do_drawing_colours(cairo_t *cr);
static void do_drawing_patterns(cairo_t *cr);
static void create_surfaces();
static void destroy_surfaces();
int points[11][2] =
    {
        {0,85},
        {75,75},
        {100,10},
        {125,75},
        {200,85},
        {150,125},
        {160,190},
        {100,150},
        {40,190},
        {50,125},
        {0,85}
    };

cairo_surface_t *surface1;
cairo_surface_t *surface2;
cairo_surface_t *surface3;
cairo_surface_t *surface4;

static gboolean basicshapes_callback(GtkWidget *widget,cairo_t *cr,gpointer data)
{
    do_drawing_basicshapes(cr);
    return FALSE;
}
static gboolean othershapes_callback(GtkWidget *widget,cairo_t *cr,gpointer data)
{
    do_drawing_othershapes(cr);
    return FALSE;
}
static gboolean colours_callback(GtkWidget *widget,cairo_t *cr,gpointer data)
{
    do_drawing_colours(cr);
    return FALSE;
}
static gboolean patterns_callback(GtkWidget *widget,cairo_t *cr,gpointer data)
{
    do_drawing_patterns(cr);
    return FALSE;
}
static void do_drawing_basicshapes(cairo_t *cr)
{
    cairo_set_source_rgb(cr,0.6,0.6,0.6);
    cairo_set_line_width(cr,1.0);

    //矩形
    cairo_rectangle(cr,20,20,60,30);
    cairo_rectangle(cr,100,20,80,80);
    cairo_stroke_preserve(cr);
    cairo_fill(cr);

    //圆
    cairo_arc(cr,250,80,40,0,2*M_PI);
    cairo_stroke_preserve(cr);
    cairo_fill(cr);

    //半圆
    cairo_arc(cr,60,170,40,M_PI/4,M_PI);
    cairo_close_path(cr);
    cairo_stroke_preserve(cr);
    cairo_fill(cr);

    //椭圆
    cairo_translate(cr,180,200);
    cairo_scale(cr,1,0.7);
    cairo_arc(cr,0,0,50,0,2*M_PI);
    cairo_stroke_preserve(cr);
    cairo_fill(cr);
}
static void do_drawing_othershapes(cairo_t *cr)
{
    cairo_set_source_rgb(cr,1,0,0);
    cairo_set_line_width(cr,2);

    gint i;
    for(i = 0;i < 10;i++)
    {
        cairo_line_to(cr,points[i][0],points[i][1]);
    }
    cairo_close_path(cr);
    cairo_stroke_preserve(cr);
    cairo_fill(cr);

    cairo_move_to(cr,220,20);
    cairo_line_to(cr,220,60);
    cairo_line_to(cr,280,60);
    cairo_close_path(cr);
    cairo_stroke_preserve(cr);
    cairo_fill(cr);


    cairo_move_to(cr,220,80);
    cairo_line_to(cr,220,120);
    cairo_line_to(cr,280,120);
    cairo_curve_to(cr,280,120,230,100,220,80);
    cairo_close_path(cr);
    cairo_stroke_preserve(cr);
    cairo_fill(cr);

}
static void do_drawing_colours(cairo_t *cr)
{
    cairo_set_source_rgb(cr,0.5,0.5,1);
    cairo_rectangle(cr,20,20,100,100);
    cairo_fill(cr);

    cairo_set_source_rgb(cr,0.6,0.6,0.6);
    cairo_rectangle(cr,170,20,100,100);
    cairo_fill(cr);

    cairo_set_source_rgb(cr,0,0.3,0);
    cairo_rectangle(cr,20,170,100,100);
    cairo_fill(cr);

    cairo_set_source_rgb(cr,1,0,0.5);
    cairo_rectangle(cr,170,170,100,100);
    cairo_fill(cr);

}
static void do_drawing_patterns(cairo_t *cr)
{
    cairo_pattern_t *pattern1;
    cairo_pattern_t *pattern2;
    cairo_pattern_t *pattern3;
    cairo_pattern_t *pattern4;

    pattern1 = cairo_pattern_create_for_surface(surface1);
    pattern2 = cairo_pattern_create_for_surface(surface2);
    pattern3 = cairo_pattern_create_for_surface(surface3);
    pattern4 = cairo_pattern_create_for_surface(surface4);

    cairo_set_source(cr,pattern1);
    cairo_pattern_set_extend(cairo_get_source(cr),CAIRO_EXTEND_REPEAT);
    cairo_rectangle(cr,20,20,100,100);
    cairo_fill(cr);

    // cairo_set_source(cr,pattern2);
    // cairo_pattern_set_extend(cairo_get_source(cr),CAIRO_EXTEND_REPEAT);
    // cairo_rectangle(cr,150,20,100,100);
    // cairo_fill(cr);
    //
    // cairo_set_source(cr,pattern3);
    // cairo_pattern_set_extend(cairo_get_source(cr),CAIRO_EXTEND_REPEAT);
    // cairo_rectangle(cr,20,140,100,100);
    // cairo_fill(cr);
    //
    // cairo_set_source(cr,pattern4);
    // cairo_pattern_set_extend(cairo_get_source(cr),CAIRO_EXTEND_REPEAT);
    // cairo_rectangle(cr,150,140,100,100);
    // cairo_fill(cr);

    cairo_pattern_destroy(pattern1);
    cairo_pattern_destroy(pattern2);
    cairo_pattern_destroy(pattern3);
    cairo_pattern_destroy(pattern4);
}
static void create_surfaces()
{
    surface1 = cairo_image_surface_create_from_png("exampleapp.png");
    surface2 = cairo_image_surface_create_from_png("maple.png");
    surface3 = cairo_image_surface_create_from_png("crack.png");
    surface4 = cairo_image_surface_create_from_png("chocolate.png");
}
static void destroy_surfaces()
{
    cairo_surface_destroy(surface1);
    cairo_surface_destroy(surface2);
    cairo_surface_destroy(surface3);
    cairo_surface_destroy(surface4);
}

int main(int argc,char **argv)
{
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *darea;

    gtk_init(&argc,&argv);

    //创建窗口
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window),1200,300);
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);


    create_surfaces();

    //新建网格
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window),grid);

    darea = gtk_drawing_area_new();
    gtk_widget_set_size_request(darea,300,300);
    g_signal_connect(G_OBJECT(darea),"draw",G_CALLBACK(basicshapes_callback),NULL);
    gtk_grid_attach(GTK_GRID(grid),darea,0,0,1,1);

    darea = gtk_drawing_area_new();
    gtk_widget_set_size_request(darea,300,300);
    g_signal_connect(G_OBJECT(darea),"draw",G_CALLBACK(othershapes_callback),NULL);
    gtk_grid_attach(GTK_GRID(grid),darea,1,0,1,1);

    darea = gtk_drawing_area_new();
    gtk_widget_set_size_request(darea,300,300);
    g_signal_connect(G_OBJECT(darea),"draw",G_CALLBACK(colours_callback),NULL);
    gtk_grid_attach(GTK_GRID(grid),darea,2,0,1,1);

    darea = gtk_drawing_area_new();
    gtk_widget_set_size_request(darea,300,300);
    g_signal_connect(G_OBJECT(darea),"draw",G_CALLBACK(patterns_callback),NULL);
    gtk_grid_attach(GTK_GRID(grid),darea,3,0,1,1);

    gtk_widget_show_all(window);
    gtk_main();
    destroy_surfaces();
    return 0;
}
