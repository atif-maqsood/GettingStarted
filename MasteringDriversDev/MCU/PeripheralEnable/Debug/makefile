################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
PeripheralEnable.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
PeripheralEnable.list \

OBJCOPY_BIN += \
PeripheralEnable.bin \


# All Target
all: PeripheralEnable.elf secondary-outputs

# Tool invocations
PeripheralEnable.elf: $(OBJS) $(USER_OBJS) D:\Learning\MasteringDriversDev\MCU\PeripheralEnable\STM32F767ZITX_FLASH.ld
	arm-none-eabi-gcc -o "PeripheralEnable.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"D:\Learning\MasteringDriversDev\MCU\PeripheralEnable\STM32F767ZITX_FLASH.ld" --specs=nosys.specs -Wl,-Map="PeripheralEnable.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

PeripheralEnable.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "PeripheralEnable.list"
	@echo 'Finished building: $@'
	@echo ' '

PeripheralEnable.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "PeripheralEnable.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
