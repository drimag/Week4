#pragma once

// Function to set cursor position
void setCursorPosition(int x, int y);

std::pair<int, int> getCurrentCursorPosition();

void printCurrentDateTime();

std::string truncateWithEllipsis(const std::string& str, size_t maxLength);