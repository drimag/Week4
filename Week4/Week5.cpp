#include "ConsoleManager.h"
#include <iostream>
#include <thread>
#include <atomic>

// Global flag to control the running state
std::atomic<bool> running(true);

// Function for handling user input in a separate thread
void inputHandler() {
    std::string input;
    while (running) {
        std::getline(std::cin, input);
        if (input == "exit") {
            running = false;
        }
    }
}

// Function for the marquee worker (responsible for bouncing text)
void marqueeWorker() {
    while (running) {
        // Update the position of the marquee text
        ConsoleManager::getInstance()->process();

        // Draw the updated marquee
        ConsoleManager::getInstance()->drawConsole();

        // Control the refresh rate with a small delay
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Adjust speed as needed
    }
}

int main() {
    // Start the input handling thread
    std::thread inputThread(inputHandler);

    // Start the marquee worker in the main thread
    marqueeWorker();

    // Wait for the input thread to finish
    inputThread.join();

    return 0;
}
