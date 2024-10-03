#include <iostream>
#include <thread>
#include <atomic>
#include <conio.h>

#include "ConsoleManager.h"
#include "util.h"

std::atomic<bool> running(true);
std::string currentCommand;

static void inputHandler(ConsoleManager* consoleManager) {
    char ch;

    while (running) {
        if (_kbhit()) {
            ch = _getch();

            if (ch == '\r') {  // Enter key 
                if (currentCommand == "exit") {
                    clearScreen();
                    running = false;
                }
                else {
                    consoleManager->addCommand(currentCommand);
                    currentCommand.clear();
                }
            }

            else if (ch == '\b') {  // Backspace
                if (!currentCommand.empty()) {
                    currentCommand.pop_back();
                    consoleManager->setCurrentCommand(currentCommand);
                }
            }

            else {
                currentCommand += ch;
                consoleManager->setCurrentCommand(currentCommand);
            }
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

static void marquee(ConsoleManager* consoleManager) {
    while (running) {
        consoleManager->drawConsole();

        std::this_thread::sleep_for(std::chrono::milliseconds(10));  
    }
}

int main() {
    //input handling thread

    ConsoleManager* consoleManager = ConsoleManager::getInstance();

    std::thread inputThread(inputHandler, consoleManager);
    std::thread displayThread(marquee, consoleManager);

    // Wait for the input thread to finish
    inputThread.join();
    displayThread.join();

    return 0;
}
