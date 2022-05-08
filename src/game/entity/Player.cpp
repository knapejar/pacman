#include "Player.hpp"

Player::Player():Entity(){
    this->name = "Player";
    this->saveName = "P";
    this->renderName = "<>";
    this->color = COLOR_YELLOW;
}
Player::Player(Position position, Angle angle):Entity(position, angle){
    targetAngle = angle;
}
Player::~Player(){
    
}

Player Player::keyboardInput(int input){
    switch(input){
        case KEY_UP:
            setAngle(UP);
            break;
        case KEY_DOWN:
            setAngle(DOWN);
            break;
        case KEY_LEFT:
            setAngle(LEFT);
            break;
        case KEY_RIGHT:
            setAngle(RIGHT);
            break;
    };
    return *this;
}

Player Player::tick(){ //Overrided function to move the player
    this->lastPosition = this->position;
    Position nextPosition = this->position;
    nextPosition.move(this->angle, 1);
    if (!map->wall(nextPosition)){
        this->position = nextPosition;
    }
    if (map->collect(this->position)){
        this->score += 1;
    }
    return *this;
}

Player Player::resetScore(){
    this->score = 0;
    return *this;
}
int Player::getScore(){
    return this->score;
}
Player Player::addScore(){
    this->score++;
    return *this;
}