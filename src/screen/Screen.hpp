#pragma once
#include "ScreenState.hpp"
#include <string>

using namespace std;

class Screen{
    public:
        Screen();
        virtual ScreenState show() = 0;
};