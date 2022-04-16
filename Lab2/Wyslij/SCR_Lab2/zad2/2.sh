#!/bin/bash

for adres in $(cat adresy.txt)
do
    mutt -s "Temat" $adres -a spec.pdf < tresc.txt
done
