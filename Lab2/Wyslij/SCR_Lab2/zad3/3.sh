#!/bin/bash

# Skrypt wyszukuje dane pliki stworzone nie później
# niż N dni i tworzy archiwum tar o danej nazwie

nazwa_archiwum=$1
N=$2
maska=$3
tar -cjf $nazwa_archiwum `find . -type f  -name "$maska" -mtime -$N `


# Wpisuj "*.pdf" - jak szukasz rozszerzenia
# "NAZWA*" - jak szukasz danej nazwy

# nazwa_archiwum.tar Liczba_dni(2) "maska"
