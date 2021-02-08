###########################################################################
## Makefile generated for Simulink model 'soar_interface_lib'. 
## 
## Makefile     : soar_interface_lib.mk
## Generated on : Wed Sep 09 17:42:20 2020
## MATLAB Coder version: 4.1 (R2018b)
## 
## Build Info:
## 
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/soar_interface_lib
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
# SHARED_OBJS             Shared Object Names

PRODUCT_NAME              = soar_interface_lib
MAKEFILE                  = soar_interface_lib.mk
COMPUTER                  = MACI64
MATLAB_ROOT               = /Applications/MATLAB_R2018b.app
MATLAB_BIN                = /Applications/MATLAB_R2018b.app/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/maci64
MASTER_ANCHOR_DIR         = 
START_DIR                 = /Users/taylorreynolds/SOCI/soci-gnc/Build
ARCH                      = maci64
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ISO_C
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
C_STANDARD_OPTS           = -fno-common -fexceptions
CPP_STANDARD_OPTS         = -fno-common -fexceptions
SHARED_SRC_DIR            = ../slprj/ert/_sharedutils
SHARED_SRC                = $(SHARED_SRC_DIR)/*.c
SHARED_BIN_DIR            = ../slprj/ert/_sharedutils
SHARED_LIB                = $(SHARED_BIN_DIR)/rtwshared.a
SHARED_OBJS               =  \
$(addprefix $(join $(SHARED_BIN_DIR),/), $(addsuffix .o, $(basename $(notdir $(wildcard $(SHARED_SRC_DIR)/*.c)))))

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Clang v3.1 | gmake (64-bit Mac)
# Supported Version(s):    3.1
# ToolchainInfo Version:   R2018b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS

#-----------
# MACROS
#-----------

ARCHS             = x86_64
XCODE_SDK_VER     = $(shell perl $(MATLAB_ROOT)/rtw/c/tools/macsdkver.pl)
XCODE_SDK         = MacOSX$(XCODE_SDK_VER).sdk
XCODE_DEVEL_DIR   = $(shell xcode-select -print-path)
XCODE_SDK_ROOT    = $(XCODE_DEVEL_DIR)/Platforms/MacOSX.platform/Developer/SDKs/$(XCODE_SDK)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Clang C Compiler
CC = xcrun clang

# Linker: Clang Linker
LD = xcrun clang++

# C++ Compiler: Clang C++ Compiler
CPP = xcrun clang++

# C++ Linker: Clang C++ Linker
CPP_LD = xcrun clang++

# Archiver: Clang Archiver
AR = xcrun ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/maci64
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
RM                  = @rm -f
ECHO                = @echo
MV                  = @mv
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c -isysroot $(XCODE_SDK_ROOT) -arch $(ARCHS) $(C_STANDARD_OPTS) \
                       -O3
CPPFLAGS             = -c -isysroot $(XCODE_SDK_ROOT) -arch $(ARCHS) $(CPP_STANDARD_OPTS) \
                       -O3
CPP_LDFLAGS          = -arch $(ARCHS) -isysroot $(XCODE_SDK_ROOT) -Wl,-rpath,$(MATLAB_ARCH_BIN) -Wl,-rpath,@executable_path -Wl,-rpath,@executable_path/$(RELATIVE_PATH_TO_ANCHOR) -L"$(MATLAB_ARCH_BIN)"
CPP_SHAREDLIB_LDFLAGS  = -dynamiclib -install_name @rpath/$(notdir $(PRODUCT)) -isysroot $(XCODE_SDK_ROOT) -L"$(MATLAB_ARCH_BIN)" \
                         -Wl,$(LD_NAMESPACE) $(LD_UNDEFS)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -arch $(ARCHS) -isysroot $(XCODE_SDK_ROOT) -Wl,-rpath,$(MATLAB_ARCH_BIN) -Wl,-rpath,@executable_path -Wl,-rpath,@executable_path/$(RELATIVE_PATH_TO_ANCHOR) -L"$(MATLAB_ARCH_BIN)"
MEX_CPPFLAGS         = -R2018a -MATLAB_ARCH=$(ARCH) $(INCLUDES) \
                         \
                       CXXOPTIMFLAGS="$(C_STANDARD_OPTS)  \
                       -O0 \
                        $(DEFINES)" \
                         \
                       -silent
MEX_CPPLDFLAGS       =
MEX_CFLAGS           = -R2018a -MATLAB_ARCH=$(ARCH) $(INCLUDES) \
                         \
                       COPTIMFLAGS="$(C_STANDARD_OPTS)  \
                       -O0 \
                        $(DEFINES)" \
                         \
                       -silent
MEX_LDFLAGS          = LDFLAGS=='$$LDFLAGS'
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -dynamiclib -install_name @rpath/$(notdir $(PRODUCT)) -isysroot $(XCODE_SDK_ROOT) -L"$(MATLAB_ARCH_BIN)" \
                       -Wl,$(LD_NAMESPACE) $(LD_UNDEFS)

#--------------------
# File extensions
#--------------------

H_EXT               = .h
OBJ_EXT             = .o
C_EXT               = .c
EXE_EXT             =
SHAREDLIB_EXT       = .dylib
HPP_EXT             = .hpp
OBJ_EXT             = .o
CPP_EXT             = .cpp
EXE_EXT             =
SHAREDLIB_EXT       = .dylib
STATICLIB_EXT       = .a
MEX_EXT             = .mexmaci64
MAKE_EXT            = .mk


###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/soar_interface_lib
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/soar_interface_lib_ert_rtw -I/Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/include -I/Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/test/soac_autocode_test -I/Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(MATLAB_ROOT)/toolbox/dsp/include -I$(MATLAB_ROOT)/toolbox/dsp/extern/src/export/include/src -I$(MATLAB_ROOT)/toolbox/dsp/extern/src/export/include -I$(MATLAB_ROOT)/toolbox/shared/dsp/vision/matlab/include -I$(START_DIR)/slprj/ert/_sharedutils

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=0 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_IMPLIED = -DTID01EQ=0
DEFINES_STANDARD = -DMODEL=soar_interface_lib -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DUNIX

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_IMPLIED) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/soar_interface_lib_ert_rtw/soar_interface_lib.c timer.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/amd_1.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/amd_2.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/amd_aat.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/amd_control.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/amd_defaults.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/amd_dump.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/amd_global.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/amd_info.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/amd_order.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/amd_post_tree.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/amd_postorder.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/amd_preprocess.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/amd_valid.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/cone.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/ctrlc.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/ecos.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/equil.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/expcone.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/kkt.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/ldl.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/matlab_main.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/preproc.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/runecos.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/spla.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/splamm.c /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/wright_omega.c

MAIN_SRC = $(START_DIR)/soar_interface_lib_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = soar_interface_lib.o timer.o amd_1.o amd_2.o amd_aat.o amd_control.o amd_defaults.o amd_dump.o amd_global.o amd_info.o amd_order.o amd_post_tree.o amd_postorder.o amd_preprocess.o amd_valid.o cone.o ctrlc.o ecos.o equil.o expcone.o kkt.o ldl.o matlab_main.o preproc.o runecos.o spla.o splamm.o wright_omega.o

MAIN_OBJ = ert_main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = $(SHARED_LIB)

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

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


download : build


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
	$(LD) $(LDFLAGS) -o $(PRODUCT) $(OBJS) $(MAIN_OBJ) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/soar_interface_lib_ert_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/soar_interface_lib_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/build/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/build/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : /Users/taylorreynolds/SOCI/soci-gnc/Lib/FSW/adcs_oac/include/ecos/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


$(SHARED_BIN_DIR)/%.o : $(SHARED_SRC_DIR)/%.c
	@echo "### Compiling "$<" ..."
	$(CC) $(CFLAGS) -o "$@" "$<"


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
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


