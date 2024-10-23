################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Embedded Systems 1 Pruefungsprojekt
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Embedded\ Systems\ 1\ Pruefungsprojekt.elf \

MAP_FILES += \
Embedded\ Systems\ 1\ Pruefungsprojekt.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Embedded\ Systems\ 1\ Pruefungsprojekt.list \


# All Target
all: main-build

# Main-build Target
main-build: Embedded\ Systems\ 1\ Pruefungsprojekt.elf secondary-outputs

# Tool invocations
Embedded\ Systems\ 1\ Pruefungsprojekt.elf Embedded\ Systems\ 1\ Pruefungsprojekt.map: $(OBJS) $(USER_OBJS) /Users/csuser/STM32CubeIDE/workspace_1.13.2/Embedded\ Systems\ 1\ Pruefungsprojekt/STM32F103RBTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Embedded Systems 1 Pruefungsprojekt.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"/Users/csuser/STM32CubeIDE/workspace_1.13.2/Embedded Systems 1 Pruefungsprojekt/STM32F103RBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Embedded Systems 1 Pruefungsprojekt.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Embedded\ Systems\ 1\ Pruefungsprojekt.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Embedded Systems 1 Pruefungsprojekt.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Embedded\ Systems\ 1\ Pruefungsprojekt.elf Embedded\ Systems\ 1\ Pruefungsprojekt.list Embedded\ Systems\ 1\ Pruefungsprojekt.map Embedded\\ Systems\\ 1\\ Pruefungsprojekt.elf default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
