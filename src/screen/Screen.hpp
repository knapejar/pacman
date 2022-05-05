#pragma once
#include "ScreenState.hpp"
#include <string>

using namespace std;

class Screen{
    public:
        virtual ScreenState show() = 0;
};