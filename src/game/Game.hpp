#pragma once

#include "map/Map.hpp"
#include "entity/EntityManager.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Game{
    private:
        Map map;
    public:
        Game();
        Game(string fileName);
        ~Game();
        void run();

    
};