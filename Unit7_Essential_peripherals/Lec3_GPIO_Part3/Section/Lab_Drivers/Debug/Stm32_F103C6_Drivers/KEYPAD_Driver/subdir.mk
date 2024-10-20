################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32_F103C6_Drivers/KEYPAD_Driver/Keypad.c 

OBJS += \
./Stm32_F103C6_Drivers/KEYPAD_Driver/Keypad.o 

C_DEPS += \
./Stm32_F103C6_Drivers/KEYPAD_Driver/Keypad.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32_F103C6_Drivers/KEYPAD_Driver/Keypad.o: ../Stm32_F103C6_Drivers/KEYPAD_Driver/Keypad.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Administrator/STM32CubeIDE/workspace2/Drivers/Stm32_F103C6_Drivers/7Segment" -I"C:/Users/Administrator/STM32CubeIDE/workspace2/Drivers/Stm32_F103C6_Drivers/KEYPAD_Driver" -I"C:/Users/Administrator/STM32CubeIDE/workspace2/Drivers/Stm32_F103C6_Drivers/LCD_Driver" -I"C:/Users/Administrator/STM32CubeIDE/workspace2/Drivers/Stm32_F103C6_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/KEYPAD_Driver/Keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

