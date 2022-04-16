#!/bin/bash

while :
do
    date -u
    sleep 1
    trap "echo LOLZ" {1..15} 

 done
