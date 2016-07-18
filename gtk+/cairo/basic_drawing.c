#include <gtk/gtk.h>
#include <math.h>
/**
 * gtk+3 基本图元
 * 画基本的线用fill或者stroke操作
 */

static void do_drawinglines(cairo_t *cr);
static void do_drawingCycle(cairo_t *cr,GtkWidget *widget);
static void do_drawingPendash(cairo_t *cr);
static void do_drawingCaps(cairo_t *cr);
static void do_drawingJoins(cairo_t *cr);

struct
{
    int count;
    double coordx[100];
    double coordy[100];
}glob;



static gboolean lines_callback(GtkWidget *widget,cairo_t *cr,gpointer data)
{
    // g_print("lines_callback\n");
    do_drawinglines(cr);
    return FALSE;
}
static void do_drawinglines(cairo_t *cr)
{
    cairo_set_source_rgb(cr,1,0,0);
    cairo_set_line_width(cr,5);

    int i,j;

    // g_print("point count = %d   ",glob.count);
    // for(i = 0; i < glob.count; i++)
    // {
    //     for(j = 0; j < glob.count; j++)
    //     {
    //         cairo_move_to(cr,glob.coordx[i],glob.coordy[i]);
    //         cairo_line_to(cr,glob.coordx[j],glob.coordy[j]);
    //     }
    // }
    for(i = 1; i < glob.count; i++)
    {
        cairo_move_to(cr,glob.coordx[i-1],glob.coordy[i-1]);
        cairo_line_to(cr,glob.coordx[i],glob.coordy[i]);

    }

    // glob.count = 0;
    cairo_stroke(cr);
}

static gboolean clicked(GtkWidget *widget,GdkEventButton *event,gpointer data)
{
    // g_print("event->button = %d\n",event->button);
    if(event->button == 1)
    {
        //g_print("clicked(%.2f,%.2f)\n",event->x,event->y);
        glob.coordx[glob.count] = event->x;
        glob.coordy[glob.count++] = event->y;
    }

    gtk_widget_queue_draw(widget);

    return TRUE;
}

static gboolean cycle_callback(GtkWidget *widget,cairo_t *cr,gpointer data)
{
    do_drawingCycle(cr,widget);
    return FALSE;
}

static void do_drawingCycle(cairo_t *cr,GtkWidget *widget)
{
    gint width;
    gint height;
    gtk_widget_get_size_request(widget,&width,&height);
    //画圆
    //设置线宽
    cairo_set_line_width(cr,9);
    //设置颜色
    cairo_set_source_rgb(cr,0.69,0.19,0);

    //指定圆心
    // cairo_translate(cr,width/2,height/2);
    cairo_arc(cr,width/2-20,height/2-20,50,0,0.5 * M_PI);
    cairo_stroke_preserve(cr);

    //设置填充颜色
    cairo_set_source_rgb(cr,0.3,0.4,0.6);
    //填充
    cairo_fill(cr);
}

static gboolean pendash_callback(GtkWidget *widget,cairo_t *cr,gpointer data)
{
    //g_print("pendash_callback\n");
    do_drawingPendash(cr);

    return FALSE;
}
static void do_drawingPendash(cairo_t *cr)
{
    //g_print("do_drawingPendash\n");
    cairo_set_source_rgb(cr,0,0,1);
    cairo_set_line_width(cr,5);

    static const double dashed1[] = {4.0,21.0,2.0};
    static int len1 = sizeof(dashed1) / sizeof(dashed1[0]);

    static const double dashed2[] = {14.0,6.0};
    static int len2 = sizeof(dashed2) / sizeof(dashed2[0]);

    static const double dashed3[] = {1.0};



    cairo_set_dash(cr,dashed1,len1,0);

    cairo_move_to(cr,40,30);
    cairo_line_to(cr,300,30);
    cairo_stroke(cr);

    cairo_set_dash(cr,dashed2,len2,1);
    cairo_move_to(cr,40,50);
    cairo_line_to(cr,300,50);
    cairo_stroke(cr);

    cairo_set_dash(cr,dashed3,1,0);
    cairo_move_to(cr,40,70);
    cairo_line_to(cr,300,70);
    cairo_stroke(cr);

}

