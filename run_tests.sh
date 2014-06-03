#!/bin/dash
set -e
for i in $(find . -type d -name 'pr_*')
do
  echo $i
  cd $i
  make test
  cd ../
done
