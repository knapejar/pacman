#pragma once

#include <ncurses.h>
#include "../screen/TextScreen.hpp"

#include "map/Map.hpp"
#include "entity/Angle.hpp"

#include "entity/EntityManager.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>



enum GameState{
    PLAYING,
    PAUSED,
    GAMEOVER,
    WON
};

class Game{
    private:
        GameState gameState = PLAYING;
        Map map;
        EntityManager entityManager;
        
        int tickLength = 100;
        WINDOW * window;
        int infoScreenSize = 3;
    public:
        Game();
        Game(std::string fileName);
        ~Game();
        void renderScoreBoard();
        void run();

        GameState getGameState();
};