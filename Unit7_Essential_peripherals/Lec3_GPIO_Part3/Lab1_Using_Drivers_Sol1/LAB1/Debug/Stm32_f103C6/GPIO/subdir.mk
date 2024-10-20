################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32_f103C6/GPIO/stm32f103c6_GPIO_driver.c 

OBJS += \
./Stm32_f103C6/GPIO/stm32f103c6_GPIO_driver.o 

C_DEPS += \
./Stm32_f103C6/GPIO/stm32f103c6_GPIO_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32_f103C6/GPIO/stm32f103c6_GPIO_driver.o: ../Stm32_f103C6/GPIO/stm32f103c6_GPIO_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Administrator/STM32CubeIDE/workspace2/Unit7_Lesson3/Stm32_f103C6/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_f103C6/GPIO/stm32f103c6_GPIO_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

