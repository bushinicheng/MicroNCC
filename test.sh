#!/bin/bash

cd test
exe=../$1

for file in `ls *.c`;do
	cat $file | $exe 1>${file}.out 2>${file}.err
done
