################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_gpio.c \
../drivers/fsl_lpi2c.c \
../drivers/fsl_lpspi.c \
../drivers/fsl_lpuart.c \
../drivers/fsl_semc.c 

OBJS += \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_gpio.o \
./drivers/fsl_lpi2c.o \
./drivers/fsl_lpspi.o \
./drivers/fsl_lpuart.o \
./drivers/fsl_semc.o 

C_DEPS += \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_gpio.d \
./drivers/fsl_lpi2c.d \
./drivers/fsl_lpspi.d \
./drivers/fsl_lpuart.d \
./drivers/fsl_semc.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MIMXRT1052DVL6B -DCPU_MIMXRT1052DVL6B_cm7 -DSDK_DEBUGCONSOLE=1 -DPRINTF_FLOAT_ENABLE=0 -DSCANF_FLOAT_ENABLE=0 -DPRINTF_ADVANCED_ENABLE=0 -DSCANF_ADVANCED_ENABLE=0 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DFSL_RTOS_FREE_RTOS -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSERIAL_PORT_TYPE_UART=1 -I"/Users/stlp/Desktop/CubeSat/soci_cdh_rtos/cdh_peripherals_test/drivers" -I"/Users/stlp/Desktop/CubeSat/soci_cdh_rtos/cdh_peripherals_test/utilities" -I"/Users/stlp/Desktop/CubeSat/soci_cdh_rtos/cdh_peripherals_test/device" -I"/Users/stlp/Desktop/CubeSat/soci_cdh_rtos/cdh_peripherals_test/CMSIS" -I"/Users/stlp/Desktop/CubeSat/soci_cdh_rtos/cdh_peripherals_test/xip" -I"/Users/stlp/Desktop/CubeSat/soci_cdh_rtos/cdh_peripherals_test/component/serial_manager" -I"/Users/stlp/Desktop/CubeSat/soci_cdh_rtos/cdh_peripherals_test/component/lists" -I"/Users/stlp/Desktop/CubeSat/soci_cdh_rtos/cdh_peripherals_test/component/uart" -I"/Users/stlp/Desktop/CubeSat/soci_cdh_rtos/cdh_peripherals_test/drivers" -I"/Users/stlp/Desktop/CubeSat/soci_cdh_rtos/cdh_peripherals_test/utilities" -I"/Users/stlp/Desktop/CubeSat/soci_cdh_rtos/cdh_peripherals_test/device" -I"/Users/stlp/Desktop/CubeSat/soci_cdh_rtos/cdh_peripherals_test/CMSIS" -I"/Users/stlp/Desktop/CubeSat/soci_cdh_rtos/cdh_peripherals_test/xip" -I"/Users/stlp/Desktop/CubeSat/soci_cdh_rtos/cdh_peripherals_test/component/serial_manager" -I"/Users/stlp/Desktop/CubeSat/soci_cdh_rtos/cdh_peripherals_test/component/lists" -I"/Users/stlp/Desktop/CubeSat/soci_cdh_rtos/cdh_peripherals_test/component/uart" -I../board -I../drivers/freertos -I../source -I../ -I../drivers -I../device -I../CMSIS -I../amazon-freertos/include -I../amazon-freertos/FreeRTOS/portable -I../utilities -I../component/serial_manager -I../component/uart -I../component/lists -I../xip -O0 -fno-common -g3 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


