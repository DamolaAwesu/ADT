APP = ADT

OBJ_DIR = obj
BIN_DIR = .

INCLUDE = -I.

CC = gcc

LIBS =

OBJECTS += $(OBJ_DIR)/new.o \
	$(OBJ_DIR)/stringT.o \
	$(OBJ_DIR)/queue.o \
	$(OBJ_DIR)/tree.o

.PHONY: clean directory

$(BIN_DIR)/$(APP) : $(OBJECTS)
	$(CC) -o $@ $^ $(INCLUDE) $(LIBS)

# C compiler rule
$(OBJ_DIR)/%.o : %.c
	$(CC) -c -o $@ $< $(INCLUDE)

directory:
	@mkdir -p $(subst /,\,$(OBJ_DIR));


clean:
	@echo cleaning....;
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi
