/*
    A class which contains info for a room, used in the CZuul project.
    @author Greggory Hickman, January 2020
*/
#ifndef ROOM_H
#define ROOM_H

#include <vector>

#include "Item.h"

class Room {
    public:
        //Constructor & Destructor
        Room();
        ~Room();

    private:
        char* name;
        char* description;
        Room* exits;
};

#endif
