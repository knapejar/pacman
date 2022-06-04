#include "Position.hpp"

Position::Position(){

}
Position::Position(int x, int y){
    this->x = x;
    this->y = y;
}
Position::~Position(){

}
int Position::getX(){
    return this->x;
}
int Position::getY(){
    return this->y;
}
Position Position::setX(int x){
    this->x = x;
    return *this;
}
Position Position::setY(int y){
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
Position Position::move(Position position){
    this->x += position.getX();
    this->y += position.getY();
    return *this;
}
Position Position::move(Angle angle, int distance){
    switch(angle.getAngle()){
        case UP:
            this->y -= distance;
            break;
        case DOWN:
            this->y += distance;
            break;
        case LEFT:
            this->x -= distance;
            break;
        case RIGHT:
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
int Position::distance(Position position){
    return abs(this->x - position.getX()) + abs(this->y - position.getY());
}