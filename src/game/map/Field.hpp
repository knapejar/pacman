
using namespace std;

enum fields {
    NONE,
    WALL,
    POINT,
    PACMAN,
    GHOST
};

class Field {
    private:
        fields field;

    public:
        Field();    
        ~Field();
        Field getField();
        void setField(fields field);
        
};