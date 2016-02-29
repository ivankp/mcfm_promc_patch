#!/bin/bash

PATCH_DIR=`sed 's/[^\/]*$//' <<< $0`patch
if [ ! -d "$PATCH_DIR" ]; then
  echo "Directory $PATCH_DIR does not exist"
  exit 1
fi

LHAPDF_DIR="`lhapdf-config --prefix 2>/dev/null`"

for i in "$@"; do
  case $i in
    -h|--help)
    echo "Usage: $0 [OPTIONS]"
    printf "  --help,-h\t\tprint this help and exit\n"
    printf "  --mcfm-dir\t\tlocation of MCFM to patch\n"
    printf "  --lhapdf-dir\t\t[${LHAPDF_DIR}]\n"
    exit
    shift # past argument=value
    ;;
    --mcfm-dir=*)
    MCFM_DIR="${i#*=}"
    shift # past argument=value
    ;;
    --lhapdf-dir=*)
    LHAPDF_DIR="${i#*=}"
    shift # past argument=value
    ;;
    *)
    echo "Unknown option $i"
    exit 1
    ;;
  esac
done

# PROMC #########################################
if [ -z "$PROMC" ]; then
  echo 'PROMC variable not defined'
  echo 'You must source $PROMC/setup.sh to procede'
  exit 1
else
  echo "PROMC = ${PROMC}"
fi

# MCFM_DIR ######################################
if [ -z "${MCFM_DIR}" ]; then
  echo 'MCFM directory not specified'
  exit 1
else
  echo "MCFM_DIR = ${MCFM_DIR}"
fi

# MCFM_VERSION ##################################
MCFM_VERSION=\
`sed -n "s/.*data codeversion\/'\([0-9\.]\+\)'\/.*/\1/p" $MCFM_DIR/src/Need/banner.f`
echo "MCFM_VERSION = ${MCFM_VERSION}"

# LHAPDF ########################################
if [ -z "${LHAPDF_DIR}" ]; then
  echo 'Could not execute `lhapdf-config --prefix`'
  echo 'Run with --lhapdf-dir=/path/to/lhapdf/directory'
  exit 1
else
  echo "LHAPDF_DIR = ${LHAPDF_DIR}"
fi

# add extra source files
# -----------------------------------------------
for f in mcfmrun.f usercode_f77.f; do
  cp -v $PATCH_DIR/mcfm/$f $MCFM_DIR/src/User/
done
sed -i "s/MCFM [0-9\.]*/MCFM ${MCFM_VERSION}/g" $MCFM_DIR/src/User/mcfmrun.f

# patch Install scripts
# -----------------------------------------------
for f in `find ${MCFM_DIR} -type f -name 'Install*'`; do
  sed -i "s/^\( *set \)\? *CERNLIB *=.*$/\#CERNLIB=/;
          s|^\( *set \)\? *LHAPDFLIB *=.*$|LHAPDFLIB=${LHAPDF_DIR}/lib|;
          s/if \[\$\([A-Z]\+\) == ''\]/if [ \"\$\1\" == \"\" ]/;
          s/^\(echo ''\)$/# Compile FortPro library\ncd FortPro; make; cd ..\n\n\1/;
          s|\(ln -s \$LHAPDFLIB/PDFsets Bin/PDFsets\)|#\1|" $f
  echo "patched $f"
done

# patch Makefile
# -----------------------------------------------
sed -i '
s/^\(USEOMP\) *=.*$/\1 = NO/
s/^\(PDFROUTINES\) *=.*$/\1 = LHAPDF/
/histofin.o \\/a mcfmrun.o \\
/LIBFLAGS *=.*/a \\nLIBFLAGS +=-LFortPro -lFortPro\nLIBFLAGS +=-L${PROMC}/lib -lprotoc -lprotobuf -lprotobuf-lite -lcbook -lz
' $MCFM_DIR/makefile
echo "patched makefile"

# copy extra Bin files
# -----------------------------------------------
cp -rv $PATCH_DIR/FortPro $MCFM_DIR/
cp -rv $PATCH_DIR/proto   $MCFM_DIR/Bin/
cp -rv $PATCH_DIR/reader  $MCFM_DIR/Bin/
cp -v  $PATCH_DIR/run.sh  $MCFM_DIR/Bin/

DIR=`pwd`
cd $MCFM_DIR/Bin/reader
ln -s ../../FortPro/src_promc
cd $DIR

echo "Done!"
