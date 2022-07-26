###########################################################################
## Makefile generated for component 'FSW_Lib'. 
## 
## Makefile     : FSW_Lib.mk
## Generated on : Tue May 24 14:45:54 2022
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/FSW_Lib.exe
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file

PRODUCT_NAME              = FSW_Lib
MAKEFILE                  = FSW_Lib.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2020b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2020b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/Nick/Documents/GitHub/soci-gnc/Build
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
COMPILER_COMMAND_FILE     = FSW_Lib_comp.rsp
CMD_FILE                  = FSW_Lib.rsp
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          MinGW64 | gmake (64-bit Windows)
# Supported Version(s):    6.x
# ToolchainInfo Version:   2020b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS
# MINGW_ROOT
# MINGW_C_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS            = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX        = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS        = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX    = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow
MW_EXTERNLIB_DIR      = $(MATLAB_ROOT)/extern/lib/win64/mingw64
SHELL                 = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lws2_32

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC_PATH = $(MINGW_ROOT)
CC = "$(CC_PATH)/gcc"

# Linker: GNU Linker
LD_PATH = $(MINGW_ROOT)
LD = "$(LD_PATH)/g++"

# C++ Compiler: GNU C++ Compiler
CPP_PATH = $(MINGW_ROOT)
CPP = "$(CPP_PATH)/g++"

# C++ Linker: GNU C++ Linker
CPP_LD_PATH = $(MINGW_ROOT)
CPP_LD = "$(CPP_LD_PATH)/g++"

# Archiver: GNU Archiver
AR_PATH = $(MINGW_ROOT)
AR = "$(AR_PATH)/ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

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
RM                  = @del
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------
# "Debug" Build Configuration
#--------------------------------

ARFLAGS              = ruvs \
                       $(ARDEBUG)
CFLAGS               = -c $(MINGW_C_STANDARD_OPTS) -m64 \
                       -O0 \
                       $(CDEBUG)
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -m64 -std=c++11 \
                       -O0 \
                       $(CPPDEBUG)
CPP_LDFLAGS          = -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -static -m64 \
                       $(CPPLDDEBUG)
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -Wl,--no-undefined \
                         $(CPPLDDEBUG) \
                         -Wl,--out-implib,$(basename $(PRODUCT)).lib
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -static -m64 \
                       $(LDDEBUG)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -Wl,--no-undefined \
                       $(LDDEBUG) \
                       -Wl,--out-implib,$(basename $(PRODUCT)).lib



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/FSW_Lib.exe
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=0 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=0
DEFINES_STANDARD = -DMODEL=FSW_Lib -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/FSW_Lib_ert_rtw/FSW_Lib.c $(START_DIR)/FSW_Lib_ert_rtw/FSW_Lib_data.c $(START_DIR)/FSW_Lib_ert_rtw/PD_Controller_Lib.c $(START_DIR)/FSW_Lib_ert_rtw/asmController_lib.c $(START_DIR)/FSW_Lib_ert_rtw/mode_select_lib.c $(START_DIR)/FSW_Lib_ert_rtw/quat_err_lib.c $(START_DIR)/FSW_Lib_ert_rtw/quat_rectify_lib.c $(START_DIR)/FSW_Lib_ert_rtw/rtGetInf.c $(START_DIR)/FSW_Lib_ert_rtw/rtGetNaN.c $(START_DIR)/FSW_Lib_ert_rtw/rt_nonfinite.c $(START_DIR)/FSW_Lib_ert_rtw/rt_sys_FSW_Lib_12.c $(START_DIR)/FSW_Lib_ert_rtw/rt_sys_FSW_Lib_16.c $(START_DIR)/FSW_Lib_ert_rtw/rt_sys_FSW_Lib_23.c $(START_DIR)/FSW_Lib_ert_rtw/rwa_allocation_lib.c $(START_DIR)/FSW_Lib_ert_rtw/sunSeek_lib.c $(START_DIR)/FSW_Lib_ert_rtw/target_generation_lib.c $(START_DIR)/FSW_Lib_ert_rtw/target_groundpass_lib.c $(START_DIR)/FSW_Lib_ert_rtw/twonorm.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_1.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_2.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_aat.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_control.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_defaults.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_dump.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_global.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_info.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_order.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_post_tree.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_postorder.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_preprocess.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_valid.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/cone.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/ctrlc.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/ecos.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/equil.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/kkt.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/ldl.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/matlab_main.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/preproc.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/runecos.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/spla.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/splamm.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/timer.c C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/wright_omega.c

MAIN_SRC = $(START_DIR)/FSW_Lib_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = FSW_Lib.obj FSW_Lib_data.obj PD_Controller_Lib.obj asmController_lib.obj mode_select_lib.obj quat_err_lib.obj quat_rectify_lib.obj rtGetInf.obj rtGetNaN.obj rt_nonfinite.obj rt_sys_FSW_Lib_12.obj rt_sys_FSW_Lib_16.obj rt_sys_FSW_Lib_23.obj rwa_allocation_lib.obj sunSeek_lib.obj target_generation_lib.obj target_groundpass_lib.obj twonorm.obj amd_1.obj amd_2.obj amd_aat.obj amd_control.obj amd_defaults.obj amd_dump.obj amd_global.obj amd_info.obj amd_order.obj amd_post_tree.obj amd_postorder.obj amd_preprocess.obj amd_valid.obj cone.obj ctrlc.obj ecos.obj equil.obj kkt.obj ldl.obj matlab_main.obj preproc.obj runecos.obj spla.obj splamm.obj timer.obj wright_omega.obj

