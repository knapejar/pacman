#include "EntityManager.hpp"

using namespace std;

EntityManager::EntityManager(){
    //THIS HAS TO BE REPLACED WITH AUTOLOADING!!
    player.setPosition(Position(8, 11));

    ghosts.emplace_back(shared_ptr<Ghost>(new Blinky()));
    ghosts[0]->setPosition(Position(8, 7));
    //ghosts.emplace_back(shared_ptr<Ghost>(new Clyde()));
}

EntityManager::~EntityManager(){
}

EntityManager EntityManager::importMap(Map * map){
    this->map = map;
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
    player.tick();
    for (auto ghost : ghosts){
        ghost->tick(1);
    }
    return *this;
}