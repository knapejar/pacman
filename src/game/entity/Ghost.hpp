#pragma once

#include "Entity.hpp"
#include "AI.hpp"



/**
 * @brief Enum containing all possible ghost behaviour states
 */

enum GhostState{
    CAGED,
    RANDOM,
    CHASE,
    CHASE_TRYHARD,
    SCATTER,
    FRIGHTENED,
    DEAD
};



/**
 * @brief This class is the base for all ghost entities
 * 
 * @details This class is being implemented by the EntityManager class and is responsible for the ghost rendering
 */

class Ghost : public Entity{
    protected:
        int state = 0;
        Position nextPosition;
        std::vector<Angle> path; 
        AI ai;

    public:
        Ghost();
        Ghost(Position position, Angle angle);
        ~Ghost();

        /**
         * @brief Virtual method to be implemented by the child classes used to find the path to the desired position
         */
        virtual void calculatePath() = 0;

        /**
         * @brief Virtual method to be implemented by the child classes that is responsible for the ghost behaviour
         */
        virtual void tick(int tick, Position playerPosition) = 0;

        /**
         * @brief Get the State object
         * 
         * @return std::string 
         */
        std::string getState();

        /**
         * @brief Frightens the ghost and sets its state to FRIGHTENED
         */
        void frighten();

        /**
         * @brief Returns the ghost state to the RANDOM state
         */
        void normal();

        /**
         * @brief Respawns the ghost at it's initial position
         */
        void respawn();
};