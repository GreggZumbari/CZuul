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
#include "BattlePack.h"
#include "UniversalSleep.h"

#define LEN 1000

using namespace std;

//Prototypes
void roomAppraise(Room*); //Print out information about the Room* to console
void runIntroduction(); //Run the intro event
void printCommands(); //Print out all possible user commands and a short description

int main() {
    /**
    Generate the world
    */
    //Create temporary test rooms
    Room* kitchen = new Room((char*)"The Kitchen");
    Room* sex1 = new Room((char*)"The Sex Room");
    Room* sex2 = new Room((char*)"The Other Sex Room");

    kitchen->addExit(sex1);
    kitchen->addExit(sex2);
    sex1->addExit(kitchen);
    sex2->addExit(kitchen);

    //Define long-term variables
    bool cat = false; //Is Irene currently in her cat form?

    //Define Irene's location
    Room* currentRoom; //This will respresent Irene's current location
    currentRoom = kitchen; //Set current room to the starting room

    //Play the game introduction
    runIntroduction();

    //Game start
    while (true) {

        //Give the player information about the current room
        roomAppraise(currentRoom);

        cout << "Irene> "; //This is the place where the player can type in a command

        char* cmd = new char[LEN]; //The user's command will be stored in char* cmd
        clearCString(cmd, LEN); //Clear cmd of data

        cin.getline(cmd, LEN); //Read in the player's command

        //Separate the what the player typed into two words

        char* firstWord = new char[(int)(LEN / 2)]; //The first word
        char* secondWord = new char[(int)(LEN / 2)];; //The second word
        clearCString(firstWord, LEN); //Clear both the first and second words of stray data
        clearCString(secondWord, LEN);
        if (cmd[0] != (char)0) { //If the user didn't leave the section blank
            //First word
            int i; //Iterator for cmd AND firstWord -- what a fun coincidence
            for (i = 0; true; i++) {
                if (cmd[i] != (char)32 && cmd[i] != (char)0) { //If != Space or Null
                    firstWord[i] = cmd[i]; //Transfer over the first word from cmd one letter at a time
                }
                else {
                    //If we got here, that means that cmd[i] is either a Space, or a Null
                    i++; //Move past the space (assuming it's not a Null, in which case, it doesn't matter)
                    break;
                }
            }
            //Second word
            int j; //Iterator for second word
            for (j = 0; true; j++) {
                if (cmd[i + j] != (char)32 && cmd[i + j] != (char)0) { //If != Space or Null
                    secondWord[j] = cmd[i + j]; //Remember: "i" is stuck at the length of the first word, so i+j comes to the correct position on the second word
                }
                else {
                    break;
                }
            }
        }

        cout << "-----" << endl << endl;

        //If the player typed "move"
        if (strcmp("move", firstWord) == 0 || firstWord[0] == 'm') {
            cout << endl << "-----" << endl;
            if (strcmp(currentRoom->getName(), kitchen->getName()) == 0) currentRoom = sex1;
            else currentRoom = kitchen;
        }

        //If the player typed "shift"
        else if (strcmp("shift", firstWord) == 0 || firstWord[0] == 's') {
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
        else if (strcmp("help", firstWord) == 0 || firstWord[0] == 'h' || firstWord[0] == '?') {
              printCommands();
        }

        //If the player typed "exit"
        else if (strcmp("exit", firstWord) == 0 || strcmp("quit", firstWord) == 0 || firstWord[0] == 'q') {
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

void roomAppraise(Room* room) {
    cout << "- Location -" << endl << room->getName() << endl; //Room name
    cout << room->getDesc() << endl << endl; //Room desc
    cout << "- Exits -" << endl << room->getExitNames() << endl << endl;
}

void runIntroduction() {
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
    wait(2000);
    cout << "All beings in this world have a SPECIAL POWER." << endl <<
    "Yours is the ability to SHIFT!" << endl << endl;
    wait(4000);
    cout << "Since birth you have studied every cat that you have ever come across, and you have learned their secrets." << endl <<
    "Because of this, you are able to transform into a cat at will." << endl << endl;
    wait(4000);
    cout << "Your name is Irene, and you are tired of the evil summoner, Gregg, weaking havoc all across the land." << endl <<
    "You know that you will be the one to put an end to his reign!" << endl << endl;
    wait(4000);
    cout << "Objective:" << endl;
    wait(4000);
    cout << "Kill Gregg." << endl << endl;
    wait(4000);
    cout << "Type \"help\" or \"?\" for commands" << endl << endl;
    cout << "-----" << endl << endl; //Divider
    wait(2000);
}



void printCommands() {
    cout << "Commands:" << endl << "move - Moves your character to an adjacent room" << endl <<
    "shift - Transform into your true state" << endl <<
    "help - Lists all possible commands (which is what you're reading right now!)" << endl <<
    "quit - Ends the game. Game cannot be saved, so this deletes your progress" << endl << endl;
}
