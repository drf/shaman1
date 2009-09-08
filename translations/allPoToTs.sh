#!/bin/bash

for arg in "fr" "it" "de" "el" "pt_BR" "es" "pl" "tr" "zh_CN" "mk" "cs" "nb" "nl" "lt" "ru" "nn" "no" "ca" "sr" "sr@latin"
do
	po2ts $arg/shaman_$arg.po shaman_$arg.ts
done

exit	
