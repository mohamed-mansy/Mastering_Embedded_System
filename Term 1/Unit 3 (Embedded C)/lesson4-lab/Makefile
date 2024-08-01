#@copyright : Mohamed_Ayman

#we made these because to compile each broed as I want
#you can replace arm-none-eabi- and put any TOOLCHAIN
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -gdwarf-2 -g
#INCS => include
INCS=-I . 
#LIBS => libaray
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)

Project_name=learn_in_depth_cortex-m4

# replace any dependency in command put $<
# replace any target in command put $@
#$< = dependency text replacement
#$@ = target text replacement
#% is a text replacement to app and uart

All: $(Project_name).bin
	@echo "===========Build is done============="

#startup.o: startup.s
#	$(CC)as.exe  $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@	
	

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(AsOBJ) $(OBJ) -o $@ -Map=Map_filo.map
	cp $(Project_name).elf $(Project_name).axf

$(Project_name).bin: $(Project_name).elf
	
	$(CC)objcopy.exe -O binary $<  $@
	
clean:
	rm *.bin *.elf
	
clean_all:
	rm *.o *.bin *.elf
	