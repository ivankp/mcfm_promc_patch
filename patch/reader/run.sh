#!/bin/bash

FILE=$1 # promc file
promc_info  $FILE
promc_proto $FILE
promc_code
make