MAIN_OBJ = ert_main.obj

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

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

CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_BASIC)

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

###########################################################################
## INLINED COMMANDS
###########################################################################


MINGW_C_STANDARD_OPTS = $(C_STANDARD_OPTS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


download : $(PRODUCT)


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

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o $(PRODUCT) @$(CMD_FILE) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/FSW_Lib_ert_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/FSW_Lib_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


FSW_Lib.obj : $(START_DIR)/FSW_Lib_ert_rtw/FSW_Lib.c
	$(CC) $(CFLAGS) -o "$@" "$<"


FSW_Lib_data.obj : $(START_DIR)/FSW_Lib_ert_rtw/FSW_Lib_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PD_Controller_Lib.obj : $(START_DIR)/FSW_Lib_ert_rtw/PD_Controller_Lib.c
	$(CC) $(CFLAGS) -o "$@" "$<"


asmController_lib.obj : $(START_DIR)/FSW_Lib_ert_rtw/asmController_lib.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ert_main.obj : $(START_DIR)/FSW_Lib_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mode_select_lib.obj : $(START_DIR)/FSW_Lib_ert_rtw/mode_select_lib.c
	$(CC) $(CFLAGS) -o "$@" "$<"


quat_err_lib.obj : $(START_DIR)/FSW_Lib_ert_rtw/quat_err_lib.c
	$(CC) $(CFLAGS) -o "$@" "$<"


quat_rectify_lib.obj : $(START_DIR)/FSW_Lib_ert_rtw/quat_rectify_lib.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetInf.obj : $(START_DIR)/FSW_Lib_ert_rtw/rtGetInf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetNaN.obj : $(START_DIR)/FSW_Lib_ert_rtw/rtGetNaN.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_nonfinite.obj : $(START_DIR)/FSW_Lib_ert_rtw/rt_nonfinite.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_sys_FSW_Lib_12.obj : $(START_DIR)/FSW_Lib_ert_rtw/rt_sys_FSW_Lib_12.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_sys_FSW_Lib_16.obj : $(START_DIR)/FSW_Lib_ert_rtw/rt_sys_FSW_Lib_16.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_sys_FSW_Lib_23.obj : $(START_DIR)/FSW_Lib_ert_rtw/rt_sys_FSW_Lib_23.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rwa_allocation_lib.obj : $(START_DIR)/FSW_Lib_ert_rtw/rwa_allocation_lib.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sunSeek_lib.obj : $(START_DIR)/FSW_Lib_ert_rtw/sunSeek_lib.c
	$(CC) $(CFLAGS) -o "$@" "$<"


target_generation_lib.obj : $(START_DIR)/FSW_Lib_ert_rtw/target_generation_lib.c
	$(CC) $(CFLAGS) -o "$@" "$<"


target_groundpass_lib.obj : $(START_DIR)/FSW_Lib_ert_rtw/target_groundpass_lib.c
	$(CC) $(CFLAGS) -o "$@" "$<"


twonorm.obj : $(START_DIR)/FSW_Lib_ert_rtw/twonorm.c
	$(CC) $(CFLAGS) -o "$@" "$<"


amd_1.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


amd_2.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_2.c
	$(CC) $(CFLAGS) -o "$@" "$<"


amd_aat.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_aat.c
	$(CC) $(CFLAGS) -o "$@" "$<"


amd_control.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_control.c
	$(CC) $(CFLAGS) -o "$@" "$<"


amd_defaults.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_defaults.c
	$(CC) $(CFLAGS) -o "$@" "$<"


amd_dump.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_dump.c
	$(CC) $(CFLAGS) -o "$@" "$<"


amd_global.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_global.c
	$(CC) $(CFLAGS) -o "$@" "$<"


amd_info.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_info.c
	$(CC) $(CFLAGS) -o "$@" "$<"


amd_order.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_order.c
	$(CC) $(CFLAGS) -o "$@" "$<"


amd_post_tree.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_post_tree.c
	$(CC) $(CFLAGS) -o "$@" "$<"


amd_postorder.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_postorder.c
	$(CC) $(CFLAGS) -o "$@" "$<"


amd_preprocess.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_preprocess.c
	$(CC) $(CFLAGS) -o "$@" "$<"


amd_valid.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/amd_valid.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cone.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/cone.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ctrlc.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/ctrlc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ecos.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/ecos.c
	$(CC) $(CFLAGS) -o "$@" "$<"


equil.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/equil.c
	$(CC) $(CFLAGS) -o "$@" "$<"


kkt.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/kkt.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ldl.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/ldl.c
	$(CC) $(CFLAGS) -o "$@" "$<"


matlab_main.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/matlab_main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


preproc.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/preproc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


runecos.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/runecos.c
	$(CC) $(CFLAGS) -o "$@" "$<"


spla.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/spla.c
	$(CC) $(CFLAGS) -o "$@" "$<"


splamm.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/splamm.c
	$(CC) $(CFLAGS) -o "$@" "$<"


timer.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/timer.c
	$(CC) $(CFLAGS) -o "$@" "$<"


wright_omega.obj : C:/Users/Nick's PC/Documents/GitHub/soci-gnc/Lib/FSW/soar/include/ecos/src/wright_omega.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


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
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


