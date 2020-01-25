#include "Room.h"

//Constructor - Set name, description, and map
Room::Room(char* name, char* desc, map<char*, Room*> map) {
  this->name = name;
  this->desc = desc;
  this->map = map;
}

//Destructor - Free up data
Room::~Room() {
  name = NULL;
  desc = NULL;
  items = NULL;
  map = NULL;
}

//Set the room's description
void Room::setDesc(char* desc) {
  this->desc = desc;
}

//Add an item to the room
void Room::addItem(Item* item) {
  items.push_back(item);
}

//Remove an item from the room using its address within the vector
void Room::removeItem(int ad) {
  items.erase(items.begin() + (ad - 1));
}

//Return the room's name
char* Room::getName() {
  return name;
}

//Return the room's description
char* Room::getDesc() {
  return desc;
}

//Return the vector pointer of the room's items
vector<Item*>* Room::getItems() {
  return items;
}

//Return the map pointer of the room's exits
map<char*, Room*>* Room::getExits() {
  return map;
}
