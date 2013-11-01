# Octave NSIS Installation script

# Download and unpack the three 7z files
# 

;;LoadLanguageFile "${NSISDIR}\Contrib\Language files\English.nlf"


!define OCTAVE_VERSION "3.6.2"
!define UPM_VERSION "R8"
!define EXE_VERSION "3.6.2"
!define OCTAVE_DIR "Octave-UPM-${UPM_VERSION}"
!define OCTAVE_ROOT "${OCTAVE_DIR}"
!define OCTAVE_PKGS_DIR "Octave_UPM_pkgs"
!define OCTAVE_PKGS_ROOT "${OCTAVE_PKGS_DIR}/Octave_UPM"
!define NOTEPAD_ROOT "npp.5.9.8.bin.minimalist"

!define PRODUCT_NAME "Octave UPM"
!define PRODUCT_VERSION "${UPM_VERSION}"

!include MUI.nsh

;;!define MUI_ICON "${OCTAVE_DIR}\octave\share\octave\${OCTAVE_VERSION}\imagelib\octave-logo.ico"

SetCompressor /SOLID lzma
SetCompressorDictSize 16
SetDatablockOptimize on



; Welcome Page

!define MUI_WELCOMEFINISHPAGE_BITMAP "${OCTAVE_DIR}\octave\share\octave\${OCTAVE_VERSION}\imagelib\EscUpmPolit.bmp"
!insertmacro MUI_PAGE_WELCOME
; License page
!define MUI_LICENSEPAGE_TEXT_BOTTOM "Press Next to continue"
!define MUI_LICENSEPAGE_BUTTON "Next >"
!insertmacro MUI_PAGE_LICENSE "gpl.txt"

; Directory page
!define MUI_DIRECTORYPAGE_TEXT_TOP  "This is a customized version of GNU Octave, adapted to the teaching needs at the Technical University of Madrid (UPM). This program will install ${PRODUCT_NAME} ${PRODUCT_VERSION} in the following directory .$\r$\n$\r$\nIMPORTANT: Please don't change the destination directory, or Octave UPM might not work."
!insertmacro MUI_PAGE_DIRECTORY

; Components page
!define MUI_COMPONENTSPAGE_TEXT_TOP "Review the components that will be installed. Click Install to start the installation."
!insertmacro MUI_PAGE_COMPONENTS

; Start menu page
var SMFOLDERNAME
!define MUI_STARTMENUPAGE_DEFAULTFOLDER "Octave UPM ${UPM_VERSION}"
!insertmacro MUI_PAGE_STARTMENU "Startmenu" $SMFOLDERNAME

; Instfiles page
!insertmacro MUI_PAGE_INSTFILES

; Finish Page
!insertmacro MUI_PAGE_FINISH

; Uninstaller pages
!insertmacro MUI_UNPAGE_WELCOME
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES
!insertmacro MUI_UNPAGE_FINISH

; Language files
!insertmacro MUI_LANGUAGE "English"

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"

!define REGLOC "Software\Microsoft\Windows\CurrentVersion\Uninstall\Octave UPM ${UPM_VERSION}"

OutFile "Octave-UPM-${UPM_VERSION}-setup.exe"

InstallDir "C:\Octave\Octave-UPM-${UPM_VERSION}"

ShowInstDetails show

ShowUnInstDetails show

XPStyle off

ComponentText

Function SetUserContext

   Push $0
   ClearErrors
   UserInfo::GetName
   IfErrors noadmin
   UserInfo::GetAccountType
   Pop $0
   StrCmp $0 "Admin" admin noadmin
admin:
   SetShellVarContext all
   Goto done
noadmin:
   SetShellVarContext current
   Goto done
done:
   Pop $0
   
FunctionEnd

Function un.SetUserContext

   Push $0
   ClearErrors
   UserInfo::GetName
   IfErrors noadmin
   UserInfo::GetAccountType
   Pop $0
   StrCmp $0 "Admin" admin noadmin
admin:
   SetShellVarContext all
   Goto done
noadmin:
   SetShellVarContext current
   Goto done
done:
   Pop $0
   
FunctionEnd

Section "Octave"
 SectionIn RO

 SetOutPath "$INSTDIR"
 File /r "${OCTAVE_ROOT}\octave\*.*"
  
 ; Shortcut's "Start In" Property seems to be defined by the current output path...
 SetOutPath "$INSTDIR\bin"
   
 ; Shortcuts
 !insertmacro MUI_STARTMENU_WRITE_BEGIN Startmenu
 CreateDirectory "$SMPROGRAMS\$SMFOLDERNAME"
 CreateShortCut "$SMPROGRAMS\$SMFOLDERNAME\Octave UPM.lnk" "$INSTDIR\bin\octave-upm.exe" "" "$INSTDIR\share\octave\${OCTAVE_VERSION}\imagelib\octave-logo.ico" 0
 CreateShortCut "$SMPROGRAMS\$SMFOLDERNAME\Octave UPM (terminal in MATLAB mode).lnk" "$INSTDIR\bin\octave-${EXE_VERSION}.exe" "-q --traditional" "$INSTDIR\share\octave\${OCTAVE_VERSION}\imagelib\octave-logo.ico" 0
 CreateShortCut "$SMPROGRAMS\$SMFOLDERNAME\GNU Octave ${EXE_VERSION}.lnk" "$INSTDIR\bin\octave-${EXE_VERSION}.exe" "" "$INSTDIR\share\octave\${OCTAVE_VERSION}\imagelib\octave-logo.ico" 0
 CreateShortCut "$SMPROGRAMS\$SMFOLDERNAME\Uninstall.lnk" "$INSTDIR\uninstaller.exe"
   
 CreateDirectory "$SMPROGRAMS\$SMFOLDERNAME\Documentation"
 CreateDirectory "$SMPROGRAMS\$SMFOLDERNAME\Documentation\PDF"
 CreateDirectory "$SMPROGRAMS\$SMFOLDERNAME\Documentation\HTML"
   
   
 CreateShortCut "$SMPROGRAMS\$SMFOLDERNAME\Documentation\PDF\GNU Octave Manual.lnk" "$INSTDIR\doc\octave\pdf\octave.pdf"
 CreateShortCut "$SMPROGRAMS\$SMFOLDERNAME\Documentation\PDF\FAQ.lnk" "$INSTDIR\doc\octave\pdf\OctaveFAQ.pdf"
 CreateShortCut "$SMPROGRAMS\$SMFOLDERNAME\Documentation\PDF\Quick Reference Card.lnk" "$INSTDIR\doc\octave\pdf\refcard-a4.pdf"
