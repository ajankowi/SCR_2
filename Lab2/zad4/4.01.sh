#!/bin/bash

usage() { echo "Usage: $0 -n [liczba dni]  -m [maska] -a [nazwa archiwum]" 1>&2; exit 1; }

while getopts ":n:m:a:" o; do
    case "${o}" in
	n)
	    dni=${OPTARG}
	    ;;
	m)
	    maska=${OPTARG}
	    ;;
	a)
	    nazwa=${OPTARG}
	    ;;
	*)
	    usage
	    ;;
    esac
done
shift $((OPTIND-1))

if [ -z "${dni}" ] && [ -z "${maska}" ] && [ -z "${nazwa}" ]; then
    usage
fi

if [ -z "${dni}" ]; then
    echo "Podaj ilsc dni np. 10"
    read dni
fi

if [ -z "${maska}" ]; then
    echo "Podaj maske np. *.pdf lub nazwa.*"
    read maska
fi

if [ -z "$nazwa" ]; then
    echo "Podaj nazwe archiwum tar np. Znalezione.tar"
    read nazwa
fi


tar -cjf $nazwa `find . -type f -name "$maska" -mtime -$dni `

