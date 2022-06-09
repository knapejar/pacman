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
string Ghost::getStateString(){
    switch (this->state){
        case CAGED:
            return "Caged";
        case CHASE:
            return "Chase";
        case SCATTER:
            return "Scatter";
        case FRIGHTENED:
            return "Frightened";
        case RANDOM:
            return "Random";
        default:
            return "Hunting";
    }
}
GhostState Ghost::getState(){
    return (GhostState)this->state;
}
void Ghost::frighten(){
    this->path.clear();
    this->state = FRIGHTENED;
}
void Ghost::normal(){
    this->state = RANDOM;
}
void Ghost::respawn(){
    this->position = this->spawnPosition;
    this->angle = Angle(0);
    this->state = GhostState(RANDOM);
}
void Ghost::frightenedBehaviour(int tick, Position playerPosition){
    this->lastPosition = this->position;
    Position nextPosition = this->position;

    if (this->position.distance(playerPosition) < 3){
        this->path.clear();
    }

    int maxAttempts = 1000;
    while (this->path.size() <= 0){
        this->path = this->ai.calculatePath(this->map, this->position, ai.awayFromPlayer(map, playerPosition));
        reverse(this->path.begin(), this->path.end());
        maxAttempts--;
        if (maxAttempts <= 0){
            return;
        }
        Position tempPosition = this->position;
        for (auto &p : this->path){
            tempPosition.move(p, 1);
            teleportCheck(tempPosition);
            if (tempPosition.distance(playerPosition) < 2){
                this->path.clear();
                break;
            }
        }
    }
    nextPosition.move(this->path.at(path.size() - 1), 1);
    this->path.pop_back();

    this->position = nextPosition;
    teleportCheck();
}