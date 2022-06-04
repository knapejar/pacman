#include "Angle.hpp"

Angle::Angle(){

}
Angle::Angle(int angle){
    this->angle = angle;
}
Angle::~Angle(){

}
int Angle::getAngle(){
    return angle;
}
Angle Angle::setAngle(int angle){
    this->angle = angle;
    return *this;
}
Angle Angle::setAngle(Angle angle){
    this->angle = angle.getAngle();
    return *this;
}
Angle Angle::rotate(int angle){
    this->angle = (this->angle + angle) % 4;
    return *this;
}
Angle Angle::operator+(Angle angle){
    return Angle((this->angle + angle.getAngle())%4);
}
Angle Angle::operator-(Angle angle){
    return Angle((this->angle - angle.getAngle())%4);
}
Angle Angle::operator+=(Angle angle){
    this->angle = (this->angle + angle.getAngle()) % 4;
    return *this;
}
Angle Angle::operator-=(Angle angle){
    this->angle = (this->angle - angle.getAngle()) % 4;
    return *this;
}