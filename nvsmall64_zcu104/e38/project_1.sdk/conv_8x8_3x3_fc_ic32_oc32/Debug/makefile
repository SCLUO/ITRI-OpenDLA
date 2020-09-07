################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
ELFSIZE += \
conv_8x8_3x3_fc_ic32_oc32.elf.size \


# All Target
all: conv_8x8_3x3_fc_ic32_oc32.elf secondary-outputs

# Tool invocations
conv_8x8_3x3_fc_ic32_oc32.elf: $(OBJS) ../src/lscript.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM v8 gcc linker'
	aarch64-none-elf-gcc -Wl,-T -Wl,../src/lscript.ld -L../../standalone_bsp_0/psu_cortexa53_0/lib -o "conv_8x8_3x3_fc_ic32_oc32.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

conv_8x8_3x3_fc_ic32_oc32.elf.size: conv_8x8_3x3_fc_ic32_oc32.elf
	@echo 'Invoking: ARM v8 Print Size'
	aarch64-none-elf-size conv_8x8_3x3_fc_ic32_oc32.elf  |tee "conv_8x8_3x3_fc_ic32_oc32.elf.size"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(S_UPPER_DEPS)$(C_DEPS)$(ELFSIZE) conv_8x8_3x3_fc_ic32_oc32.elf
	-@echo ' '

secondary-outputs: $(ELFSIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
