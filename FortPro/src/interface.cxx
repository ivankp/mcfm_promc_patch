// ----------------------------------------------------------------------
// ProMCFortran
// Author: Kyle Strand
// Date: 29th August 2012
// 
// This is the interface implementation. It converts the Fortran MC
// simulation and implements it using the PromcFortran class. It then
// converts the Fortran using c++ to create and write the compact 
// ProMC file in one quick shot
// 
// ----------------------------------------------------------------------

#include "interface.h"
#include "promcfortran.h"

// Declare global pointer
PromcFortran *eventHandler;

void promcinit(int myid, char *workdir, char *message, int maxiter, int ncalls,
               double Energy) {
  eventHandler = new PromcFortran();
  cout << "In interface::promcinit filename.ext = " << myid << endl;
  cout << "In interface::promcinit output file = " << workdir << endl;
  cout << "In interface::promcinit message = " << message << endl;
  eventHandler->Initialise(myid, workdir, message, maxiter, ncalls, Energy);
} // Promcinit

void promcclose() {
  eventHandler->Close();
  delete eventHandler;
} // Promcclose

void promcaddparticle(int barcode, double px, double py, double pz, double e) {
  eventHandler->AddParticle(barcode, px, py, pz, e);
} // Promcaddparticle

// add float
void promcaddfloat(double info) {
  eventHandler->AddEventFloat(info);
} // Promcaddevent

// add integer
void promcaddint(int info) {
  eventHandler->AddEventInt(info);
} // Promcaddevent


void promcaddevent(double weight) {
  eventHandler->AddEvent(weight);
} // Promcaddevent

void promcaddstats(double cross, double crosserr, double lumi, int events) {
  eventHandler->SetStats(cross, crosserr, lumi, events);
}

// Converts a FORTRAN string to a C++ string
std::string strFtoC(const char *str, int len) {
  int tlen = 0;

  // Counts non-blank characters in a string str until a first blank character 
  // or the end of the string is met
  while (str[tlen] != ' ' && (tlen < len) && str[tlen++]);

  return std::string(str,tlen);
} // strFtoC
