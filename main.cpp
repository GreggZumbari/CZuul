/*
Main class for Irene Sim

Requires Gregg's BattlePack 9/14/2020 or newer

@author Greggory Hickman, January 2020
@version dev
*/

#include <iostream>
#include <cstring>

#include "Room.h"
//#include "Item.h"
#include "UniversalSleep.h"

using namespace std;

//Prototypes
void printCommands(); //Print out all possible user commands and a short description

int main() {
    //Create temporary test rooms
    Room* room1 = new Room((char*)"Kitchen");
    Room* room2 = new Room((char*)"Sex Room");
    Room* room3 = new Room((char*)"Other Sex Room");

    room1->addExit(room2);
    room1->addExit(room3);
    room2->addExit(room1);
    room3->addExit(room1);

    //Define the player's current room
    Room* currentRoom;

    //Greeting the user for the first time
    //ASCII art, reading "Irene Sim"
    cout << ".___                                 _________.__    " << endl <<
    "|   |______   ____   ____   ____    /   _____/|__| _____  " << endl <<
    "|   \\_  __ \\_/ __ \\ /    \\_/ __ \\   \\_____  \\ |  |/     \\ " << endl <<
    "|   ||  | \\/\\  ___/|   |  \\  ___/   /        \\|  |  Y Y  \\" << endl <<
    "|___||__|    \\___  >___|  /\\___  > /_______  /|__|__|_|  /" << endl <<
    "                 \\/     \\/     \\/          \\/          \\/ " << endl;
    //Opening Dialogue
    cout << "Greggory Hickman, September 2020" << endl << endl;
    cout << "Hello, and welcome to Irene Simulator 2020!" << endl << endl;
    //wait(2000);
    cout << "All beings in this world have a SPECIAL POWER." << endl <<
    "Yours is the ability to SHIFT!" << endl << endl;
    //wait(4000);
    cout << "From a small child, you have owned several cats, and have learned their secrets." << endl <<
    "Because of this, you are able to transform into a cat at will." << endl << endl;
    //wait(4000);
    cout << "Your name is Irene, and you are tired of your friend, Gregg, being alive," << endl <<
    "and so you have decided to end his existence!" << endl << endl;
    //wait(4000);
    cout << "Objective:" << endl;
    //wait(4000);
    cout << "Kill Gregg." << endl << endl;
    //wait(4000);
    printCommands(); //Print command
    cout << endl;

    //Game start

    bool cat = false; //Is Irene currently in her cat form?
    currentRoom = room1; //Set current room to the starting room


    while (true) {

        //Give the player information about the current room
        cout << "Room name: " << currentRoom->getName() << endl;
        cout << "Room description: " << currentRoom->getDesc() << endl;
        cout << "Exits: " << currentRoom->getExitNames() << endl;

        cout << "Please type your command: " << endl;
        cout << "Irene> "; //This is the place where the player can type in a command

        char* cmd = new char[1000]; //The user's command will be stored in char* cmd
        cin >> cmd; cin.clear(); cin.ignore((char)0, 1000); //Read in the player's command

        cout << "-----" << endl << endl;

        //If the player typed "move"
        if (strcmp("move", cmd) == 0 || cmd[0] == 'm') {
            cout << endl << "-----" << endl;
            if (strcmp(currentRoom->getName(), room1->getName()) == 0) currentRoom = room2;
            else currentRoom = room1;
        }

        //If the player typed "shift"
        else if (strcmp("shift", cmd) == 0 || cmd[0] == 's') {
            cat = !cat;
            if (cat) {
                cout << "You transformed into a cat.";
            }
            else {
                cout << "You transformed back into a human.";
            }
            cout << endl << "-----" << endl;
        }

        //If the player typed "help"
        else if (strcmp("help", cmd) == 0 || cmd[0] == 'h') {
              printCommands();
        }

        //If the player typed "exit"
        else if (strcmp("exit", cmd) == 0 || strcmp("quit", cmd) == 0 || cmd[0] == 'q') {
              //Kill the program
              cout << "Okay, bye!" << endl << "Quitting game..." << endl;
              return 0;
        }

        //If the player typed an invalid command
        else {
              cout << "Command not recognized." << endl;
              cout << endl << "-----" << endl;
        }
    }

}

void printCommands() {
    cout << "Commands:" << endl << "move - Moves your character to an adjacent room" << endl <<
    "shift - Transform into your true state" << endl <<
    "help - Lists all possible commands (which is what you're reading right now!)" << endl <<
    "quit - Ends the game. Game cannot be saved, so this deletes your progress" << endl;
}
