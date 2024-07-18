################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include app/src/subdir.mk
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


BUILD_ARTIFACT_NAME := bare-metal_app_pwm_hw_nucleo-F103rb
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
bare-metal_app_pwm_hw_nucleo-F103rb.elf \

MAP_FILES += \
bare-metal_app_pwm_hw_nucleo-F103rb.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
bare-metal_app_pwm_hw_nucleo-F103rb.list \


# All Target
all: main-build

# Main-build Target
main-build: bare-metal_app_pwm_hw_nucleo-F103rb.elf secondary-outputs

# Tool invocations
bare-metal_app_pwm_hw_nucleo-F103rb.elf bare-metal_app_pwm_hw_nucleo-F103rb.map: $(OBJS) $(USER_OBJS) C:\Users\lococ\OneDrive\ -\ fi.uba.ar\Fiuba\Taller\ de\ Sistemas\ Embebidos\Workspace\Ejemplos\ de\ Clase\bare-metal_app_pwm_hw_nucleo-F103rb\bare-metal_app_pwm_hw_nucleo-F103rb\STM32F103RBTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "bare-metal_app_pwm_hw_nucleo-F103rb.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\lococ\OneDrive - fi.uba.ar\Fiuba\Taller de Sistemas Embebidos\Workspace\Ejemplos de Clase\bare-metal_app_pwm_hw_nucleo-F103rb\bare-metal_app_pwm_hw_nucleo-F103rb\STM32F103RBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="bare-metal_app_pwm_hw_nucleo-F103rb.map" -Wl,--gc-sections -static -specs=rdimon.specs --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

bare-metal_app_pwm_hw_nucleo-F103rb.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "bare-metal_app_pwm_hw_nucleo-F103rb.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) bare-metal_app_pwm_hw_nucleo-F103rb.elf bare-metal_app_pwm_hw_nucleo-F103rb.list bare-metal_app_pwm_hw_nucleo-F103rb.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
