#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <atomic>
#include <vector>
#include <Windows.h>

#include "graphics.h"
#include "util.h"
#include "ConsoleManager.h"


ConsoleManager* ConsoleManager::instance = nullptr;

ConsoleManager* ConsoleManager::getInstance() {
    if (!instance) {
        instance = new ConsoleManager();
    }
    return instance;
}

ConsoleManager::ConsoleManager() : text("This is a Marquee"), posX(0), posY(3), width(80), height(20), directionX(true), directionY(true), running(true) {}

void ConsoleManager::process() {
    setCursorPosition(posX, posY);
}

void ConsoleManager::drawConsole() {
    clearScreen();
    printMarqueeHeader();
    updateCursorPosition();
    setCursorPosition(posX, posY);
    std::cout << text;
}

bool ConsoleManager::isRunning() {
    return running.load();
}

void ConsoleManager::stop() {
    running.store(false);
}

void ConsoleManager::setText(const std::string& newText) {
    text = newText;
}

void ConsoleManager::setConsoleSize(int w, int h) {
    width = w;
    height = h;
}

void ConsoleManager::updateCursorPosition() {
    if (directionX) {
        posX++;
    }
    else {
        posX--;
    }

    if (posX <= 0 || posX >= width - text.size()) {
        directionX = !directionX;
    }

    if (directionY) {
        posY++;
    }
    else {
        posY--;
    }

    if (posY <= 3 || posY >= height - 1) {
        directionY = !directionY;
    }
}
