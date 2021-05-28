#ifndef GAMEPROPERTIES_H
#define GAMEPROPERTIES_H

#include <map>

#define WILD        0
#define WILD_WIN    200
#define STAR        1
#define STAR_WIN    100
#define MELON       2
#define MELON_WIN   50
#define BELL        3
#define BELL_WIN    20
#define GRAPES      4
#define GRAPES_WIN  20
#define PLUM        5
#define PLUM_WIN    5
#define ORANGE      6
#define ORANGE_WIN  5
#define LEMON       7
#define LEMON_WIN   5
#define CHERRY      8
#define CHERRY_WIN  5

struct GameProperties {
    std::map<int, int> gameProperties;

    GameProperties()
    {
        gameProperties.insert(std::pair<int, int>(WILD, WILD_WIN));
        gameProperties.insert(std::pair<int, int>(STAR, STAR_WIN));
        gameProperties.insert(std::pair<int, int>(MELON, MELON_WIN));
        gameProperties.insert(std::pair<int, int>(BELL, BELL_WIN));
        gameProperties.insert(std::pair<int, int>(GRAPES, GRAPES_WIN));
        gameProperties.insert(std::pair<int, int>(PLUM, PLUM_WIN));
        gameProperties.insert(std::pair<int, int>(ORANGE, ORANGE));
        gameProperties.insert(std::pair<int, int>(LEMON, LEMON_WIN));
        gameProperties.insert(std::pair<int, int>(CHERRY, CHERRY_WIN));
    }
};

#endif // GAMEPROPERTIES_H