; CreateShortCut "$SMPROGRAMS\$SMFOLDERNAME\Documentation\PDF\Octave C++ API.lnk" "$INSTDIR\doc\octave\pdf\liboctave.pdf"
   
CreateShortCut "$SMPROGRAMS\$SMFOLDERNAME\Documentation\HTML\GNU Octave Manual.lnk" "$INSTDIR\doc\octave\html\interpreter\index.html"
CreateShortCut "$SMPROGRAMS\$SMFOLDERNAME\Documentation\HTML\Octave C++ API.lnk" "$INSTDIR\doc\octave\html\liboctave\index.html"


 CreateShortCut "$DESKTOP\Octave UPM.lnk" "$INSTDIR\bin\octave-upm.exe" "Octave UPM" "$INSTDIR\share\octave\${OCTAVE_VERSION}\imagelib\octave-logo.ico" 0   


   
 !insertmacro MUI_STARTMENU_WRITE_END
   
 ; Uninstaller
 WriteUninstaller $INSTDIR\uninstaller.exe
   
 ; Create entry in "Add/Remove programs"
 WriteRegStr SHELL_CONTEXT "${REGLOC}" "DisplayName" "Octave UPM ${UPM_VERSION}"
 WriteRegStr SHELL_CONTEXT "${REGLOC}" "DisplayVersion" "${UPM_VERSION}"
 WriteRegStr SHELL_CONTEXT "${REGLOC}" "InstallLocation" $INSTDIR
 WriteRegStr SHELL_CONTEXT "${REGLOC}" "UninstallString" "$INSTDIR\uninstaller.exe"
 WriteRegDWORD SHELL_CONTEXT "${REGLOC}" "NoModify" 1
 WriteRegDWORD SHELL_CONTEXT "${REGLOC}" "NoRepair" 1
SectionEnd

