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
    start_color();
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
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    //wattron(window, COLOR_PAIR(1));
    //mvwprintw(window, 1, 2, "▄▄");
    //wattron(window, COLOR_PAIR(1));
    //mvwprintw(window, 2, 2, "▀▀");
    keypad(window, TRUE ); // enable keyboard input for the window.
    int ch;
    while((ch = wgetch(window)) != 10){
        switch( ch ) {
            case KEY_UP:
                player.setAngle(UP);
                break;
            case KEY_DOWN:
                player.setAngle(DOWN);
                break;
            case KEY_LEFT:
                player.setAngle(LEFT);
                break;
            case KEY_RIGHT:
                player.setAngle(RIGHT);
                break;
        };
        
        player.tick();

        //mvwaddstr(window, 2, 2, "Hello World!");
        string str = to_string(c);
        //mvwaddstr(window, 0, 0, str.c_str());
        wrefresh(window);
        napms(100);
        c++;
    }
}