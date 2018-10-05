//
//  HTNDomain.cpp
//  GamePersonalities
//
//  Created by VITALIJA STEPUSAITYTE on 25/08/2018.
//  Copyright © 2018 Thomas. All rights reserved.
//

#include "HTNDomain.hpp"
#include "Locations.hpp"
#include "Player.hpp"

//Start HTNPrimitives****************************************
//***********************************************************
void Study::Effect(HTNWorldState &htnWorldState)
{
    htnWorldState.m_v.at(WorldE::intelligence) += 1;
    return;
}

Actions Study::Operator(int playerIndex, Player player[], World &world)
{
    return Actions::useRoom;
}

bool Study::Preconditions(HTNWorldState &htnWorldState)
{
    return static_cast<Locations>(htnWorldState.m_v.at(WorldE::location)) == Locations::library;
}

std::string Study::ToString()
{
    std::string name = "Study";
    return name;
}

//***********************************************************
void Sleep::Effect(HTNWorldState &htnWorldState)
{
    htnWorldState.m_v.at(WorldE::health) += 1;
    return;
}

Actions Sleep::Operator(int playerIndex, Player player[], World &world)
{
    return Actions::useRoom;
}

bool Sleep::Preconditions(HTNWorldState &htnWorldState)
{
    return static_cast<Locations>(htnWorldState.m_v.at(WorldE::location)) == Locations::bedroom;
}

std::string Sleep::ToString()
{
    std::string name = "Sleep";
    return name;
}

//***********************************************************
void UseGym::Effect(HTNWorldState &htnWorldState)
{
    htnWorldState.m_v.at(WorldE::strength) += 1;
    return;
}

Actions UseGym::Operator(int playerIndex, Player player[], World &world)
{
    return Actions::useRoom;
}

bool UseGym::Preconditions(HTNWorldState &htnWorldState)
{
    return static_cast<Locations>(htnWorldState.m_v.at(WorldE::location)) == Locations::gym;
}

std::string UseGym::ToString()
{
    std::string name = "UseGym";
    return name;
}

//***********************************************************
void RunCircuits::Effect(HTNWorldState &htnWorldState)
{
    htnWorldState.m_v.at(WorldE::agility) += 1;
    return;
}

Actions RunCircuits::Operator(int playerIndex, Player player[], World &world)
{
    return Actions::useRoom;
}

bool RunCircuits::Preconditions(HTNWorldState &htnWorldState)
{
    return static_cast<Locations>(htnWorldState.m_v.at(WorldE::location)) == Locations::circuitTrack;
}

std::string RunCircuits::ToString()
{
    std::string name = "RunCircuits";
    return name;
}

//***********************************************************
void GoToGym::Effect(HTNWorldState &htnWorldState)
{
    htnWorldState.m_v.at(WorldE::location) = static_cast<int>(Locations::gym);
    return;
}

Actions GoToGym::Operator(int playerIndex, Player player[], World &world)
{
    return Actions::goToGym;
}

bool GoToGym::Preconditions(HTNWorldState &htnWorldState)
{
    return static_cast<Locations>(htnWorldState.m_v.at(WorldE::location)) == Locations::mainHall;
}

std::string GoToGym::ToString()
{
    std::string name = "GoToGym";
    return name;
}

//***********************************************************
void GoToLibrary::Effect(HTNWorldState &htnWorldState)
{
    htnWorldState.m_v.at(WorldE::location) = static_cast<int>(Locations::library);
    return;
}

Actions GoToLibrary::Operator(int playerIndex, Player player[], World &world)
{
    return Actions::goToLibrary;
}

bool GoToLibrary::Preconditions(HTNWorldState &htnWorldState)
{
    return static_cast<Locations>(htnWorldState.m_v.at(WorldE::location)) == Locations::mainHall;
}

std::string GoToLibrary::ToString()
{
    std::string name = "GoToLibrary";
    return name;
}

//***********************************************************
void GoToBedroom::Effect(HTNWorldState &htnWorldState)
{
    htnWorldState.m_v.at(WorldE::location) = static_cast<int>(Locations::bedroom);
    return;
}

Actions GoToBedroom::Operator(int playerIndex, Player player[], World &world)
{
    return Actions::goToBedroom;
}

bool GoToBedroom::Preconditions(HTNWorldState &htnWorldState)
{
    return static_cast<Locations>(htnWorldState.m_v.at(WorldE::location)) == Locations::mainHall;
}

std::string GoToBedroom::ToString()
{
    std::string name = "GoToBedroom";
    return name;
}

//***********************************************************
void GoToCircuitTrack::Effect(HTNWorldState &htnWorldState)
{
    htnWorldState.m_v.at(WorldE::location) = static_cast<int>(Locations::circuitTrack);
    return;
}

