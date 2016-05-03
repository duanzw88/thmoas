VPATH = src include example libs
MKDIR = mkdir
INCLUDE_DIR = include

CC=gcc
CFLAGS= -std=c99
AR=ar
RM=rm -rf

OBJ_DIR=./objs
LIB_DIR=./libs

objects = 	mem.o \
			except.o \
 			assert.o \
			atom.o \
			counter.o \
			btree.o
OBJS = $(addprefix $(OBJ_DIR)/,$(objects))

lib=libalgorthim.a
LIB=$(addprefix $(LIB_DIR)/,$(lib))

EXAMPLE_DIR=./example
examples=counter_demo \
		btree_demo
EXAMPLES=$(addprefix $(EXAMPLE_DIR)/,$(examples))

all:$(OBJ_DIR) $(LIB) $(EXAMPLES)
	$(RM) $(OBJ_DIR)

cii:$(OBJ_DIR) $(LIB)

$(OBJ_DIR):
	$(MKDIR) $@

$(LIB):$(OBJS)
	ar crs $@ $(OBJS)
	@echo "compile lib"

$(OBJ_DIR)/mem.o:mem.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCLUDE_DIR)
$(OBJ_DIR)/except.o:except.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCLUDE_DIR)
$(OBJ_DIR)/assert.o:assert.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCLUDE_DIR)
$(OBJ_DIR)/atom.o:atom.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCLUDE_DIR)
$(OBJ_DIR)/counter.o:counter.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCLUDE_DIR)
$(OBJ_DIR)/btree.o:btree.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCLUDE_DIR)



$(EXAMPLE_DIR)/counter_demo:counter_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lalgorthim
$(EXAMPLE_DIR)/btree_demo:btree_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lalgorthim

clean:
	$(RM) $(OBJ_DIR) $(LIB) $(EXAMPLES)
