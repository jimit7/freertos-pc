################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../example/src/cr_startup_lpc175x_6x.c \
../example/src/freertos_blinkyRGB_VTASKDELAY.c \
../example/src/sysinit2.c 

OBJS += \
./example/src/cr_startup_lpc175x_6x.o \
./example/src/freertos_blinkyRGB_VTASKDELAY.o \
./example/src/sysinit2.o 

C_DEPS += \
./example/src/cr_startup_lpc175x_6x.d \
./example/src/freertos_blinkyRGB_VTASKDELAY.d \
./example/src/sysinit2.d 


# Each subdirectory must supply rules for building sources it contributes
example/src/%.o: ../example/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M3 -I"/home/jpatel/Downloads/freertos-pc/lpc_chip_175x_6x/inc" -I"/home/jpatel/Downloads/freertos-pc/lpc_board_nxp_lpcxpresso_1769/inc" -I"/home/jpatel/Downloads/freertos-pc/freertos_blinkyRGB VTASKDELAY/example/inc" -I"/home/jpatel/Downloads/freertos-pc/freertos_blinkyRGB VTASKDELAY/freertos/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


