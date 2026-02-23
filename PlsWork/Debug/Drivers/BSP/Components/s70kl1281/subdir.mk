################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/s70kl1281/s70kl1281.c 

OBJS += \
./Drivers/BSP/Components/s70kl1281/s70kl1281.o 

C_DEPS += \
./Drivers/BSP/Components/s70kl1281/s70kl1281.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/s70kl1281/%.o Drivers/BSP/Components/s70kl1281/%.su Drivers/BSP/Components/s70kl1281/%.cyclo: ../Drivers/BSP/Components/s70kl1281/%.c Drivers/BSP/Components/s70kl1281/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_DIRECT_SMPS_SUPPLY -DUSE_HAL_DRIVER -DSTM32H735xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/BSP" -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/BSP/Components" -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/BSP/Components/Common" -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/Fonts" -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/HAL_Drivers_Manual" -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/HAL_Drivers_Manual/Inc" -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/HAL_Drivers_Manual/Inc/Legacy" -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/Utils" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-s70kl1281

clean-Drivers-2f-BSP-2f-Components-2f-s70kl1281:
	-$(RM) ./Drivers/BSP/Components/s70kl1281/s70kl1281.cyclo ./Drivers/BSP/Components/s70kl1281/s70kl1281.d ./Drivers/BSP/Components/s70kl1281/s70kl1281.o ./Drivers/BSP/Components/s70kl1281/s70kl1281.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-s70kl1281

