CC=gcc
TARGET=mycmd
CFLAGS=

OBJDIR := obj
SRCDIR := src
SRCEXT := c
LIB :=
INCLUDE := -I include
DIRBIN = bin

SOURCE = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))

OBJ = $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCE:.$(SRCEXT)=.o))

## Default rule executed
all: $(TARGET)
	@true

## Clean Rule
clean:
	@-rm -f $(DIRBIN)/$(TARGET) $(OBJ)

install:
	@echo "Installing $(TARGET) ..."
	install -m 0755 $(TARGET) $(DIRBIN)/$(TARGET)
	@echo "done" 

## Rule for making the actual target
$(TARGET): $(OBJ)
	@echo "============="
	@echo "Linking the target $@"
	@echo "============="
	@$(CC) $(CFLAGS) -o $(DIRBIN)/$@ $^ $(LIBS)
	@echo -- Link finished --

## Rules for object files from c files
## Object file for each file is put in obj directory
obj/%.o : src/%.c
	@mkdir -p $(dir $@)
	@echo "============="
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

