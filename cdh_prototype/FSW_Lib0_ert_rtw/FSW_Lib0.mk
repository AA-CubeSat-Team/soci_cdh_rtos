###########################################################################
## Makefile generated for Simulink model 'FSW_Lib0'. 
## 
## Makefile     : FSW_Lib0.mk
## Generated on : Fri Jan 14 15:17:31 2022
## MATLAB Coder version: 4.1 (R2018b)
## 
## Build Info:
## 
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/FSW_Lib0.elf
## Product type : executable
## Build type   : Top-Level Standalone Executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPUTER                Computer type. See the MATLAB "computer" command.
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# SHARED_OBJS             Shared Object Names

PRODUCT_NAME              = FSW_Lib0
MAKEFILE                  = FSW_Lib0.mk
COMPUTER                  = PCWIN64
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2018b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2018b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
MASTER_ANCHOR_DIR         = 
START_DIR                 = C:/Users/Nick/Documents/FSW_Builds/Build_01042022
ARCH                      = win64
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
COMPILER_COMMAND_FILE     = FSW_Lib0_comp.rsp
CMD_FILE                  = FSW_Lib0.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
SHARED_SRC_DIR            = ../slprj/ert/_sharedutils
SHARED_SRC                = $(SHARED_SRC_DIR)/*.c
SHARED_BIN_DIR            = ../slprj/ert/_sharedutils
SHARED_LIB                = $(SHARED_BIN_DIR)/rtwshared.lib
SHARED_OBJS               =  \
$(addprefix $(join $(SHARED_BIN_DIR),/), $(addsuffix .o, $(basename $(notdir $(wildcard $(SHARED_SRC_DIR)/*.c)))))

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU Tools for ARM Embedded Processors v7.2.1 | gmake (64-bit Windows)
# Supported Version(s):    
# ToolchainInfo Version:   R2018b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# TARGET_LOAD_CMD_ARGS
# TARGET_LOAD_CMD
# MW_GNU_ARM_TOOLS_PATH
# FDATASECTIONS_FLG

#-----------
# MACROS
#-----------

LIBGCC                = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-libgcc-file-name}
LIBC                  = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-file-name=libc.a}
LIBM                  = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-file-name=libm.a}
PRODUCT_BIN           = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).bin
PRODUCT_HEX           = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
CPFLAGS               = -O binary
SHELL                 = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: GNU ARM Assembler
AS_PATH = $(MW_GNU_ARM_TOOLS_PATH)
AS = $(AS_PATH)/arm-none-eabi-gcc

# C Compiler: GNU ARM C Compiler
CC_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CC = $(CC_PATH)/arm-none-eabi-gcc

# Linker: GNU ARM Linker
LD_PATH = $(MW_GNU_ARM_TOOLS_PATH)
LD = $(LD_PATH)/arm-none-eabi-g++

# C++ Compiler: GNU ARM C++ Compiler
CPP_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CPP = $(CPP_PATH)/arm-none-eabi-g++

# C++ Linker: GNU ARM C++ Linker
CPP_LD_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CPP_LD = $(CPP_LD_PATH)/arm-none-eabi-g++

# Archiver: GNU ARM Archiver
AR_PATH = $(MW_GNU_ARM_TOOLS_PATH)
AR = $(AR_PATH)/arm-none-eabi-ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = $(MEX_PATH)/mex

# Binary Converter: Binary Converter
OBJCOPYPATH = $(MW_GNU_ARM_TOOLS_PATH)
OBJCOPY = $(OBJCOPYPATH)/arm-none-eabi-objcopy

# Hex Converter: Hex Converter
OBJCOPYPATH = $(MW_GNU_ARM_TOOLS_PATH)
OBJCOPY = $(OBJCOPYPATH)/arm-none-eabi-objcopy

# Executable Size: Executable Size
EXESIZEPATH = $(MW_GNU_ARM_TOOLS_PATH)
EXESIZE = $(EXESIZEPATH)/arm-none-eabi-size

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = $(MAKE_PATH)/gmake


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /f/q
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = ruvs
ASFLAGS              = -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -Wall \
                       -x assembler-with-cpp \
                       $(ASFLAGS_ADDITIONAL) \
                       $(DEFINES) \
                       $(INCLUDES) \
                       -c
OBJCOPYFLAGS_BIN     = -O binary $(PRODUCT) $(PRODUCT_BIN)
CFLAGS               = $(FDATASECTIONS_FLG) \
                       -Wall \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -c \
                       -O0
CPPFLAGS             = -std=c++98 \
                       -fno-rtti \
                       -fno-exceptions \
                       $(FDATASECTIONS_FLG) \
                       -Wall \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -c \
                       -O0
CPP_LDFLAGS          = -Wl,--gc-sections \
                       -Wl,-Map="$(PRODUCT_NAME).map"
CPP_SHAREDLIB_LDFLAGS  =
DOWNLOAD_FLAGS       =
EXESIZE_FLAGS        = $(PRODUCT)
EXECUTE_FLAGS        =
OBJCOPYFLAGS_HEX     = -O ihex $(PRODUCT) $(PRODUCT_HEX)
LDFLAGS              = -Wl,--gc-sections \
                       -Wl,-Map="$(PRODUCT_NAME).map"
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =

#--------------------
# File extensions
#--------------------

ASM_Type1_Ext       = .S
DEP_EXT             = .dep
OBJ_EXT             = .o
ASM_EXT             = .s
DEP_EXT             = .dep
H_EXT               = .h
OBJ_EXT             = .o
C_EXT               = .c
EXE_EXT             = .elf
SHAREDLIB_EXT       = .so
CXX_EXT             = .cxx
DEP_EXT             = .dep
HPP_EXT             = .hpp
OBJ_EXT             = .o
CPP_EXT             = .cpp
UNIX_TYPE1_EXT      = .cc
UNIX_TYPE2_EXT      = .C
EXE_EXT             = .elf
SHAREDLIB_EXT       = .so
STATICLIB_EXT       = .lib
MEX_EXT             = .mexw64
MAKE_EXT            = .mk


###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/FSW_Lib0.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/FSW_Lib0_ert_rtw -IC:/Users/Nick/DOCUME~1/GitHub/soci-gnc/Lib/FSW/soar/include -IC:/Users/Nick/DOCUME~1/GitHub/soci-gnc/Src -IC:/Users/Nick/DOCUME~1/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(MATLAB_ROOT)/toolbox/dsp/include -I$(MATLAB_ROOT)/toolbox/dsp/extern/src/export/include/src -I$(MATLAB_ROOT)/toolbox/dsp/extern/src/export/include -I$(MATLAB_ROOT)/toolbox/shared/dsp/vision/matlab/include -I$(START_DIR)/slprj/ert/_sharedutils -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2018b/3P778C~1.INS/CMSIS~1.INS/CMSIS/Include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2018b/toolbox/target/SUPPOR~1/ARM_CO~1/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2018b/toolbox/target/SUPPOR~1/ARMCOR~1/SCHEDU~1/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -DMODEL=FSW_Lib0 -DNUMST=2 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=0 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -DNULL=0 -D__NO_SYSTEM_INIT -DARM_MATH_CM3=1 -D__NVIC_PRIO_BITS=3 -DEXIT_FAILURE=1 -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DRT
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=0 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1
DEFINES_IMPLIED = -DTID01EQ=0
DEFINES_SKIPFORSIL = -DNULL=0 -D__NO_SYSTEM_INIT -DARM_MATH_CM3=1 -D__NVIC_PRIO_BITS=3 -DEXIT_FAILURE=1 -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DSTACK_SIZE=64 -DRT
DEFINES_STANDARD = -DMODEL=FSW_Lib0 -DNUMST=2 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_IMPLIED) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/FSW_Lib0_ert_rtw/CrossProdMatrix_lib.c $(START_DIR)/FSW_Lib0_ert_rtw/FSW_Lib0.c $(START_DIR)/FSW_Lib0_ert_rtw/FSW_Lib0_data.c $(START_DIR)/FSW_Lib0_ert_rtw/L_inf_allocation_lib.c $(START_DIR)/FSW_Lib0_ert_rtw/MEKF_lib.c $(START_DIR)/FSW_Lib0_ert_rtw/PD_Controller_Lib.c $(START_DIR)/FSW_Lib0_ert_rtw/TRIADActivation_lib.c $(START_DIR)/FSW_Lib0_ert_rtw/asmController_lib.c $(START_DIR)/FSW_Lib0_ert_rtw/maggyroProcessing_lib.c $(START_DIR)/FSW_Lib0_ert_rtw/mode_select_lib.c $(START_DIR)/FSW_Lib0_ert_rtw/null_control_lib.c $(START_DIR)/FSW_Lib0_ert_rtw/parallel_protection_lib.c $(START_DIR)/FSW_Lib0_ert_rtw/quat_err_lib.c $(START_DIR)/FSW_Lib0_ert_rtw/quat_rectify_lib.c $(START_DIR)/FSW_Lib0_ert_rtw/rt_sys_MEKF_lib_39.c $(START_DIR)/FSW_Lib0_ert_rtw/rt_sys_MEKF_lib_49.c $(START_DIR)/FSW_Lib0_ert_rtw/rt_sys_MEKF_lib_56.c $(START_DIR)/FSW_Lib0_ert_rtw/rwa_allocation_lib.c $(START_DIR)/FSW_Lib0_ert_rtw/sunSeek_lib.c $(START_DIR)/FSW_Lib0_ert_rtw/target_generation_lib.c $(START_DIR)/FSW_Lib0_ert_rtw/target_groundpass_lib.c $(START_DIR)/FSW_Lib0_ert_rtw/twonorm.c expcone.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_1.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_2.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_aat.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_control.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_defaults.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_dump.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_global.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_info.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_order.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_post_tree.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_postorder.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_preprocess.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_valid.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/cone.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/ctrlc.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/ecos.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/equil.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/kkt.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/ldl.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/matlab_main.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/preproc.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/runecos.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/spla.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/splamm.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/timer.c C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/wright_omega.c C:/ProgramData/MATLAB/SupportPackages/R2018b/toolbox/target/supportpackages/arm_cortex_m/registry/../src/startup_gcc.c C:/ProgramData/MATLAB/SupportPackages/R2018b/toolbox/target/supportpackages/arm_cortex_m/registry/../src/system_LM3S.c C:/ProgramData/MATLAB/SupportPackages/R2018b/toolbox/target/supportpackages/arm_cortex_m/registry/../src/syscalls.c C:/ProgramData/MATLAB/SupportPackages/R2018b/toolbox/target/supportpackages/armcortexmbase/scheduler/src/SysTickScheduler.c C:/ProgramData/MATLAB/SupportPackages/R2018b/toolbox/target/supportpackages/armcortexmbase/scheduler/src/m3m4m4f_multitasking.c

MAIN_SRC = $(START_DIR)/FSW_Lib0_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = CrossProdMatrix_lib.o FSW_Lib0.o FSW_Lib0_data.o L_inf_allocation_lib.o MEKF_lib.o PD_Controller_Lib.o TRIADActivation_lib.o asmController_lib.o maggyroProcessing_lib.o mode_select_lib.o null_control_lib.o parallel_protection_lib.o quat_err_lib.o quat_rectify_lib.o rt_sys_MEKF_lib_39.o rt_sys_MEKF_lib_49.o rt_sys_MEKF_lib_56.o rwa_allocation_lib.o sunSeek_lib.o target_generation_lib.o target_groundpass_lib.o twonorm.o expcone.o amd_1.o amd_2.o amd_aat.o amd_control.o amd_defaults.o amd_dump.o amd_global.o amd_info.o amd_order.o amd_post_tree.o amd_postorder.o amd_preprocess.o amd_valid.o cone.o ctrlc.o ecos.o equil.o kkt.o ldl.o matlab_main.o preproc.o runecos.o spla.o splamm.o timer.o wright_omega.o startup_gcc.o system_LM3S.o syscalls.o SysTickScheduler.o m3m4m4f_multitasking.o

MAIN_OBJ = ert_main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = $(SHARED_LIB) C:/ProgramData/MATLAB/SupportPackages/R2018b/3P.instrset/cmsis.instrset/CMSIS/Lib/GCC/libarm_cortexM3l_math.a

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_SKIPFORSIL = -mcpu=cortex-m3 -mthumb -mlittle-endian -mthumb-interwork
CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL = -mcpu=cortex-m3 -mthumb -mlittle-endian -mthumb-interwork
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m3 -mthumb -mlittle-endian -mthumb-interwork -nostartfiles -T "C:\ProgramData\MATLAB\SupportPackages\R2018b\toolbox\target\supportpackages\arm_cortex_m\registry\../src/arm_cortex_m3_qemu_gcc.ld"

CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m3 -mthumb -mlittle-endian -mthumb-interwork -nostartfiles -T "C:\ProgramData\MATLAB\SupportPackages\R2018b\toolbox\target\supportpackages\arm_cortex_m\registry\../src/arm_cortex_m3_qemu_gcc.ld"

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------
# Linker
#-----------

LDFLAGS_SKIPFORSIL = -mcpu=cortex-m3 -mthumb -mlittle-endian -mthumb-interwork -nostartfiles -T "C:\ProgramData\MATLAB\SupportPackages\R2018b\toolbox\target\supportpackages\arm_cortex_m\registry\../src/arm_cortex_m3_qemu_gcc.ld"

LDFLAGS += $(LDFLAGS_SKIPFORSIL)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m3 -mthumb -mlittle-endian -mthumb-interwork -nostartfiles -T "C:\ProgramData\MATLAB\SupportPackages\R2018b\toolbox\target\supportpackages\arm_cortex_m\registry\../src/arm_cortex_m3_qemu_gcc.ld"

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


ALL_DEPS:=$(patsubst %$(OBJ_EXT),%$(DEP_EXT),$(ALL_OBJS))
all:

ifndef DISABLE_GCC_FUNCTION_DATA_SECTIONS
FDATASECTIONS_FLG := -ffunction-sections -fdata-sections
endif



-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk
-include ../../codertarget_assembly_flags.mk
-include $(ALL_DEPS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild postbuild download execute


all : build postbuild
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


postbuild : build
	@echo "### Invoking postbuild tool "Binary Converter" ..."
	$(OBJCOPY) $(OBJCOPYFLAGS_BIN)
	@echo "### Done invoking postbuild tool."
	@echo "### Invoking postbuild tool "Hex Converter" ..."
	$(OBJCOPY) $(OBJCOPYFLAGS_HEX)
	@echo "### Done invoking postbuild tool."
	@echo "### Invoking postbuild tool "Executable Size" ..."
	$(EXESIZE) $(EXESIZE_FLAGS)
	@echo "### Done invoking postbuild tool."


download : postbuild


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o $(PRODUCT) @$(CMD_FILE) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : %.s
	$(AS) $(ASFLAGS) -o $@ $<


%.o : %.S
	$(AS) $(ASFLAGS) -o $@ $<


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : %.cc
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : %.C
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : %.cxx
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.S
	$(AS) $(ASFLAGS) -o $@ $<


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : C:/Users/Nick/Documents/GitHub/soci-gnc/Src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : C:/Users/Nick/Documents/GitHub/soci-gnc/Src/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.o : C:/Users/Nick/Documents/GitHub/soci-gnc/Src/%.S
	$(AS) $(ASFLAGS) -o $@ $<


%.o : C:/Users/Nick/Documents/GitHub/soci-gnc/Src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : C:/Users/Nick/Documents/GitHub/soci-gnc/Src/%.cc
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : C:/Users/Nick/Documents/GitHub/soci-gnc/Src/%.C
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : C:/Users/Nick/Documents/GitHub/soci-gnc/Src/%.cxx
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.o : $(START_DIR)/%.S
	$(AS) $(ASFLAGS) -o $@ $<


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(START_DIR)/%.C
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(START_DIR)/FSW_Lib0_ert_rtw/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(START_DIR)/FSW_Lib0_ert_rtw/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.o : $(START_DIR)/FSW_Lib0_ert_rtw/%.S
	$(AS) $(ASFLAGS) -o $@ $<


%.o : $(START_DIR)/FSW_Lib0_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(START_DIR)/FSW_Lib0_ert_rtw/%.cc
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(START_DIR)/FSW_Lib0_ert_rtw/%.C
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(START_DIR)/FSW_Lib0_ert_rtw/%.cxx
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.o : C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/%.S
	$(AS) $(ASFLAGS) -o $@ $<


%.o : C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/%.cc
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/%.C
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : C:/Users/Nick/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/%.cxx
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/rtw/c/src/%.S
	$(AS) $(ASFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cc
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/rtw/c/src/%.C
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cxx
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/simulink/src/%.S
	$(AS) $(ASFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/simulink/src/%.cc
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/simulink/src/%.C
	$(CPP) $(CPPFLAGS) -o $@ $<


%.o : $(MATLAB_ROOT)/simulink/src/%.cxx
	$(CPP) $(CPPFLAGS) -o $@ $<


startup_gcc.o : C:/ProgramData/MATLAB/SupportPackages/R2018b/toolbox/target/supportpackages/arm_cortex_m/registry/../src/startup_gcc.c
	$(CC) $(CFLAGS) -o $@ $<


system_LM3S.o : C:/ProgramData/MATLAB/SupportPackages/R2018b/toolbox/target/supportpackages/arm_cortex_m/registry/../src/system_LM3S.c
	$(CC) $(CFLAGS) -o $@ $<


syscalls.o : C:/ProgramData/MATLAB/SupportPackages/R2018b/toolbox/target/supportpackages/arm_cortex_m/registry/../src/syscalls.c
	$(CC) $(CFLAGS) -o $@ $<


SysTickScheduler.o : C:/ProgramData/MATLAB/SupportPackages/R2018b/toolbox/target/supportpackages/armcortexmbase/scheduler/src/SysTickScheduler.c
	$(CC) $(CFLAGS) -o $@ $<


m3m4m4f_multitasking.o : C:/ProgramData/MATLAB/SupportPackages/R2018b/toolbox/target/supportpackages/armcortexmbase/scheduler/src/m3m4m4f_multitasking.c
	$(CC) $(CFLAGS) -o $@ $<


$(SHARED_BIN_DIR)/%.o : $(SHARED_SRC_DIR)/%.c
	@echo "### Compiling $< ..."
	$(CC) $(CFLAGS) -o $@ $<


#---------------------------
# SHARED UTILITY LIBRARY
#---------------------------

$(SHARED_LIB) : $(SHARED_OBJS)
	@echo "### Creating shared utilities library "$(SHARED_LIB)" ..."
	$(AR) $(ARFLAGS)  $(SHARED_LIB) $(SHARED_OBJS)
	@echo "### Created: $(SHARED_LIB)"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### OBJCOPYFLAGS_BIN = $(OBJCOPYFLAGS_BIN)"
	@echo "### OBJCOPYFLAGS_HEX = $(OBJCOPYFLAGS_HEX)"
	@echo "### EXESIZE_FLAGS = $(EXESIZE_FLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(RM) *.dep
	$(ECHO) "### Deleted all derived files."


