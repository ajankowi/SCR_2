#!/bin/bash
LC_ALL=C
dzien=$(date +%u)
if [ $dzien -gt 5 ]
then
    echo Weekend!
else
    echo Witaj w pracy
fi

