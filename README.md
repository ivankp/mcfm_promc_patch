# Installation instructions

1. [Install promc library]
   Go to <https://atlaswww.hep.anl.gov/asc/wikidoc/doku.php?id=asc:promc:installation>
   Follow instructions for 'Installation from the source (Linux)'
   Don't forget to source $PROMC/setup.sh! The following steps assume you have.

   The meat of promc installation is:
   ```bash
   wget -O- http://atlaswww.hep.anl.gov/asc/promc/download/current.php | tar -xzf -
   cd ProMC
   ./build.sh               # build all source files
   ./install.sh [promc_dir] # install into some directory
   source [promc_dir]/promc/setup.sh # make it available
   ```

2. [Get MCFM source]
   Download source from <http://mcfm.fnal.gov/>
   Extract the archive

3. [Patch MCFM]
   Download this patch
   Run ./patch.sh -h to see patching options
   ./patch.sh /path/to/MCFM-source [options]

4. [Compile MCFM]
   cd /path/to/MCFM-source
   ./Install[_omp]
   make

