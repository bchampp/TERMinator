##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=terminator
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Andrew/Documents/CMPE320
ProjectPath            :=C:/Users/Andrew/Documents/CMPE320/terminator
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Andrew
Date                   :=25/11/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/msys64/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/msys64/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="terminator.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/msys64/mingw64/bin/windres.exe
LinkOptions            :=  -ltesseract -lpthread -llept -lz -lpng16 -ljpeg -lgif -ltiff -lwebp
IncludePath            := $(IncludeSwitch)C:\msys64\mingw64\include\gtkmm-3.0 $(IncludeSwitch)C:\msys64\mingw64\lib\gtkmm-3.0\include $(IncludeSwitch)C:\msys64\mingw64\include\atkmm-1.6 $(IncludeSwitch)C:\msys64\mingw64\include\gdkmm-3.0 $(IncludeSwitch)C:\msys64\mingw64\lib\gdkmm-3.0\include $(IncludeSwitch)C:\msys64\mingw64\include\giomm-2.4 $(IncludeSwitch)C:\msys64\mingw64\lib\giomm-2.4\include $(IncludeSwitch)C:\msys64\mingw64\include\pangomm-1.4 $(IncludeSwitch)C:\msys64\mingw64\lib\pangomm-1.4\include $(IncludeSwitch)C:\msys64\mingw64\include\glibmm-2.4 $(IncludeSwitch)C:\msys64\mingw64\lib\glibmm-2.4\include $(IncludeSwitch)C:\msys64\mingw64\include\gtk-3.0 $(IncludeSwitch)C:\msys64\mingw64\include\cairo $(IncludeSwitch)C:\msys64\mingw64\include $(IncludeSwitch)C:\msys64\mingw64\include\pango-1.0 $(IncludeSwitch)C:\msys64\mingw64\include\fribidi $(IncludeSwitch)C:\msys64\mingw64\include $(IncludeSwitch)C:\msys64\mingw64\include\atk-1.0 $(IncludeSwitch)C:\msys64\mingw64\include\cairo $(IncludeSwitch)C:\msys64\mingw64\include\cairomm-1.0 $(IncludeSwitch)C:\msys64\mingw64\lib\cairomm-1.0\include $(IncludeSwitch)C:\msys64\mingw64\include\cairo $(IncludeSwitch)C:\msys64\mingw64\include\pixman-1 $(IncludeSwitch)C:\msys64\mingw64\include $(IncludeSwitch)C:\msys64\mingw64\include\freetype2 $(IncludeSwitch)C:\msys64\mingw64\include $(IncludeSwitch)C:\msys64\mingw64\include\harfbuzz $(IncludeSwitch)C:\msys64\mingw64\include $(IncludeSwitch)C:\msys64\mingw64\include\libpng16 $(IncludeSwitch)C:\msys64\mingw64\include\sigc++-2.0 $(IncludeSwitch)C:\msys64\mingw64\lib\sigc++-2.0\include $(IncludeSwitch)C:\msys64\mingw64\include\gdk-pixbuf-2.0 $(IncludeSwitch)C:\msys64\mingw64\include\libpng16 $(IncludeSwitch)C:\msys64\mingw64\include $(IncludeSwitch)C:\msys64\mingw64\lib\libffi-3.2.1\include $(IncludeSwitch)C:\msys64\mingw64\include\glib-2.0 $(IncludeSwitch)C:\msys64\mingw64\lib\glib-2.0\include $(IncludeSwitch)C:\msys64\mingw64\include $(IncludeSwitch)C:\msys64\mingw64\lib\ $(IncludeSwitch)C:\msys64\mingw64\include\leptonica  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)gtkmm-3.0 $(LibrarySwitch)atkmm-1.6 $(LibrarySwitch)gdkmm-3.0 $(LibrarySwitch)giomm-2.4 $(LibrarySwitch)pangomm-1.4 $(LibrarySwitch)glibmm-2.4 $(LibrarySwitch)gtk-3 $(LibrarySwitch)gdk-3 $(LibrarySwitch)gdi32 $(LibrarySwitch)imm32 $(LibrarySwitch)shell32 $(LibrarySwitch)ole32 $(LibrarySwitch)uuid $(LibrarySwitch)winmm $(LibrarySwitch)dwmapi $(LibrarySwitch)setupapi $(LibrarySwitch)cfgmgr32 $(LibrarySwitch)epoxy $(LibrarySwitch)opengl32 $(LibrarySwitch)gdi32 $(LibrarySwitch)pangocairo-1.0 $(LibrarySwitch)gdi32 $(LibrarySwitch)pangoft2-1.0 $(LibrarySwitch)pangowin32-1.0 $(LibrarySwitch)usp10 $(LibrarySwitch)gdi32 $(LibrarySwitch)pango-1.0 $(LibrarySwitch)fribidi $(LibrarySwitch)thai $(LibrarySwitch)datrie $(LibrarySwitch)atk-1.0 $(LibrarySwitch)cairo-gobject $(LibrarySwitch)cairomm-1.0 $(LibrarySwitch)cairo $(LibrarySwitch)pixman-1 $(LibrarySwitch)fontconfig $(LibrarySwitch)iconv $(LibrarySwitch)expat $(LibrarySwitch)freetype $(LibrarySwitch)bz2 $(LibrarySwitch)harfbuzz $(LibrarySwitch)usp10 $(LibrarySwitch)gdi32 $(LibrarySwitch)rpcrt4 $(LibrarySwitch)dwrite $(LibrarySwitch)graphite2 $(LibrarySwitch)png16 $(LibrarySwitch)sigc-2.0 $(LibrarySwitch)gdk_pixbuf-2.0 $(LibrarySwitch)gdiplus $(LibrarySwitch)ole32 $(LibrarySwitch)jpeg $(LibrarySwitch)jasper $(LibrarySwitch)png16 $(LibrarySwitch)tiff $(LibrarySwitch)zstd $(LibrarySwitch)lzma $(LibrarySwitch)jpeg $(LibrarySwitch)gio-2.0 $(LibrarySwitch)intl $(LibrarySwitch)shlwapi $(LibrarySwitch)dnsapi $(LibrarySwitch)iphlpapi $(LibrarySwitch)ws2_32 $(LibrarySwitch)gmodule-2.0 $(LibrarySwitch)intl $(LibrarySwitch)gobject-2.0 $(LibrarySwitch)intl $(LibrarySwitch)ffi $(LibrarySwitch)intl $(LibrarySwitch)glib-2.0 $(LibrarySwitch)ws2_32 $(LibrarySwitch)ole32 $(LibrarySwitch)winmm $(LibrarySwitch)shlwapi $(LibrarySwitch)pcre 
ArLibs                 :=  "gtkmm-3.0" "atkmm-1.6" "gdkmm-3.0" "giomm-2.4" "pangomm-1.4" "glibmm-2.4" "gtk-3" "gdk-3" "gdi32" "imm32" "shell32" "ole32" "uuid" "winmm" "dwmapi" "setupapi" "cfgmgr32" "epoxy" "opengl32" "gdi32" "pangocairo-1.0" "gdi32" "pangoft2-1.0" "pangowin32-1.0" "usp10" "gdi32" "pango-1.0" "fribidi" "thai" "datrie" "atk-1.0" "cairo-gobject" "cairomm-1.0" "cairo" "pixman-1" "fontconfig" "iconv" "expat" "freetype" "bz2" "harfbuzz" "usp10" "gdi32" "rpcrt4" "dwrite" "graphite2" "png16" "sigc-2.0" "gdk_pixbuf-2.0" "gdiplus" "ole32" "jpeg" "jasper" "png16" "tiff" "zstd" "lzma" "jpeg" "gio-2.0" "intl" "shlwapi" "dnsapi" "iphlpapi" "ws2_32" "gmodule-2.0" "intl" "gobject-2.0" "intl" "ffi" "intl" "glib-2.0" "ws2_32" "ole32" "winmm" "shlwapi" "pcre" 
LibPath                :=$(LibraryPathSwitch)C:\msys64\mingw64\lib  $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/msys64/mingw64/bin/ar.exe rcu
CXX      := C:/msys64/mingw64/bin/g++.exe
CC       := C:/msys64/mingw64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/msys64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Image.cpp$(ObjectSuffix) $(IntermediateDirectory)/mainwindow.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_image_image.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Andrew/Documents/CMPE320/terminator/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Image.cpp$(ObjectSuffix): Image.cpp $(IntermediateDirectory)/Image.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Andrew/Documents/CMPE320/terminator/Image.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Image.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Image.cpp$(DependSuffix): Image.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Image.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Image.cpp$(DependSuffix) -MM Image.cpp

