#pragma once

#include "Entity.hpp"



/**
 * @brief Class responsible for the player behaviour - parsing the input and moving the player, eating, counting the score and health management
 * 
 * @details This class is being implemented by the EntityManager class and is responsible for the entity logic and rendering
 */

class Player : public Entity{
    private:
        std::string name = "Player";
        std::string saveName = "P";
        std::string renderName = "XX";
        Angle targetAngle;
        int score = 0;
        int lives = config.playerHealth;
    public:
        Player();
        Player(Position position, Angle angle);
        ~Player();

        /**
         * @brief Method responsible for the player movement
         * 
         * @param input 
         * @return Player 
         */
        Player keyboardInput(int input);

        /**
         * @brief Method performing one tick of the game logic (especially the player movement)
         * 
         * @return Player 
         */
        Player tick();

        /**
         * @brief Resets the player score
         * 
         * @return Player 
         */
        Player resetScore();

        /**
         * @brief Get the Score object
         * 
         * @return int 
         */
        int getScore();

        /**
         * @brief Adds one point to the player score
         * 
         * @return Player 
         */
        Player addScore();

        /**
         * @brief Get the Lives object
         * 
         * @return int 
         */
        int getLives();

        /**
         * @brief Subtracts one life from the player
         * 
         * @return Player 
         */
        Player loseLife();
};