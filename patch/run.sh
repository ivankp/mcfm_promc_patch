#!/bin/bash

if [ -z "$PROMC" ]; then
  echo "PROMC env variable is not set. Run setup.sh first"
fi

DIR=`pwd`
export PROMC_OUT=$DIR/out
rm -rf $PROMC_OUT

mkdir -p $PROMC_OUT

# ProMC settings to buld good file
#export PROMC=$PROMC
export PROMC_LOG=$PROMC_OUT
export PROMC_PROTO=$PROMC_OUT
echo "PROMC_LOG_DIR=$PROMC_LOG"
echo "PROMC_PROTO_DIR=$PROMC_PROTO"
echo "PROMC_OUT_DIR=$PROMC_OUT"

cp input.DAT $PROMC_LOG/logfile.txt
cp -r proto $PROMC_OUT/
cp input.DAT $PROMC_OUT/

./mcfm $PROMC_OUT input.DAT

echo "Done!"

