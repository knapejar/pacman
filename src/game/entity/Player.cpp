#include "Player.hpp"

Player::Player():Entity(){
    this->name = "Player";
    this->saveName = "P";
    this->renderName = "<>";
    this->color = 2; //YELLOW
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
        case 'w':
            setAngle(UP);
            break;
        case 's':
            setAngle(DOWN);
            break;
        case 'a':
            setAngle(LEFT);
            break;
        case 'd':
            setAngle(RIGHT);
            break;
        default:
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
    if (this->position.getX() < 0){
        this->position = Position(map->getWidth() - 1, this->position.getY());
    }
    if (this->position.getX() > map->getWidth() - 1){
        this->position = Position(0, this->position.getY());
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