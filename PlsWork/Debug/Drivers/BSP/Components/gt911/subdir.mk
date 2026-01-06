################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/gt911/gt911.c \
../Drivers/BSP/Components/gt911/gt911_reg.c 

OBJS += \
./Drivers/BSP/Components/gt911/gt911.o \
./Drivers/BSP/Components/gt911/gt911_reg.o 

C_DEPS += \
./Drivers/BSP/Components/gt911/gt911.d \
./Drivers/BSP/Components/gt911/gt911_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/gt911/%.o Drivers/BSP/Components/gt911/%.su Drivers/BSP/Components/gt911/%.cyclo: ../Drivers/BSP/Components/gt911/%.c Drivers/BSP/Components/gt911/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_DIRECT_SMPS_SUPPLY -DUSE_HAL_DRIVER -DSTM32H735xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/BSP" -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/BSP/Components" -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/BSP/Components/Common" -I"C:/Users/Admin/GitHub/Microcontroller2/PlsWork/Drivers/Fonts" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-gt911

clean-Drivers-2f-BSP-2f-Components-2f-gt911:
	-$(RM) ./Drivers/BSP/Components/gt911/gt911.cyclo ./Drivers/BSP/Components/gt911/gt911.d ./Drivers/BSP/Components/gt911/gt911.o ./Drivers/BSP/Components/gt911/gt911.su ./Drivers/BSP/Components/gt911/gt911_reg.cyclo ./Drivers/BSP/Components/gt911/gt911_reg.d ./Drivers/BSP/Components/gt911/gt911_reg.o ./Drivers/BSP/Components/gt911/gt911_reg.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-gt911