Actions GoToCircuitTrack::Operator(int playerIndex, Player player[], World &world)
{
    return Actions::goToCircuitTrack;
}

bool GoToCircuitTrack::Preconditions(HTNWorldState &htnWorldState)
{
    return static_cast<Locations>(htnWorldState.m_v.at(WorldE::location)) == Locations::mainHall;
}

std::string GoToCircuitTrack::ToString()
{
    std::string name = "GoToCircuitTrack";
    return name;
}

//***********************************************************
void GoToMainHall::Effect(HTNWorldState &htnWorldState)
{
    htnWorldState.m_v.at(WorldE::location) = static_cast<int>(Locations::mainHall);
    return;
}

Actions GoToMainHall::Operator(int playerIndex, Player player[], World &world)
{
    return Actions::goToMainHall;
}

bool GoToMainHall::Preconditions(HTNWorldState &htnWorldState)
{
    return static_cast<Locations>(htnWorldState.m_v.at(WorldE::location)) != Locations::mainHall;
}

std::string GoToMainHall::ToString()
{
    std::string name = "GoToMainHall";
    return name;
}

//***********************************************************
void Drink::Effect(HTNWorldState &htnWorldState)
{
    htnWorldState.m_v.at(WorldE::intelligence) -= 1;
    return;
}

Actions Drink::Operator(int playerIndex, Player player[], World &world)
{
    return Actions::noAction;
}

bool Drink::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

std::string Drink::ToString()
{
    std::string name = "Drink";
    return name;
}

//***********************************************************
Punch::Punch(int playerIndex)
{
    m_targetPlayerIndex = playerIndex;
}

void Punch::Effect(HTNWorldState &htnWorldState)
{
    htnWorldState.m_v.at(WorldE::punches) += 1;
}

Actions Punch::Operator(int playerIndex, Player player[], World &world)
{
    player[playerIndex].playerTarget = m_targetPlayerIndex;
    return Actions::attack;
}

bool Punch::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

std::string Punch::ToString()
{
    std::string name = "Punch";
    return name;
}

//***********************************************************
void Evade::Effect(HTNWorldState &htnWorldState)
{
    htnWorldState.m_v.at(WorldE::evading) = 1;
}

Actions Evade::Operator(int playerIndex, Player player[], World &world)
{
    return Actions::evade;
}

bool Evade::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

std::string Evade::ToString()
{
    std::string name = "Evade";
    return name;
}

//***********************************************************
PickUpItem::PickUpItem(Item* itemFocusPtr)
{
    m_itemFocusPtr = itemFocusPtr;
}

void PickUpItem::Effect(HTNWorldState &htnWorldState)
{
    m_itemFocusPtr->m_carryingPlayer = htnWorldState.m_ptrToSelf;
}

Actions PickUpItem::Operator(int playerIndex, Player player[], World &world)
{
    player[playerIndex].itemFocusPtr = m_itemFocusPtr;
    return Actions::pickUpItem;
}

bool PickUpItem::Preconditions(HTNWorldState &htnWorldState)
{
    //TODO hook this into the actions code
    if (m_itemFocusPtr != nullptr)
    {
        if (static_cast<Locations>(htnWorldState.m_v.at(WorldE::location)) == m_itemFocusPtr->m_locationClass.location)
        {
            if (m_itemFocusPtr->m_carryingPlayer == nullptr)
            {
                return true;
            }
        }
    }
    return false;
}

void PickUpItem::PointToRealItems()
{
    m_itemFocusPtr = &((static_cast<SimItem*>(m_itemFocusPtr))->m_realItem);
}

std::string PickUpItem::ToString()
{
    std::string name = "PickUpItem";
    return name;
}

//***********************************************************
DropItem::DropItem(Item* itemFocusPtr)
{
    m_itemFocusPtr = itemFocusPtr;
}

void DropItem::Effect(HTNWorldState &htnWorldState)
{
    m_itemFocusPtr->m_carryingPlayer = nullptr;
}

Actions DropItem::Operator(int playerIndex, Player player[], World &world)
{
    player[playerIndex].itemFocusPtr = m_itemFocusPtr;
    return Actions::dropItem;
}

bool DropItem::Preconditions(HTNWorldState &htnWorldState)
{
    return m_itemFocusPtr != nullptr; //TODO hook this into the actions code
}

void DropItem::PointToRealItems()
{
    m_itemFocusPtr = &((static_cast<SimItem*>(m_itemFocusPtr))->m_realItem);
}

std::string DropItem::ToString()
{
    std::string name = "DropItem";
    return name;
}

