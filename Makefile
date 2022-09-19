APP = ADT

OBJ_DIR = obj
BIN_DIR = .

INCLUDE = -I.

CC = gcc

COMPILE = -DQUEUE_TEST

LIBS =

OBJECTS += $(OBJ_DIR)/new_adt.o \
	$(OBJ_DIR)/stringT.o \
	$(OBJ_DIR)/queue.o \
	$(OBJ_DIR)/tree.o

.PHONY: clean directory

all: directory $(BIN_DIR)/$(APP)

$(BIN_DIR)/$(APP) : $(OBJECTS)
	$(CC) -o $@ $^ $(INCLUDE) $(LIBS)

# C compiler rule
$(OBJ_DIR)/%.o : %.c
	$(CC) -c -o $@ $< $(INCLUDE) $(COMPILE)

directory:
	@mkdir -p $(subst /,\,$(OBJ_DIR));


clean:
	@echo cleaning....;
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi
