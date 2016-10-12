#!/bin/bash

exe=$1

for file in "test/*.c";do
	cat $file | $exe 1>$file.out 2>$file.err
done
