
examples = example1 \
		example2_button \
		example3_ui \
		example_draw \
		example_cairo \
		backends \
		basic_drawing \
		shape_fill \
		gradient \
		transparency \
		compositing \
		clip_mask \
		transformation \
		text \
		images \
		root_window
all:$(examples)

example1:example1.c
	gcc `pkg-config --cflags gtk+-3.0` -o $@ $< `pkg-config --libs gtk+-3.0`

example2_button:example2_button.c
	gcc `pkg-config --cflags gtk+-3.0` -o $@ $< `pkg-config --libs gtk+-3.0`

example3_ui:example3_ui.c
	gcc `pkg-config --cflags gtk+-3.0` -o $@ $< `pkg-config --libs gtk+-3.0`

example_draw:example_draw.c
	gcc `pkg-config --cflags gtk+-3.0` -o $@ $< `pkg-config --libs gtk+-3.0`

example_cairo:cairo/example_cairo.c
	gcc `pkg-config --cflags gtk+-3.0` -o $@ $< `pkg-config --libs gtk+-3.0`

backends:cairo/backend.c
	gcc `pkg-config --cflags gtk+-3.0` -o $@ $< `pkg-config --libs gtk+-3.0`
basic_drawing:cairo/basic_drawing.c
	gcc `pkg-config --cflags gtk+-3.0` -o $@ $< `pkg-config --libs gtk+-3.0`
shape_fill:cairo/shape_fill.c
	gcc `pkg-config --cflags gtk+-3.0` -o $@ $< `pkg-config --libs gtk+-3.0`
gradient:cairo/gradient.c
	gcc `pkg-config --cflags gtk+-3.0` -o $@ $< `pkg-config --libs gtk+-3.0`
transparency:cairo/transparency.c
	gcc `pkg-config --cflags gtk+-3.0` -o $@ $< `pkg-config --libs gtk+-3.0`
compositing:cairo/compositing.c
	gcc `pkg-config --cflags gtk+-3.0` -o $@ $< `pkg-config --libs gtk+-3.0`
clip_mask:cairo/clip_mask.c
	gcc `pkg-config --cflags gtk+-3.0` -o $@ $< `pkg-config --libs gtk+-3.0`
transformation:cairo/transformation.c
	gcc `pkg-config --cflags gtk+-3.0` -o $@ $< `pkg-config --libs gtk+-3.0`
text:cairo/text.c
	gcc `pkg-config --cflags gtk+-3.0` -o $@ $< `pkg-config --libs gtk+-3.0`
images:cairo/images.c
	gcc `pkg-config --cflags gtk+-3.0` -o $@ $< `pkg-config --libs gtk+-3.0`
root_window:cairo/root_window.c
	gcc `pkg-config --cflags gtk+-3.0` -o $@ $< `pkg-config --libs gtk+-3.0`

clean:
	rm -rf $(examples)
