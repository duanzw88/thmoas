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
			btree.o \
			flexstack.o \
			timer.o \
			binarySearch.o \
			sort.o \
			priorityQueue.o \
			item.o \
			bst.o \
			rbtree.o \
			matrix.o \
			kalman_lib.o
			# st_unorder.o \
			bst.o
OBJS = $(addprefix $(OBJ_DIR)/,$(objects))

lib=libalgorthim.a
LIB=$(addprefix $(LIB_DIR)/,$(lib))

EXAMPLE_DIR=./example
examples=counter_demo \
		btree_demo \
		flexstack_demo \
		threesum_demo \
		quicksort_demo \
		quick3way_demo \
		sort_demo \
		pq_demo \
		heapsort_demo \
		bst_demo \
		rbtree_demo \
		matrix_demo \
		kalman_demo \
		demo
		# st_unorder_demo \
		bst_demo \
		demo
EXAMPLES=$(addprefix $(EXAMPLE_DIR)/,$(examples))

all:$(OBJ_DIR) $(LIB) $(EXAMPLES)
	$(RM) $(OBJ_DIR)

lib:$(OBJ_DIR) $(LIB)
examples:$(EXAMPLES)

$(OBJ_DIR):
	$(MKDIR) $@

$(LIB):$(OBJS)
	ar crs $@ $(OBJS)
	@echo "compile lib"

$(OBJ_DIR)/mem.o:memchk.c
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
$(OBJ_DIR)/flexstack.o:flexstack.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCLUDE_DIR)
$(OBJ_DIR)/timer.o:timer.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCLUDE_DIR)
$(OBJ_DIR)/binarySearch.o:binarySearch.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCLUDE_DIR)
$(OBJ_DIR)/sort.o:sort.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCLUDE_DIR)
$(OBJ_DIR)/priorityQueue.o:priorityQueue.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCLUDE_DIR)
$(OBJ_DIR)/item.o:item.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCLUDE_DIR)
# $(OBJ_DIR)/st_unorder.o:st_unorder.c
# 	$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCLUDE_DIR)
$(OBJ_DIR)/bst.o:bst.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCLUDE_DIR)
$(OBJ_DIR)/rbtree.o:rbtree.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCLUDE_DIR)
$(OBJ_DIR)/matrix.o:matrix.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCLUDE_DIR)
$(OBJ_DIR)/kalman_lib.o:kalman.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCLUDE_DIR)


$(EXAMPLE_DIR)/counter_demo:counter_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lalgorthim
$(EXAMPLE_DIR)/btree_demo:btree_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lalgorthim
$(EXAMPLE_DIR)/flexstack_demo:flexstack_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lalgorthim
$(EXAMPLE_DIR)/threesum_demo:threesum_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lalgorthim
$(EXAMPLE_DIR)/quicksort_demo:quicksort_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lalgorthim
$(EXAMPLE_DIR)/quick3way_demo:quick3way_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lalgorthim

$(EXAMPLE_DIR)/heapsort_demo:heapsort_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lalgorthim

$(EXAMPLE_DIR)/sort_demo:sort_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lalgorthim
$(EXAMPLE_DIR)/pq_demo:pq_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lalgorthim
$(EXAMPLE_DIR)/st_unorder_demo:st_unorder_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lalgorthim
$(EXAMPLE_DIR)/bst_demo:bst_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lalgorthim
$(EXAMPLE_DIR)/rbtree_demo:rbtree_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lalgorthim
$(EXAMPLE_DIR)/matrix_demo:matrix_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lalgorthim
$(EXAMPLE_DIR)/kalman_demo:kalman_demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lalgorthim
$(EXAMPLE_DIR)/demo:demo.c
	$(CC) $(CFLAGS) -o $@  $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lalgorthim
clean:
	$(RM) $(OBJ_DIR) $(LIB) $(EXAMPLES)
