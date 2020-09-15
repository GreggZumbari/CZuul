#include "Room.h"

//Constructor - Set name, description, and map
Room::Room(char* name) {
    this->name = name;
    description = "DESCRIPTION GOES HERE"
    exits = new *Room[MAXEXITCOUNT];
    exitCount = 0;
}

//Destructor - Free up data
Room::~Room() {
    name = NULL;
    description = NULL;
    exits = NULL;
    exitCount = 0;
}

//Set room's name
void Room::setName(char* name) {
    this->name = name;
}

//Set the room's description
void Room::setDesc(char* desc) {
    this->description = desc;
}

//Add an exit to this room
void Room::addExit(Room* exit) {
    exits[exitCount] = exit;
    exitCount++;
}

//Remove an exit from this room
void Room::removeExit(char* name) {
    for (int i = 0; i < exitCount; i++) { //For each exit
        if (exits[i].getName() = name) { //If this exit has the same name as the one foretold by the prophecy
            exits[i] = NULL; //Delete that room's pointer

            //Move the remaining rooms one to the left to patch the hole left by the deleted room
            for (int j = i + 1; j < exitCount; j++) {
                exits[j-1] = exits[j]; //Set the previous slot equal to the current slot
            }
            break;
        }
    }
}

//Add an item to the room
/*
void Room::addItem(Item* item) {
  items.push_back(item);
}
*/

//Remove an item from the room using its address within the vector
/*
void Room::removeItem(int ad) {
  items.erase(items.begin() + (ad - 1));
}
*/

//Return the room's name
char* Room::getName() {
    return name;
}

//Return the room's description
char* Room::getDesc() {
    return description;
}

//Return a list of rooms
Room* Room::getExits() {
    return map;
}

//Return the vector pointer of the room's items
/*
vector<Item*>* Room::getItems() {
  return items;
}
*/
