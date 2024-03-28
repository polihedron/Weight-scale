################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button.cpp \
../TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button_pressed.cpp \
../TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_icon_button.cpp \
../TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_icon_button_pressed.cpp 

OBJS += \
./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button.o \
./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button_pressed.o \
./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_icon_button.o \
./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_icon_button_pressed.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button.d \
./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button_pressed.d \
./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_icon_button.d \
./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_icon_button_pressed.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/__designer/%.o TouchGFX/generated/images/src/__designer/%.su TouchGFX/generated/images/src/__designer/%.cyclo: ../TouchGFX/generated/images/src/__designer/%.cpp TouchGFX/generated/images/src/__designer/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/generated/videos/include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__designer

clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__designer:
	-$(RM) ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button.cyclo ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button.d ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button.o ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button.su ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button_pressed.cyclo ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button_pressed.d ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button_pressed.o ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button_pressed.su ./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_icon_button.cyclo ./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_icon_button.d ./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_icon_button.o ./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_icon_button.su ./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_icon_button_pressed.cyclo ./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_icon_button_pressed.d ./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_icon_button_pressed.o ./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_icon_button_pressed.su

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__designer

