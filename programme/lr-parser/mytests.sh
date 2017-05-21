#!/bin/bash
FILES=tests/test*
for f in $FILES
do
  echo "Processing $f file..."
  (exec lr-parser $f)  
done
