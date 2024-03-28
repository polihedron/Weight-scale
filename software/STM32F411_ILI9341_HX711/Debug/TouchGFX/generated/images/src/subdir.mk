################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/BitmapDatabase.cpp \
../TouchGFX/generated/images/src/SVGDatabase.cpp \
../TouchGFX/generated/images/src/image_back_black.cpp \
../TouchGFX/generated/images/src/image_back_white.cpp \
../TouchGFX/generated/images/src/image_keyboard_background.cpp \
../TouchGFX/generated/images/src/image_keyboard_key_delete_highlighted.cpp \
../TouchGFX/generated/images/src/image_keyboard_key_exit.cpp \
../TouchGFX/generated/images/src/image_keyboard_key_exit_highlighted.cpp \
../TouchGFX/generated/images/src/image_keyboard_key_highlighted.cpp \
../TouchGFX/generated/images/src/image_keyboard_key_ok.cpp \
../TouchGFX/generated/images/src/image_keyboard_key_ok_highlighted.cpp \
../TouchGFX/generated/images/src/image_reset_black.cpp \
../TouchGFX/generated/images/src/image_reset_white.cpp \
../TouchGFX/generated/images/src/image_save_black60.cpp \
../TouchGFX/generated/images/src/image_save_white60.cpp \
../TouchGFX/generated/images/src/image_settings_black.cpp \
../TouchGFX/generated/images/src/image_settings_white.cpp 

OBJS += \
./TouchGFX/generated/images/src/BitmapDatabase.o \
./TouchGFX/generated/images/src/SVGDatabase.o \
./TouchGFX/generated/images/src/image_back_black.o \
./TouchGFX/generated/images/src/image_back_white.o \
./TouchGFX/generated/images/src/image_keyboard_background.o \
./TouchGFX/generated/images/src/image_keyboard_key_delete_highlighted.o \
./TouchGFX/generated/images/src/image_keyboard_key_exit.o \
./TouchGFX/generated/images/src/image_keyboard_key_exit_highlighted.o \
./TouchGFX/generated/images/src/image_keyboard_key_highlighted.o \
./TouchGFX/generated/images/src/image_keyboard_key_ok.o \
./TouchGFX/generated/images/src/image_keyboard_key_ok_highlighted.o \
./TouchGFX/generated/images/src/image_reset_black.o \
./TouchGFX/generated/images/src/image_reset_white.o \
./TouchGFX/generated/images/src/image_save_black60.o \
./TouchGFX/generated/images/src/image_save_white60.o \
./TouchGFX/generated/images/src/image_settings_black.o \
./TouchGFX/generated/images/src/image_settings_white.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/BitmapDatabase.d \
./TouchGFX/generated/images/src/SVGDatabase.d \
./TouchGFX/generated/images/src/image_back_black.d \
./TouchGFX/generated/images/src/image_back_white.d \
./TouchGFX/generated/images/src/image_keyboard_background.d \
./TouchGFX/generated/images/src/image_keyboard_key_delete_highlighted.d \
./TouchGFX/generated/images/src/image_keyboard_key_exit.d \
./TouchGFX/generated/images/src/image_keyboard_key_exit_highlighted.d \
./TouchGFX/generated/images/src/image_keyboard_key_highlighted.d \
./TouchGFX/generated/images/src/image_keyboard_key_ok.d \
./TouchGFX/generated/images/src/image_keyboard_key_ok_highlighted.d \
./TouchGFX/generated/images/src/image_reset_black.d \
./TouchGFX/generated/images/src/image_reset_white.d \
./TouchGFX/generated/images/src/image_save_black60.d \
./TouchGFX/generated/images/src/image_save_white60.d \
./TouchGFX/generated/images/src/image_settings_black.d \
./TouchGFX/generated/images/src/image_settings_white.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/%.o TouchGFX/generated/images/src/%.su TouchGFX/generated/images/src/%.cyclo: ../TouchGFX/generated/images/src/%.cpp TouchGFX/generated/images/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/generated/videos/include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src

