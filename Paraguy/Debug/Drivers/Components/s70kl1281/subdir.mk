################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Components/s70kl1281/s70kl1281.c 

OBJS += \
./Drivers/Components/s70kl1281/s70kl1281.o 

C_DEPS += \
./Drivers/Components/s70kl1281/s70kl1281.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Components/s70kl1281/%.o Drivers/Components/s70kl1281/%.su Drivers/Components/s70kl1281/%.cyclo: ../Drivers/Components/s70kl1281/%.c Drivers/Components/s70kl1281/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_DIRECT_SMPS_SUPPLY -DUSE_HAL_DRIVER -DSTM32H735xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Admin/GitHub/Microcontroller2/Paraguy/Drivers/BSP" -I"C:/Users/Admin/GitHub/Microcontroller2/Paraguy/Core/Inc/Display" -I"C:/Users/Admin/GitHub/Microcontroller2/Paraguy/Drivers/PDM" -I"C:/Users/Admin/GitHub/Microcontroller2/Paraguy/Drivers/PDM/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Components-2f-s70kl1281

clean-Drivers-2f-Components-2f-s70kl1281:
	-$(RM) ./Drivers/Components/s70kl1281/s70kl1281.cyclo ./Drivers/Components/s70kl1281/s70kl1281.d ./Drivers/Components/s70kl1281/s70kl1281.o ./Drivers/Components/s70kl1281/s70kl1281.su

.PHONY: clean-Drivers-2f-Components-2f-s70kl1281

