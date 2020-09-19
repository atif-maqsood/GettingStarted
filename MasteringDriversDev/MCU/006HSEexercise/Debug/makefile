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
006HSEexercise.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
006HSEexercise.list \

OBJCOPY_BIN += \
006HSEexercise.bin \


# All Target
all: 006HSEexercise.elf secondary-outputs

# Tool invocations
006HSEexercise.elf: $(OBJS) $(USER_OBJS) D:\Learning\MasteringDriversDev\MCU\006HSEexercise\STM32F767ZITX_FLASH.ld
	arm-none-eabi-gcc -o "006HSEexercise.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"D:\Learning\MasteringDriversDev\MCU\006HSEexercise\STM32F767ZITX_FLASH.ld" --specs=nosys.specs -Wl,-Map="006HSEexercise.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

006HSEexercise.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "006HSEexercise.list"
	@echo 'Finished building: $@'
	@echo ' '

006HSEexercise.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "006HSEexercise.bin"
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
