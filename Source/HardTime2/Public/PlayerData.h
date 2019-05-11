#pragma once

#include <iostream>
#include "PStats.hpp"
#include "Missions.hpp"
#include "BasicAI.hpp"
#include "ActorItem.h"
#include "Actions.hpp"
#include "Constants.hpp"
#include "Object.h"
#include "RelMap.hpp"
#include "Relationship.h"
#include "Runtime/Core/Public/UObject/NameTypes.h"
#include "PlayerData.generated.h"

class USimWorld;
class AActorItem;
class AHardTime2Character;

UCLASS(BlueprintType, Blueprintable)
class UPlayerData : public UObject
{
	GENERATED_BODY()

public:
    PStats pStats;

	int m_key; //players PlayerRegistry index
    int cash = 0; //cash, in dollars, no bounds.
    int sentence = 5; //days left in prison sentence, only bound is above -1.
    Actions action = Actions::useRoom; //stores the current action being attempted. This is held till the end of the frame, as it may be interrupted by another action.
    Actions lastAction = Actions::useRoom; //stores the last action taken. Useful for checking if hidden.
    LocationClass locationClass; //location maps to a discrete set of locations, gym, library, circuit track, bed.
    LocationClass lastLocationClass; //location the character was at when the turn began. Used by the print display.
    bool attacked = false; //tracks whether an attack has disrupted his turn.
    //std::string narrative; //printed at the end of each round, giving the update for this character
    FName m_playerName; //name of the character, used in speech.
    MissionClass missionClass; //a mission currently assigned to the character
    AIController aiController; //controlling AI for this character
    MissionClass missionOffer; // a mission being offered to 'playerTarget'

	UPROPERTY()
		AActorItem* itemPtr = nullptr; //pointer to an item carried by the player

	UPROPERTY()
		UPlayerData* playerTargetPtr = nullptr; //index of the character being targetted. You must set this when attacking or assigning a mission to another player!

	UPROPERTY()
		AActorItem* itemFocusPtr = nullptr; //pointer to an item the player is trying to interact with

	UPROPERTY()
		AHardTime2Character* physicalCharacter = nullptr;

	void UpdateMissions(USimWorld &world);
    void PrintPlayer();
	bool IsRequestedRecently(UPlayerData* requestedPlayer, EItemType m_itemType);
	void SetRequested(UPlayerData* requestedPlayer);
	UPlayerData();
	UPlayerData(const FObjectInitializer& ObjectInitializer);
    
	RelMap relMap;

	virtual class UWorld* GetWorld() const override;
};

std::string CharacterName(UPlayerData* playerPtr);
MissionClass CreateNewMission(UPlayerData* playerPtr);
