#include <iostream>
#include <utility>

#include "processes.h"
#include "util.h"

void printProcess() {

    Process processes[5] = {
        {1234, "C+G", "Process1", "N/A"},
        {5678, "C+G", "Process2/thequickBrown/Outplayed/ValoPlant/longProcessName.exe", "N/A"},
        {9101, "C+G", "Process3", "N/A"},
        {1121, "C+G", "Process4", "N/A"},
        {1341, "C+G", "Process5", "N/A"}
    };

    std::pair<int, int> cursorPosBefore = getCurrentCursorPosition();
    int row = cursorPosBefore.first;
    
    for (int i = 0; i < 5; i++) {
        setCursorPosition(0, row + i); std::cout << "|    0   N/A  N/A                                                                         |";
        setCursorPosition(23, row + i); std::cout << processes[i].pid;
        setCursorPosition(31, row + i); std::cout << processes[i].type;
        setCursorPosition(37, row + i); std::cout << truncateWithEllipsis(processes[i].name, 41);
        setCursorPosition(81, row + i); std::cout << processes[i].gpuMemory;
    }
    std::pair<int, int> cursorPosAfter = getCurrentCursorPosition();
    setCursorPosition(0, cursorPosAfter.first + 1);

}
