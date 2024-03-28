################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/EnhancedFonts/Bahnschrift_SemiCondensed\ _76pt.c \
../Core/Src/EnhancedFonts/Bahnschrift_SemiCondensed_24pt.c \
../Core/Src/EnhancedFonts/arialBlack_20ptFontInfo.c 

OBJS += \
./Core/Src/EnhancedFonts/Bahnschrift_SemiCondensed\ _76pt.o \
./Core/Src/EnhancedFonts/Bahnschrift_SemiCondensed_24pt.o \
./Core/Src/EnhancedFonts/arialBlack_20ptFontInfo.o 

C_DEPS += \
./Core/Src/EnhancedFonts/Bahnschrift_SemiCondensed\ _76pt.d \
./Core/Src/EnhancedFonts/Bahnschrift_SemiCondensed_24pt.d \
./Core/Src/EnhancedFonts/arialBlack_20ptFontInfo.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/EnhancedFonts/Bahnschrift_SemiCondensed\ _76pt.o: ../Core/Src/EnhancedFonts/Bahnschrift_SemiCondensed\ _76pt.c Core/Src/EnhancedFonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/Src/EnhancedFonts/Bahnschrift_SemiCondensed _76pt.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/EnhancedFonts/%.o Core/Src/EnhancedFonts/%.su Core/Src/EnhancedFonts/%.cyclo: ../Core/Src/EnhancedFonts/%.c Core/Src/EnhancedFonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-EnhancedFonts

clean-Core-2f-Src-2f-EnhancedFonts:
	-$(RM) ./Core/Src/EnhancedFonts/Bahnschrift_SemiCondensed\ _76pt.cyclo ./Core/Src/EnhancedFonts/Bahnschrift_SemiCondensed\ _76pt.d ./Core/Src/EnhancedFonts/Bahnschrift_SemiCondensed\ _76pt.o ./Core/Src/EnhancedFonts/Bahnschrift_SemiCondensed\ _76pt.su ./Core/Src/EnhancedFonts/Bahnschrift_SemiCondensed_24pt.cyclo ./Core/Src/EnhancedFonts/Bahnschrift_SemiCondensed_24pt.d ./Core/Src/EnhancedFonts/Bahnschrift_SemiCondensed_24pt.o ./Core/Src/EnhancedFonts/Bahnschrift_SemiCondensed_24pt.su ./Core/Src/EnhancedFonts/arialBlack_20ptFontInfo.cyclo ./Core/Src/EnhancedFonts/arialBlack_20ptFontInfo.d ./Core/Src/EnhancedFonts/arialBlack_20ptFontInfo.o ./Core/Src/EnhancedFonts/arialBlack_20ptFontInfo.su

.PHONY: clean-Core-2f-Src-2f-EnhancedFonts

