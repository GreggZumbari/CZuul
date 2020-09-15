/*
    An object class which contains info for a room, used in the CZuul project.
    @author Greggory Hickman, January 2020
*/

/*
void Room::setName(char*) - Set the room's name
void Room::setDesc(char*) - Set the room's description
void Room::addExit(Room*) - Add an exit to this room
void Room::removeExit(char*) - Delete an existing exit from this room
char* Room::getName() - Return the room's name
char* Room::getDesc() - Return the room's description
Room* Room::getExits() - Return a list of this room's exits in the form of a Room Array (Pointer)
*/

#ifndef ROOM_H
#define ROOM_H

#define MAXEXITCOUNT 50

#include <vector>

#include "Item.h"

class Room {
    public:
        //Constructor & Destructor
        Room(char* name);
        ~Room();
        //Misc. Classes
        void Room::setName(char*);
        void Room::setDesc(char*);
        void Room::addExit(Room*);
        void Room::removeExit(char*);
        char* Room::getName();
        char* Room::getDesc();
        Room* Room::getExits();

    private:
        char* name;
        char* description;
        Room** exits;
        int exitCount;
};

#endif
