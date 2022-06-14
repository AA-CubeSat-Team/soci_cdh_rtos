###########################################################################
## Makefile generated for component 'rtwshared'. 
## 
## Makefile     : rtwshared.mk
## Generated on : Tue Mar 29 09:23:00 2022
## Final product: ./rtwshared.lib
## Product type : static library
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
# MODELLIB                Static library target

PRODUCT_NAME              = rtwshared
MAKEFILE                  = rtwshared.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2020b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2020b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/Nick/Documents/GitHub/soci-gnc/Src
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
COMPILER_COMMAND_FILE     = rtwshared_comp.rsp
CMD_FILE                  = rtwshared.rsp
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = rtwshared.lib

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

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(MINGW_C_STANDARD_OPTS) -m64 \
                       -O0
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -m64 -std=c++11 \
                       -O0
CPP_LDFLAGS          = -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -static -m64
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -Wl,--no-undefined \
                         -Wl,--out-implib,$(basename $(PRODUCT)).lib
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -static -m64
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -Wl,--no-undefined \
                       -Wl,--out-implib,$(basename $(PRODUCT)).lib



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./rtwshared.lib
PRODUCT_TYPE = "static library"
BUILD_TYPE = "Model Reference Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DINTEGER_CODE=0
DEFINES_CUSTOM = 

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/slprj/ert/_sharedutils/MWDSP_EPH_R_B.c $(START_DIR)/slprj/ert/_sharedutils/align_vecs_f4vBXsDu.c $(START_DIR)/slprj/ert/_sharedutils/bsearch_qRItHZGW.c $(START_DIR)/slprj/ert/_sharedutils/const_params.c $(START_DIR)/slprj/ert/_sharedutils/convert_to_CCS_9tojus3A.c $(START_DIR)/slprj/ert/_sharedutils/convert_to_CCS_fbGN0NKz.c $(START_DIR)/slprj/ert/_sharedutils/deriv_M9RZx2VO.c $(START_DIR)/slprj/ert/_sharedutils/deriv_XPX6EHrN.c $(START_DIR)/slprj/ert/_sharedutils/eml_dlahqr_9Xlai4UO.c $(START_DIR)/slprj/ert/_sharedutils/factorial_sZPOa6fO.c $(START_DIR)/slprj/ert/_sharedutils/foh_c1NVxM2u.c $(START_DIR)/slprj/ert/_sharedutils/get_f_vals_QHwIX6tr.c $(START_DIR)/slprj/ert/_sharedutils/jseconds2ymdhms_eXoGXxIT.c $(START_DIR)/slprj/ert/_sharedutils/merge_B5HnnN1b.c $(START_DIR)/slprj/ert/_sharedutils/mldivide_CcWu5YGv.c $(START_DIR)/slprj/ert/_sharedutils/mldivide_NEqYeqp4.c $(START_DIR)/slprj/ert/_sharedutils/mldivide_Uh5i7tR8.c $(START_DIR)/slprj/ert/_sharedutils/mod_TpoWkbJk.c $(START_DIR)/slprj/ert/_sharedutils/mrdiv_01FAo0m2.c $(START_DIR)/slprj/ert/_sharedutils/mrdiv_lFGeJT69.c $(START_DIR)/slprj/ert/_sharedutils/norm_EzB1R8di.c $(START_DIR)/slprj/ert/_sharedutils/qr_MDOP2S80.c $(START_DIR)/slprj/ert/_sharedutils/qr_v7LIxcTX.c $(START_DIR)/slprj/ert/_sharedutils/qrf_87AzkAFc.c $(START_DIR)/slprj/ert/_sharedutils/rtGetInf.c $(START_DIR)/slprj/ert/_sharedutils/rtGetNaN.c $(START_DIR)/slprj/ert/_sharedutils/rt_atan2d_snf.c $(START_DIR)/slprj/ert/_sharedutils/rt_hypotd_snf.c $(START_DIR)/slprj/ert/_sharedutils/rt_invd3x3_snf.c $(START_DIR)/slprj/ert/_sharedutils/rt_modd_snf.c $(START_DIR)/slprj/ert/_sharedutils/rt_nonfinite.c $(START_DIR)/slprj/ert/_sharedutils/rt_powd_snf.c $(START_DIR)/slprj/ert/_sharedutils/rt_remd_snf.c $(START_DIR)/slprj/ert/_sharedutils/rt_roundd_snf.c $(START_DIR)/slprj/ert/_sharedutils/schur_ZrGmuypS.c $(START_DIR)/slprj/ert/_sharedutils/sort_Z8R2ikQI.c $(START_DIR)/slprj/ert/_sharedutils/xdlanv2_7VfWHvfb.c $(START_DIR)/slprj/ert/_sharedutils/xgehrd_oBoAXf5H.c $(START_DIR)/slprj/ert/_sharedutils/xgemv_gLgGfGIZ.c $(START_DIR)/slprj/ert/_sharedutils/xgeqrf_J92VbJAL.c $(START_DIR)/slprj/ert/_sharedutils/xgerc_jhTkIWHW.c $(START_DIR)/slprj/ert/_sharedutils/xgetrf_HqzFX9EF.c $(START_DIR)/slprj/ert/_sharedutils/xnrm2_KoFIUVBo.c $(START_DIR)/slprj/ert/_sharedutils/xnrm2_nrXTaW8D.c $(START_DIR)/slprj/ert/_sharedutils/xnrm2_oLi98ch9.c $(START_DIR)/slprj/ert/_sharedutils/xorgqr_jioZAUaB.c $(START_DIR)/slprj/ert/_sharedutils/xrot_GqxWzXOv.c $(START_DIR)/slprj/ert/_sharedutils/xrot_MOZ0Ssgv.c $(START_DIR)/slprj/ert/_sharedutils/xrot_w5C6g5Fw.c $(START_DIR)/slprj/ert/_sharedutils/xzlarf_Ddk2Tem0.c $(START_DIR)/slprj/ert/_sharedutils/xzlarfg_OnHd8y0N.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = MWDSP_EPH_R_B.obj align_vecs_f4vBXsDu.obj bsearch_qRItHZGW.obj const_params.obj convert_to_CCS_9tojus3A.obj convert_to_CCS_fbGN0NKz.obj deriv_M9RZx2VO.obj deriv_XPX6EHrN.obj eml_dlahqr_9Xlai4UO.obj factorial_sZPOa6fO.obj foh_c1NVxM2u.obj get_f_vals_QHwIX6tr.obj jseconds2ymdhms_eXoGXxIT.obj merge_B5HnnN1b.obj mldivide_CcWu5YGv.obj mldivide_NEqYeqp4.obj mldivide_Uh5i7tR8.obj mod_TpoWkbJk.obj mrdiv_01FAo0m2.obj mrdiv_lFGeJT69.obj norm_EzB1R8di.obj qr_MDOP2S80.obj qr_v7LIxcTX.obj qrf_87AzkAFc.obj rtGetInf.obj rtGetNaN.obj rt_atan2d_snf.obj rt_hypotd_snf.obj rt_invd3x3_snf.obj rt_modd_snf.obj rt_nonfinite.obj rt_powd_snf.obj rt_remd_snf.obj rt_roundd_snf.obj schur_ZrGmuypS.obj sort_Z8R2ikQI.obj xdlanv2_7VfWHvfb.obj xgehrd_oBoAXf5H.obj xgemv_gLgGfGIZ.obj xgeqrf_J92VbJAL.obj xgerc_jhTkIWHW.obj xgetrf_HqzFX9EF.obj xnrm2_KoFIUVBo.obj xnrm2_nrXTaW8D.obj xnrm2_oLi98ch9.obj xorgqr_jioZAUaB.obj xrot_GqxWzXOv.obj xrot_MOZ0Ssgv.obj xrot_w5C6g5Fw.obj xzlarf_Ddk2Tem0.obj xzlarfg_OnHd8y0N.obj

