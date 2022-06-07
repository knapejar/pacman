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
#include "../Config.hpp"
#include "../screen/Screen.hpp"


/**
 * @brief This class represents the game screen
 *
 * @details This class implements the game logic state machine
 */

enum GameState{
    PLAYING,
    PAUSED,
    GAMEOVER,
    WON
};

/**
 * @brief The main Game class
 *
 * @details This class implements EntityManager and Map
 * @details It is responsible for the game logic
 */

class Game : public EntityManager, public Map, public Screen{
    public:
        Config config;
    private:
        GameState gameState = PLAYING;
        Map map;
        std::string mapFileName = "";
        EntityManager entityManager;
        
        int tickLength = config.tickLength;
        WINDOW * window;
        int infoScreenSize = 3;
    public:
        Game();
        Game(std::string fileName);
        ~Game();
        void renderScoreBoard();
        void run();

        ScreenState show();

        GameState getGameState();
};