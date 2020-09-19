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
002DebuggingProject.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
002DebuggingProject.list \

OBJCOPY_BIN += \
002DebuggingProject.bin \


# All Target
all: 002DebuggingProject.elf secondary-outputs

# Tool invocations
002DebuggingProject.elf: $(OBJS) $(USER_OBJS) D:\Learning\MasteringDriversDev\MCU\002DebuggingProject\STM32F767ZITX_FLASH.ld
	arm-none-eabi-gcc -o "002DebuggingProject.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"D:\Learning\MasteringDriversDev\MCU\002DebuggingProject\STM32F767ZITX_FLASH.ld" --specs=nosys.specs -Wl,-Map="002DebuggingProject.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

002DebuggingProject.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "002DebuggingProject.list"
	@echo 'Finished building: $@'
	@echo ' '

002DebuggingProject.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "002DebuggingProject.bin"
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
