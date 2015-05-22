################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LazIR-Brain-v1.0.cpp \
../src/LazIRDatabase.cpp 

OBJS += \
./src/LazIR-Brain-v1.0.o \
./src/LazIRDatabase.o 

CPP_DEPS += \
./src/LazIR-Brain-v1.0.d \
./src/LazIRDatabase.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


