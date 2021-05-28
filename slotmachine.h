#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include "rell.h"
#include "gameProperties.h"

class SlotMachine
{
    const std::vector<Rell<int>> rells;
    const GameProperties gameProperties;
    std::vector<std::vector<int>> lastRoll;

public:
    SlotMachine();
    SlotMachine(std::vector<Rell<int>> rellsVec);

    int spinMachine();
    void showLastRoll();

private:
    int analiseLine(std::vector<int> line);
};

#endif // SLOTMACHINE_H
