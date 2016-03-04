Please, read until the "Limitations" section before proceeding.

# Installation instructions

1. [Install promc library]<br>
   Go to <https://atlaswww.hep.anl.gov/asc/wikidoc/doku.php?id=asc:promc:installation><br>
   Follow instructions for 'Installation from the source (Linux)'.<br>
   Don't forget to `source $PROMC/setup.sh`! The following steps assume you have.

   The meat of promc installation is:
   ```bash
   wget -O- http://atlaswww.hep.anl.gov/asc/promc/download/current.php | tar -xzf -
   cd ProMC
   ./build.sh               # build all source files
   ./install.sh [promc_dir] # install into some directory
   source [promc_dir]/promc/setup.sh # make it available
   ```

2. [Get MCFM source]<br>
   Download source from <http://mcfm.fnal.gov/><br>
   Extract the archive<br>
   E.g.: `wget -O- http://mcfm.fnal.gov/MCFM-7.0.1.tar.gz | tar -xzf -`

3. [Patch MCFM]<br>
   Download this patch<br>
   Run `./patch.sh -h` to see patching options<br>
   `./patch.sh /path/to/MCFM-source [options]`

4. [Compile MCFM]

   ```bash
   cd /path/to/MCFM-source
   ./Install
   make
   ```

# Patch script options

`--help,-h`<br>
Prints short discription of options.

One positional argument is required, which is the path to MCFM installation to be patched.

`--lhapdf`<br>
If used without a value, the path is assumed to be the string printed by `lhapdf-config --prefix`.<br>
Can also be used with a value, as in `--lhapdf=/foo/bar`. Note, that this path should lead to the root of lhapdf installation, not the `lib` directory.

`--make-j`<br>
If used, the calls `make` in mcfm `Install` scripts will be appended with the `-j` flag.
May be used with a value, as in `--make-j=8`. Without the value the default is 4.

`--unpatch`<br>
If this flag is passed, an unpatch script will be created in the current directory.
The unpatch script restore the MCFM to the state before patching if run.
Running `./patch.sh --unpatch` does *not* unpatch!

# Limitations
For now, promc output works only with MCFM compiled without omp.
We've also experienced problems saving promc output for process #1.
We are working on these issue.

# Running MCFM with promc
The command for running MCFM is unchanged by this patch.

The output promc file name is determined by ['runstring'] parameter in the input file.
For example, if the respective line in your input.DAT file reads
```
'best_process_ever' ['runstring']
```
the output file will be called `best_process_ever.promc`.

The `proto` directory (or a link to it) in the same directory as the input file is needed to include the Protocol Buffers definitions into the promc file to make it self descriptive.

The `logfile.txt` file (or a link to it) in the same directory as the input file is needed to attach extra user information.
By default, the patch makes it a link to the `input.DAT`, to include the generation settings.

# Inspecting promc files
Events and metadata in the output promc files can be viewed using a gui Java program `browser_promc`.
The program can be downloaded [here](http://atlaswww.hep.anl.gov/asc/promc/download/browser_promc.jar).
To run the program run:
```bash
java -cp ~/browser_promc.jar probrowser.NLO input.promc
```

# How this works
`promc` format is a zip file containing events stored as individual
[Protocol Buffers](https://developers.google.com/protocol-buffers/) files, as well as metadata describing the data.
The metadata includes Protocol Buffers .proto files,
definitions of physical particles and units,
and a `logfile.txt`, in which the user can provide extra information about the data set,
for example Monta Carlo generator settings.

The patch adds a `FortPro` directory to the MCFM directory.
The former contains:
1. `proto`: Protocol Buffers definitions,
2. `src_promc`: Protocol Buffers derived C++ code for writing events,
3. `src`: fortran bindings for writing promc files,
4. `mcfm`: extra MCFM code to inject the new functionality,
5. `reader`: an example program for reading promc files.

The `patch.sh` script replaces the `$MCFM/src/User/usercode_f77.f` file with a link to the new version
in `$MCFM/FortPro/mcfm/` and adds a link to `$MCFM/FortPro/mcfm/mcfmrun.f`.
A few extra compilation instructions are added to the `Install` scripts and the `makefile`.
This is done with `sed` commands.

# Credits
[Sergei Chekanov](https://github.com/chekanov) for designing the [promc](https://github.com/chekanov/ProMC) format and the original code for writing promc ntuples in MCFM.

[Kyle Strand](https://github.com/kyletstrand) for the original implementation of [FortPro](https://github.com/kyletstrand/FortranProMC).

[Ivan Pogrebnyak](https://github.com/ivankp) for this patch.
