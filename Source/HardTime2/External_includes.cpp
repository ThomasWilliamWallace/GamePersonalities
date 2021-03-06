// This file pulls in cpp files from outside the Source/HardTime2 folder that Unreal is limited to.
// Hack to allow including a subset of the htn_planner files into Unreal: https://answers.unrealengine.com/questions/894331/how-do-you-includeexclude-files-from-build-1.html

#include "../htn_planner/htn_planner/Private/Constants.cpp"
#include "../htn_planner/htn_planner/Private/pLog.cpp"
#include "../htn_planner/htn_planner/Private/Locations.cpp"
#include "../htn_planner/htn_planner/Private/AbstractItem.cpp"
#include "../htn_planner/htn_planner/Private/AbstractAction.cpp"
#include "../htn_planner/htn_planner/Private/AbstractPlayerData.cpp"
#include "../htn_planner/htn_planner/Private/AbstractMission.cpp"
#include "../htn_planner/htn_planner/Private/HTNPlanner.cpp"
#include "../htn_planner/htn_planner/Private/HTNWorldState.cpp"
#include "../htn_planner/htn_planner/Private/PlatformSpecific.cpp"
#include "../htn_planner/htn_planner/Private/PStats.cpp"