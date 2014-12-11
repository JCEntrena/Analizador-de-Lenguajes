#!/bin/bash
# Script en bash que elimina las tildes de un archivo de texto y lo almacena todo en un archivo llamado final.txt
# Uso: eliminatildes.sh Archivo

sed 's/á/a/g' $1 | sed 's/à/a/g' | sed 's/Á/A/g' | sed 's/À/A/g' | sed 's/ä/a/g' | 
sed 's/í/i/g' | sed 's/ì/i/g' | sed 's/Í/I/g' | sed 's/Ì/I/g' | sed 's/ï/i/g' |
sed 's/é/e/g' | sed 's/è/e/g' | sed 's/É/E/g' | sed 's/È/E/g' | sed 's/ë/e/g' | sed 's/ê/e/g' |
sed 's/ó/o/g' | sed 's/ò/o/g' | sed 's/Ó/O/g' | sed 's/Ò/O/g' | sed 's/ö/o/g' | sed 's/Ö/O/g' | 
sed 's/ú/u/g' | sed 's/ù/u/g' | sed 's/Ú/U/g' | sed 's/Ù/U/g' | sed 's/ü/u/g' > final.txt
