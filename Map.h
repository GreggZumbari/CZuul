/*
    A class which contains info for a map, which contains , used in the CZuul project.
    @author Greggory Hickman, January 2020
*/
#ifndef ROOM_H
#define ROOM_H

#include "Room.h"

class Map {
    public:
        //Constructor & Destructor
        Map();
        ~Map();

    private:
        char* name;
        char* desc;
        vector<Item*> items;
        map<char*, Room*> map;
};

#endif
