#include <iostream>
#include <windows.h>
#include <ctime>
#include <utility>

#include "util.h"

// setting cursor location at the location
void setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { x, y };
    SetConsoleCursorPosition(hConsole, pos);
}

std::pair<int, int> getCurrentCursorPosition() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        return std::make_pair(csbi.dwCursorPosition.Y, csbi.dwCursorPosition.X);
    }
    else {
        std::cerr << "Error getting console screen buffer info." << std::endl;
        return std::make_pair(-1, -1);  // Return invalid values in case of an error
    }
}

void printCurrentDateTime() {
    std::time_t currentTime = std::time(nullptr);
    std::tm localTime;

    localtime_s(&localTime, &currentTime);

    char buffer[100];

    // Format the time
    std::strftime(buffer, sizeof(buffer), "%a %b %d %H:%M:%S %Y", &localTime);

    std::cout << buffer << std::endl;
}

std::string truncateWithEllipsis(const std::string& str, size_t maxLength) {
    if (str.length() > maxLength) {
        size_t numToKeep = maxLength - 3;
        return "..." + str.substr(str.length() - numToKeep);
    }
    return str; 
}