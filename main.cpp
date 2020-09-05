/*
This is a text-based adventure game in which Irene has to battle everyone
@author Greggory Hickman, January 2020
@version dev
*/

#include <iostream>
#include <cstring>
#include <map>

#include "Room.h"
#include "Item.h"

using namespace std;

int main() {

  //Greeting the user for the first time
  cout << ".___                                 _________.__    " << endl <<
  "|   |______   ____   ____   ____    /   _____/|__| _____  " << endl <<
  "|   \\_  __ \\_/ __ \\ /    \\_/ __ \\   \\_____  \\ |  |/     \\ " << endl <<
  "|   ||  | \\/\\  ___/|   |  \\  ___/   /        \\|  |  Y Y  \\" << endl <<
  "|___||__|    \\___  >___|  /\\___  > /_______  /|__|__|_|  /" << endl <<
  "                 \\/     \\/     \\/          \\/          \\/ " << endl;
  cout << "Greggory Hickman, September 2020" << endl;
  cout << "Hello, and welcome to Irene Simulator 2020!" << endl << endl << "You are Irene and you are tired of Gregg being alive," << endl << "but the rest of the discord server is protecting him!!!" << endl <<
  "If you still have food poisoning during your concert, you will throw up on stage." << endl << "From a small child, you have owned several cats, and have learned their secrets. Because of this, you are able to transform into a cat at will." << endl << endl << "Objective:" << endl << "You must find a way to cure your food poisoning before your concert in one hour." << endl << endl;
  cout << "Commands:" << endl << "move - Moves your character to an adjacent room" << endl << "stab " << endl << "quit - Ends the game. Game cannot be saved, so this deletes your progress" << endl << "help - Lists all possible commands" << endl << endl;

  bool cat = false;
  while (true) {

    cout << "Please type your command: " << endl;
    cout << "Irene> ";

    char* cmd = new char[1000];
    cin >> cmd; cin.clear(); cin.ignore((char)0, 1000);

    cout << "-----" << endl << endl;

    //If the player typed "move"
    if (strcmp("move", cmd) == 0 || cmd[0] == 'm') {
      cout << endl << "-----" << endl;
    }

    //If the player typed "shift"
    else if (strcmp("shift", cmd) == 0 || cmd[0] == 's') {
      cat = !cat;
      cout << cat << endl;
      cout << endl << "-----" << endl;
    }

    //If the player typed "exit"
    else if (strcmp("exit", cmd) == 0 || strcmp("quit", cmd) == 0 || cmd[0] == 'q') {
      //Kill the program
      cout << "Okay, bye!" << endl << "Quitting game..." << endl;
      return 0;
    }

    //If the player typed "help"
    else if (strcmp("help", cmd) == 0 || cmd[0] == 'h') {
      cout << "Commands:" << endl << "move - Moves your character to an adjacent room" << endl << "shift - Transform into your true state" << endl << "quit - Ends the game. Game cannot be saved, so this deletes your progress" << endl << "help - Lists all possible commands" << endl;
    }

    else {
      cout << "Command not recognized." << endl;
      cout << endl << "-----" << endl;
    }
  }

}
