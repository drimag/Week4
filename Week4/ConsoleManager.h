#pragma once

#include <string>
#include <atomic>
#include <vector>

class ConsoleManager {
public:
    static ConsoleManager* getInstance();

    void process();
    void displayProcess();
    void drawConsole();
    void setCurrentCommand(const std::string& newCommand);
    void addCommand(const std::string& newCommand);
    void updateCursorPosition();

private:
    ConsoleManager();
    static ConsoleManager* instance;

    std::string text;
    std::vector<std::string> pastCommands;
    std::string currentCommand;
    int posX, posY;
    int width, height;
    bool directionX, directionY;
};
