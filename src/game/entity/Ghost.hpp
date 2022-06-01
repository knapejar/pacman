#pragma once

#include "Entity.hpp"

class Ghost : public Entity{
    private:
        string name = "Ghost";
        string saveName = "G";
        string renderName = "GG";

        //Ghost only variables
        vector<Angle> path; 
    public:
        Ghost();
        Ghost(Position position, Angle angle);
        ~Ghost();
        
        virtual void calculatePath(){

        }

        void tick(){
            if (!this->isAlive){
                
            }
            if (path.empty()){
                calculatePath();
            }


        }

};