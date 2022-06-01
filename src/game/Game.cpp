#include "Game.hpp"

Game::Game(){
    this->map = Map();
    player.importMaps(&map, &entityMap);
    player.setPosition(Position(8, 7));
}

Game::Game(string fileName){
    //this->map = Map();
    //Load from the filename
}

Game::~Game(){
    //To be implemented
}

void Game::renderAll(){
    player.render(window);
    for (auto ghost : ghosts){
        ghost.render(window);
    }
}

void Game::renderHalfAll(){
    player.renderHalf(window);
    for (auto ghost : ghosts){
        ghost.renderHalf(window);
    }
}

void Game::tickAll(){
    player.tick();
    for (auto ghost : ghosts){
        ghost.tick();
    }
}

void Game::hideAll(){
    player.hide(window);
    for (auto ghost : ghosts){
        ghost.hide(window);
    }
}

int readOneChar(WINDOW * window){
    int tmpch;
    int ch = -1;
    for (int i = 0; i < 1; i++){
        tmpch = wgetch(window);
        if (tmpch != -1){
            ch = tmpch;
        }
    }
    return ch;
}

void renderMap(Map & map, WINDOW * window){
    ostringstream ss;
    map.render(ss);
    mvwprintw(window, 0, 0, ss.str().c_str());
}

void Game::run(){
    initscr();
    start_color();
    curs_set(0);
    int starty = (LINES - map.getHeight()) / 2;
	int startx = (COLS - (2 * map.getWidth())) / 2;

    window = newwin(map.getHeight(), (2 * map.getWidth()), starty, startx);
    noecho();
    wtimeout(window, 0);

    int c = 0;
    int ch;    
    keypad(window, TRUE );

    init_pair(2, 7, 8);
    init_pair(1, 7, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    wattron(window, COLOR_PAIR(1));
    
    renderMap(map, window);
    wrefresh(window);

    bool running = true;

    while(running){
        while ((ch = readOneChar(window)) && ch != -1){
            if (ch == 'q'){
                running = false;
            } else if (ch == KEY_RESIZE){
                //Resize the window
                
                //wclear(window);
                //wrefresh(window);
                
                wclear(window);
                wrefresh(window);
                starty = (LINES - map.getHeight()) / 2;
                startx = (COLS - (2 * map.getWidth())) / 2;
                mvwin(window, starty, startx);
                wresize(window, map.getHeight(), (2 * map.getWidth()));
                renderMap(map, window);
                
            } else {
                player.keyboardInput(ch);
            }
        }
        if (not running){
            break;
        }

        //Animation stage in the tick <- should be stored into renderer TODO
        hideAll();
        tickAll();
        renderHalfAll();
        wrefresh(window);
        napms(tickLength);

        //Second stage in the tick
        hideAll();
        renderAll();

        //mvwaddstr(window, 2, 2, "Hello World!");
        string str = to_string(player.getScore()); //map.maxScore()
        mvwaddstr(window, 0, 0, str.c_str());
        wrefresh(window);
        napms(tickLength);
        c++;
    }
    cout << "EXIT\n";
    //Delete window
    wtimeout(window, 1);
    mvwaddstr(window, 0, map.getWidth() - 5, "Game Over!");
    wrefresh(window);
    delwin(window);
    endwin();
}