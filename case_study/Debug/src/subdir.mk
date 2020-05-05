################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/admissionsystem.cpp \
../src/capacities.cpp \
../src/center.cpp \
../src/course.cpp \
../src/eligibilities.cpp \
../src/main.cpp \
../src/preferences.cpp \
../src/student.cpp 

OBJS += \
./src/admissionsystem.o \
./src/capacities.o \
./src/center.o \
./src/course.o \
./src/eligibilities.o \
./src/main.o \
./src/preferences.o \
./src/student.o 

CPP_DEPS += \
./src/admissionsystem.d \
./src/capacities.d \
./src/center.d \
./src/course.d \
./src/eligibilities.d \
./src/main.d \
./src/preferences.d \
./src/student.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


