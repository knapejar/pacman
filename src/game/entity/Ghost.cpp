#include "Ghost.hpp"

using namespace std;



Ghost::Ghost(): Entity(){
    this->nextPosition = Position(0, 0);
    this->state = CAGED;
    this->name = "Ghost";
}
Ghost::Ghost(Position position, Angle angle):Entity(position, angle){
    this->nextPosition = Position(0, 0);
    this->spawnPosition = this->position;
    this->nextPosition = this->position;
    this->state = CAGED;
    this->name = "Ghost";
}
Ghost::~Ghost(){

}
string Ghost::getState(){
    switch (this->state){
        case CAGED:
            return "Caged";
        case RANDOM:
            return "Random";
        case CHASE:
            return "Chase";
        case CHASE_TRYHARD:
            return "ChaseTryHard";
        case SCATTER:
            return "Scatter";
        case FRIGHTENED:
            return "Frightened";
        case DEAD:
            return "Dead";
        default:
            return "Unknown";
    }
}
void Ghost::frighten(){
    this->state = FRIGHTENED;
}
void Ghost::normal(){
    this->state = RANDOM;
}
void Ghost::respawn(){
    this->position = this->spawnPosition;
    this->angle = Angle(2);
    this->state = GhostState(RANDOM);
}