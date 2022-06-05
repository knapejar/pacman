#pragma once

#include <ncurses.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <climits>
#include <assert.h>

#include "game/Game.hpp"



/**
 * @brief Self testing utility for the basic functionality of the game
 * 
 * @details This class verifies the basic functionality of the game including the map loading, the player movement, the ghosts movement and the ghosts behaviour.
 */

class SelfTest{
    private:
        bool verbose = false;
    public:
        SelfTest();
        SelfTest(bool verbose);
        ~SelfTest();

        /**
         * @brief Performs the test
         * 
         * @return true if test succeeded
         * @return false if test failed
         */
        bool test();
};
