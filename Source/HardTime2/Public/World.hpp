#pragma once

#include <vector>
#include "Player.hpp"

class AActorItem;

class World //represents the simulated world
{
public:
    Player* weightsOccupied;
    Player* circuitsOccupied;
    Player* studyOccupied;
    Player* bedOccupied;
    void WorldEffects(Player player[], int frame);
    void Clean();
    World();
    std::vector< AActorItem* > items;
};