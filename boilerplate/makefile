###############################################################################
#	makefile
#	by Mohamad Elzohbi.
#
#	A makefile script for building mixed C & Assembly programs RPI3
###############################################################################


# The intermediate directory for compiled object files.
BUILD = build/

# The directory in which source files are stored.
SOURCE = source/

# The names of all object files that must be generated. Deduced from the 
# assembly code files in source.
OBJECTS := $(patsubst $(SOURCE)%.s,$(BUILD)%.o,$(wildcard $(SOURCE)*.s))
COBJECTS := $(patsubst $(SOURCE)%.c,$(BUILD)%.o,$(wildcard $(SOURCE)*.c))

all: clean kernel8.img

# Rule to make the executable files.
kernel8.img: start.o $(OBJECTS) $(COBJECTS)
	aarch64-elf-ld -nostdlib -nostartfiles $(BUILD)start.o $(OBJECTS) $(COBJECTS) -T link.ld -o kernel8.elf
	aarch64-elf-objcopy -O binary kernel8.elf kernel8.img

start.o: $(SOURCE)start.S
	aarch64-elf-gcc -c $(SOURCE)start.S -o $(BUILD)start.o


# Rule to make the object files.
$(BUILD)%.o: $(SOURCE)%.s
	as --gstabs -I $(SOURCE) $< -o $@

$(BUILD)%.o: $(SOURCE)%.c
	aarch64-elf-gcc -g -c -O0 -Wall -I $(SOURCE) $< -o $@

# Rule to clean files.
clean : 
	-rm -f $(BUILD)*.o myProg

