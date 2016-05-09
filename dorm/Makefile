VPATH = src include example libs
MKDIR = mkdir
INCLUDE_DIR = include

CC=gcc
CFLAGS= -std=c99
AR=ar
RM=rm -rf

OBJ_DIR=./objs
LIB_DIR=./libs

objects =
OBJS = $(addprefix $(OBJ_DIR)/,$(objects))

lib=libalgorthim.a
LIB=$(addprefix $(LIB_DIR)/,$(lib))

EXAMPLE_DIR=./example
examples=dorm_demo
EXAMPLES=$(addprefix $(EXAMPLE_DIR)/,$(examples))

# all:$(OBJ_DIR) $(LIB) $(EXAMPLES)
all:$(OBJ_DIR) $(EXAMPLES)
	$(RM) $(OBJ_DIR)

cii:$(OBJ_DIR) $(LIB)

$(OBJ_DIR):
	$(MKDIR) $@

$(LIB):$(OBJS)
	ar crs $@ $(OBJS)
	@echo "compile lib"



$(EXAMPLE_DIR)/dorm_demo:dorm_demo.c
	$(CC) $(CFLAGS) $(pkg-config gtk+-3.0 --cflags) $(pkg-config gtk+-3.0 --libs) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lalgorthim
	

clean:
	$(RM) $(OBJ_DIR) $(LIB) $(EXAMPLES)
