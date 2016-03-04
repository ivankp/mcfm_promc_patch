// ----------------------------------------------------------------------
// ProMCFortran
// Author: Kyle Strand., S.Chekanov, E.May
// Date: 28 June 2013
// 
// Cloning promc file.
// This implements the RootTuple class.
// 
// ----------------------------------------------------------------------

#include "promcfortran.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace promc;

int static nev = 0;

// --------------------------------------------------------------
// Public methods
// --------------------------------------------------------------
string getEnvVar(std::string const &key) {
  char *val = getenv(key.c_str());
  return val == NULL ? std::string() : std::string(val);
} // for use with readPDG()

void readPDG(ProMCHeader * header) {

  string temp_string;
  istringstream curstring;

  string PdgTableFilename = getEnvVar("PROMC") + "/data/particle.tbl";
  if (PdgTableFilename.size() < 2) {
    cout << "**        "
      "ERROR: PROMC variable not set. Did you run source.sh"
      "      **" << endl;
    exit(1);
  }

  ifstream fichier_a_lire(PdgTableFilename.c_str());
  if (!fichier_a_lire.good()) {
    cout << "**      	ERROR: PDG Table (" << PdgTableFilename <<
      ") not found!			**" << endl;
    exit(1);
    return;
  }

  getline(fichier_a_lire, temp_string);
  getline(fichier_a_lire, temp_string);
  getline(fichier_a_lire, temp_string);
  while (getline(fichier_a_lire, temp_string)) {
    curstring.clear();
    curstring.str(temp_string);
    long int ID;
    std::string name;
    int charge;
    float mass;
    float width;
    float lifetime;

    curstring >> ID >> name >> charge >> mass >> width >> lifetime;

    ProMCHeader_ParticleData *pp = header->add_particledata();
    pp->set_id(ID);
    pp->set_mass(mass);
    pp->set_name(name);
    pp->set_width(width);
    pp->set_lifetime(lifetime);
    pp->set_charge(charge);
  }

} // fuction to gather particle data
PromcFortran::PromcFortran()  { } // Constructor
PromcFortran::~PromcFortran() { } // Destructor

void PromcFortran::Initialise(int myid, char *filename, char *message,
                              int maxIter, int nrCalls, double Energy) {
  const double kEV = 1000 * 100;
  const double uL = 1000.;

  nev = 0;

  // Define promc and create headers

  cout << "Opening output ext =  " << myid << endl;

  cout << "In PromcFortran::Initialise Opening output filename = "
       << filename << endl;
  epbook = new ProMCBook(filename, "w", true);
  epbook->setDescription(myid, message);

  ProMCHeader header;
  // define length and momentum units
  // momentum in 0.01*MeV (px, py, pz)
  // length in cm*1000
  header.set_momentumunit((int)kEV);
  header.set_lengthunit((int)uL);
  header.set_id1(0);
  header.set_id2(0);
  header.set_pdf1(0);
  header.set_pdf2(0);
  header.set_x1(0);
  header.set_x2(0);
  header.set_scalepdf(0);
  header.set_weight(maxIter);
  header.set_name("MCFM 7.0 NLO");
  header.set_code(nrCalls);
  header.set_ecm(Energy);
  header.set_s(Energy);
  header.set_cross_section(0);
  header.set_cross_section_error(0);

  // read in predefined header data
  readPDG(&header);

  epbook->setHeader(header);

} // Initialise

void PromcFortran::AddEvent(double m_weight) {
  // skip ghost event
  if (nev == 0) {
    nev++;
    ClearVectors();
    return;
  }
  // Check vectors sizes consistent
  if ((int)m_Px.size() != (int)m_barcode.size() ||
      (int)m_Py.size() != (int)m_barcode.size() ||
      (int)m_Pz.size() != (int)m_barcode.size() ||
      (int)m_E.size() != (int)m_barcode.size())
    std::cout << "PromcFortran:: Warning: "
                 "Inconsistent vector sizes" << std::endl;

  ProMCEvent promc;

  // fill event information
  ProMCEvent_Event *eve = promc.mutable_event();
  eve->set_number(nev);         // all these zeroes to be filled later

  ++nev;

  // add doubles if any 
  for (unsigned int i = 0; i < m_fdata.size(); ++i) {
    eve->add_fdata(m_fdata[i]);
  }

  // add varints if any 
  for (unsigned int i = 0; i < m_idata.size(); ++i) {
    eve->add_idata(m_idata[i]);
  }

  // fill truth particle information 
  ProMCEvent_Particles *pa = promc.mutable_particles();

  int vlength = m_Px.size();
  for (int i = 0; i < vlength; ++i) {
    pa->add_pdg_id(m_barcode[i]);
    pa->add_px((int)(m_Px[i] * kEV));
    pa->add_py((int)(m_Py[i] * kEV));
    pa->add_pz((int)(m_Pz[i] * kEV));
    pa->add_energy((int)(m_E[i] * kEV));
  }

  epbook->write(promc);

  // enm Reset vectors
  ClearVectors();
} // AddEvent

void PromcFortran::Close() {
  epbook->close();
} // Close

void PromcFortran::AddParticle(int barcode, double px, double py, double pz,
                               double e) {
  m_barcode.push_back(barcode);
  m_Px.push_back(px);
  m_Py.push_back(py);
  m_Pz.push_back(pz);
  m_E.push_back(e);
} // AddParticle in Root file: promc is defined in AddEvent

// add float value
void PromcFortran::AddEventFloat(double sinfo) {
  m_fdata.push_back(sinfo);
}

// add integer value
void PromcFortran::AddEventInt(int iinfo) {
  m_idata.push_back(iinfo);
}

void PromcFortran::SetStats(double cross, double crosserr, double lumi,
                            int events) {
  ProMCStat stat;
  stat.set_cross_section_accumulated(cross);    // pb
  stat.set_cross_section_error_accumulated(crosserr);
  stat.set_luminosity_accumulated(lumi);
  stat.set_ntried(events);
  stat.set_nselected(events);
  stat.set_naccepted(events);
  epbook->setStatistics(stat);
}

// --------------------------------------------------------------
// Private methods
// --------------------------------------------------------------

void PromcFortran::ClearVectors() {
  m_barcode.clear();
  m_Px.clear();
  m_Py.clear();
  m_Pz.clear();
  m_E.clear();
  m_idata.clear();
  m_fdata.clear();
} // ClearVectors