ALL_OBJS = $(OBJS)

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

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) @$(CMD_FILE)
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


MWDSP_EPH_R_B.obj : $(START_DIR)/slprj/ert/_sharedutils/MWDSP_EPH_R_B.c
	$(CC) $(CFLAGS) -o "$@" "$<"


align_vecs_f4vBXsDu.obj : $(START_DIR)/slprj/ert/_sharedutils/align_vecs_f4vBXsDu.c
	$(CC) $(CFLAGS) -o "$@" "$<"


bsearch_qRItHZGW.obj : $(START_DIR)/slprj/ert/_sharedutils/bsearch_qRItHZGW.c
	$(CC) $(CFLAGS) -o "$@" "$<"


const_params.obj : $(START_DIR)/slprj/ert/_sharedutils/const_params.c
	$(CC) $(CFLAGS) -o "$@" "$<"


convert_to_CCS_9tojus3A.obj : $(START_DIR)/slprj/ert/_sharedutils/convert_to_CCS_9tojus3A.c
	$(CC) $(CFLAGS) -o "$@" "$<"


convert_to_CCS_fbGN0NKz.obj : $(START_DIR)/slprj/ert/_sharedutils/convert_to_CCS_fbGN0NKz.c
	$(CC) $(CFLAGS) -o "$@" "$<"


