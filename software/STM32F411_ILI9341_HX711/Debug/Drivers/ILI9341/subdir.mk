################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/ILI9341/core.c 

C_DEPS += \
./Drivers/ILI9341/core.d 

OBJS += \
./Drivers/ILI9341/core.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/ILI9341/%.o Drivers/ILI9341/%.su Drivers/ILI9341/%.cyclo: ../Drivers/ILI9341/%.c Drivers/ILI9341/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/generated/videos/include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-ILI9341

clean-Drivers-2f-ILI9341:
	-$(RM) ./Drivers/ILI9341/core.cyclo ./Drivers/ILI9341/core.d ./Drivers/ILI9341/core.o ./Drivers/ILI9341/core.su

.PHONY: clean-Drivers-2f-ILI9341

