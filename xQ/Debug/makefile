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
all: xQ.axf

# Tool invocations
xQ.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/jpatel/freertos-pc/lpc_chip_175x_6x/Debug" -L"/home/jpatel/freertos-pc/lpc_board_nxp_lpcxpresso_1769/Debug" -Xlinker -Map="xQ.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "xQ_Debug.ld" -o "xQ.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) xQ.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "xQ.axf"; # arm-none-eabi-objcopy -v -O binary "xQ.axf" "xQ.bin" ; # checksum -p LPC1769 -d "xQ.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
