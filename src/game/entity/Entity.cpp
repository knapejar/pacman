#include "Entity.hpp"

Entity::Entity(){

}

Entity::~Entity(){

}

pair<int,int> Entity::getPos(){
    return (make_pair(x, y));
}

