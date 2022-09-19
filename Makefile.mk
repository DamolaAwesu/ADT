APP = ADT

OBJ_DIR = obj
BIN_DIR = .

INCLUDE = -I.

CC = gcc

LIBS =

.PHONY: clean directory

$(BIN_DIR)/$(APP) : $(OBJ_DIR)/%.o
	$(CC) -o $@ $^ $(INCLUDE) $(LIBS)

# C compiler rule
$(OBJ_DIR)/%.o : %.c
	$(CC) -c -o $@ $< $(INCLUDE)

directory:
	@mkdir -p $(subst /,\,$(OBJ_DIR));


clean:
	@echo cleaning....;
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi
