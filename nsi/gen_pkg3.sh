i=1; ls -d * | while read l; do echo '!insertmacro MUI_DESCRIPTION_TEXT ${sec'$i'} $(DESC_sec'$i')'; let "i += 1"; done >> ../packages.txt
