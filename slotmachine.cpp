#include "slotmachine.h"

#define SIZE_WINDOW_OX 3
#define SIZE_WINDOW_OY 3
#define WILD_POSITION 0

#include <iostream>
using namespace std;

bool compareSymbols(int s1, int s2);
bool compareSymbolIsWild(int s1, int s2);
vector<vector<int>> createLines(const vector<vector<int>> &spinResult);
void createHorizontalLines(vector<vector<int>> *lines, const vector<vector<int>> &spinResult);
void createDiagonalLines(vector<vector<int>> *lines, const vector<vector<int>> &spinResult);

SlotMachine::SlotMachine()
{

}

// constructor class SlotMachine
// @param rellsVec - vector showing spinning rollers
SlotMachine::SlotMachine(std::vector<Rell<int>> rellsVec) : rells(rellsVec), gameProperties()
{

}

// function simulates spinning the machine
// @return winnings multiplier
int SlotMachine::spinMachine()
{
    lastRoll.clear();
    for(int i = 0; i < SIZE_WINDOW_OX; i++)
    {
        lastRoll.push_back(rells[i].spin(SIZE_WINDOW_OY));
    }

    vector<vector<int>> lines = createLines(lastRoll);
    int result = 0;
    for(size_t i = 0; i < lines.size(); i++) {
        result += analiseLine(lines[i]);
    }

    return result;
}

// function based on send line determines winning multiplier
// @param line - arranged one line from spin result
// @return winning multiplier on this line
int SlotMachine::analiseLine(vector<int> line)
{
    int symbol = line[0];
    int resultWin = 0;
    for(size_t i = 1; i < line.size(); i++)
    {
        if(compareSymbolIsWild(line[i], symbol)) {
            symbol = line[i];
        }

        if(compareSymbols(line[i], symbol)) {
            break;
        }

        if(i == line.size()-1)
            resultWin = gameProperties.gameProperties.at(symbol);
    }

    return resultWin;
}

// function character comparison
// @return true if characters is the same or character is wild
//         false if charactrs isn't the same
bool compareSymbols(int s1, int s2)
{
    if(s1 != s2 && s1 != WILD_POSITION) {
        return true;
    }
    return false;
}

// function character comparison
// @return true if characters is wild
//         false if charactrs isn't wild
bool compareSymbolIsWild(int s1, int s2)
{
    if(s2 == WILD_POSITION && s1 != WILD_POSITION) {
        return true;
    }
    return false;
}

// function laying all lines in spin
// @return vector with all lines from spin
vector<vector<int>> createLines(const vector<vector<int>> &spinResult)
{
    vector<vector<int>> lines;
    createHorizontalLines(&lines, spinResult);
    createDiagonalLines(&lines, spinResult);

    return lines;
}

// function laying all horizontal lines in spin
// @param lines - pointer to the resultant vector
//        spinResult - result from spin
// @return vector with all horizontal lines from spin
void createHorizontalLines(vector<vector<int>> *lines, const vector<vector<int>> &spinResult)
{
    vector<int> tempVec;

    for(int i = 0; i < SIZE_WINDOW_OX; i++)
    {
        for(int j = 0; j < SIZE_WINDOW_OY; j++)
        {
            tempVec.push_back(spinResult[i][j]);
        }
        lines->push_back(tempVec);
        tempVec.clear();
    }
}

// function laying all horizontal lines in spin
// @param lines - pointer to the resultant vector
//        spinResult - result from spin
// @return vector with all horizontal lines from spin
void createDiagonalLines(vector<vector<int>> *lines, const vector<vector<int>> &spinResult)
{
    vector<int> tempVec;

    for(int i = 0; i < SIZE_WINDOW_OY; i++) {
        tempVec.push_back(spinResult[i][i]);
    }
    lines->push_back(tempVec);
    tempVec.clear();

    for(int i = SIZE_WINDOW_OY-1; i >= 0; i--) {
        tempVec.push_back(spinResult[spinResult.size()-i-1][i]);
    }
    lines->push_back(tempVec);
    tempVec.clear();
}

// function showing last roll
void SlotMachine::showLastRoll()
{
    for(const auto &lastRollVec : lastRoll)
    {
        for(const auto & lastRollValue : lastRollVec)
        {
            cout << lastRollValue << " ";
        }
        cout << endl;
    }
}
