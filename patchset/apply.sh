#!/bin/sh

for i in $(find usr/ -type f);do patch /$i $i; done;