clean-TouchGFX-2f-generated-2f-images-2f-src:
	-$(RM) ./TouchGFX/generated/images/src/BitmapDatabase.cyclo ./TouchGFX/generated/images/src/BitmapDatabase.d ./TouchGFX/generated/images/src/BitmapDatabase.o ./TouchGFX/generated/images/src/BitmapDatabase.su ./TouchGFX/generated/images/src/SVGDatabase.cyclo ./TouchGFX/generated/images/src/SVGDatabase.d ./TouchGFX/generated/images/src/SVGDatabase.o ./TouchGFX/generated/images/src/SVGDatabase.su ./TouchGFX/generated/images/src/image_back_black.cyclo ./TouchGFX/generated/images/src/image_back_black.d ./TouchGFX/generated/images/src/image_back_black.o ./TouchGFX/generated/images/src/image_back_black.su ./TouchGFX/generated/images/src/image_back_white.cyclo ./TouchGFX/generated/images/src/image_back_white.d ./TouchGFX/generated/images/src/image_back_white.o ./TouchGFX/generated/images/src/image_back_white.su ./TouchGFX/generated/images/src/image_keyboard_background.cyclo ./TouchGFX/generated/images/src/image_keyboard_background.d ./TouchGFX/generated/images/src/image_keyboard_background.o ./TouchGFX/generated/images/src/image_keyboard_background.su ./TouchGFX/generated/images/src/image_keyboard_key_delete_highlighted.cyclo ./TouchGFX/generated/images/src/image_keyboard_key_delete_highlighted.d ./TouchGFX/generated/images/src/image_keyboard_key_delete_highlighted.o ./TouchGFX/generated/images/src/image_keyboard_key_delete_highlighted.su ./TouchGFX/generated/images/src/image_keyboard_key_exit.cyclo ./TouchGFX/generated/images/src/image_keyboard_key_exit.d ./TouchGFX/generated/images/src/image_keyboard_key_exit.o ./TouchGFX/generated/images/src/image_keyboard_key_exit.su ./TouchGFX/generated/images/src/image_keyboard_key_exit_highlighted.cyclo ./TouchGFX/generated/images/src/image_keyboard_key_exit_highlighted.d ./TouchGFX/generated/images/src/image_keyboard_key_exit_highlighted.o ./TouchGFX/generated/images/src/image_keyboard_key_exit_highlighted.su ./TouchGFX/generated/images/src/image_keyboard_key_highlighted.cyclo ./TouchGFX/generated/images/src/image_keyboard_key_highlighted.d ./TouchGFX/generated/images/src/image_keyboard_key_highlighted.o ./TouchGFX/generated/images/src/image_keyboard_key_highlighted.su ./TouchGFX/generated/images/src/image_keyboard_key_ok.cyclo ./TouchGFX/generated/images/src/image_keyboard_key_ok.d ./TouchGFX/generated/images/src/image_keyboard_key_ok.o ./TouchGFX/generated/images/src/image_keyboard_key_ok.su ./TouchGFX/generated/images/src/image_keyboard_key_ok_highlighted.cyclo ./TouchGFX/generated/images/src/image_keyboard_key_ok_highlighted.d ./TouchGFX/generated/images/src/image_keyboard_key_ok_highlighted.o ./TouchGFX/generated/images/src/image_keyboard_key_ok_highlighted.su ./TouchGFX/generated/images/src/image_reset_black.cyclo ./TouchGFX/generated/images/src/image_reset_black.d ./TouchGFX/generated/images/src/image_reset_black.o ./TouchGFX/generated/images/src/image_reset_black.su ./TouchGFX/generated/images/src/image_reset_white.cyclo ./TouchGFX/generated/images/src/image_reset_white.d ./TouchGFX/generated/images/src/image_reset_white.o ./TouchGFX/generated/images/src/image_reset_white.su ./TouchGFX/generated/images/src/image_save_black60.cyclo ./TouchGFX/generated/images/src/image_save_black60.d ./TouchGFX/generated/images/src/image_save_black60.o ./TouchGFX/generated/images/src/image_save_black60.su ./TouchGFX/generated/images/src/image_save_white60.cyclo ./TouchGFX/generated/images/src/image_save_white60.d ./TouchGFX/generated/images/src/image_save_white60.o ./TouchGFX/generated/images/src/image_save_white60.su ./TouchGFX/generated/images/src/image_settings_black.cyclo ./TouchGFX/generated/images/src/image_settings_black.d ./TouchGFX/generated/images/src/image_settings_black.o ./TouchGFX/generated/images/src/image_settings_black.su ./TouchGFX/generated/images/src/image_settings_white.cyclo ./TouchGFX/generated/images/src/image_settings_white.d ./TouchGFX/generated/images/src/image_settings_white.o ./TouchGFX/generated/images/src/image_settings_white.su

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src

