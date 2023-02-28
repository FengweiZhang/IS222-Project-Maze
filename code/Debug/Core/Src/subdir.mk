################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/flash.c \
../Core/Src/fonts.c \
../Core/Src/fsmc.c \
../Core/Src/gpio.c \
../Core/Src/key.c \
../Core/Src/lcd.c \
../Core/Src/main.c \
../Core/Src/maze.c \
../Core/Src/spi.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/tim.c \
../Core/Src/touch.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/flash.o \
./Core/Src/fonts.o \
./Core/Src/fsmc.o \
./Core/Src/gpio.o \
./Core/Src/key.o \
./Core/Src/lcd.o \
./Core/Src/main.o \
./Core/Src/maze.o \
./Core/Src/spi.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/tim.o \
./Core/Src/touch.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/flash.d \
./Core/Src/fonts.d \
./Core/Src/fsmc.d \
./Core/Src/gpio.d \
./Core/Src/key.d \
./Core/Src/lcd.d \
./Core/Src/main.d \
./Core/Src/maze.d \
./Core/Src/spi.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/tim.d \
./Core/Src/touch.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/flash.d ./Core/Src/flash.o ./Core/Src/flash.su ./Core/Src/fonts.d ./Core/Src/fonts.o ./Core/Src/fonts.su ./Core/Src/fsmc.d ./Core/Src/fsmc.o ./Core/Src/fsmc.su ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/key.d ./Core/Src/key.o ./Core/Src/key.su ./Core/Src/lcd.d ./Core/Src/lcd.o ./Core/Src/lcd.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/maze.d ./Core/Src/maze.o ./Core/Src/maze.su ./Core/Src/spi.d ./Core/Src/spi.o ./Core/Src/spi.su ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/tim.su ./Core/Src/touch.d ./Core/Src/touch.o ./Core/Src/touch.su ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su

.PHONY: clean-Core-2f-Src

