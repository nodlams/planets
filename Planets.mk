##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=Planets
ConfigurationName      :=Release
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/jqs/codelite-workspace"
ProjectPath            := "/home/jqs/codelite-workspace"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=James Smaldon
Date                   :=14/12/10
CodeLitePath           :="/home/jqs/.codelite"
LinkerName             :=g++
ArchiveTool            :=ar rcus
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
CompilerName           :=g++
C_CompilerName         :=gcc
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
MakeDirCommand         :=mkdir -p
CmpOptions             := -O3 -ffast-math -march=athlon64-sse3 -mtune=athlon64-sse3 -msse -msse2 -msse3 -mfpmath=sse $(Preprocessors)
LinkOptions            :=  -O3 -ffast-math -march=athlon64-sse3 -mtune=athlon64-sse3 -msse -msse2 -msse3 -mfpmath=sse
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)." "$(IncludeSwitch)/usr/include/SDL" 
RcIncludePath          :=
Libs                   :=$(LibrarySwitch)GLU $(LibrarySwitch)glut $(LibrarySwitch)SDL 
LibPath                := "$(LibraryPathSwitch)." 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/planetarium$(ObjectSuffix) $(IntermediateDirectory)/gravity$(ObjectSuffix) $(IntermediateDirectory)/bodycontainer$(ObjectSuffix) $(IntermediateDirectory)/datavector$(ObjectSuffix) $(IntermediateDirectory)/velocity_verlet_integrator$(ObjectSuffix) $(IntermediateDirectory)/vbo$(ObjectSuffix) $(IntermediateDirectory)/subdividedicosahedron$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@test -d ./Release || $(MakeDirCommand) ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jqs/codelite-workspace/main.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "/home/jqs/codelite-workspace/main.cpp"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "/home/jqs/codelite-workspace/main.cpp"

$(IntermediateDirectory)/planetarium$(ObjectSuffix): planetarium.cpp $(IntermediateDirectory)/planetarium$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jqs/codelite-workspace/planetarium.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/planetarium$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/planetarium$(DependSuffix): planetarium.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/planetarium$(ObjectSuffix) -MF$(IntermediateDirectory)/planetarium$(DependSuffix) -MM "/home/jqs/codelite-workspace/planetarium.cpp"

$(IntermediateDirectory)/planetarium$(PreprocessSuffix): planetarium.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/planetarium$(PreprocessSuffix) "/home/jqs/codelite-workspace/planetarium.cpp"

$(IntermediateDirectory)/gravity$(ObjectSuffix): gravity.cpp $(IntermediateDirectory)/gravity$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jqs/codelite-workspace/gravity.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gravity$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gravity$(DependSuffix): gravity.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/gravity$(ObjectSuffix) -MF$(IntermediateDirectory)/gravity$(DependSuffix) -MM "/home/jqs/codelite-workspace/gravity.cpp"

$(IntermediateDirectory)/gravity$(PreprocessSuffix): gravity.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gravity$(PreprocessSuffix) "/home/jqs/codelite-workspace/gravity.cpp"

$(IntermediateDirectory)/bodycontainer$(ObjectSuffix): bodycontainer.cpp $(IntermediateDirectory)/bodycontainer$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jqs/codelite-workspace/bodycontainer.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/bodycontainer$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bodycontainer$(DependSuffix): bodycontainer.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/bodycontainer$(ObjectSuffix) -MF$(IntermediateDirectory)/bodycontainer$(DependSuffix) -MM "/home/jqs/codelite-workspace/bodycontainer.cpp"

$(IntermediateDirectory)/bodycontainer$(PreprocessSuffix): bodycontainer.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bodycontainer$(PreprocessSuffix) "/home/jqs/codelite-workspace/bodycontainer.cpp"

$(IntermediateDirectory)/datavector$(ObjectSuffix): datavector.cpp $(IntermediateDirectory)/datavector$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jqs/codelite-workspace/datavector.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/datavector$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/datavector$(DependSuffix): datavector.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/datavector$(ObjectSuffix) -MF$(IntermediateDirectory)/datavector$(DependSuffix) -MM "/home/jqs/codelite-workspace/datavector.cpp"

$(IntermediateDirectory)/datavector$(PreprocessSuffix): datavector.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/datavector$(PreprocessSuffix) "/home/jqs/codelite-workspace/datavector.cpp"

$(IntermediateDirectory)/velocity_verlet_integrator$(ObjectSuffix): velocity_verlet_integrator.cpp $(IntermediateDirectory)/velocity_verlet_integrator$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jqs/codelite-workspace/velocity_verlet_integrator.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/velocity_verlet_integrator$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/velocity_verlet_integrator$(DependSuffix): velocity_verlet_integrator.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/velocity_verlet_integrator$(ObjectSuffix) -MF$(IntermediateDirectory)/velocity_verlet_integrator$(DependSuffix) -MM "/home/jqs/codelite-workspace/velocity_verlet_integrator.cpp"

$(IntermediateDirectory)/velocity_verlet_integrator$(PreprocessSuffix): velocity_verlet_integrator.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/velocity_verlet_integrator$(PreprocessSuffix) "/home/jqs/codelite-workspace/velocity_verlet_integrator.cpp"

$(IntermediateDirectory)/vbo$(ObjectSuffix): vbo.cpp $(IntermediateDirectory)/vbo$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jqs/codelite-workspace/vbo.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/vbo$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vbo$(DependSuffix): vbo.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/vbo$(ObjectSuffix) -MF$(IntermediateDirectory)/vbo$(DependSuffix) -MM "/home/jqs/codelite-workspace/vbo.cpp"

$(IntermediateDirectory)/vbo$(PreprocessSuffix): vbo.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vbo$(PreprocessSuffix) "/home/jqs/codelite-workspace/vbo.cpp"

$(IntermediateDirectory)/subdividedicosahedron$(ObjectSuffix): subdividedicosahedron.cpp $(IntermediateDirectory)/subdividedicosahedron$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/jqs/codelite-workspace/subdividedicosahedron.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/subdividedicosahedron$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/subdividedicosahedron$(DependSuffix): subdividedicosahedron.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/subdividedicosahedron$(ObjectSuffix) -MF$(IntermediateDirectory)/subdividedicosahedron$(DependSuffix) -MM "/home/jqs/codelite-workspace/subdividedicosahedron.cpp"

$(IntermediateDirectory)/subdividedicosahedron$(PreprocessSuffix): subdividedicosahedron.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/subdividedicosahedron$(PreprocessSuffix) "/home/jqs/codelite-workspace/subdividedicosahedron.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/planetarium$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/planetarium$(DependSuffix)
	$(RM) $(IntermediateDirectory)/planetarium$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gravity$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gravity$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gravity$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/bodycontainer$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/bodycontainer$(DependSuffix)
	$(RM) $(IntermediateDirectory)/bodycontainer$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/datavector$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/datavector$(DependSuffix)
	$(RM) $(IntermediateDirectory)/datavector$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/velocity_verlet_integrator$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/velocity_verlet_integrator$(DependSuffix)
	$(RM) $(IntermediateDirectory)/velocity_verlet_integrator$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/vbo$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/vbo$(DependSuffix)
	$(RM) $(IntermediateDirectory)/vbo$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/subdividedicosahedron$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/subdividedicosahedron$(DependSuffix)
	$(RM) $(IntermediateDirectory)/subdividedicosahedron$(PreprocessSuffix)
	$(RM) $(OutputFile)


