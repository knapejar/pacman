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
         * @brief Virtual method to be implemented by the child classes that is responsible for the ghost behaviour
         */
        virtual void tick(const int & tick, const Position & playerPosition) = 0;

        /**
         * @brief Get the ghost state
         * 
         * @return std::string 
         */
        std::string getStateString();

        /**
         * @brief Get the ghost state
         * 
         * @return std::string 
         */

        GhostState getState();

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

        /**
         * @brief The similar behaviour for the ghosts to avoid the player when ghosts can be eaten
         * 
         * @param tick 
         * @param playerPosition 
         */
        void frightenedBehaviour(int tick, Position playerPosition);
};