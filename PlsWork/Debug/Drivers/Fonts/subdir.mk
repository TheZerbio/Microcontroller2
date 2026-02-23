################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Fonts/font12.c \
../Drivers/Fonts/font16.c \
../Drivers/Fonts/font20.c \
../Drivers/Fonts/font24.c \
../Drivers/Fonts/font8.c 

OBJS += \
./Drivers/Fonts/font12.o \
./Drivers/Fonts/font16.o \
./Drivers/Fonts/font20.o \
./Drivers/Fonts/font24.o \
./Drivers/Fonts/font8.o 

C_DEPS += \
./Drivers/Fonts/font12.d \
./Drivers/Fonts/font16.d \
./Drivers/Fonts/font20.d \
./Drivers/Fonts/font24.d \
./Drivers/Fonts/font8.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Fonts/%.o Drivers/Fonts/%.su Drivers/Fonts/%.cyclo: ../Drivers/Fonts/%.c Drivers/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_DIRECT_SMPS_SUPPLY -DUSE_HAL_DRIVER -DSTM32H735xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/BSP" -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/BSP/Components" -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/BSP/Components/Common" -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/Fonts" -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/HAL_Drivers_Manual" -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/HAL_Drivers_Manual/Inc" -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/HAL_Drivers_Manual/Inc/Legacy" -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/Utils" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Fonts

clean-Drivers-2f-Fonts:
	-$(RM) ./Drivers/Fonts/font12.cyclo ./Drivers/Fonts/font12.d ./Drivers/Fonts/font12.o ./Drivers/Fonts/font12.su ./Drivers/Fonts/font16.cyclo ./Drivers/Fonts/font16.d ./Drivers/Fonts/font16.o ./Drivers/Fonts/font16.su ./Drivers/Fonts/font20.cyclo ./Drivers/Fonts/font20.d ./Drivers/Fonts/font20.o ./Drivers/Fonts/font20.su ./Drivers/Fonts/font24.cyclo ./Drivers/Fonts/font24.d ./Drivers/Fonts/font24.o ./Drivers/Fonts/font24.su ./Drivers/Fonts/font8.cyclo ./Drivers/Fonts/font8.d ./Drivers/Fonts/font8.o ./Drivers/Fonts/font8.su

.PHONY: clean-Drivers-2f-Fonts

