#include "TranslateToHTNWorldState.h"
#include "PlayerData.h"
#include "SimWorld.h"
#include "PlayerRegistry.h"
#include "ActorItem.h"
#include <vector>

HTNWorldState const& TranslateToHTNWorldState(UPlayerData* playerPtr, USimWorld& simworld, PlayerMap& playerMap, UPlayerData* requester) {
    //TODO reflect players sensors rather than being hardwired to the world

    std::vector<AbstractItem*> world_items;
    //    std::cout << "simworld.items:\n";
    for (auto& itemPtr : simworld.items)
    {
        //        std::cout << itemPtr << "\n";
        world_items.push_back(new AbstractItem(itemPtr->m_itemType, itemPtr->m_locationClass.location));  //TODO memory management, TODO copy all data from real object
    }
    //    std::cout << "\n";

    AActorItem* itemCarriedPtr = nullptr;

    std::vector<AbstractPlayerData*> attackers;
    std::vector<AbstractPlayerData*> playersInTheRoom;
    for (const IntRelPair& pair : playerPtr->relMap)
    {
        int relIndex = pair.Key;
        URelationship* rel = pair.Value;
        if (rel != nullptr) {
            if (rel->getAggro() > 29)
            {
                attackers.push_back(&(playerMap[relIndex]->abstractPlayerData));
            }
            if (playerMap[relIndex]->locationClass.location == playerPtr->locationClass.location && playerMap[relIndex] != playerPtr)
            {
                playersInTheRoom.push_back(&(playerMap[relIndex]->abstractPlayerData));
            }
        }
    }

    return HTNWorldState(&(playerPtr->abstractPlayerData), playerMap, world_items, &(requester->abstractPlayerData), attackers, playersInTheRoom);
}