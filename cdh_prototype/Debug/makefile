################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include xip/subdir.mk
-include wrappers/subdir.mk
-include utilities/subdir.mk
-include tasks/subdir.mk
-include startup/subdir.mk
-include source/subdir.mk
-include drivers/freertos/subdir.mk
-include drivers/subdir.mk
-include device/subdir.mk
-include component/uart/subdir.mk
-include component/serial_manager/subdir.mk
-include component/lists/subdir.mk
-include board/subdir.mk
-include FSW_Lib_ert_rtw/subdir.mk
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
all: cdh_rt1020_prototype.axf

# Tool invocations
cdh_rt1020_prototype.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="cdh_rt1020_prototype.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -T "cdh_rt1020_prototype_Debug.ld" -o "cdh_rt1020_prototype.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) cdh_rt1020_prototype.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "cdh_rt1020_prototype.axf"; # arm-none-eabi-objcopy -v -O binary "cdh_rt1020_prototype.axf" "cdh_rt1020_prototype.bin" ; # checksum -p MIMXRT1021xxxxx -d "cdh_rt1020_prototype.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
