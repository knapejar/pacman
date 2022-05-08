#include "Game.hpp"

Game::Game(){
    this->map = Map();
    player.importMap(&map);
    player.setPosition(Position(8, 7));
}

Game::Game(string fileName){
    //this->map = Map();
    //Load from the filename
}

Game::~Game(){
    //To be implemented
}

int readOneChar(WINDOW * window){
    int tmpch;
    int ch = -1;
    for (int i = 0; i < 10; i++){ //Flush the buffer
        tmpch = wgetch(window);
        if (tmpch != -1){
            ch = tmpch;
        }
    }
    return ch;
}

void Game::run(){
    initscr();
    start_color();
    curs_set(0);
    WINDOW *window;
    int starty = (LINES - map.getHeight()) / 2;
	int startx = (COLS - (2 * map.getWidth())) / 2;

    window = newwin(map.getHeight(), (2 * map.getWidth()), starty, startx);
    //cbreak();
    noecho();
    wtimeout(window, 0);

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

    while((ch = readOneChar(window)) != 27){
        
        player.keyboardInput(ch);
        player.hide(window);
        player.tick();
        player.hide(window);
        player.renderHalf(window);
        wrefresh(window);
        napms(tickLength);

        ch = readOneChar(window);
        player.keyboardInput(ch);

        player.hide(window);
        player.render(window);

        //mvwaddstr(window, 2, 2, "Hello World!");
        string str = to_string(ch);
        mvwaddstr(window, 0, 0, str.c_str());
        wrefresh(window);
        napms(tickLength);
        c++;
    }
}