SectionGroup "Octave Packages"
Section /o "actuarial-1.1.0" sec1
SetOutPath "$INSTDIR\share\octave\packages\actuarial-1.1.0"
File /r "${OCTAVE_ROOT}\packages\actuarial-1.1.0\*.*"
SectionEnd
Section /o "ad-1.0.6" sec2
SetOutPath "$INSTDIR\share\octave\packages\ad-1.0.6"
File /r "${OCTAVE_ROOT}\packages\ad-1.0.6\*.*"
SectionEnd
Section /o "benchmark-1.1.1" sec3
SetOutPath "$INSTDIR\share\octave\packages\benchmark-1.1.1"
File /r "${OCTAVE_ROOT}\packages\benchmark-1.1.1\*.*"
SectionEnd
Section /o "bim-1.0.2" sec4
SetOutPath "$INSTDIR\share\octave\packages\bim-1.0.2"
File /r "${OCTAVE_ROOT}\packages\bim-1.0.2\*.*"
SectionEnd
Section /o "bioinfo-0.1.2" sec5
SetOutPath "$INSTDIR\share\octave\packages\bioinfo-0.1.2"
File /r "${OCTAVE_ROOT}\packages\bioinfo-0.1.2\*.*"
SectionEnd
Section /o "civil-engineering-1.0.7" sec6
SetOutPath "$INSTDIR\share\octave\packages\civil-engineering-1.0.7"
File /r "${OCTAVE_ROOT}\packages\civil-engineering-1.0.7\*.*"
SectionEnd
Section /o "combinatorics-1.0.9" sec7
SetOutPath "$INSTDIR\share\octave\packages\combinatorics-1.0.9"
File /r "${OCTAVE_ROOT}\packages\combinatorics-1.0.9\*.*"
SectionEnd
Section /o "communications-1.1.1" sec8
SetOutPath "$INSTDIR\share\octave\packages\communications-1.1.1"
File /r "${OCTAVE_ROOT}\packages\communications-1.1.1\*.*"
SectionEnd
Section /o "control-2.3.51" sec9
SetOutPath "$INSTDIR\share\octave\packages\control-2.3.51"
File /r "${OCTAVE_ROOT}\packages\control-2.3.51\*.*"
SectionEnd
Section /o "dataframe-0.9.1" sec10
SetOutPath "$INSTDIR\share\octave\packages\dataframe-0.9.1"
File /r "${OCTAVE_ROOT}\packages\dataframe-0.9.1\*.*"
SectionEnd
Section /o "data-smoothing-1.3.0" sec11
SetOutPath "$INSTDIR\share\octave\packages\data-smoothing-1.3.0"
File /r "${OCTAVE_ROOT}\packages\data-smoothing-1.3.0\*.*"
SectionEnd
Section /o "dicom-0.1.1" sec12
SetOutPath "$INSTDIR\share\octave\packages\dicom-0.1.1"
File /r "${OCTAVE_ROOT}\packages\dicom-0.1.1\*.*"
SectionEnd
Section /o "econometrics-1.0.8" sec13
SetOutPath "$INSTDIR\share\octave\packages\econometrics-1.0.8"
File /r "${OCTAVE_ROOT}\packages\econometrics-1.0.8\*.*"
SectionEnd
Section /o "es-0.0.4" sec14
SetOutPath "$INSTDIR\share\octave\packages\es-0.0.4"
File /r "${OCTAVE_ROOT}\packages\es-0.0.4\*.*"
SectionEnd
Section /o "fenv-0.1.0" sec15
SetOutPath "$INSTDIR\share\octave\packages\fenv-0.1.0"
File /r "${OCTAVE_ROOT}\packages\fenv-0.1.0\*.*"
SectionEnd
Section /o "financial-0.4.0" sec16
SetOutPath "$INSTDIR\share\octave\packages\financial-0.4.0"
File /r "${OCTAVE_ROOT}\packages\financial-0.4.0\*.*"
SectionEnd
Section /o "fits-1.0.1" sec17
SetOutPath "$INSTDIR\share\octave\packages\fits-1.0.1"
File /r "${OCTAVE_ROOT}\packages\fits-1.0.1\*.*"
SectionEnd
Section /o "fl-core-1.0.0" sec18
SetOutPath "$INSTDIR\share\octave\packages\fl-core-1.0.0"
File /r "${OCTAVE_ROOT}\packages\fl-core-1.0.0\*.*"
SectionEnd
Section /o "fpl-1.2.0" sec19
SetOutPath "$INSTDIR\share\octave\packages\fpl-1.2.0"
File /r "${OCTAVE_ROOT}\packages\fpl-1.2.0\*.*"
SectionEnd
Section /o "fuzzy-logic-toolkit-0.3.0" sec20
SetOutPath "$INSTDIR\share\octave\packages\fuzzy-logic-toolkit-0.3.0"
File /r "${OCTAVE_ROOT}\packages\fuzzy-logic-toolkit-0.3.0\*.*"
SectionEnd
Section /o "ga-0.10.0" sec21
SetOutPath "$INSTDIR\share\octave\packages\ga-0.10.0"
File /r "${OCTAVE_ROOT}\packages\ga-0.10.0\*.*"
SectionEnd
Section /o "general-1.3.1" sec22
SetOutPath "$INSTDIR\share\octave\packages\general-1.3.1"
File /r "${OCTAVE_ROOT}\packages\general-1.3.1\*.*"
SectionEnd
Section /o "general-1.3.2" sec23
SetOutPath "$INSTDIR\share\octave\packages\general-1.3.2"
File /r "${OCTAVE_ROOT}\packages\general-1.3.2\*.*"
SectionEnd
Section /o "generate_html-0.1.4" sec24
SetOutPath "$INSTDIR\share\octave\packages\generate_html-0.1.4"
File /r "${OCTAVE_ROOT}\packages\generate_html-0.1.4\*.*"
SectionEnd
Section /o "geometry-1.4.1" sec25
SetOutPath "$INSTDIR\share\octave\packages\geometry-1.4.1"
File /r "${OCTAVE_ROOT}\packages\geometry-1.4.1\*.*"
SectionEnd
Section /o "geometry-1.5.0" sec26
SetOutPath "$INSTDIR\share\octave\packages\geometry-1.5.0"
File /r "${OCTAVE_ROOT}\packages\geometry-1.5.0\*.*"
SectionEnd
Section /o "gnuplot-1.0.1" sec27
SetOutPath "$INSTDIR\share\octave\packages\gnuplot-1.0.1"
File /r "${OCTAVE_ROOT}\packages\gnuplot-1.0.1\*.*"
SectionEnd
Section /o "gsl-1.0.8" sec28
SetOutPath "$INSTDIR\share\octave\packages\gsl-1.0.8"
File /r "${OCTAVE_ROOT}\packages\gsl-1.0.8\*.*"
SectionEnd
Section /o "ident-1.0.7" sec29
SetOutPath "$INSTDIR\share\octave\packages\ident-1.0.7"
File /r "${OCTAVE_ROOT}\packages\ident-1.0.7\*.*"
SectionEnd
Section /o "image-1.0.15" sec30
SetOutPath "$INSTDIR\share\octave\packages\image-1.0.15"
File /r "${OCTAVE_ROOT}\packages\image-1.0.15\*.*"
SectionEnd
Section /o "image-2.0.0" sec31
SetOutPath "$INSTDIR\share\octave\packages\image-2.0.0"
File /r "${OCTAVE_ROOT}\packages\image-2.0.0\*.*"
SectionEnd
Section /o "informationtheory-0.1.8" sec32
SetOutPath "$INSTDIR\share\octave\packages\informationtheory-0.1.8"
File /r "${OCTAVE_ROOT}\packages\informationtheory-0.1.8\*.*"
SectionEnd
Section /o "integration-1.0.7" sec33
SetOutPath "$INSTDIR\share\octave\packages\integration-1.0.7"
File /r "${OCTAVE_ROOT}\packages\integration-1.0.7\*.*"
SectionEnd
Section /o "io-1.0.18" sec34
SetOutPath "$INSTDIR\share\octave\packages\io-1.0.18"
File /r "${OCTAVE_ROOT}\packages\io-1.0.18\*.*"
SectionEnd
Section /o "io-1.0.19" sec35
SetOutPath "$INSTDIR\share\octave\packages\io-1.0.19"
File /r "${OCTAVE_ROOT}\packages\io-1.0.19\*.*"
SectionEnd
Section /o "irsa-1.0.7" sec36
SetOutPath "$INSTDIR\share\octave\packages\irsa-1.0.7"
File /r "${OCTAVE_ROOT}\packages\irsa-1.0.7\*.*"
SectionEnd
Section /o "java-1.2.8" sec37
SetOutPath "$INSTDIR\share\octave\packages\java-1.2.8"
File /r "${OCTAVE_ROOT}\packages\java-1.2.8\*.*"
SectionEnd
Section /o "linear-algebra-2.2.0" sec38
SetOutPath "$INSTDIR\share\octave\packages\linear-algebra-2.2.0"
File /r "${OCTAVE_ROOT}\packages\linear-algebra-2.2.0\*.*"
SectionEnd
Section /o "lssa-0.1.2" sec39
SetOutPath "$INSTDIR\share\octave\packages\lssa-0.1.2"
File /r "${OCTAVE_ROOT}\packages\lssa-0.1.2\*.*"
SectionEnd
Section /o "mapping-1.0.7" sec40
SetOutPath "$INSTDIR\share\octave\packages\mapping-1.0.7"
File /r "${OCTAVE_ROOT}\packages\mapping-1.0.7\*.*"
SectionEnd
Section /o "mechanics-1.2.0" sec41
SetOutPath "$INSTDIR\share\octave\packages\mechanics-1.2.0"
File /r "${OCTAVE_ROOT}\packages\mechanics-1.2.0\*.*"
SectionEnd
Section /o "miscellaneous-1.1.0" sec42
SetOutPath "$INSTDIR\share\octave\packages\miscellaneous-1.1.0"
File /r "${OCTAVE_ROOT}\packages\miscellaneous-1.1.0\*.*"
SectionEnd
Section /o "missing-functions-1.0.2" sec43
SetOutPath "$INSTDIR\share\octave\packages\missing-functions-1.0.2"
File /r "${OCTAVE_ROOT}\packages\missing-functions-1.0.2\*.*"
SectionEnd
Section /o "msh-1.0.2" sec44
SetOutPath "$INSTDIR\share\octave\packages\msh-1.0.2"
File /r "${OCTAVE_ROOT}\packages\msh-1.0.2\*.*"
SectionEnd
Section /o "nan-2.5.5" sec45
SetOutPath "$INSTDIR\share\octave\packages\nan-2.5.5"
File /r "${OCTAVE_ROOT}\packages\nan-2.5.5\*.*"
SectionEnd
Section /o "ncarray-1.0.0" sec46
SetOutPath "$INSTDIR\share\octave\packages\ncarray-1.0.0"
File /r "${OCTAVE_ROOT}\packages\ncarray-1.0.0\*.*"
SectionEnd
Section /o "nlwing2-1.2.0" sec47
SetOutPath "$INSTDIR\share\octave\packages\nlwing2-1.2.0"
File /r "${OCTAVE_ROOT}\packages\nlwing2-1.2.0\*.*"
SectionEnd
Section /o "nnet-0.1.13" sec48
SetOutPath "$INSTDIR\share\octave\packages\nnet-0.1.13"
File /r "${OCTAVE_ROOT}\packages\nnet-0.1.13\*.*"
SectionEnd
Section /o "nurbs-1.3.6" sec49
SetOutPath "$INSTDIR\share\octave\packages\nurbs-1.3.6"
File /r "${OCTAVE_ROOT}\packages\nurbs-1.3.6\*.*"
SectionEnd
Section /o "ocs-0.1.3" sec50
SetOutPath "$INSTDIR\share\octave\packages\ocs-0.1.3"
File /r "${OCTAVE_ROOT}\packages\ocs-0.1.3\*.*"
SectionEnd
Section /o "octcdf-1.1.4" sec51
SetOutPath "$INSTDIR\share\octave\packages\octcdf-1.1.4"
File /r "${OCTAVE_ROOT}\packages\octcdf-1.1.4\*.*"
SectionEnd
Section /o "octcdf-1.1.5" sec52
SetOutPath "$INSTDIR\share\octave\packages\octcdf-1.1.5"
File /r "${OCTAVE_ROOT}\packages\octcdf-1.1.5\*.*"
SectionEnd
Section /o "octclip-1.0.0" sec53
SetOutPath "$INSTDIR\share\octave\packages\octclip-1.0.0"
File /r "${OCTAVE_ROOT}\packages\octclip-1.0.0\*.*"
SectionEnd
Section /o "octgpr-1.2.0" sec54
SetOutPath "$INSTDIR\share\octave\packages\octgpr-1.2.0"
File /r "${OCTAVE_ROOT}\packages\octgpr-1.2.0\*.*"
SectionEnd
Section /o "octproj-1.1.0" sec55
SetOutPath "$INSTDIR\share\octave\packages\octproj-1.1.0"
File /r "${OCTAVE_ROOT}\packages\octproj-1.1.0\*.*"
SectionEnd
Section /o "odebvp-1.0.6" sec56
SetOutPath "$INSTDIR\share\octave\packages\odebvp-1.0.6"
File /r "${OCTAVE_ROOT}\packages\odebvp-1.0.6\*.*"
SectionEnd
Section /o "odepkg-0.8.2" sec57
SetOutPath "$INSTDIR\share\octave\packages\odepkg-0.8.2"
File /r "${OCTAVE_ROOT}\packages\odepkg-0.8.2\*.*"
SectionEnd
Section /o "optim-1.1.0" sec58
SetOutPath "$INSTDIR\share\octave\packages\optim-1.1.0"
File /r "${OCTAVE_ROOT}\packages\optim-1.1.0\*.*"
SectionEnd
Section /o "optim-1.2.0" sec59
SetOutPath "$INSTDIR\share\octave\packages\optim-1.2.0"
File /r "${OCTAVE_ROOT}\packages\optim-1.2.0\*.*"
SectionEnd
Section /o "optiminterp-0.3.3" sec60
SetOutPath "$INSTDIR\share\octave\packages\optiminterp-0.3.3"
File /r "${OCTAVE_ROOT}\packages\optiminterp-0.3.3\*.*"
SectionEnd
Section /o "outliers-0.13.9" sec61
SetOutPath "$INSTDIR\share\octave\packages\outliers-0.13.9"
File /r "${OCTAVE_ROOT}\packages\outliers-0.13.9\*.*"
SectionEnd
Section /o "physicalconstants-0.1.7" sec62
SetOutPath "$INSTDIR\share\octave\packages\physicalconstants-0.1.7"
File /r "${OCTAVE_ROOT}\packages\physicalconstants-0.1.7\*.*"
SectionEnd
Section /o "plot-1.1.0" sec63
SetOutPath "$INSTDIR\share\octave\packages\plot-1.1.0"
File /r "${OCTAVE_ROOT}\packages\plot-1.1.0\*.*"
SectionEnd
Section /o "pt_br-1.0.9" sec64
SetOutPath "$INSTDIR\share\octave\packages\pt_br-1.0.9"
File /r "${OCTAVE_ROOT}\packages\pt_br-1.0.9\*.*"
SectionEnd
Section /o "quaternion-2.0.0" sec65
SetOutPath "$INSTDIR\share\octave\packages\quaternion-2.0.0"
File /r "${OCTAVE_ROOT}\packages\quaternion-2.0.0\*.*"
SectionEnd
Section /o "queueing-1.1.0" sec66
SetOutPath "$INSTDIR\share\octave\packages\queueing-1.1.0"
File /r "${OCTAVE_ROOT}\packages\queueing-1.1.0\*.*"
SectionEnd
Section /o "secs1d-0.0.9" sec67
SetOutPath "$INSTDIR\share\octave\packages\secs1d-0.0.9"
File /r "${OCTAVE_ROOT}\packages\secs1d-0.0.9\*.*"
SectionEnd
Section /o "secs2d-0.0.8" sec68
SetOutPath "$INSTDIR\share\octave\packages\secs2d-0.0.8"
File /r "${OCTAVE_ROOT}\packages\secs2d-0.0.8\*.*"
SectionEnd
Section /o "secs3d-0.0.1" sec69
SetOutPath "$INSTDIR\share\octave\packages\secs3d-0.0.1"
File /r "${OCTAVE_ROOT}\packages\secs3d-0.0.1\*.*"
SectionEnd
Section /o "signal-1.1.3" sec70
SetOutPath "$INSTDIR\share\octave\packages\signal-1.1.3"
File /r "${OCTAVE_ROOT}\packages\signal-1.1.3\*.*"
SectionEnd
Section /o "signal-1.2.0" sec71
SetOutPath "$INSTDIR\share\octave\packages\signal-1.2.0"
File /r "${OCTAVE_ROOT}\packages\signal-1.2.0\*.*"
SectionEnd
Section /o "simp-1.1.0" sec72
SetOutPath "$INSTDIR\share\octave\packages\simp-1.1.0"
File /r "${OCTAVE_ROOT}\packages\simp-1.1.0\*.*"
SectionEnd
Section /o "sockets-1.0.7" sec73
SetOutPath "$INSTDIR\share\octave\packages\sockets-1.0.7"
File /r "${OCTAVE_ROOT}\packages\sockets-1.0.7\*.*"
SectionEnd
Section /o "specfun-1.1.0" sec74
SetOutPath "$INSTDIR\share\octave\packages\specfun-1.1.0"
File /r "${OCTAVE_ROOT}\packages\specfun-1.1.0\*.*"
SectionEnd
Section /o "special-matrix-1.0.7" sec75
SetOutPath "$INSTDIR\share\octave\packages\special-matrix-1.0.7"
File /r "${OCTAVE_ROOT}\packages\special-matrix-1.0.7\*.*"
SectionEnd
Section /o "splines-1.0.7" sec76
SetOutPath "$INSTDIR\share\octave\packages\splines-1.0.7"
File /r "${OCTAVE_ROOT}\packages\splines-1.0.7\*.*"
SectionEnd
Section /o "statistics-1.1.3" sec77
SetOutPath "$INSTDIR\share\octave\packages\statistics-1.1.3"
File /r "${OCTAVE_ROOT}\packages\statistics-1.1.3\*.*"
SectionEnd
Section /o "strings-1.1.0" sec78
SetOutPath "$INSTDIR\share\octave\packages\strings-1.1.0"
File /r "${OCTAVE_ROOT}\packages\strings-1.1.0\*.*"
SectionEnd
Section /o "struct-1.0.10" sec79
SetOutPath "$INSTDIR\share\octave\packages\struct-1.0.10"
File /r "${OCTAVE_ROOT}\packages\struct-1.0.10\*.*"
SectionEnd
Section /o "symband-1.0.10" sec80
SetOutPath "$INSTDIR\share\octave\packages\symband-1.0.10"
File /r "${OCTAVE_ROOT}\packages\symband-1.0.10\*.*"
SectionEnd
Section /o "symbolic-1.1.0" sec81
SetOutPath "$INSTDIR\share\octave\packages\symbolic-1.1.0"
File /r "${OCTAVE_ROOT}\packages\symbolic-1.1.0\*.*"
SectionEnd
Section /o "time-2.0.0" sec82
SetOutPath "$INSTDIR\share\octave\packages\time-2.0.0"
File /r "${OCTAVE_ROOT}\packages\time-2.0.0\*.*"
SectionEnd
Section /o "tsa-4.2.4" sec83
SetOutPath "$INSTDIR\share\octave\packages\tsa-4.2.4"
File /r "${OCTAVE_ROOT}\packages\tsa-4.2.4\*.*"
SectionEnd
Section /o "video-1.0.2" sec84
SetOutPath "$INSTDIR\share\octave\packages\video-1.0.2"
File /r "${OCTAVE_ROOT}\packages\video-1.0.2\*.*"
SectionEnd
Section /o "vrml-1.0.13" sec85
SetOutPath "$INSTDIR\share\octave\packages\vrml-1.0.13"
File /r "${OCTAVE_ROOT}\packages\vrml-1.0.13\*.*"
SectionEnd
Section /o "windows-1.1.0" sec86
SetOutPath "$INSTDIR\share\octave\packages\windows-1.1.0"
File /r "${OCTAVE_ROOT}\packages\windows-1.1.0\*.*"
SectionEnd
Section /o "xraylib-1.0.8" sec87
SetOutPath "$INSTDIR\share\octave\packages\xraylib-1.0.8"
File /r "${OCTAVE_ROOT}\packages\xraylib-1.0.8\*.*"
SectionEnd
Section /o "zenity-0.5.7" sec88
SetOutPath "$INSTDIR\share\octave\packages\zenity-0.5.7"
File /r "${OCTAVE_ROOT}\packages\zenity-0.5.7\*.*"
SectionEnd

