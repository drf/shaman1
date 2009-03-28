#!/bin/bash

for arg in "fr" "it" "de" "el" "pt_BR" "es" "pl" "tr" "zh_CN" "mk" "cs" "nb" "nl" "lt" "ru" "en" "nn" "no" "es_CA"
do
	lupdate *.cxx src/* ui/* -ts translations/shaman_$arg.ts
	mkdir translations/$arg
	ts2po translations/shaman_$arg.ts -o translations/$arg/shaman_$arg.po
done

exit	