deriv_M9RZx2VO.obj : $(START_DIR)/slprj/ert/_sharedutils/deriv_M9RZx2VO.c
	$(CC) $(CFLAGS) -o "$@" "$<"


deriv_XPX6EHrN.obj : $(START_DIR)/slprj/ert/_sharedutils/deriv_XPX6EHrN.c
	$(CC) $(CFLAGS) -o "$@" "$<"


eml_dlahqr_9Xlai4UO.obj : $(START_DIR)/slprj/ert/_sharedutils/eml_dlahqr_9Xlai4UO.c
	$(CC) $(CFLAGS) -o "$@" "$<"


factorial_sZPOa6fO.obj : $(START_DIR)/slprj/ert/_sharedutils/factorial_sZPOa6fO.c
	$(CC) $(CFLAGS) -o "$@" "$<"


foh_c1NVxM2u.obj : $(START_DIR)/slprj/ert/_sharedutils/foh_c1NVxM2u.c
	$(CC) $(CFLAGS) -o "$@" "$<"


get_f_vals_QHwIX6tr.obj : $(START_DIR)/slprj/ert/_sharedutils/get_f_vals_QHwIX6tr.c
	$(CC) $(CFLAGS) -o "$@" "$<"


jseconds2ymdhms_eXoGXxIT.obj : $(START_DIR)/slprj/ert/_sharedutils/jseconds2ymdhms_eXoGXxIT.c
	$(CC) $(CFLAGS) -o "$@" "$<"


merge_B5HnnN1b.obj : $(START_DIR)/slprj/ert/_sharedutils/merge_B5HnnN1b.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mldivide_CcWu5YGv.obj : $(START_DIR)/slprj/ert/_sharedutils/mldivide_CcWu5YGv.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mldivide_NEqYeqp4.obj : $(START_DIR)/slprj/ert/_sharedutils/mldivide_NEqYeqp4.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mldivide_Uh5i7tR8.obj : $(START_DIR)/slprj/ert/_sharedutils/mldivide_Uh5i7tR8.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mod_TpoWkbJk.obj : $(START_DIR)/slprj/ert/_sharedutils/mod_TpoWkbJk.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mrdiv_01FAo0m2.obj : $(START_DIR)/slprj/ert/_sharedutils/mrdiv_01FAo0m2.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mrdiv_lFGeJT69.obj : $(START_DIR)/slprj/ert/_sharedutils/mrdiv_lFGeJT69.c
	$(CC) $(CFLAGS) -o "$@" "$<"


norm_EzB1R8di.obj : $(START_DIR)/slprj/ert/_sharedutils/norm_EzB1R8di.c
	$(CC) $(CFLAGS) -o "$@" "$<"


