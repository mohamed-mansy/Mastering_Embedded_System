#@Copyright: Mohamed_Ayman

cc=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)

project_name=Pressure_Sensor

All: $(project_name).bin
	@echo "=========Build is done==============" 

%.o: %.s
	$(cc)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(cc)gcc.exe $(CFLAGS) -c $(INCS) $< -o $@

$(project_name).elf: $(OBJ) $(AsOBJ)
	$(cc)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map

$(project_name).bin: $(project_name).elf
	$(cc)objcopy.exe -O binary $<  $@
	
	
clean:
	rm *.bin *.elf
	
clean_all:
	rm *.o *.bin *.elf
	

