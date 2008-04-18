#!/bin/bash

for arg in "fr" "it" "de" "el" "pt_BR" "es" "pl" "tr"
do
	lupdate *.cxx src/* ui/* -ts translations/shaman_$arg.ts
done

exit	
