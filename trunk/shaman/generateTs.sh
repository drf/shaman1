#!/bin/bash

for arg in "fr" "it" "de" "el" "pt_BR" "es" "pl" "tr" "zh_CN" "mk" "cs"
do
	lupdate *.cxx src/* ui/* -ts translations/shaman_$arg.ts
done

exit	
