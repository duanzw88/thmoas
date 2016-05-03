VPATH = src include example libs
MKDIR = mkdir
INCLUDE_DIR = include

CC=gcc
CFLAGS= -std=c99
AR=ar
RM=rm -rf

OBJ_DIR=./objs
LIB_DIR=./libs

objects = sqlite3.o
OBJS = $(addprefix $(OBJ_DIR)/,$(objects))

lib=libsqlite.a
LIB=$(addprefix $(LIB_DIR)/,$(lib))

EXAMPLE_DIR=./example
examples=demo \
		query_demo \
		insert_demo \
		retrieve_demo \
		parameterized_demo \
		image_demo \
		metadata_demo
EXAMPLES=$(addprefix $(EXAMPLE_DIR)/,$(examples))

all:$(OBJ_DIR) $(LIB) $(EXAMPLES)
	$(RM) $(OBJ_DIR)

cii:$(OBJ_DIR) $(LIB)

$(OBJ_DIR):
	$(MKDIR) $@

$(LIB):$(OBJS)
	ar crs $@ $(OBJS)
	@echo "compile lib"

$(OBJ_DIR)/sqlite3.o:sqlite3.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCLUDE_DIR)


$(EXAMPLE_DIR)/demo:demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lsqlite3
$(EXAMPLE_DIR)/query_demo:query_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lsqlite3
$(EXAMPLE_DIR)/insert_demo:insert_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lsqlite3
$(EXAMPLE_DIR)/retrieve_demo:retrieve_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lsqlite3
$(EXAMPLE_DIR)/parameterized_demo:parameterized_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lsqlite3
$(EXAMPLE_DIR)/image_demo:image_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lsqlite3

$(EXAMPLE_DIR)/metadata_demo:metadata_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lsqlite3

clean:
	$(RM) $(OBJ_DIR) $(LIB) $(EXAMPLES)
