################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include freertos/src/subdir.mk
-include example/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: freertos_blinkyRGB\ mutex.axf

# Tool invocations
freertos_blinkyRGB\ mutex.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/jpatel/freertos-pc/lpc_chip_175x_6x/Debug" -L"/home/jpatel/freertos-pc/lpc_board_nxp_lpcxpresso_1769/Debug" -Xlinker -Map="freertos_blinkyRGB mutex.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "freertos_blinky_Debug.ld" -o "freertos_blinkyRGB mutex.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) "freertos_blinkyRGB mutex.axf"
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "freertos_blinkyRGB mutex.axf"; # arm-none-eabi-objcopy -v -O binary "freertos_blinkyRGB mutex.axf" "freertos_blinkyRGB mutex.bin" ; # checksum -p LPC1769 -d "freertos_blinkyRGB mutex.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
