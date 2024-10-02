#include <iostream>
#include <string>

#include "processes.h"
#include "graphics.h"
#include "util.h"

int main()
{
    while (true) {
        std::string userInput;
        std::getline(std::cin, userInput);


        if (userInput == "nvidia-smi") {
            // If the command is correct, run the program
            printCurrentDateTime();
            printHeader();
            printProcessHeader();
            printProcess();
        }
        else {
            // If the command is incorrect, inform the user
            std::cout << "Invalid command. Please enter 'nvidia-smi'." << std::endl;
        }
    }
    
}