qr_MDOP2S80.obj : $(START_DIR)/slprj/ert/_sharedutils/qr_MDOP2S80.c
	$(CC) $(CFLAGS) -o "$@" "$<"


qr_v7LIxcTX.obj : $(START_DIR)/slprj/ert/_sharedutils/qr_v7LIxcTX.c
	$(CC) $(CFLAGS) -o "$@" "$<"


qrf_87AzkAFc.obj : $(START_DIR)/slprj/ert/_sharedutils/qrf_87AzkAFc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetInf.obj : $(START_DIR)/slprj/ert/_sharedutils/rtGetInf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetNaN.obj : $(START_DIR)/slprj/ert/_sharedutils/rtGetNaN.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_atan2d_snf.obj : $(START_DIR)/slprj/ert/_sharedutils/rt_atan2d_snf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_hypotd_snf.obj : $(START_DIR)/slprj/ert/_sharedutils/rt_hypotd_snf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_invd3x3_snf.obj : $(START_DIR)/slprj/ert/_sharedutils/rt_invd3x3_snf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_modd_snf.obj : $(START_DIR)/slprj/ert/_sharedutils/rt_modd_snf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_nonfinite.obj : $(START_DIR)/slprj/ert/_sharedutils/rt_nonfinite.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_powd_snf.obj : $(START_DIR)/slprj/ert/_sharedutils/rt_powd_snf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_remd_snf.obj : $(START_DIR)/slprj/ert/_sharedutils/rt_remd_snf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_roundd_snf.obj : $(START_DIR)/slprj/ert/_sharedutils/rt_roundd_snf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


schur_ZrGmuypS.obj : $(START_DIR)/slprj/ert/_sharedutils/schur_ZrGmuypS.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sort_Z8R2ikQI.obj : $(START_DIR)/slprj/ert/_sharedutils/sort_Z8R2ikQI.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xdlanv2_7VfWHvfb.obj : $(START_DIR)/slprj/ert/_sharedutils/xdlanv2_7VfWHvfb.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xgehrd_oBoAXf5H.obj : $(START_DIR)/slprj/ert/_sharedutils/xgehrd_oBoAXf5H.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xgemv_gLgGfGIZ.obj : $(START_DIR)/slprj/ert/_sharedutils/xgemv_gLgGfGIZ.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xgeqrf_J92VbJAL.obj : $(START_DIR)/slprj/ert/_sharedutils/xgeqrf_J92VbJAL.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xgerc_jhTkIWHW.obj : $(START_DIR)/slprj/ert/_sharedutils/xgerc_jhTkIWHW.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xgetrf_HqzFX9EF.obj : $(START_DIR)/slprj/ert/_sharedutils/xgetrf_HqzFX9EF.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xnrm2_KoFIUVBo.obj : $(START_DIR)/slprj/ert/_sharedutils/xnrm2_KoFIUVBo.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xnrm2_nrXTaW8D.obj : $(START_DIR)/slprj/ert/_sharedutils/xnrm2_nrXTaW8D.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xnrm2_oLi98ch9.obj : $(START_DIR)/slprj/ert/_sharedutils/xnrm2_oLi98ch9.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xorgqr_jioZAUaB.obj : $(START_DIR)/slprj/ert/_sharedutils/xorgqr_jioZAUaB.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xrot_GqxWzXOv.obj : $(START_DIR)/slprj/ert/_sharedutils/xrot_GqxWzXOv.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xrot_MOZ0Ssgv.obj : $(START_DIR)/slprj/ert/_sharedutils/xrot_MOZ0Ssgv.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xrot_w5C6g5Fw.obj : $(START_DIR)/slprj/ert/_sharedutils/xrot_w5C6g5Fw.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xzlarf_Ddk2Tem0.obj : $(START_DIR)/slprj/ert/_sharedutils/xzlarf_Ddk2Tem0.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xzlarfg_OnHd8y0N.obj : $(START_DIR)/slprj/ert/_sharedutils/xzlarfg_OnHd8y0N.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw


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


