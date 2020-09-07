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
        Room(char* name, char* desc, map<char*, Room*>);
        ~Room();

        //Setters and Getters
        void setDesc(char*);
        void addItem(Item*);
        void removeItem(int);
        char* getName();
        char* getDesc();
        vector<Item*>* getItems();
        map<Room*> getExits();

    private:
        char* name;
        char* desc;
        vector<Item*> items;
        map<char*, Room*> map;
};

#endif
