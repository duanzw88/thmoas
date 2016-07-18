#include <gtk/gtk.h>
#include <cairo-pdf.h>
#include <cairo-svg.h>

static void do_drawing(cairo_t *cr);
/**
 * 创建一个png图片
 */
static void png_image(GtkWidget *widget,gpointer data)
{
    cairo_surface_t *surface;
    cairo_t *cr;

    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32,54,80);
    cr = cairo_create(surface);

    cairo_set_source_rgb(cr,1,0,0);
    cairo_select_font_face(cr,"Sans",CAIRO_FONT_SLANT_NORMAL,CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(cr,40.0);

    // cairo_move_to(cr,10.0,50.0);
    // cairo_show_text(cr,"Duanzw gtk+---cairo");
    cairo_rectangle(cr,0,0,54,80);
    cairo_stroke_preserve(cr);
    cairo_fill(cr);

    cairo_surface_write_to_png(surface,"cairo_png.png");

    cairo_destroy(cr);
    cairo_surface_destroy(surface);
}
/**
 * 创建一个pdf文件
 */
static void pdf_file(GtkWidget *widget,gpointer data)
{
    cairo_surface_t *surface;
    cairo_t *cr;

    surface = cairo_pdf_surface_create("pdffile.pdf",504.0,648.0);
    cr = cairo_create(surface);

    cairo_set_source_rgb(cr,0,1,0);
    cairo_select_font_face(cr,"Sans",CAIRO_FONT_SLANT_NORMAL,CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(cr,40.0);

    cairo_move_to(cr,10.0,50.0);
    cairo_show_text(cr,"Duanzw gtk+---cairo");

    cairo_show_page(cr);

    cairo_surface_destroy(surface);
    cairo_destroy(cr);
}
/**
 * 创建一个svg文件
 */
static void svg_file(GtkWidget *widget,gpointer data)
{
    cairo_surface_t *surface;
    cairo_t *cr;

    surface = cairo_svg_surface_create("svgfile.svg",390.0,60.0);
    cr = cairo_create(surface);

    cairo_set_source_rgb(cr,0,0,1);
    cairo_select_font_face(cr,"Sans",CAIRO_FONT_SLANT_NORMAL,CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(cr,40.0);

    cairo_move_to(cr,10.0,50.0);
    cairo_show_text(cr,"Duanzw gtk+---cairo");

    cairo_show_page(cr);

    cairo_surface_destroy(surface);
    cairo_destroy(cr);
}

static void do_drawing(cairo_t *cr)
{
    cairo_set_source_rgb(cr,0,0,0);
    cairo_select_font_face(cr,"Sans",CAIRO_FONT_SLANT_NORMAL,CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(cr,10.0);

    cairo_move_to(cr,10.0,20.0);
    cairo_show_text(cr,"Diziplin ist Macht.");

}
static gboolean on_draw_event(GtkWidget *widget,cairo_t *cr,gpointer data)
{
    g_print("on_draw_event\n");

    // cairo_set_source_surface(cr,surface,0,0);
    do_drawing(cr);
    return FALSE;
}
/**
 * 在gtk窗口绘制文字
 */
static void gtk_window(GtkWidget *widget,gpointer data)
{
    g_print("gtk_window\n");
    // do_drawing(widget);

}
int main(int argc,char **argv)
{
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *grid;
    GtkWidget *button;
    GtkWidget *darea;

    gtk_init(&argc,&argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL,10);

    gtk_window_set_default_size(GTK_WINDOW(window),400,400);
    gtk_container_set_border_width(GTK_CONTAINER(window),10);
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_container_add(GTK_CONTAINER(window),box);

    darea = gtk_drawing_area_new();
    // gtk_grid_attach(GTK_GRID(grid),darea,0,1,2,4);
    gtk_widget_set_size_request(darea,400,200);
    gtk_container_add(GTK_CONTAINER(box),darea);
    g_signal_connect(G_OBJECT(darea),"draw",G_CALLBACK(on_draw_event),NULL);

    grid = gtk_grid_new();
    // gtk_container_add(GTK_CONTAINER(window),grid);
    gtk_container_add(GTK_CONTAINER(box),grid);

    button = gtk_button_new_with_label("PNG Image");
    g_signal_connect(button,"clicked",G_CALLBACK(png_image),NULL);
    gtk_grid_attach(GTK_GRID(grid),button,0,0,1,1);

    button = gtk_button_new_with_label("PDF File");
    g_signal_connect(button,"clicked",G_CALLBACK(pdf_file),NULL);
    gtk_grid_attach(GTK_GRID(grid),button,1,0,1,1);

    button = gtk_button_new_with_label("SVG File");
    g_signal_connect(button,"clicked",G_CALLBACK(svg_file),NULL);
    gtk_grid_attach(GTK_GRID(grid),button,2,0,1,1);

    button = gtk_button_new_with_label("GtkWindow");
    g_signal_connect(button,"clicked",G_CALLBACK(gtk_window),NULL);
    // gtk_grid_attach(GTK_GRID(grid),button,3,0,1,1);



    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
