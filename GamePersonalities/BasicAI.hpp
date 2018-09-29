//
//  BasicAI.hpp
//  GamePersonalities
//
//  Created by VITALIJA STEPUSAITYTE on 25/08/2018.
//  Copyright © 2018 Thomas. All rights reserved.
//

#ifndef BasicAI_hpp
#define BasicAI_hpp

#include "Actions.hpp"
#include "Constants.hpp"

class Stats;

class AIController
{
    AI algo;
    Actions ChooseRoom(int playerIndex, Player player[]);
    Actions RandomAIChooseAction(int playerIndex, Player player[], bool playersInReach[], int countPlayersInReach);
    Actions aggroAIChooseAction(int playerIndex, Player player[], bool playersInReach[], int countPlayersInReach);
    Actions humanAIChooseAction(int playerIndex, Player player[], bool playersInReach[], int countPlayersInReach);
    Actions greedyAIChooseAction(int playerIndex, Player player[], bool playersInReach[], int countPlayersInReach);
    Actions htnAIChooseAction(int playerIndex, Player player[], bool playersInReach[], int countPlayersInReach);
    void CreateMissionOffer(Player player[], int playerIndex, bool playersInReach[], int countPlayersInReach);
    int TargetForMakeFriend(Player player[], int playerIndex, bool playersInReach[], int countPlayersInReach);
public:
    Actions ChooseAction(int playerIndex, Player player[]);
    AIController(AI _algo);
    AIController();
};

#endif /* BasicAI_hpp */
