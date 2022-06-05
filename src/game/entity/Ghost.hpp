#pragma once

#include "Entity.hpp"

enum GhostState{
    CAGED,
    RANDOM,
    CHASE,
    CHASE_TRYHARD,
    SCATTER,
    FRIGHTENED,
    DEAD
};

class Ghost : public Entity{
    protected:
        int state = 0;
        Position nextPosition;
        std::vector<Angle> path; 
    public:
        Ghost();
        Ghost(Position position, Angle angle);
        ~Ghost();
        virtual void calculatePath() = 0;
        virtual void tick(int tick) = 0;
        std::string getState();
        void frighten();
        void normal();
        void respawn();
};