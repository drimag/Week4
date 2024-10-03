#include <iostream>
#include <thread>
#include <atomic>
#include <conio.h>

#include "ConsoleManager.h"

std::atomic<bool> running(true);

static void inputHandler() {
    std::string input;
    while (running) {
        //if (_kbhit()) {  // If a key was pressed
        //    char ch = _getch();  // Get the key that was pressed
        //    std::cout << "You pressed: " << ch << std::endl;

        //    if (ch == 'q') {  // Quit if 'q' is pressed
        //        running = false;
        //    }
        //}

        /*std::getline(std::cin, input);
        if (input == "exit") {
            running = false;
        }*/
        
    }


    while (running);


}

static void marquee() {
    while (running) {
        ConsoleManager::getInstance()->process();
        ConsoleManager::getInstance()->drawConsole();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));  
    }
}

int main() {
    //input handling thread
    //std::thread inputThread(inputHandler);

    // Start the marquee worker in the main thread
    marquee();

    // Wait for the input thread to finish
    //inputThread.join();

    return 0;
}
