################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../xip/evkmimxrt1020_flexspi_nor_config.c \
../xip/fsl_flexspi_nor_boot.c 

OBJS += \
./xip/evkmimxrt1020_flexspi_nor_config.o \
./xip/fsl_flexspi_nor_boot.o 

C_DEPS += \
./xip/evkmimxrt1020_flexspi_nor_config.d \
./xip/fsl_flexspi_nor_boot.d 


# Each subdirectory must supply rules for building sources it contributes
xip/%.o: ../xip/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MIMXRT1021DAG5A -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DSERIAL_PORT_TYPE_UART=1 -DFSL_RTOS_FREE_RTOS -DCPU_MIMXRT1021DAG5A_cm7 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_DEBUGCONSOLE=0 -I"/Users/stlp/Documents/MCUX_workspace/soci_cdh_rtos/cdh_prototype/board" -I"/Users/stlp/Documents/MCUX_workspace/soci_cdh_rtos/cdh_prototype/source" -I"/Users/stlp/Documents/MCUX_workspace/soci_cdh_rtos/cdh_prototype" -I"/Users/stlp/Documents/MCUX_workspace/soci_cdh_rtos/cdh_prototype/drivers" -I"/Users/stlp/Documents/MCUX_workspace/soci_cdh_rtos/cdh_prototype/device" -I"/Users/stlp/Documents/MCUX_workspace/soci_cdh_rtos/cdh_prototype/CMSIS" -I"/Users/stlp/Documents/MCUX_workspace/soci_cdh_rtos/cdh_prototype/freertos/freertos_kernel/include" -I"/Users/stlp/Documents/MCUX_workspace/soci_cdh_rtos/cdh_prototype/freertos/freertos_kernel/portable/GCC/ARM_CM4F" -I"/Users/stlp/Documents/MCUX_workspace/soci_cdh_rtos/cdh_prototype/utilities" -I"/Users/stlp/Documents/MCUX_workspace/soci_cdh_rtos/cdh_prototype/component/serial_manager" -I"/Users/stlp/Documents/MCUX_workspace/soci_cdh_rtos/cdh_prototype/component/lists" -I"/Users/stlp/Documents/MCUX_workspace/soci_cdh_rtos/cdh_prototype/component/uart" -I"/Users/stlp/Documents/MCUX_workspace/soci_cdh_rtos/cdh_prototype/xip" -O0 -fno-common -g3 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


