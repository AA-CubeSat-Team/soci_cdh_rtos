################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../device/system_MIMXRT1021.c 

OBJS += \
./device/system_MIMXRT1021.o 

C_DEPS += \
./device/system_MIMXRT1021.d 


# Each subdirectory must supply rules for building sources it contributes
device/%.o: ../device/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MIMXRT1021DAG5A -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DSERIAL_PORT_TYPE_UART=1 -DFSL_RTOS_FREE_RTOS -DCPU_MIMXRT1021DAG5A_cm7 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_DEBUGCONSOLE=0 -DSDK_OS_FREE_RTOS -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\component\lists" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\component\serial_manager" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\drivers" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\utilities" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\component\uart" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\CMSIS" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\freertos\freertos_kernel\include" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\freertos\freertos_kernel\portable\GCC\ARM_CM4F" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\source" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\xip" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\device" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\component\lists" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\component\serial_manager" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\utilities" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\component\uart" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\drivers" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\CMSIS" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\freertos\freertos_kernel\include" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\freertos\freertos_kernel\portable\GCC\ARM_CM4F" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\source" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\xip" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\device" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\board" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\tasks" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\wrappers" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype" -I"C:\Users\USER\Desktop\UW\AACT\soci_cdh_rtos\cdh_prototype\drivers\freertos" -O0 -fno-common -g3 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


