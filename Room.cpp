#include "Room.h"
//#include "BattlePack.h"

//Constructor - Set name, description, and map
Room::Room(char* name) {
    this->name = name;
    description = new char[MAX_DESC_LENGTH];
    strcpy(description, "DESCRIPTION");
    exits = new Room*[MAX_EXIT_COUNT];
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
        if (name) { //If this exit's name and the name passed in match...
            exits[i] = NULL; //...then delete that room's pointer

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

//Return the list of exits (type Room*)
Room** Room::getExits() {
    return exits;
}

//Return a list of the exit names separated by commas and spaces
char* Room::getExitNames() {
    const int EXIT_LIST_LENGTH = MAX_EXIT_LENGTH * (exitCount + 1); //MAX_EXIT_LENGTH * (exitCount + 1) is an over-estimate of how much space will need to be allocated for this char*, in order to avoid allocating too much more than is needed

    char* exitList = new char[EXIT_LIST_LENGTH]; //Will contain the list of all exits
    for (int i = 0; i < EXIT_LIST_LENGTH; i++) { //Clear exitList of stray data
		exitList[i] = (char)0;
	}

    for (int i = 0; i < exitCount; i++) {
        strcat(exitList, exits[i]->getName()); //Slap the exit's name on the end of the char*...
        strcat(exitList, ", "); //...followed by a comma and a space
    }
    return exitList;
}

//Return the vector pointer of the room's items
/*
vector<Item*>* Room::getItems() {
  return items;
}
*/
