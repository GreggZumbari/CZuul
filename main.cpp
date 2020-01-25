#include <iostream>
#include <cstring>

int main() {

  while (true) {
    //Starting instructions
    cout << "Hello, welcome to Freddie Mercury simulator 2020" << endl;
    cout << "Commands:" << endl << "move - Moves your character to an adjacent room" << endl << "shift - Transform into your true state" << endl << "quit - Ends the game. Game cannot be saved, so this deletes your progress" << endl;
    
    cout << "Please type your command: " << endl;
    cout << "FMS> " << endl;
    
    char* cmd = new char[1000];
    cin >> cmd; cin.clear(); cin.ignore((char)0, 1000);

    for (int i = 0; i < strlen(cmd); i++) {
      if (cmd[i] >= 65 && cmd[i] <= 90) {

      }
    }
    
    if (strcmp("MOVE"
  }

}
