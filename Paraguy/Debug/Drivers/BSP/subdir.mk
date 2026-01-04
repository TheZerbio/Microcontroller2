################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/stm32h735g_discovery.c \
../Drivers/BSP/stm32h735g_discovery_audio.c \
../Drivers/BSP/stm32h735g_discovery_bus.c \
../Drivers/BSP/stm32h735g_discovery_lcd.c \
../Drivers/BSP/stm32h735g_discovery_ospi.c \
../Drivers/BSP/stm32h735g_discovery_sd.c \
../Drivers/BSP/stm32h735g_discovery_ts.c 

OBJS += \
./Drivers/BSP/stm32h735g_discovery.o \
./Drivers/BSP/stm32h735g_discovery_audio.o \
./Drivers/BSP/stm32h735g_discovery_bus.o \
./Drivers/BSP/stm32h735g_discovery_lcd.o \
./Drivers/BSP/stm32h735g_discovery_ospi.o \
./Drivers/BSP/stm32h735g_discovery_sd.o \
./Drivers/BSP/stm32h735g_discovery_ts.o 

C_DEPS += \
./Drivers/BSP/stm32h735g_discovery.d \
./Drivers/BSP/stm32h735g_discovery_audio.d \
./Drivers/BSP/stm32h735g_discovery_bus.d \
./Drivers/BSP/stm32h735g_discovery_lcd.d \
./Drivers/BSP/stm32h735g_discovery_ospi.d \
./Drivers/BSP/stm32h735g_discovery_sd.d \
./Drivers/BSP/stm32h735g_discovery_ts.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/%.o Drivers/BSP/%.su Drivers/BSP/%.cyclo: ../Drivers/BSP/%.c Drivers/BSP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_DIRECT_SMPS_SUPPLY -DUSE_HAL_DRIVER -DSTM32H735xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Admin/GitHub/Microcontroller2/Paraguy/Drivers/BSP" -I"C:/Users/Admin/GitHub/Microcontroller2/Paraguy/Core/Inc/Display" -I"C:/Users/Admin/GitHub/Microcontroller2/Paraguy/Drivers/PDM" -I"C:/Users/Admin/GitHub/Microcontroller2/Paraguy/Drivers/PDM/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP

clean-Drivers-2f-BSP:
	-$(RM) ./Drivers/BSP/stm32h735g_discovery.cyclo ./Drivers/BSP/stm32h735g_discovery.d ./Drivers/BSP/stm32h735g_discovery.o ./Drivers/BSP/stm32h735g_discovery.su ./Drivers/BSP/stm32h735g_discovery_audio.cyclo ./Drivers/BSP/stm32h735g_discovery_audio.d ./Drivers/BSP/stm32h735g_discovery_audio.o ./Drivers/BSP/stm32h735g_discovery_audio.su ./Drivers/BSP/stm32h735g_discovery_bus.cyclo ./Drivers/BSP/stm32h735g_discovery_bus.d ./Drivers/BSP/stm32h735g_discovery_bus.o ./Drivers/BSP/stm32h735g_discovery_bus.su ./Drivers/BSP/stm32h735g_discovery_lcd.cyclo ./Drivers/BSP/stm32h735g_discovery_lcd.d ./Drivers/BSP/stm32h735g_discovery_lcd.o ./Drivers/BSP/stm32h735g_discovery_lcd.su ./Drivers/BSP/stm32h735g_discovery_ospi.cyclo ./Drivers/BSP/stm32h735g_discovery_ospi.d ./Drivers/BSP/stm32h735g_discovery_ospi.o ./Drivers/BSP/stm32h735g_discovery_ospi.su ./Drivers/BSP/stm32h735g_discovery_sd.cyclo ./Drivers/BSP/stm32h735g_discovery_sd.d ./Drivers/BSP/stm32h735g_discovery_sd.o ./Drivers/BSP/stm32h735g_discovery_sd.su ./Drivers/BSP/stm32h735g_discovery_ts.cyclo ./Drivers/BSP/stm32h735g_discovery_ts.d ./Drivers/BSP/stm32h735g_discovery_ts.o ./Drivers/BSP/stm32h735g_discovery_ts.su

.PHONY: clean-Drivers-2f-BSP

