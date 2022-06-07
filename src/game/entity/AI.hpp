#pragma once

#include <vector>
#include <string>
#include "../map/Map.hpp"
#include "Angle.hpp"
#include "Position.hpp"
#include "Entity.hpp"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <climits>

#include "../../screen/TextScreen.hpp"

class AI{
    public:
        std::vector<Angle>calculatePath(Map * map, Position start, Position end);
        Position randomPosition(Map * map);
};