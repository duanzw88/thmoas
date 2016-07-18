#include <gtk/gtk.h>

int startx = 0;
int w = 400;
int h = 300;

struct
{
    double x[2];
    double y[2];
}glob;
static cairo_surface_t *surface = NULL;

static void do_drawing(GtkWidget *widget)
{
    cairo_t *cr;

    cr = cairo_create(surface);

    cairo_set_source_rgb(cr,1,0,0);
    cairo_set_line_width(cr,1);

    cairo_move_to(cr,glob.x[0],glob.y[0]);
    cairo_line_to(cr,glob.x[1],glob.y[1]);

    cairo_stroke(cr);
    cairo_destroy(cr);

    gtk_widget_queue_draw(widget);
}
/**
 * 清空surface
 */
static void clear_surface(GtkWidget *widget)
{
    cairo_t *cr;

    cr = cairo_create(surface);

    cairo_set_source_rgb(cr,1,1,1);
    cairo_paint(cr);
    cairo_destroy(cr);

    gtk_widget_queue_draw(widget);
}

//鼠标按下信号处理
static gboolean button_press(GtkWidget *widget,GdkEventButton *event,gpointer user_data)
{
    g_print("button_press button = %d\n",event->button);
    if(event->button == 1)
    {
        glob.x[0] = event->x;
        glob.y[0] = event->y;
    }
    // if(event->button == 3)
    // {
    //     clear_surface(widget);
    // }

    return TRUE;
}
//鼠标按钮释放信号
static gboolean button_release(GtkWidget *widget,GdkEventButton *event,gpointer user_data)
{
    g_print("button_release\n");
    if(event->button == 1)
    {
        glob.x[1] = event->x;
        glob.y[1] = event->y;

        do_drawing(widget);
    }

    return TRUE;
}


//控件大小发生改变是发出信号，包括窗口创建时
static gboolean configure_event(GtkWidget *widget,GdkEventConfigure *event,gpointer data)
{
    if(surface)
    {
        cairo_surface_destroy(surface);
    }

    surface = gdk_window_create_similar_surface(gtk_widget_get_window(widget),
                                                CAIRO_CONTENT_COLOR,
                                                gtk_widget_get_allocated_width(widget),
                                                gtk_widget_get_allocated_height(widget));

    clear_surface(widget);

    return TRUE;
}
/**
 * 绘图事件
 */
static void  on_expose_event(GtkWidget *widget,cairo_t *cr,gpointer data)
{
    g_print("on_expose_event\n");

    cairo_set_source_surface(cr,surface,0,0);
    cairo_paint(cr);
    //创建cairo环境
    // cairo_t *cr = gdk_cairo_create(gtk_widget_get_window(widget));
    //
    // //画背景图
    // //获取图片
    // GdkPixbuf *src_pixbuf = gdk_pixbuf_new_from_file("./image/back.jpg",NULL);
    // //指定图片大小
    // GdkPixbuf* dst_pixbuf = gdk_pixbuf_scale_simple(src_pixbuf,w,h,GDK_INTERP_BILINEAR);
    // //dst_pixbuf作为cr环境的画图原材料,(0,0)为画图的起点坐标
    // gdk_cairo_set_source_pixbuf(cr,dst_pixbuf,0,0);
    // //绘图
    // cairo_paint(cr);
    // g_object_unref(dst_pixbuf);
    // g_object_unref(src_pixbuf);
    //
    // //画笑脸
    // src_pixbuf = gdk_pixbuf_new_from_file("./image/face.png",NULL);
    // dst_pixbuf = gdk_pixbuf_scale_simple(src_pixbuf,80,80,GDK_INTERP_BILINEAR);
    // gdk_cairo_set_source_pixbuf(cr,dst_pixbuf,startx,(h/10)*3);
    // cairo_paint(cr);
    // g_object_unref(dst_pixbuf);
    // g_object_unref(src_pixbuf);
    //
    // cairo_destroy(cr);
    // return FALSE;
}
/**
 * 按钮处理事件
 */
static void button_clicked(GtkWidget *widget,gpointer data)
{
    startx += 20;
    if(startx >= w)
    {
        startx = 0;
    }

    gtk_widget_queue_draw(GTK_WIDGET(data));
}
int main(int argc,char **argv)
{
    //初始化
    gtk_init(&argc,&argv);

    //创建顶层窗口
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_window_set_title(GTK_WINDOW(window),"绘图");
    //设置窗口位置
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    //设置窗口大小
    gtk_widget_set_size_request(window,w,h);
    //固定窗口大小
    gtk_window_set_resizable(GTK_WINDOW(window),FALSE);

    //表格布局容器
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window),grid);

    //button
    // GtkWidget *button = gtk_button_new_with_label("click me");
    // g_signal_connect(button,"clicked",G_CALLBACK(button_clicked),window);
    // gtk_grid_attach(GTK_GRID(grid),button,3,4,1,1);

    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
    //鼠标按下信号
    g_signal_connect(window,"button-press-event",G_CALLBACK(button_press),NULL);
    //鼠标按钮释放信号
    g_signal_connect(window,"button-release-event",G_CALLBACK(button_release),NULL);
    //绘图事件信号与回调函数连接
    g_signal_connect(window,"draw",G_CALLBACK(on_expose_event),NULL);
    //控件大小发生改变是发出信号，包括窗口创建时
    g_signal_connect(window,"configure-event",G_CALLBACK(configure_event),NULL);
    //允许窗口可以绘图
    gtk_widget_set_app_paintable(window,TRUE);

    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}