SectionGroupEnd

LangString DESC_sec1 ${LANG_ENGLISH} " Actuarial functions for Casualty and Property lines."
LangString DESC_sec2 ${LANG_ENGLISH} " Automatic Forward Differentiation"
LangString DESC_sec3 ${LANG_ENGLISH} " The package contains code used to benchmark speed of Octave."
LangString DESC_sec4 ${LANG_ENGLISH} " Package for solving Diffusion Advection Reaction (DAR) Partial Differential Equations based on the Finite Volume Scharfetter-Gummel (FVSG) method a.k.a Box Integration Method (BIM)"
LangString DESC_sec5 ${LANG_ENGLISH} " Bioinformatics manipulation"
LangString DESC_sec6 ${LANG_ENGLISH} " Functions to solution some ODE's in Civil Engineering."
LangString DESC_sec7 ${LANG_ENGLISH} " Combinatorics functions, incuding partitioning."
LangString DESC_sec8 ${LANG_ENGLISH} " Digital Communications, Error Correcting Codes (Channel Code), Source Code functions, Modulation and Galois Fields"
LangString DESC_sec9 ${LANG_ENGLISH} " Octave control systems package based on the proven SLICOT library"
LangString DESC_sec10 ${LANG_ENGLISH} " Data manipulation toolbox similar to R data.frame"
LangString DESC_sec11 ${LANG_ENGLISH} " Algorithms for smoothing noisy data"
LangString DESC_sec12 ${LANG_ENGLISH} " Digital communications in medicine (DICOM) file io. "
LangString DESC_sec13 ${LANG_ENGLISH} " Econometrics functions including MLE and GMM based techniques."
LangString DESC_sec14 ${LANG_ENGLISH} " Spanish package for the construction of native language"
LangString DESC_sec15 ${LANG_ENGLISH} " On supported architectures, change the rounding mode of the floating point arithmetics (to nearest, up, down, to zero) or change the precision of the arithmetical operations (single, double, double extended). Experimentally test the properties of the floating point arithmetics."
LangString DESC_sec16 ${LANG_ENGLISH} " Financial manipulation, plotting functions and additional"
LangString DESC_sec17 ${LANG_ENGLISH} " The Octave-FITS package provides functions for"
LangString DESC_sec18 ${LANG_ENGLISH} " The package contains code for basic functions in Fuzzy Logic for Octave."
LangString DESC_sec19 ${LANG_ENGLISH} " Collection of routines to save data in different graphical formats."
LangString DESC_sec20 ${LANG_ENGLISH} " A mostly MATLAB-compatible fuzzy logic toolkit for Octave."
LangString DESC_sec21 ${LANG_ENGLISH} " Genetic optimization code"
LangString DESC_sec22 ${LANG_ENGLISH} " General tools for Octave, string dictionary, parallel computing."
LangString DESC_sec23 ${LANG_ENGLISH} " General tools for Octave, string dictionary, parallel computing."
LangString DESC_sec24 ${LANG_ENGLISH} " This package provides functions for generating HTML pages that"
LangString DESC_sec25 ${LANG_ENGLISH} " Library for geometric computing extending MatGeom functions. Useful to create, transform, manipulate and display geometric primitives."
LangString DESC_sec26 ${LANG_ENGLISH} " Library for geometric computing extending MatGeom functions. Useful to create, transform, manipulate and display geometric primitives."
LangString DESC_sec27 ${LANG_ENGLISH} " Scripts to save data in gnuplot-readable formats,"
LangString DESC_sec28 ${LANG_ENGLISH} " Octave bindings to the GNU Scientific Library"
LangString DESC_sec29 ${LANG_ENGLISH} " Addition System Indentification Control functions."
LangString DESC_sec30 ${LANG_ENGLISH} " The Octave-forge Image package provides functions for"
LangString DESC_sec31 ${LANG_ENGLISH} " The Octave-forge Image package provides functions for"
LangString DESC_sec32 ${LANG_ENGLISH} " Functions and routines for basic Information Theory definitions, and source coding."
LangString DESC_sec33 ${LANG_ENGLISH} " Toolbox for 1-D, 2-D, and n-D Numerical Integration"
LangString DESC_sec34 ${LANG_ENGLISH} " Input/Output in external formats."
LangString DESC_sec35 ${LANG_ENGLISH} " Input/Output in external formats."
LangString DESC_sec36 ${LANG_ENGLISH} " Irregular sampling analysis."
LangString DESC_sec37 ${LANG_ENGLISH} " Provides Java interface with OO-like Java objects manipulation"
LangString DESC_sec38 ${LANG_ENGLISH} " Additional linear algebra code, including general SVD and matrix functions."
LangString DESC_sec39 ${LANG_ENGLISH} " A package implementing tools to compute spectral decompositions of"
LangString DESC_sec40 ${LANG_ENGLISH} " Simple Mapping functions. "
LangString DESC_sec41 ${LANG_ENGLISH} " Library with functions useful for numerical computation in classical mechanics and structural analysis."
LangString DESC_sec42 ${LANG_ENGLISH} " Miscellaneous tools that don't fit somewhere else."
LangString DESC_sec43 ${LANG_ENGLISH} " Find functions that are in Matlab but not in Octave."
LangString DESC_sec44 ${LANG_ENGLISH} " Create and manage triangular and tetrahedral meshes for Finite Element or Finite Volume PDE solvers. Use a mesh data structure compatible with PDEtool. Rely on gmsh for unstructured mesh generation."
LangString DESC_sec45 ${LANG_ENGLISH} " A statistics and machine learning toolbox for Octave and Matlab for data with and w/o missing values."
LangString DESC_sec46 ${LANG_ENGLISH} " Access a single or a collection of NetCDF files as a multi-dimensional array"
LangString DESC_sec47 ${LANG_ENGLISH} " This package allows efficient computation of nonlinear aerodynamic"
LangString DESC_sec48 ${LANG_ENGLISH} " A feed forward multi-layer neural network."
LangString DESC_sec49 ${LANG_ENGLISH} " Collection of routines for the creation, and manipulation of Non-Uniform Rational B-Splines (NURBS), based on the NURBS toolbox by Mark Spink."
LangString DESC_sec50 ${LANG_ENGLISH} " Package for solving DC and transient electrical circuit equations "
LangString DESC_sec51 ${LANG_ENGLISH} " A NetCDF interface for octave"
LangString DESC_sec52 ${LANG_ENGLISH} " A NetCDF interface for octave"
LangString DESC_sec53 ${LANG_ENGLISH} " This package allows to do boolean operations with polygons using"
LangString DESC_sec54 ${LANG_ENGLISH} " The package allows interpolating and smoothing scattered "
LangString DESC_sec55 ${LANG_ENGLISH} " This package allows to call functions of PROJ.4 library for"
LangString DESC_sec56 ${LANG_ENGLISH} " To approximate the solution of the boundary-value problem y''=p(x)*y' + q(x)*y + r(x), a<=x<=b, y(a)=alpha, y(b)=beta by the linear finite-diffence method."
LangString DESC_sec57 ${LANG_ENGLISH} " A package for solving ordinary differential equations and more."
LangString DESC_sec58 ${LANG_ENGLISH} " Non-linear optimization toolkit."
LangString DESC_sec59 ${LANG_ENGLISH} " Non-linear optimization toolkit."
LangString DESC_sec60 ${LANG_ENGLISH} " An optimal interpolation toolbox for octave. This package provides functions to perform a n-dimensional optimal interpolations of arbitrarily distributed data points."
LangString DESC_sec61 ${LANG_ENGLISH} " Grubbs, Dixon and Cochran tests for outlier detection"
LangString DESC_sec62 ${LANG_ENGLISH} " Physical Constants from Atomic & Molecular Physics, taken from NIST database"
LangString DESC_sec63 ${LANG_ENGLISH} " Additional ploting tools for Octave."
LangString DESC_sec64 ${LANG_ENGLISH} " Brazilian Portuguese translations of the help strings of the"
LangString DESC_sec65 ${LANG_ENGLISH} " Overloaded operators for quaternions"
LangString DESC_sec66 ${LANG_ENGLISH} " The queueing toolbox provides functions for queueing"
LangString DESC_sec67 ${LANG_ENGLISH} " A Drift-Diffusion simulator for 1d semiconductor devices"
LangString DESC_sec68 ${LANG_ENGLISH} " A Drift-Diffusion simulator for 2d semiconductor devices"
LangString DESC_sec69 ${LANG_ENGLISH} " A Drift-Diffusion simulator for 3d semiconductor devices"
LangString DESC_sec70 ${LANG_ENGLISH} " Signal processing tools, including filtering, windowing and display functions."
LangString DESC_sec71 ${LANG_ENGLISH} " Signal processing tools, including filtering, windowing and display functions."
LangString DESC_sec72 ${LANG_ENGLISH} " This package define the basic operations on intervals. It is useful when some values for a computation are incerte."
LangString DESC_sec73 ${LANG_ENGLISH} " Socket functions for networking from within octave."
LangString DESC_sec74 ${LANG_ENGLISH} " Special functions including ellipitic functions, etc"
LangString DESC_sec75 ${LANG_ENGLISH} " Additional Special Matrices for Octave."
LangString DESC_sec76 ${LANG_ENGLISH} " Additional Cubic spline functions."
LangString DESC_sec77 ${LANG_ENGLISH} " Additional statistics functions for Octave."
LangString DESC_sec78 ${LANG_ENGLISH} " Additional manipulation functions"
LangString DESC_sec79 ${LANG_ENGLISH} " Additional Structure manipulations functions."
LangString DESC_sec80 ${LANG_ENGLISH} " Linear Algebra for Symmetric Banded Matrices."
LangString DESC_sec81 ${LANG_ENGLISH} " Symbolic toolbox based on GiNaC and CLN."
LangString DESC_sec82 ${LANG_ENGLISH} " Additional date manipulation tools. This a dummy package"
LangString DESC_sec83 ${LANG_ENGLISH} " A toolbox for Time Series Analysis ."
LangString DESC_sec84 ${LANG_ENGLISH} " Implements addframe, avifile, aviinfo, and aviread, using ffmpeg. (and approximately conforms to Matlab interface)"
LangString DESC_sec85 ${LANG_ENGLISH} " 3D graphics using VRML"
LangString DESC_sec86 ${LANG_ENGLISH} " Provides COM interface and additional functionality on Windows"
LangString DESC_sec87 ${LANG_ENGLISH} " Bindings to the Xraylib functions"
LangString DESC_sec88 ${LANG_ENGLISH} " A set of functions for creating simple graphical"

!insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
!insertmacro MUI_DESCRIPTION_TEXT ${sec1} $(DESC_sec1)
!insertmacro MUI_DESCRIPTION_TEXT ${sec2} $(DESC_sec2)
!insertmacro MUI_DESCRIPTION_TEXT ${sec3} $(DESC_sec3)
!insertmacro MUI_DESCRIPTION_TEXT ${sec4} $(DESC_sec4)
!insertmacro MUI_DESCRIPTION_TEXT ${sec5} $(DESC_sec5)
!insertmacro MUI_DESCRIPTION_TEXT ${sec6} $(DESC_sec6)
!insertmacro MUI_DESCRIPTION_TEXT ${sec7} $(DESC_sec7)
!insertmacro MUI_DESCRIPTION_TEXT ${sec8} $(DESC_sec8)
!insertmacro MUI_DESCRIPTION_TEXT ${sec9} $(DESC_sec9)
!insertmacro MUI_DESCRIPTION_TEXT ${sec10} $(DESC_sec10)
!insertmacro MUI_DESCRIPTION_TEXT ${sec11} $(DESC_sec11)
!insertmacro MUI_DESCRIPTION_TEXT ${sec12} $(DESC_sec12)
!insertmacro MUI_DESCRIPTION_TEXT ${sec13} $(DESC_sec13)
!insertmacro MUI_DESCRIPTION_TEXT ${sec14} $(DESC_sec14)
!insertmacro MUI_DESCRIPTION_TEXT ${sec15} $(DESC_sec15)
!insertmacro MUI_DESCRIPTION_TEXT ${sec16} $(DESC_sec16)
!insertmacro MUI_DESCRIPTION_TEXT ${sec17} $(DESC_sec17)
!insertmacro MUI_DESCRIPTION_TEXT ${sec18} $(DESC_sec18)
!insertmacro MUI_DESCRIPTION_TEXT ${sec19} $(DESC_sec19)
!insertmacro MUI_DESCRIPTION_TEXT ${sec20} $(DESC_sec20)
!insertmacro MUI_DESCRIPTION_TEXT ${sec21} $(DESC_sec21)
!insertmacro MUI_DESCRIPTION_TEXT ${sec22} $(DESC_sec22)
!insertmacro MUI_DESCRIPTION_TEXT ${sec23} $(DESC_sec23)
!insertmacro MUI_DESCRIPTION_TEXT ${sec24} $(DESC_sec24)
!insertmacro MUI_DESCRIPTION_TEXT ${sec25} $(DESC_sec25)
!insertmacro MUI_DESCRIPTION_TEXT ${sec26} $(DESC_sec26)
!insertmacro MUI_DESCRIPTION_TEXT ${sec27} $(DESC_sec27)
!insertmacro MUI_DESCRIPTION_TEXT ${sec28} $(DESC_sec28)
!insertmacro MUI_DESCRIPTION_TEXT ${sec29} $(DESC_sec29)
!insertmacro MUI_DESCRIPTION_TEXT ${sec30} $(DESC_sec30)
!insertmacro MUI_DESCRIPTION_TEXT ${sec31} $(DESC_sec31)
!insertmacro MUI_DESCRIPTION_TEXT ${sec32} $(DESC_sec32)
!insertmacro MUI_DESCRIPTION_TEXT ${sec33} $(DESC_sec33)
!insertmacro MUI_DESCRIPTION_TEXT ${sec34} $(DESC_sec34)
!insertmacro MUI_DESCRIPTION_TEXT ${sec35} $(DESC_sec35)
!insertmacro MUI_DESCRIPTION_TEXT ${sec36} $(DESC_sec36)
!insertmacro MUI_DESCRIPTION_TEXT ${sec37} $(DESC_sec37)
!insertmacro MUI_DESCRIPTION_TEXT ${sec38} $(DESC_sec38)
!insertmacro MUI_DESCRIPTION_TEXT ${sec39} $(DESC_sec39)
!insertmacro MUI_DESCRIPTION_TEXT ${sec40} $(DESC_sec40)
!insertmacro MUI_DESCRIPTION_TEXT ${sec41} $(DESC_sec41)
!insertmacro MUI_DESCRIPTION_TEXT ${sec42} $(DESC_sec42)
!insertmacro MUI_DESCRIPTION_TEXT ${sec43} $(DESC_sec43)
!insertmacro MUI_DESCRIPTION_TEXT ${sec44} $(DESC_sec44)
!insertmacro MUI_DESCRIPTION_TEXT ${sec45} $(DESC_sec45)
!insertmacro MUI_DESCRIPTION_TEXT ${sec46} $(DESC_sec46)
!insertmacro MUI_DESCRIPTION_TEXT ${sec47} $(DESC_sec47)
!insertmacro MUI_DESCRIPTION_TEXT ${sec48} $(DESC_sec48)
!insertmacro MUI_DESCRIPTION_TEXT ${sec49} $(DESC_sec49)
!insertmacro MUI_DESCRIPTION_TEXT ${sec50} $(DESC_sec50)
!insertmacro MUI_DESCRIPTION_TEXT ${sec51} $(DESC_sec51)
!insertmacro MUI_DESCRIPTION_TEXT ${sec52} $(DESC_sec52)
!insertmacro MUI_DESCRIPTION_TEXT ${sec53} $(DESC_sec53)
!insertmacro MUI_DESCRIPTION_TEXT ${sec54} $(DESC_sec54)
!insertmacro MUI_DESCRIPTION_TEXT ${sec55} $(DESC_sec55)
!insertmacro MUI_DESCRIPTION_TEXT ${sec56} $(DESC_sec56)
!insertmacro MUI_DESCRIPTION_TEXT ${sec57} $(DESC_sec57)
!insertmacro MUI_DESCRIPTION_TEXT ${sec58} $(DESC_sec58)
!insertmacro MUI_DESCRIPTION_TEXT ${sec59} $(DESC_sec59)
!insertmacro MUI_DESCRIPTION_TEXT ${sec60} $(DESC_sec60)
!insertmacro MUI_DESCRIPTION_TEXT ${sec61} $(DESC_sec61)
!insertmacro MUI_DESCRIPTION_TEXT ${sec62} $(DESC_sec62)
!insertmacro MUI_DESCRIPTION_TEXT ${sec63} $(DESC_sec63)
!insertmacro MUI_DESCRIPTION_TEXT ${sec64} $(DESC_sec64)
!insertmacro MUI_DESCRIPTION_TEXT ${sec65} $(DESC_sec65)
!insertmacro MUI_DESCRIPTION_TEXT ${sec66} $(DESC_sec66)
!insertmacro MUI_DESCRIPTION_TEXT ${sec67} $(DESC_sec67)
!insertmacro MUI_DESCRIPTION_TEXT ${sec68} $(DESC_sec68)
!insertmacro MUI_DESCRIPTION_TEXT ${sec69} $(DESC_sec69)
!insertmacro MUI_DESCRIPTION_TEXT ${sec70} $(DESC_sec70)
!insertmacro MUI_DESCRIPTION_TEXT ${sec71} $(DESC_sec71)
!insertmacro MUI_DESCRIPTION_TEXT ${sec72} $(DESC_sec72)
!insertmacro MUI_DESCRIPTION_TEXT ${sec73} $(DESC_sec73)
!insertmacro MUI_DESCRIPTION_TEXT ${sec74} $(DESC_sec74)
!insertmacro MUI_DESCRIPTION_TEXT ${sec75} $(DESC_sec75)
!insertmacro MUI_DESCRIPTION_TEXT ${sec76} $(DESC_sec76)
!insertmacro MUI_DESCRIPTION_TEXT ${sec77} $(DESC_sec77)
!insertmacro MUI_DESCRIPTION_TEXT ${sec78} $(DESC_sec78)
!insertmacro MUI_DESCRIPTION_TEXT ${sec79} $(DESC_sec79)
!insertmacro MUI_DESCRIPTION_TEXT ${sec80} $(DESC_sec80)
!insertmacro MUI_DESCRIPTION_TEXT ${sec81} $(DESC_sec81)
!insertmacro MUI_DESCRIPTION_TEXT ${sec82} $(DESC_sec82)
!insertmacro MUI_DESCRIPTION_TEXT ${sec83} $(DESC_sec83)
!insertmacro MUI_DESCRIPTION_TEXT ${sec84} $(DESC_sec84)
!insertmacro MUI_DESCRIPTION_TEXT ${sec85} $(DESC_sec85)
!insertmacro MUI_DESCRIPTION_TEXT ${sec86} $(DESC_sec86)
!insertmacro MUI_DESCRIPTION_TEXT ${sec87} $(DESC_sec87)
!insertmacro MUI_DESCRIPTION_TEXT ${sec88} $(DESC_sec88)
!insertmacro MUI_FUNCTION_DESCRIPTION_END

Section Uninstall
   !insertmacro MUI_STARTMENU_GETFOLDER "Startmenu" $SMFOLDERNAME
   Delete "$DESKTOP\Octave UPM.lnk"
   Rmdir /r "$SMPROGRAMS\$SMFOLDERNAME"
   RMDir /r "$INSTDIR"
   ; Delete entry in "Add/Remove programs"
   DeleteRegKey SHELL_CONTEXT "${REGLOC}"
SectionEnd

Function .onInit
   Call SetUserContext
FunctionEnd

Function un.onInit
   Call un.SetUserContext
FunctionEnd

Section -Post
   ExecWait '"$INSTDIR\bin\octave.exe" -qfH --eval "pkg rebuild;"'
;;; pkg rebuild -noauto ad windows nan gsl java"'
SectionEnd
