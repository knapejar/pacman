#include <iostream>

using namespace std;

enum fieldType {
    NONE,
    WALL,
    POINT,
    PACMAN,
    GHOST
};

class Field {
    private:
        enum fieldType field;

    public:
        Field();    
        ~Field();
        Field getField();
        void setField(fieldType field);
        istream & load(istream & is);
        ostream & save(ostream & os);
        ostream & render(ostream & os);
        
};