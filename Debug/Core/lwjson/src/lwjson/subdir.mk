################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lwjson/src/lwjson/lwjson.c \
../Core/lwjson/src/lwjson/lwjson_debug.c \
../Core/lwjson/src/lwjson/lwjson_stream.c 

OBJS += \
./Core/lwjson/src/lwjson/lwjson.o \
./Core/lwjson/src/lwjson/lwjson_debug.o \
./Core/lwjson/src/lwjson/lwjson_stream.o 

C_DEPS += \
./Core/lwjson/src/lwjson/lwjson.d \
./Core/lwjson/src/lwjson/lwjson_debug.d \
./Core/lwjson/src/lwjson/lwjson_stream.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lwjson/src/lwjson/%.o Core/lwjson/src/lwjson/%.su Core/lwjson/src/lwjson/%.cyclo: ../Core/lwjson/src/lwjson/%.c Core/lwjson/src/lwjson/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"D:/STM32_Workspace_Blog/JSON_parser_via_UART/Core/lwjson/src/include/" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lwjson-2f-src-2f-lwjson

clean-Core-2f-lwjson-2f-src-2f-lwjson:
	-$(RM) ./Core/lwjson/src/lwjson/lwjson.cyclo ./Core/lwjson/src/lwjson/lwjson.d ./Core/lwjson/src/lwjson/lwjson.o ./Core/lwjson/src/lwjson/lwjson.su ./Core/lwjson/src/lwjson/lwjson_debug.cyclo ./Core/lwjson/src/lwjson/lwjson_debug.d ./Core/lwjson/src/lwjson/lwjson_debug.o ./Core/lwjson/src/lwjson/lwjson_debug.su ./Core/lwjson/src/lwjson/lwjson_stream.cyclo ./Core/lwjson/src/lwjson/lwjson_stream.d ./Core/lwjson/src/lwjson/lwjson_stream.o ./Core/lwjson/src/lwjson/lwjson_stream.su

.PHONY: clean-Core-2f-lwjson-2f-src-2f-lwjson

