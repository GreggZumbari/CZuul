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
Room** Room::getExits() - Return a list of this room's exits in the form of a Room** (List of Room Pointers)
char* Room::getExitNames() - Return a list of this room's exits names in the form of char* (Example: Exit1, Exit2, Exit3,... etc.)
*/

#ifndef ROOM_H
#define ROOM_H

#define MAX_EXIT_LENGTH 40
#define MAX_EXIT_COUNT 50
#define MAX_DESC_LENGTH 1000

#include <cstring>

#include "Item.h"

class Room {
    public:
        //Constructor & Destructor
        Room(char* name);
        ~Room();
        //Misc. Classes
        void setName(char*);
        void setDesc(char*);
        void addExit(Room*);
        void removeExit(char*);
        char* getName();
        char* getDesc();
        Room** getExits();
        char* getExitNames();

    private:
        char* name; //Room name
        char* description; //Room description
        Room** exits; //Room exits (list of room pointers)
        int exitCount; //Number of current exits. Note: Starts at 0, not 1
};

#endif
