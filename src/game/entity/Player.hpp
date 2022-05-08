#pragma once

#include "Entity.hpp"

class Player : public Entity{
    private:
        string name = "Player";
        string saveName = "P";
        string renderName = "XX";
    public:
        Player();
        Player(Position position, Angle angle);
        ~Player();
        Player keyboardInput(int input);
};