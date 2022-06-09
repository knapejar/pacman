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

class Game : public Screen{
    public:
        Config config;
    private:
        GameState gameState = PLAYING;
        int tickLength = config.tickLength;
        int infoScreenSize = 3;

        std::string mapFileName = "";
        Map map;
        EntityManager entityManager;
        
        /**
         * @brief Renders the scoreboard inside the game window, this method is used internally
         */
        void renderScoreBoard();
    public:
        /**
         * @brief Construct a new Game object with the default map
         */
        Game();

        /**
         * @brief Construct a new Game object from the given file
         * 
         * @param fileName (file from the example folder by default)
         */
        Game(std::string & fileName);

        /**
         * @brief The main game method
         */
        void run();

        ScreenState show();

        /**
         * @brief Get the Game State object which controlls the main game loop
         * 
         * @return GameState 
         */
        GameState getGameState();
};