//Start HTNCompounds*****************************************
//***********************************************************
GoToLibraryMethod1::GoToLibraryMethod1()
{
    AddTask(new GoToLibrary());
}

bool GoToLibraryMethod1::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

GoToLibraryMethod2::GoToLibraryMethod2()
{
    AddTask(new GoToMainHall());
    AddTask(new GoToLibrary());
}

bool GoToLibraryMethod2::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

GoToLibraryCompound::GoToLibraryCompound()
{
    m_methods.push_back(new GoToLibraryMethod1());
    m_methods.push_back(new GoToLibraryMethod2());
}

//***********************************************************
GoToGymMethod1::GoToGymMethod1()
{
    AddTask(new GoToGym());
}

bool GoToGymMethod1::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

GoToGymMethod2::GoToGymMethod2()
{
    AddTask(new GoToMainHall());
    AddTask(new GoToGym());
}

bool GoToGymMethod2::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

GoToGymCompound::GoToGymCompound()
{
    m_methods.push_back(new GoToGymMethod1());
    m_methods.push_back(new GoToGymMethod2());
}

//***********************************************************
GoToCircuitTrackMethod1::GoToCircuitTrackMethod1()
{
    AddTask(new GoToCircuitTrack());
}

bool GoToCircuitTrackMethod1::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

GoToCircuitTrackMethod2::GoToCircuitTrackMethod2()
{
    AddTask(new GoToMainHall());
    AddTask(new GoToCircuitTrack());
}

bool GoToCircuitTrackMethod2::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

GoToCircuitTrackCompound::GoToCircuitTrackCompound()
{
    m_methods.push_back(new GoToCircuitTrackMethod1());
    m_methods.push_back(new GoToCircuitTrackMethod2());
}

//***********************************************************
GoToBedroomMethod1::GoToBedroomMethod1()
{
    AddTask(new GoToBedroom());
}

bool GoToBedroomMethod1::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

GoToBedroomMethod2::GoToBedroomMethod2()
{
    AddTask(new GoToMainHall());
    AddTask(new GoToBedroom());
}

bool GoToBedroomMethod2::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

GoToBedroomCompound::GoToBedroomCompound()
{
    m_methods.push_back(new GoToBedroomMethod1());
    m_methods.push_back(new GoToBedroomMethod2());
}

//***********************************************************
IncreaseHealthMethod1::IncreaseHealthMethod1()
{
    AddTask(new Sleep());
}

bool IncreaseHealthMethod1::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

IncreaseHealthMethod2::IncreaseHealthMethod2()
{
    AddTask(new GoToBedroomCompound());
    AddTask(new Sleep());
}

bool IncreaseHealthMethod2::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

IncreaseHealthCompound::IncreaseHealthCompound()
{
    m_methods.push_back(new IncreaseHealthMethod1());
    m_methods.push_back(new IncreaseHealthMethod2());
}

//***********************************************************
IncreaseStrengthMethod1::IncreaseStrengthMethod1()
{
    AddTask(new UseGym());
}

bool IncreaseStrengthMethod1::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

IncreaseStrengthMethod2::IncreaseStrengthMethod2()
{
    AddTask(new GoToGymCompound());
    AddTask(new UseGym());
}

bool IncreaseStrengthMethod2::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

IncreaseStrengthCompound::IncreaseStrengthCompound()
{
    m_methods.push_back(new IncreaseStrengthMethod1());
    m_methods.push_back(new IncreaseStrengthMethod2());
}

//***********************************************************
IncreaseAgilityMethod1::IncreaseAgilityMethod1()
{
    AddTask(new RunCircuits());
}

bool IncreaseAgilityMethod1::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

IncreaseAgilityMethod2::IncreaseAgilityMethod2()
{
    AddTask(new GoToCircuitTrackCompound());
    AddTask(new RunCircuits());
}

bool IncreaseAgilityMethod2::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

IncreaseAgilityCompound::IncreaseAgilityCompound()
{
    m_methods.push_back(new IncreaseAgilityMethod1());
    m_methods.push_back(new IncreaseAgilityMethod2());
}

//***********************************************************
IncreaseIntelligenceMethod1::IncreaseIntelligenceMethod1()
{
    AddTask(new Study());
}

bool IncreaseIntelligenceMethod1::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

IncreaseIntelligenceMethod2::IncreaseIntelligenceMethod2()
{
    AddTask(new GoToLibraryCompound());
    AddTask(new Study());
}

bool IncreaseIntelligenceMethod2::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

IncreaseIntelligenceCompound::IncreaseIntelligenceCompound()
{
    m_methods.push_back(new IncreaseIntelligenceMethod1());
    m_methods.push_back(new IncreaseIntelligenceMethod2());
}