static gboolean caps_callback(GtkWidget *widget,cairo_t *cr,gpointer data)
{
    do_drawingCaps(cr);

    return FALSE;
}
static void do_drawingCaps(cairo_t *cr)
{
    g_print("do_drawingCaps\n");
    cairo_set_line_width(cr,10);

    cairo_set_line_cap(cr,CAIRO_LINE_CAP_BUTT);
    cairo_move_to(cr,30,50);
    cairo_line_to(cr,150,50);
    cairo_stroke(cr);

    cairo_set_line_cap(cr,CAIRO_LINE_CAP_ROUND);
    cairo_move_to(cr,30,70);
    cairo_line_to(cr,150,70);
    cairo_stroke(cr);

    cairo_set_line_cap(cr,CAIRO_LINE_CAP_SQUARE);
    cairo_move_to(cr,30,130);
    cairo_line_to(cr,150,130);
    cairo_stroke(cr);

    cairo_set_line_width(cr,1.5);
    cairo_move_to(cr,30,40);
    cairo_line_to(cr,30,140);
    cairo_stroke(cr);

    cairo_move_to(cr,150,40);
    cairo_line_to(cr,150,140);
    cairo_stroke(cr);

    cairo_move_to(cr,155,40);
    cairo_line_to(cr,155,140);
    cairo_stroke(cr);
}

static gboolean joins_callback(GtkWidget *widget,cairo_t *cr,gpointer data)
{
    do_drawingJoins(cr);

    return FALSE;
}
static void do_drawingJoins(cairo_t *cr)
{
    cairo_set_source_rgb(cr,0.1,0,0);
    cairo_set_line_width(cr,14);

    //斜切
    cairo_set_line_join(cr,CAIRO_LINE_JOIN_MITER);
    cairo_rectangle(cr,30,30,100,100);
    cairo_stroke(cr);

    //斜角
    cairo_set_line_join(cr,CAIRO_LINE_JOIN_BEVEL);
    cairo_rectangle(cr,160,30,100,100);
    cairo_stroke(cr);

    //圆角
    cairo_set_line_join(cr,CAIRO_LINE_JOIN_ROUND);
    cairo_rectangle(cr,300,30,100,100);
    cairo_stroke(cr);
}
int main(int argc,char **argv)
{

    //创建窗口
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *darea;

    glob.count = 0;

    gtk_init(&argc,&argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window),800,600);
    gtk_window_set_title(GTK_WINDOW(window),"Lines");
    g_signal_connect(window,"button-press-event",G_CALLBACK(clicked),NULL);
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);


    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window),grid);

    darea = gtk_drawing_area_new();
    gtk_widget_set_size_request(darea,400,200);
    g_signal_connect(G_OBJECT(darea),"draw",G_CALLBACK(lines_callback),NULL);
    // gtk_container_add(GTK_CONTAINER(window),darea);
    gtk_grid_attach(GTK_GRID(grid),darea,0,0,1,1);


    darea = gtk_drawing_area_new();
    gtk_widget_set_size_request(darea,400,200);
    g_signal_connect(G_OBJECT(darea),"draw",G_CALLBACK(cycle_callback),NULL);
    gtk_grid_attach(GTK_GRID(grid),darea,1,0,1,1);

    darea = gtk_drawing_area_new();
    gtk_widget_set_size_request(darea,400,200);
    g_signal_connect(G_OBJECT(darea),"draw",G_CALLBACK(pendash_callback),NULL);
    gtk_grid_attach(GTK_GRID(grid),darea,0,1,1,1);

    darea = gtk_drawing_area_new();
    gtk_widget_set_size_request(darea,400,200);
    g_signal_connect(G_OBJECT(darea),"draw",G_CALLBACK(caps_callback),NULL);
    gtk_grid_attach(GTK_GRID(grid),darea,1,1,1,1);

    darea = gtk_drawing_area_new();
    gtk_widget_set_size_request(darea,400,200);
    g_signal_connect(G_OBJECT(darea),"draw",G_CALLBACK(joins_callback),NULL);
    gtk_grid_attach(GTK_GRID(grid),darea,0,2,2,1);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
