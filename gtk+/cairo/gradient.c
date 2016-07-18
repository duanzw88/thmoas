#include <gtk/gtk.h>
#include <math.h>
/**
 * 渐变
 * 涉及到的函数
 * 下面两个函数主要是创建一个渐变模式，控制渐变方向
 * cairo_pattern_t *cairo_pattern_create_linear(double x0,double y0,double x1,double y1)
 * 			x0:开始点的坐标
 * 			y0:
 * 			x1:结束点的坐标
 * 			y1:
 * cairo_pattern_t *cairo_pattern_create_radial(double cx0,double cy0,double radius0,double cx1,double cy1,double radius1);
 * 		cx0:       放射渐变的开始点坐标
 * 		cy0:
 * 		radius0:   放射渐变的开始点的半径
 * 		cx1:       放射渐变结束点的坐标
 * 		cy1:
 * 		radius1:  放射渐变结束点的半径
 *
 * void cairo_pattern_add_color_stop_rgb(cairo_pattern_t *pat,double offset,double red,double green,double blue);
 * 		cairo_pattern_t: 一个cairo_t的模式
 * 		offset:    偏移量 该值是指在该偏移位置时达到饱和，该值是0.0-1.0 表示占总长度的比例
 * 		red:       红色的成分(0-1)
 * 		green:     绿色的成分(0-1)
 * 		blue:      蓝色的成分(0-1)
 *
 */
static void linear_gradient(cairo_t *cr);
static void radial_gradient(cairo_t *cr);

static gboolean linear_gradient_callback(GtkWidget *widget,cairo_t *cr,gpointer data)
{
    linear_gradient(cr);
    return FALSE;
}
static gboolean radial_gradient_callback(GtkWidget *widget,cairo_t *cr,gpointer data)
{
    radial_gradient(cr);
    return FALSE;
}
static void linear_gradient(cairo_t *cr)
{
    cairo_pattern_t *pat1;
    cairo_pattern_t *pat2;
    cairo_pattern_t *pat3;

    //第一条渐变带
    pat1 = cairo_pattern_create_linear(0.0,0.0,350,350);
    gdouble j;
    gint count = 1;
    for(j = 0.1; j < 1; j+=0.1)
    {
        if(count % 2 == 0)
        {
            cairo_pattern_add_color_stop_rgb(pat1,j,1,0,0);
        }
        else if(count % 3 == 0)
        {
            cairo_pattern_add_color_stop_rgb(pat1,j,0,1,0);
        }
        else
        {
            cairo_pattern_add_color_stop_rgb(pat1,j,0,0,1);
        }
        count++;
    }
    cairo_rectangle(cr,20,20,300,100);
    cairo_set_source(cr,pat1);
    cairo_fill(cr);
    cairo_pattern_destroy(pat1);

    //第二条渐变带
    count = 0;
    pat2 = cairo_pattern_create_linear(0.0,0.0,250.0,50.0);
    for(j = 0.05; j < 0.95; j+= 0.025)
    {
        if(count % 2)
        {
            cairo_pattern_add_color_stop_rgb(pat2,j,0,0,1);
        }
        else
        {
            cairo_pattern_add_color_stop_rgb(pat2,j,1,0,0);
        }
        count++;
    }
    cairo_rectangle(cr,20,140,300,100);
    cairo_set_source(cr,pat2);
    cairo_fill(cr);
    cairo_pattern_destroy(pat2);

    //第三条渐变带
    pat3 = cairo_pattern_create_linear(20.0, 260.0, 20.0, 360.0);

    /**
     * 下方三句话的意思：
     * 渐变团从矩形的上端至下端
     * 开始是黑色，到1/10宽度时黑色便停止了
     * 然后就是黑色向黄色渐变渲染；
     * 到达1/2处时，黄色达到饱和状态
     * 黄色断点会在9/10宽度处终止
     * 最后的1/10又是黑色
     */
    cairo_pattern_add_color_stop_rgb(pat3,0.1,0,0,0);
    cairo_pattern_add_color_stop_rgb(pat3,0.5,1,1,0);
    cairo_pattern_add_color_stop_rgb(pat3,0.9,0,0,0);

    // cairo_pattern_add_color_stop_rgb(pat3,0.0,0,1,0);
    // cairo_pattern_add_color_stop_rgb(pat3,0.5,1,0,0);
    // cairo_pattern_add_color_stop_rgb(pat3,1.0,0,1,0);
    // cairo_pattern_add_color_stop_rgb(pat3,0.8,0,0,1);


    cairo_rectangle(cr, 20, 260, 300, 100);
    cairo_set_source(cr, pat3);
    cairo_fill(cr);

    cairo_pattern_destroy(pat3);
}
static void radial_gradient(cairo_t *cr)
{
    cairo_pattern_t *pat1;
    cairo_pattern_t *pat2;
    cairo_pattern_t *pat3;

    cairo_set_source_rgba(cr,0,0,0,1);
    cairo_set_line_width(cr,12);
    cairo_translate(cr,60,60);

    pat1 = cairo_pattern_create_radial(30,30,10,30,30,90);
    cairo_pattern_add_color_stop_rgba(pat1,0.0,1.0,1.0,1.0,1.0);
    cairo_pattern_add_color_stop_rgba(pat1,1.0,0.6,0.6,0.6,1.0);
    cairo_set_source(cr,pat1);
    cairo_arc(cr,0,0,40,0,2*M_PI);
    cairo_fill(cr);
    cairo_pattern_destroy(pat1);

    cairo_translate(cr,120,0);
    pat2 = cairo_pattern_create_radial(0,0,10,0,0,40);
    cairo_pattern_add_color_stop_rgb(pat2,0.0,1.0,0.0,0.0);
    cairo_pattern_add_color_stop_rgb(pat2,0.5,0.0,1.0,0.0);
    cairo_pattern_add_color_stop_rgb(pat2,0.8,0.0,0.0,0.0);
    cairo_set_source(cr,pat2);
    cairo_arc(cr,0,0,40,0,2 * M_PI);
    cairo_fill(cr);
    cairo_pattern_destroy(pat2);

    pat3 = cairo_pattern_create_radial(0.0,0.0,80,500,360,20);
    cairo_pattern_add_color_stop_rgba(pat3, 0,  0, 0, 0.8, 1);
    cairo_pattern_add_color_stop_rgba(pat3, 0.25,  1, 1, 0, 1);
    cairo_pattern_add_color_stop_rgba(pat3, 0.5,  0.9, 0.0, 0.0, 1);
    cairo_pattern_add_color_stop_rgba(pat3, 0.75,  0.8, 0.12, 0.56, 1);
    cairo_pattern_add_color_stop_rgba(pat3, 1,  0, 0, 0, 1);
    cairo_set_source(cr,pat3);
    cairo_paint(cr);
}


int main(int argc,char **argv)
{
    GtkWidget *window;
    GtkWidget *hbox;
    GtkWidget *darea;

    gtk_init(&argc,&argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window),800,400);
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);

    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,10);
    gtk_container_add(GTK_CONTAINER(window),hbox);

    darea = gtk_drawing_area_new();
    gtk_widget_set_size_request(darea,400,400);
    g_signal_connect(G_OBJECT(darea),"draw",G_CALLBACK(linear_gradient_callback),NULL);
    gtk_container_add(GTK_CONTAINER(hbox),darea);

    darea = gtk_drawing_area_new();
    gtk_widget_set_size_request(darea,400,400);
    g_signal_connect(G_OBJECT(darea),"draw",G_CALLBACK(radial_gradient_callback),NULL);
    gtk_container_add(GTK_CONTAINER(hbox),darea);


    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
