#include "mathfuncs.h"
#include <stdexcept>
#include <string>

double calculate(const std::string& command, double operand1, double operand2) {
    if (command == "add") {
        return operand1 + operand2;
    }
    else if (command == "subtract") {
        return operand1 - operand2;
    }
    else if (command == "multiply") {
        return operand1 * operand2;
    }
    else if (command == "divide") {
        if (operand2 == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return operand1 / operand2;
    }
    else {
        throw std::invalid_argument("Invalid command");
    }
}