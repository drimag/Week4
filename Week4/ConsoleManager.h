#pragma once

#include <string>
#include <atomic>

class ConsoleManager {
public:
    static ConsoleManager* getInstance();

    void process();
    void drawConsole();
    bool isRunning();
    void stop();
    void setText(const std::string& newText);
    void setConsoleSize(int w, int h);

private:
    ConsoleManager();
    static ConsoleManager* instance;

    std::string text;
    std::string pastCommands;
    std::string currentCommand;
    int posX, posY;
    int width, height;
    bool directionX, directionY;
    std::atomic<bool> running;
};
