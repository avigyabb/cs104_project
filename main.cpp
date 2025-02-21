#include <iostream>
#include <cstdlib>
#include "randfuncs.h"

using namespace std;

int main(int argc, char *argv[]) {
    const string EXIT = "quit";
    string command;

    cout << "Welcome to the Random Function Program!" << endl;
    cout << "Type 'help' for available commands or 'quit' to exit." << endl;

    do {
        cout << "calc: ";
        cin >> command;

        if (command == "help") {
            cout << "Available commands:\n";
            cout << "  flip    - Flip a coin (returns heads or tails)\n";
            cout << "  roll N  - Roll a die with N sides (N must be an integer > 1)\n";
            cout << "  quit    - Exit the program\n";
        } 
        else if (command == "flip") {
            int result = flip_coin();
            cout << (result == 0 ? "Heads" : "Tails") << endl;
        } 
        else if (command == "roll") {
            int sides;
            cin >> sides;

            if (sides > 1) {
                cout << "Rolled: " << roll_dice(sides) << endl;
            } else {
                cout << "Invalid number of sides. Must be greater than 1." << endl;
            }
        } 
        else if (command != EXIT) {
            cout << "Unknown command. Type 'help' for available commands." << endl;
        }

    } while (command != EXIT);

    cout << "Exiting program. Goodbye!" << endl;
    return 0;
}
