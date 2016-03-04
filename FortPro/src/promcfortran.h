// ----------------------------------------------------------------------
// ProMCFortran
// Author: Kyle Strand 
// Date: 3 July 2013
// 
// This declares the ProMCFortran class.
// 
// ----------------------------------------------------------------------

#ifndef promcfortran_H
#define promcfortran_H

#include <vector>
#include "../src_promc/ProMCHeader.pb.h"
#include "../src_promc/ProMC.pb.h"
#include "../src_promc/ProMCBook.h"

const double kEV = 1000 * 100;
const double uL = 1000.;

class PromcFortran {
public:

  // Constructors and destructors
  PromcFortran();
  ~PromcFortran();

  // Public methods
  void Initialise(int myid, char *workdir, char *filename, int maxIter,
                  int nrCall, double Energy);
  void AddEvent(double weight);
  void AddEventFloat(double sinfo);
  void AddEventInt(int sinfo);
  void Close();
  void AddParticle(int barcode, double px, double py, double pz, double e);
  void SetStats(double cross, double crosserr, double lumi, int events);

private:
  // Private methods
  void ClearVectors();

  // ProMC object
  ProMCBook *epbook;

  // ProMC Variables
  std::vector<int> m_barcode;
  std::vector<double> m_fdata;
  std::vector<int> m_idata;
  std::vector<double> m_Px, m_Py, m_Pz, m_E;
};

#endif