//***********************************************************
AttackMethod1::AttackMethod1(Item* itemPtr)
{
    m_itemPtr = itemPtr;
    AddTask(new PickUpItem(m_itemPtr));
    AddTask(new Punch(0));
}

bool AttackMethod1::Preconditions(HTNWorldState &htnWorldState)
{
    return htnWorldState.m_v.at(WorldE::inSameRoom) && (m_itemPtr->m_locationClass.location == static_cast<Locations>(htnWorldState.m_v.at(WorldE::location)));
}

AttackMethod2::AttackMethod2()
{
    AddTask(new Punch(0));
}

bool AttackMethod2::Preconditions(HTNWorldState &htnWorldState)
{
    return htnWorldState.m_v.at(WorldE::inSameRoom);
}

AttackCompound::AttackCompound(HTNWorldState &htnWorldState)
{
    for (auto &item : htnWorldState.m_items)
    {
        if (item->m_locationClass.location == static_cast<Locations>(htnWorldState.m_v.at(WorldE::location)))
        {
            m_methods.push_back(new AttackMethod1(item));
        }
    }
    m_methods.push_back(new AttackMethod2());
}

AttackCompoundMethod::AttackCompoundMethod(HTNWorldState &htnWorldState)
{
    AddTask(new AttackCompound(htnWorldState));
}

bool AttackCompoundMethod::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

//***********************************************************
EvadeMethod::EvadeMethod()
{
    AddTask(new Evade());
}

bool EvadeMethod::Preconditions(HTNWorldState &htnWorldState)
{
    return (htnWorldState.m_v.at(WorldE::health) < 66) && htnWorldState.m_v.at(WorldE::inSameRoom);
}

CombatCompound::CombatCompound(HTNWorldState &htnWorldState)
{
    m_methods.push_back(new EvadeMethod());
    m_methods.push_back(new AttackCompoundMethod(htnWorldState));
}

//***********************************************************
DoMissionMethod1::DoMissionMethod1()
{
    AddTask(new IncreaseStrengthCompound());
}

bool DoMissionMethod1::Preconditions(HTNWorldState &htnWorldState)
{
    return htnWorldState.m_v.at(WorldE::mission) == static_cast<int>(Missions::increaseStrength);
}

DoMissionMethod2::DoMissionMethod2()
{
    AddTask(new IncreaseAgilityCompound());
}

bool DoMissionMethod2::Preconditions(HTNWorldState &htnWorldState)
{
    return htnWorldState.m_v.at(WorldE::mission) == static_cast<int>(Missions::increaseAgility);
}

DoMissionMethod3::DoMissionMethod3()
{
    AddTask(new IncreaseIntelligenceCompound());
}

bool DoMissionMethod3::Preconditions(HTNWorldState &htnWorldState)
{
    return htnWorldState.m_v.at(WorldE::mission) == static_cast<int>(Missions::increaseIntelligence);
}

DoMissionCompound::DoMissionCompound()
{
    m_methods.push_back(new DoMissionMethod1());
    m_methods.push_back(new DoMissionMethod2());
    m_methods.push_back(new DoMissionMethod3());
}

//***********************************************************
CombatMethod::CombatMethod(HTNWorldState &htnWorldState)
{
    AddTask(new CombatCompound(htnWorldState));
}

bool CombatMethod::Preconditions(HTNWorldState &htnWorldState)
{
    return htnWorldState.m_v.at(WorldE::health) < 68;
}

DoMissionMethod::DoMissionMethod()
{
    AddTask(new DoMissionCompound());
}

bool DoMissionMethod::Preconditions(HTNWorldState &htnWorldState)
{
    return htnWorldState.m_v.at(WorldE::mission) != static_cast<int>(Missions::noMission);
}

IncreaseIntelligenceMethod::IncreaseIntelligenceMethod()
{
    AddTask(new IncreaseIntelligenceCompound());
}

bool IncreaseIntelligenceMethod::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

PrisonerBehaviourCompound::PrisonerBehaviourCompound(HTNWorldState &htnWorldState)
{
    m_methods.push_back(new CombatMethod(htnWorldState));
    m_methods.push_back(new DoMissionMethod());
    m_methods.push_back(new IncreaseIntelligenceMethod());
}

//***********************************************************
PickUpItemMethod1::PickUpItemMethod1(Item* itemFocusPtr)
{
    AddTask(new PickUpItem(itemFocusPtr));
}

bool PickUpItemMethod1::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}

//***********************************************************
DropItemMethod1::DropItemMethod1(Item* itemFocusPtr)
{
    AddTask(new DropItem(itemFocusPtr));
}

bool DropItemMethod1::Preconditions(HTNWorldState &htnWorldState)
{
    return true;
}