#include "EntityManager.hpp"

using namespace std;



EntityManager::EntityManager(){
    this->totalTicks = 0;
    this->ghostsReleased = 0;
}

EntityManager EntityManager::importMap(Map * map){
    this->totalTicks = 0;
    this->ghostsReleased = 0;
    this->map = map;
    this->ghosts.clear();

    for (int y = 0; y < map->getHeight(); y++){
        for (int x = 0; x < map->getWidth(); x++){
            if (map->getField(Position(x, y)).toChar() == 'P'){
                player.setPosition(Position(x, y));
            } else if (map->getField(Position(x, y)).toChar() == 'B'){
                ghosts.emplace_back(shared_ptr<Ghost>(new Blinky()));
                ghosts[ghosts.size() - 1]->setPosition(Position(x, y));
            } else if (map->getField(Position(x, y)).toChar() == 'C'){
                ghosts.emplace_back(shared_ptr<Ghost>(new Clyde()));
                ghosts[ghosts.size() - 1]->setPosition(Position(x, y));
            } else if (map->getField(Position(x, y)).toChar() == 'I'){
                ghosts.emplace_back(shared_ptr<Ghost>(new Inky()));
                ghosts[ghosts.size() - 1]->setPosition(Position(x, y));
            } else if (map->getField(Position(x, y)).toChar() == 'G'){
                ghosts.emplace_back(shared_ptr<Ghost>(new Pinky()));
                ghosts[ghosts.size() - 1]->setPosition(Position(x, y));
            }
        }
    }

    player.resetScore();
    player.importMap(map);
    for (auto ghost : ghosts){
        ghost->importMap(map);
    }    

    return *this;
}

EntityManager EntityManager::importWindow(WINDOW * window){
    this->window = window;
    return *this;
}

EntityManager EntityManager::render(){
    player.render(window);
    for (auto ghost : ghosts){
        ghost->render(window);
    }
    return *this;
}

EntityManager EntityManager::renderHalf(){
    player.renderHalf(window);
    for (auto ghost : ghosts){
        ghost->renderHalf(window);
    }
    return *this;
}

EntityManager EntityManager::hide(){
    player.hide(window);
    for (auto ghost : ghosts){
        ghost->hide(window);
    }
    return *this;
}

EntityManager EntityManager::tick(){
    totalTicks++;
    //Mechanics for releasing the ghosts
    if (totalTicks % map->getGhostReleaseTimeout() == 1){
        if (ghostsReleased < ghosts.size()){
            ghosts[ghostsReleased]->respawn();
            ghostsReleased++;
        }
    }

    player.tick();
    for (auto ghost : ghosts){
        ghost->tick(1);
    }
    return *this;
}

bool EntityManager::gameEnded(){
    int minimalDistance = INT_MAX;
    Position nextPosition = player.getPosition();
    nextPosition.move(player.getAngle(), 1);
    for (auto ghost : ghosts){
        int distance = player.getPosition().distance(ghost->getPosition());
        if (distance < minimalDistance){
            minimalDistance = distance;
        }
        if (nextPosition == ghost->getPosition() && (ghost->getAngle() + Angle(2)).getAngle() == player.getAngle().getAngle()){
            minimalDistance = 0;
            break;
        }
    }

    /*
    //Sežrání ducha
    if (minimalDistance < 1){
        for (auto ghost : ghosts){
            ghost->respawn();
        }
    }
    return false;*/
    
    if (minimalDistance < 1){
        if (player.getLives() > 1){
            player.loseLife();
            player.hide(window);
            player.respawn();
        } else {
            return true;
        }
    }
    return false;
}