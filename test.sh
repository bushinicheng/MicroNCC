#!/bin/bash

exe=./$1
dir=output
mkdir -p ${dir}

for file in `find test -name "*.cmm"`;do
	bname=`basename ${file}`
	$exe $file 1>${dir}/${bname/cmm/out} 2>${dir}/${bname/cmm/err}
done
