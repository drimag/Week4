#include <iostream>
#include <thread>
#include <atomic>

#include "ConsoleManager.h"

std::atomic<bool> running(true);

static void inputHandler() {
    std::string input;
    while (running) {
        std::getline(std::cin, input);
        if (input == "exit") {
            running = false;
        }
    }

    while (running);


}

static void marquee() {
    while (running) {
        ConsoleManager::getInstance()->process();
        ConsoleManager::getInstance()->drawConsole();

        std::this_thread::sleep_for(std::chrono::milliseconds(10));  
    }
}

int main() {
    //input handling thread
    std::thread inputThread(inputHandler);

    // Start the marquee worker in the main thread
    marquee();

    // Wait for the input thread to finish
    inputThread.join();

    return 0;
}
