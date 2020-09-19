################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/Src/Stm32F7xxRcc.c \
../drivers/Src/stm32f7xx_gpio.c \
../drivers/Src/stm32f7xx_i2c.c \
../drivers/Src/stm32f7xx_spi.c 

OBJS += \
./drivers/Src/Stm32F7xxRcc.o \
./drivers/Src/stm32f7xx_gpio.o \
./drivers/Src/stm32f7xx_i2c.o \
./drivers/Src/stm32f7xx_spi.o 

C_DEPS += \
./drivers/Src/Stm32F7xxRcc.d \
./drivers/Src/stm32f7xx_gpio.d \
./drivers/Src/stm32f7xx_i2c.d \
./drivers/Src/stm32f7xx_spi.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/Src/Stm32F7xxRcc.o: ../drivers/Src/Stm32F7xxRcc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DNUCLEO_F767ZI -DSTM32F7 -DDEBUG -DSTM32F767ZITx -c -I../Inc -I"D:/Learning/MasteringDriversDev/MCU/STM32F7Drivers/drivers/Inc" -I"../STM32F7Drivers/drivers/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/Src/Stm32F7xxRcc.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
drivers/Src/stm32f7xx_gpio.o: ../drivers/Src/stm32f7xx_gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DNUCLEO_F767ZI -DSTM32F7 -DDEBUG -DSTM32F767ZITx -c -I../Inc -I"D:/Learning/MasteringDriversDev/MCU/STM32F7Drivers/drivers/Inc" -I"../STM32F7Drivers/drivers/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/Src/stm32f7xx_gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
drivers/Src/stm32f7xx_i2c.o: ../drivers/Src/stm32f7xx_i2c.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DNUCLEO_F767ZI -DSTM32F7 -DDEBUG -DSTM32F767ZITx -c -I../Inc -I"D:/Learning/MasteringDriversDev/MCU/STM32F7Drivers/drivers/Inc" -I"../STM32F7Drivers/drivers/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/Src/stm32f7xx_i2c.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
drivers/Src/stm32f7xx_spi.o: ../drivers/Src/stm32f7xx_spi.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DNUCLEO_F767ZI -DSTM32F7 -DDEBUG -DSTM32F767ZITx -c -I../Inc -I"D:/Learning/MasteringDriversDev/MCU/STM32F7Drivers/drivers/Inc" -I"../STM32F7Drivers/drivers/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/Src/stm32f7xx_spi.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

