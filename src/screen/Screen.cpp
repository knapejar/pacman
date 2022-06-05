#include "Screen.hpp"

Screen::Screen(){

}

void Screen::newWindow(int height, int width, int starty, int startx){
	this->window = newwin(height, width, starty, startx);
	box(this->window, 0 , 0);
	wrefresh(this->window);
}

void Screen::destroyWindow(){
	wclear(this->window);
	wrefresh(this->window);
	delwin(this->window);
}