#include "Player.hpp"

Player::Player():Entity(){
    this->name = "Player";
    this->saveName = "P";
    this->renderName = "<>";
    this->color = COLOR_YELLOW;
}
Player::Player(Position position, Angle angle):Entity(position, angle){

}
Player::~Player(){

}

Player Player::keyboardInput(int input){
    switch(input) {
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