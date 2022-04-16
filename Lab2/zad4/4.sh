#!/bin/bash

while getopts "n:a:m" OPTION
do
    case $OPTION in
	n) n=$OPTARG;;
    a) nazwatar=$OPTARG;;
    m) maska=$OPTARG;;
	*) echo "Usage: $0 -n timesincemodification -a archname -m mask"; exit 1;;
    esac
done

if test -z "$n" ; then
    echo "Brakuje licza dni do modyfikacji. Podaj liczbe dni np(10)"
    read n
fi

if test -z "$nazwatar" ; then
    echo "Podaj nazwe archiwum"
    read nazwatar
fi

if test -z "$maska" ; then
    echo "Brakuje maski. Podaj np *.pdf"
    read maska
fi

tar -cjf $nazwatar `find . -type f -name "$maska" -mtime -$n `

