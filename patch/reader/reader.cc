/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** A library for HEP events storage and processing based on 
** Google's ProtocolBuffers 
** Read more: http://atlaswww.hep.anl.gov/asc/promc
** 
** Author: S.Chekanov (ANL). chekanov@anl.gov
** Copyright  2013 
** -------------------------------------------------------------------------*/
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include"ProMCBook.h"
#include"ProMCHeader.pb.h"
#include"ProMC.pb.h"
#include"ProMCStat.pb.h"
using namespace std;
using namespace promc; 


// read a ProMC input file
int main(int argc, char **argv)
{


  // Look for a help argument
  for (int i = 1; i < argc; ++i) {
    const string arg = argv[i];
    if (arg == "--help" || arg == "-h") {
      cout << argv[0] << ": reader" << endl;
      cout << "Usage: " << argv[0] << "[<infile>]" << endl;
      exit(0);
    }
  }

  // Choose input and output files from the command line
  string infile("-");
  if (argc == 2) {
    infile = argv[1];
  } else if (argc == 1 || argc > 3) {
    cerr << "Usage: " << argv[0] << " [<infile>]" << endl;
    exit(1);
  }


  ProMCBook*  epbook = new ProMCBook(infile.c_str(),"r");


  cout << "\n\n Start to read this file.." << endl;

  // get the version number
  int  h=epbook->getVersion();
  cout << "Version = " << h << endl;
  // get the description of this file
  string d=epbook->getDescription();
  cout << "Description = " << d << endl;
  unsigned int  nev=epbook->getEvents();
  cout << "Events = " << nev  << endl;



  // get the header file with units, cross sections etc.
  ProMCHeader header = epbook->getHeader();
  cout << "Cross section=" << header.cross_section() << endl;

  // here is the units for energy
  double kEV=(double)(header.momentumunit());
  cout << "Momentum units 0.01*MeV=" << kEV << endl;
  //cout << "Nr of entries = " << epbook->size() << endl;


  for (unsigned int j=0; j<nev; ++j) {
    if (epbook->next() !=0) continue;
    ProMCEvent eve = epbook->get();


    // event information
    ProMCEvent_Event  *e=eve.mutable_event();
    //double  weight=e->weight();



    // get truth information 
    ProMCEvent_Particles  *pa=eve.mutable_particles();

    // print particles 
    if (j%1000==0) { 
      cout << "Event=" << j <<  " Nr of particles=" << pa->pdg_id_size() << endl;
      for (unsigned nn=0, n=e->fdata_size(); nn<n; ++nn) {
        cout << e->fdata(nn) << " ";
      }

      cout << "PDF=";  
      for (unsigned nn=0, n=e->idata_size(); nn<n; ++nn) {
        cout << e->idata(nn) << " ";
      }

      cout << " " << endl; 
      for (int i=0; i<pa->pdg_id_size(); ++i) {
        cout << " " <<  pa->pdg_id(i) << " " << pa->px(i)/kEV << " " << pa->py(i)/kEV << " " << pa->pz(i)/kEV << " e=" << pa->energy(i)/kEV << endl; 
      }
    }

  } // end loop


  epbook->close(); // close


  return 0;
}