$(IntermediateDirectory)/Image.cpp$(PreprocessSuffix): Image.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Image.cpp$(PreprocessSuffix) Image.cpp

$(IntermediateDirectory)/mainwindow.cpp$(ObjectSuffix): mainwindow.cpp $(IntermediateDirectory)/mainwindow.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Andrew/Documents/CMPE320/terminator/mainwindow.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mainwindow.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mainwindow.cpp$(DependSuffix): mainwindow.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mainwindow.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mainwindow.cpp$(DependSuffix) -MM mainwindow.cpp

$(IntermediateDirectory)/mainwindow.cpp$(PreprocessSuffix): mainwindow.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mainwindow.cpp$(PreprocessSuffix) mainwindow.cpp

$(IntermediateDirectory)/src_image_image.cpp$(ObjectSuffix): src/image/image.cpp $(IntermediateDirectory)/src_image_image.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Andrew/Documents/CMPE320/terminator/src/image/image.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_image_image.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_image_image.cpp$(DependSuffix): src/image/image.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_image_image.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_image_image.cpp$(DependSuffix) -MM src/image/image.cpp

$(IntermediateDirectory)/src_image_image.cpp$(PreprocessSuffix): src/image/image.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_image_image.cpp$(PreprocessSuffix) src/image/image.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


