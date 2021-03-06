#pragma once

/**
 * @brief Brief self-explanatory class used to store angle values
 *
 * @details 0 = UP, 1 = RIGHT, 2 = DOWN, 3 = LEFT
 */

class Angle{
    private:
        int angle;
    public:
        Angle();
        Angle(int angle);
        ~Angle();
        int getAngle() const;
        Angle setAngle(int & angle);
        Angle setAngle(Angle & angle);
        Angle rotate(int & angle);
        Angle rotate(Angle & angle);
        Angle operator+(Angle angle);
        Angle operator-(Angle angle);
        Angle operator+=(Angle angle);
        Angle operator-=(Angle angle);
};