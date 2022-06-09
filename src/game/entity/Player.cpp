#include "Player.hpp"

using namespace std;



Player::Player():Entity(){
    this->name = "Player";
    this->saveName = "P";
    this->renderName = "<>";
    this->color = 2; //YELLOW
    this->angle = Angle(2);
    this->targetAngle = Angle(2);
    this->score = 0;
    this->lives = 3;
}
Player::Player(Position position, Angle angle):Entity(position, angle){
    this->name = "Player";
    this->saveName = "P";
    this->renderName = "<>";
    this->color = 2; //YELLOW
    this->angle = Angle(2);
    targetAngle = angle;
    this->score = 0;
    this->lives = 3;
}
Player::~Player(){
    
}

Player Player::keyboardInput(int & input){
    switch(input){
        case KEY_UP:
            setAngle(0);
            break;
        case KEY_DOWN:
            setAngle(2);
            break;
        case KEY_LEFT:
            setAngle(3);
            break;
        case KEY_RIGHT:
            setAngle(1);
            break;
        case 'w':
            setAngle(0);
            break;
        case 's':
            setAngle(2);
            break;
        case 'a':
            setAngle(3);
            break;
        case 'd':
            setAngle(1);
            break;
        default:
            break;
    };
    return *this;
}

Player Player::tick(){ //Overrided function to move the player
    if (*(this->ghostsEatable) <= 0){
        this->color = 2;
    } else {
        *(this->ghostsEatable) -= 1;
    }
    this->lastPosition = this->position;
    Position nextPosition = this->position;
    nextPosition.move(this->angle, 1);
    teleportCheck(nextPosition);
    if (!map->wall(nextPosition)){
        this->position = nextPosition;
    }
    if (map->collect(this->position)){
        this->score += 1;
    }
    if (map->pickUpBonus(this->position)){
        this->lives += 1;
    }
    if (map->pickUpCherry(this->position)){
        this->color = 7;
        if (this->ghostsEatable != nullptr){
            *(this->ghostsEatable) = config.ghostsEatableDuration;
        }
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
int Player::getLives(){
    return this->lives;
}
Player Player::loseLife(){
    this->lives--;

    //Enable the imunity for a certain amount of time
    this->color = 7;
    if (this->ghostsEatable != nullptr){
        *(this->ghostsEatable) = config.respawnImunityDuration;
    }

    return *this;
}
Player Player::resetLives(){
    this->lives = config.playerHealth;
    return *this;
}

void Player::importGhostsEatable(int * ghostsEatable){
    this->ghostsEatable = ghostsEatable;
}