/*
    A class which contains info for a room, used in the CZuul project.
    @author Greggory Hickman, January 2020
*/
#ifndef ROOM_H
#define ROOM_H

struct Item {
    char* name;
    char* desc;
    char type; //'w' = weapon, 'b' = battle item, 'i' = item
};

#endif