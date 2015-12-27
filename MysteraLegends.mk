##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=MysteraLegends
ConfigurationName      :=Debug
WorkspacePath          := "/home/john/.codelite/Main/MysteraLegends"
ProjectPath            := "/home/john/.codelite/Main/MysteraLegends"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=John
Date                   :=26/12/15
CodeLitePath           :="/home/john/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
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
ObjectsFileList        :="MysteraLegends.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            := -pthread 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS := -std=c++11 -pthread  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/Connection.cpp$(ObjectSuffix) $(IntermediateDirectory)/Endianness.cpp$(ObjectSuffix) $(IntermediateDirectory)/Main.cpp$(ObjectSuffix) $(IntermediateDirectory)/NetworkBuffer.cpp$(ObjectSuffix) $(IntermediateDirectory)/ConnectionManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/Chat.cpp$(ObjectSuffix) $(IntermediateDirectory)/Keepalive.cpp$(ObjectSuffix) $(IntermediateDirectory)/Serializable.cpp$(ObjectSuffix) $(IntermediateDirectory)/ChatBroadcast.cpp$(ObjectSuffix) $(IntermediateDirectory)/PlayerInfo.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/ServerError.cpp$(ObjectSuffix) 



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
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Connection.cpp$(ObjectSuffix): Connection.cpp $(IntermediateDirectory)/Connection.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/john/.codelite/Main/MysteraLegends/Connection.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Connection.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Connection.cpp$(DependSuffix): Connection.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Connection.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Connection.cpp$(DependSuffix) -MM "Connection.cpp"

$(IntermediateDirectory)/Connection.cpp$(PreprocessSuffix): Connection.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Connection.cpp$(PreprocessSuffix) "Connection.cpp"

$(IntermediateDirectory)/Endianness.cpp$(ObjectSuffix): Endianness.cpp $(IntermediateDirectory)/Endianness.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/john/.codelite/Main/MysteraLegends/Endianness.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Endianness.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Endianness.cpp$(DependSuffix): Endianness.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Endianness.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Endianness.cpp$(DependSuffix) -MM "Endianness.cpp"

$(IntermediateDirectory)/Endianness.cpp$(PreprocessSuffix): Endianness.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Endianness.cpp$(PreprocessSuffix) "Endianness.cpp"

$(IntermediateDirectory)/Main.cpp$(ObjectSuffix): Main.cpp $(IntermediateDirectory)/Main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/john/.codelite/Main/MysteraLegends/Main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Main.cpp$(DependSuffix): Main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Main.cpp$(DependSuffix) -MM "Main.cpp"

$(IntermediateDirectory)/Main.cpp$(PreprocessSuffix): Main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Main.cpp$(PreprocessSuffix) "Main.cpp"

$(IntermediateDirectory)/NetworkBuffer.cpp$(ObjectSuffix): NetworkBuffer.cpp $(IntermediateDirectory)/NetworkBuffer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/john/.codelite/Main/MysteraLegends/NetworkBuffer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NetworkBuffer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/NetworkBuffer.cpp$(DependSuffix): NetworkBuffer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/NetworkBuffer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/NetworkBuffer.cpp$(DependSuffix) -MM "NetworkBuffer.cpp"

$(IntermediateDirectory)/NetworkBuffer.cpp$(PreprocessSuffix): NetworkBuffer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/NetworkBuffer.cpp$(PreprocessSuffix) "NetworkBuffer.cpp"

$(IntermediateDirectory)/ConnectionManager.cpp$(ObjectSuffix): ConnectionManager.cpp $(IntermediateDirectory)/ConnectionManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/john/.codelite/Main/MysteraLegends/ConnectionManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ConnectionManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ConnectionManager.cpp$(DependSuffix): ConnectionManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ConnectionManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ConnectionManager.cpp$(DependSuffix) -MM "ConnectionManager.cpp"

$(IntermediateDirectory)/ConnectionManager.cpp$(PreprocessSuffix): ConnectionManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ConnectionManager.cpp$(PreprocessSuffix) "ConnectionManager.cpp"

$(IntermediateDirectory)/Chat.cpp$(ObjectSuffix): Chat.cpp $(IntermediateDirectory)/Chat.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/john/.codelite/Main/MysteraLegends/Chat.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Chat.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Chat.cpp$(DependSuffix): Chat.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Chat.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Chat.cpp$(DependSuffix) -MM "Chat.cpp"

$(IntermediateDirectory)/Chat.cpp$(PreprocessSuffix): Chat.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Chat.cpp$(PreprocessSuffix) "Chat.cpp"

$(IntermediateDirectory)/Keepalive.cpp$(ObjectSuffix): Keepalive.cpp $(IntermediateDirectory)/Keepalive.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/john/.codelite/Main/MysteraLegends/Keepalive.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Keepalive.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Keepalive.cpp$(DependSuffix): Keepalive.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Keepalive.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Keepalive.cpp$(DependSuffix) -MM "Keepalive.cpp"

$(IntermediateDirectory)/Keepalive.cpp$(PreprocessSuffix): Keepalive.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Keepalive.cpp$(PreprocessSuffix) "Keepalive.cpp"

$(IntermediateDirectory)/Serializable.cpp$(ObjectSuffix): Serializable.cpp $(IntermediateDirectory)/Serializable.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/john/.codelite/Main/MysteraLegends/Serializable.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Serializable.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Serializable.cpp$(DependSuffix): Serializable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Serializable.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Serializable.cpp$(DependSuffix) -MM "Serializable.cpp"

$(IntermediateDirectory)/Serializable.cpp$(PreprocessSuffix): Serializable.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Serializable.cpp$(PreprocessSuffix) "Serializable.cpp"

$(IntermediateDirectory)/ChatBroadcast.cpp$(ObjectSuffix): ChatBroadcast.cpp $(IntermediateDirectory)/ChatBroadcast.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/john/.codelite/Main/MysteraLegends/ChatBroadcast.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ChatBroadcast.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ChatBroadcast.cpp$(DependSuffix): ChatBroadcast.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ChatBroadcast.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ChatBroadcast.cpp$(DependSuffix) -MM "ChatBroadcast.cpp"

$(IntermediateDirectory)/ChatBroadcast.cpp$(PreprocessSuffix): ChatBroadcast.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ChatBroadcast.cpp$(PreprocessSuffix) "ChatBroadcast.cpp"

$(IntermediateDirectory)/PlayerInfo.cpp$(ObjectSuffix): PlayerInfo.cpp $(IntermediateDirectory)/PlayerInfo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/john/.codelite/Main/MysteraLegends/PlayerInfo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PlayerInfo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PlayerInfo.cpp$(DependSuffix): PlayerInfo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PlayerInfo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PlayerInfo.cpp$(DependSuffix) -MM "PlayerInfo.cpp"

$(IntermediateDirectory)/PlayerInfo.cpp$(PreprocessSuffix): PlayerInfo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PlayerInfo.cpp$(PreprocessSuffix) "PlayerInfo.cpp"

$(IntermediateDirectory)/ServerError.cpp$(ObjectSuffix): ServerError.cpp $(IntermediateDirectory)/ServerError.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/john/.codelite/Main/MysteraLegends/ServerError.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ServerError.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ServerError.cpp$(DependSuffix): ServerError.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ServerError.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ServerError.cpp$(DependSuffix) -MM "ServerError.cpp"

$(IntermediateDirectory)/ServerError.cpp$(PreprocessSuffix): ServerError.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ServerError.cpp$(PreprocessSuffix) "ServerError.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


