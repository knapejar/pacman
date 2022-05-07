#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

class Angle{
    private:
        int angle;
    public:
        Angle();
        Angle(int angle);
        ~Angle();
        int getAngle();
        Angle setAngle(int angle);
        Angle setAngle(Angle angle);
        Angle rotate(int angle);
        Angle rotate(Angle angle);
};