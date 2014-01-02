// $Id$
//
// Earth System Modeling Framework
// Copyright 2002-2014, University Corporation for Atmospheric Research,
// Massachusetts Institute of Technology, Geophysical Fluid Dynamics
// Laboratory, University of Michigan, National Centers for Environmental
// Prediction, Los Alamos National Laboratory, Argonne National Laboratory,
// NASA Goddard Space Flight Center.
// Licensed under the University of Illinois-NCSA License.
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// This file is part of the pure C public ESMC API
//-----------------------------------------------------------------------------

//-------------------------------------------------------------------------
// these lines prevent this file from being read more than once if it
// ends up being included multiple times

#ifndef ESMC_UTIL_H
#define ESMC_UTIL_H

#include "ESMC_Conf.h"

#ifdef __cplusplus
extern "C" {
#endif

  int ESMC_UtilGetArgIndex(int argc, char * const argv[], const char *value, int *rc);

#ifdef __cplusplus
} // extern "C"
#endif

enum ESMC_GridItem_Flag {ESMC_GRIDITEM_INVALID=-2,
                         ESMC_GRIDITEM_UNINIT,
                         ESMC_GRIDITEM_MASK,
                         ESMC_GRIDITEM_AREA};

enum ESMC_GridStatus_Flag {ESMC_GRIDSTATUS_INVALID=-1,
                      ESMC_GRIDSTATUS_UNINIT,
                      ESMC_GRIDSTATUS_NOT_READY,
                      ESMC_GRIDSTATUS_SHAPE_READY};

// general logical value - MUST MATCH F90
enum ESMC_Logical { ESMF_TRUE=1,
                    ESMF_FALSE };

// Values must match F90
enum ESMC_LogKind_Flag{
                ESMC_LOGKIND_SINGLE=1,
                ESMC_LOGKIND_MULTI =2,
                ESMC_LOGKIND_NONE  =3 };

// Values must match F90
enum ESMC_LogMsgType_Flag{
		ESMC_LOGMSG_INFO =1,
		ESMC_LOGMSG_WARN =2,
		ESMC_LOGMSG_ERROR=3,
		ESMC_LOGMSG_TRACE=4 };

enum ESMC_MeshLoc_Flag {ESMC_MESHLOC_NODE=1,
                        ESMC_MESHLOC_ELEMENT};

enum ESMC_PoleKind_Flag {ESMC_POLEKIND_NONE=0,
                         ESMC_POLEKIND_MONOPOLE=1,
                         ESMC_POLEKIND_BIPOLE=2};

enum ESMC_PoleMethod_Flag {ESMF_POLEMETHOD_NONE=0,
			   ESMF_POLEMETHOD_ALLAVG,
			   ESMF_POLEMETHOD_NPNTAVG,
			   ESMF_POLEMETHOD_TEETH};

enum ESMC_Region_Flag { ESMC_REGION_TOTAL=0,
                       ESMC_REGION_SELECT,
                       ESMC_REGION_EMPTY};

enum ESMC_RegridMethod_Flag {ESMC_REGRIDMETHOD_BILINEAR=0,
			     ESMC_REGRIDMETHOD_PATCH,
			     ESMC_REGRIDMETHOD_CONSERVE,
                             ESMC_REGRIDMETHOD_NEAREST_STOD,
                             ESMC_REGRIDMETHOD_NEAREST_DTOS};

enum ESMC_StaggerLoc {ESMC_STAGGERLOC_INVALID=-2,
                      ESMC_STAGGERLOC_UNINIT,
                      ESMC_STAGGERLOC_CENTER,
                      ESMC_STAGGERLOC_EDGE1,
                      ESMC_STAGGERLOC_EDGE2,
                      ESMC_STAGGERLOC_CORNER};

enum ESMC_TypeKind_Flag {ESMC_TYPEKIND_I1=1,
                    ESMC_TYPEKIND_I2,
                    ESMC_TYPEKIND_I4,
                    ESMC_TYPEKIND_I8,
                    ESMC_TYPEKIND_R4,
                    ESMC_TYPEKIND_R8,
                    ESMF_C8,
                    ESMF_C16,
                    ESMC_TYPEKIND_LOGICAL,
                    ESMC_TYPEKIND_CHARACTER,
                    ESMF_NOKIND=99};

enum ESMC_UnmappedAction_Flag {ESMC_UNMAPPEDACTION_ERROR=0,
			       ESMC_UNMAPPEDACTION_IGNORE};

enum ESMC_FileFormat_Flag {ESMC_FILEFORMAT_UNDEFINED, ESMC_FILEFORMAT_VTK,
			   ESMC_FILEFORMAT_SCRIP, ESMC_FILEFORMAT_ESMFMESH,
			   ESMC_FILEFORMAT_ESMCGRID, ESMC_FILEFORMAT_UGRID,
			   ESMC_FILEFORMAT_GRIDSPEC};

enum ESMC_Decomp_Flag {ESMC_DECOMP_BALANCED, ESMC_DECOMP_RESTFIRST,
		       ESMC_DECOMP_RESTLAST, ESMC_DECOMP_CYCLIC};

// ESMF platform-dependent data types
#if (ESMC_POINTER_SIZE == 4)
  // 32-bit machine
  typedef long long ESMC_I8;
  typedef int       ESMC_I4;
  typedef short     ESMC_I2;
  typedef char      ESMC_I1;
  typedef double    ESMC_R8;
  typedef float     ESMC_R4;
  typedef unsigned long      ESMC_POINTER;
#else
  // 64-bit machine
#if defined (PARCH_mingw)
  typedef long long ESMC_I8;
#else
  typedef long      ESMC_I8;
#endif
  typedef int       ESMC_I4;
  typedef short     ESMC_I2;
  typedef char      ESMC_I1;
  typedef double    ESMC_R8;
  typedef float     ESMC_R4;
  typedef unsigned long long ESMC_POINTER;
#endif

#endif  // ESMC_UTIL_H
