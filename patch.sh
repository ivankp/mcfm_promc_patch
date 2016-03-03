#!/bin/bash

PATCH_DIR=`sed 's/[^\/]*$//' <<< $0`patch
if [ ! -d "$PATCH_DIR" ]; then
  echo "Directory $PATCH_DIR does not exist"
  exit 1
fi

LHAPDF_DIR=""
MAKE_J_FLAG=""
MCFM_DIR=""
WITH_OMP="NO"
UNPATCH="NO"

for i in "$@"; do
  case $i in
    -h|--help)
    echo "Usage: $0 mcfm-dir [OPTIONS]"
    printf "  --help,-h\t\tprint this help and exit\n"
    printf "  mcfm-dir\t\tlocation of MCFM to patch (required)\n"
    printf "  --lhapdf\t\t=[${LHAPDF_DIR}] use lhapdf with mcfm\n"
    printf "  --omp\t\tuse omp\n"
    printf "  --make-j\t\t=[4] mcfm install scripts will use make -j\n"
    printf "  --unpatch\t\tcreate unpatch\n"
    exit
    shift # past argument=value
    ;;
    --lhapdf)
    LHAPDF_DIR="`lhapdf-config --prefix 2>/dev/null`"
    shift # past argument=value
    ;;
    --lhapdf=*)
    LHAPDF_DIR="${i#*=}"
    shift # past argument=value
    ;;
    --omp)
    WITH_OMP="YES"
    shift # past argument=value
    ;;
    --make-j)
    MAKE_J_FLAG="4"
    shift # past argument=value
    ;;
    --make-j=*)
    MAKE_J_FLAG="${i#*=}"
    shift # past argument=value
    ;;
    --unpatch)
    UNPATCH="YES"
    shift # past argument=value
    ;;
    --*)
    echo "Unknown option $i"
    exit 1
    ;;
    *)
    MCFM_DIR="$i"
    shift
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
  if [ ! -d "${MCFM_DIR}" ]; then
    echo "Directory ${MCFM_DIR} specified for MCFM location does not exist"
    exit 1
  fi
  echo "MCFM_DIR = ${MCFM_DIR}"
fi

# MCFM_VERSION ##################################
MCFM_VERSION=\
`sed -n "s/.*data codeversion\/'\([0-9\.]\+\)'\/.*/\1/p" $MCFM_DIR/src/Need/banner.f`
echo "MCFM_VERSION = ${MCFM_VERSION}"

# LHAPDF ########################################
if [ -n "${LHAPDF_DIR}" ]; then
  if [ ! -d "${LHAPDF_DIR}" ]; then
    echo "Directory ${LHAPDF_DIR} specified for LHAPDF location does not exist"
    exit 1
  fi
  echo "LHAPDF_DIR = ${LHAPDF_DIR}"
fi

# make unpatch
# -----------------------------------------------
if [ "$UNPATCH" == "YES" ]; then
  rm -rf unpatch unpatch.sh
  mkdir unpatch
  cp $MCFM_DIR/Install* $MCFM_DIR/makefile $MCFM_DIR/src/User/usercode_f77.f unpatch/
  printf "#!/bin/bash\n
rm -rf ${MCFM_DIR}/FortPro ${MCFM_DIR}/Bin/proto ${MCFM_DIR}/Bin/reader
rm -f $MCFM_DIR/src/User/mcfmrun.f
cp -v unpatch/Install* unpatch/makefile $MCFM_DIR/
cp -v unpatch/usercode_f77.f $MCFM_DIR/src/User/
" > unpatch.sh
  chmod +x unpatch.sh
  echo "created unpatch"
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
          s/if \[\$\([A-Z]\+\) == ''\]/if [ \"\$\1\" == \"\" ]/;
          s/^\(echo ''\)$/# Compile FortPro library\ncd FortPro; make; cd ..\n\n\1/;
          s|\(ln -s \$LHAPDFLIB/PDFsets Bin/PDFsets\)|#\1|" $f
  if [ -z "$LHAPDF_DIR" ]; then
    sed -i "s/^\( *set \)\? *LHAPDFLIB *=.*$/\#LHAPDFLIB=/" $f
  else
    sed -i "s|^\( *set \)\? *LHAPDFLIB *=.*$|LHAPDFLIB=${LHAPDF_DIR}/lib|" $f
  fi
  if [ -n "$MAKE_J_FLAG" ]; then
    sed -i "s/make\b/make -j${MAKE_J_FLAG}/" $f
  fi
  echo "patched $f"
done

# patch Makefile
# -----------------------------------------------
sed -i "s/^\(USEOMP\) *=.*$/\1 = ${WITH_OMP}/" $MCFM_DIR/makefile
sed -i '
/histofin.o \\/a mcfmrun.o \\
/LIBFLAGS *=.*/a \\nLIBFLAGS += -LFortPro -lFortPro\nLIBFLAGS += -L${PROMC}\/lib -lprotoc -lprotobuf -lprotobuf-lite -lcbook -lz
' $MCFM_DIR/makefile
if [ -z "$LHAPDF_DIR" ]; then
  sed -i "s/^\(PDFROUTINES\) *=.*$/\1 = NATIVE/" $MCFM_DIR/makefile
else
  sed -i "s/^\(PDFROUTINES\) *=.*$/\1 = LHAPDF/" $MCFM_DIR/makefile
fi
echo "patched makefile"

# copy extra Bin files
# -----------------------------------------------
cp -rv $PATCH_DIR/FortPro $MCFM_DIR/
cp -rv $PATCH_DIR/proto   $MCFM_DIR/Bin/
cp -rv $PATCH_DIR/reader  $MCFM_DIR/Bin/
#cp -v  $PATCH_DIR/run.sh  $MCFM_DIR/Bin/

DIR=`pwd`
cd $MCFM_DIR/Bin/reader
ln -s ../../FortPro/src_promc src
cd $DIR

echo "Done!"
