#pragma once

#include "Player.hpp"
#include "Ghost.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <utility>

class EntityManager{
    private:
        Player player;
        vector<Ghost> ghosts;
    public:
        EntityManager();
        ~EntityManager();
        void tick();
        void render();
};