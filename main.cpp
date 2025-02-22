#include <iostream>
#include <cstdlib>
#include "randfuncs.h"

using namespace std;

#include <string>
#include "mathfuncs.h"

using namespace std;

double calculate(const string& command, double operand1, double operand2);

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
            cout << "add <num1> <num2> - Adds two numbers" << endl;
            cout << "subtract <num1> <num2> - Subtracts num2 from num1" << endl;
            cout << "multiply <num1> <num2> - Multiplies two numbers" << endl;
            cout << "divide <num1> <num2> - Divides num1 by num2" << endl;
            cout << "quit - Exits the calculator" << endl;
        } 
        else if (command == "flip") {
            int result = flip_coin();
            cout << (result == 0 ? "Heads" : "Tails") << endl;
        } 
        else if (command == "roll") {
            int sides;
            cin >> sides;

            if (sides == 6 || sides == 20) {
                cout << "Rolled: " << roll_dice(sides) << endl;
            } else {
                cout << "Invalid number of sides. Must be 6 or 20." << endl;
            }
        } 
        else if (command == "add" || command == "subtract" || command == "multiply" || command == "divide") {
            double num1, num2;
            cin >> num1 >> num2;
            try {
                double result = calculate(command, num1, num2);
                cout << "Result: " << result << endl;
            }
            catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
                return 1;
            }
        }
        else if (command != EXIT) {
            cout << "Unknown command. Type 'help' for available commands." << endl;
        }
    } while (command != EXIT);        
    return 0;
}
