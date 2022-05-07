#include "Game.hpp"

Game::Game(){
    //this->map = Map();
    //To be implemented
}

Game::Game(string fileName){
    //this->map = Map();
    //Load from the filename
}

Game::~Game(){
    //To be implemented
}

void Game::run(){
    initscr();
    curs_set(0);
    WINDOW *window;
    int starty = (LINES - map.getHeight()) / 2;
	int startx = (COLS - (2 * map.getWidth())) / 2;

    window = newwin(map.getHeight(), (2 * map.getWidth()), starty, startx);
    
    wrefresh(window);

    int c = 0;

    ostringstream ss;
    map.render(ss);
    mvwprintw(window, 0, 0, ss.str().c_str());

    while(true){
        mvwaddstr(window, 2, 2, "Hello World!");
        string str = to_string(c);
        mvwaddstr(window, 0, 0, str.c_str());
        wrefresh(window);
        napms(100);
        c++;
    }
}