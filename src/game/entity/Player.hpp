#pragma once

#include "Entity.hpp"

class Player : public Entity{
    private:
        std::string name = "Player";
        std::string saveName = "P";
        std::string renderName = "XX";
        Angle targetAngle;
        int score = 0;
        int lives = 3;
    public:
        Player();
        Player(Position position, Angle angle);
        ~Player();
        Player keyboardInput(int input);
        Player tick();
        Player resetScore();
        int getScore();
        Player addScore();
        int getLives();
        Player loseLife();
};