#include "Position.hpp"

Position::Position(){

}
Position::Position(int x, int y){
    this->x = x;
    this->y = y;
}
Position::~Position(){

}
int Position::getX() const{
    return this->x;
}
int Position::getY() const{
    return this->y;
}
Position Position::setX(int & x){
    this->x = x;
    return *this;
}
Position Position::setY(int & y){
    this->y = y;
    return *this;
}
Position Position::setXY(int x, int y){
    this->x = x;
    this->y = y;
    return *this;
}
Position Position::move(int x, int y){
    this->x += x;
    this->y += y;
    return *this;
}
Position Position::move(Position & position){
    this->x += position.getX();
    this->y += position.getY();
    return *this;
}
Position Position::move(Angle angle, int distance){
    switch(angle.getAngle()){
        case 0:
            this->y -= distance;
            break;
        case 2:
            this->y += distance;
            break;
        case 3:
            this->x -= distance;
            break;
        case 1:
            this->x += distance;
            break;
    }
    return *this;
}
Position Position::operator+(Position position){
    this->x += position.getX();
    this->y += position.getY();
    return *this;
}
Position Position::operator-(Position position){
    this->x -= position.getX();
    this->y -= position.getY();
    return *this;
}
bool Position::operator==(Position position){
    return this->x == position.getX() && this->y == position.getY();
}
bool Position::operator!=(Position position){
    return this->x != position.getX() || this->y != position.getY();
}
int Position::distance(Position position) const{
    return abs(this->x - position.getX()) + abs(this->y - position.getY());
}