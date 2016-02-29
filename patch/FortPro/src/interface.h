//----------------------------------------------------------------------
//                             ProMCFortran
//  Author:  Kyle Strand
//  Date:    3 July 2013
//
//  This is the interface declaration. It uses a wrapper from the
//  implementation to the symbols that the FORTRAN compiler will
//  find. It uses macros found in FC_namemangling.h to get the name
//  mangling correct for the user's compiler. These macros are output
//  by CMake during build, but the user could define them if needed.
//
//  Based on RootTuple interface
//----------------------------------------------------------------------

#ifndef interface_H
#define interface_H

#include <string>
#include "FC_namemangling.h"

int *myid;


void promcinit(int myid, char* workdir, char* filename, int maxIter, int nrCalls, double Energy);
void promcclose();

void promcaddparticle(int barcode, double px, double py, double pz, double e);
void promcaddfloat(double info);
void promcaddint(int info);
void promcaddevent(double weight);
void promcaddstats(double cross, double crosserr, double lumi, int events);

std::string strFtoC(const char *str, int len);

// Wrappers from FORTRAN subroutines to C++ functions
// Name mangling is accounted for by FortranCInterface_GLOBAL macro
// Problems could occur with character array argument from FORTRAN subroutine
#ifdef __cplusplus
extern "C" {
#endif
    void FortranCInterface_GLOBAL(promcinit,PROMCINIT)(int *myid, char* workdir, char*filename, int* maxIter, int *nrCalls, double *Energy)
    {promcinit(*myid,workdir,filename,*maxIter,*nrCalls,*Energy);};

    void FortranCInterface_GLOBAL(promcclose,PROMCCLOSE)()
    {promcclose();};

    void FortranCInterface_GLOBAL(promcaddparticle,PROMCADDPARTICLE)(int *barcode, double *px, double *py, double *pz, double *e)
    {promcaddparticle(*barcode, *px, *py, *pz, *e);};

    void FortranCInterface_GLOBAL(promcaddevent,PROMCADDEVENT)(double *weight)
    {promcaddevent(*weight);};

    void FortranCInterface_GLOBAL(promcaddfloat,PROMCADDFLOAT)(double *info)
    {promcaddfloat(*info);};

    void FortranCInterface_GLOBAL(promcaddint,PROMCADDINT)(int *idata)
    {promcaddint(*idata);};

    void FortranCInterface_GLOBAL(promcaddstats,PROMCADDSTATS)(double *cross, double *crosserr, double *lumi, int *events)
    {promcaddstats(*cross, *crosserr, *lumi, *events);};


#ifdef __cplusplus
}
#endif

#endif
