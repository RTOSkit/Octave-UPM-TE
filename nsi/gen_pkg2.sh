i=1; ls -d * | while read l; do echo "LangString DESC_sec"$i '${LANG_ENGLISH} "'`grep Description $l/packinfo/DESCRIPTION | cut -d ':' -f 2`'"'; let "i += 1"; done >> ../packages.txt
