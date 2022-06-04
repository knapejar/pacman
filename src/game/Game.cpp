#include "Game.hpp"

using namespace std;

Game::Game(){
    this->map = Map();
    entityManager.importMap(&map);
}

Game::Game(string fileName){
    this->map = Map(fileName);
    entityManager.importMap(&map);
}

Game::~Game(){
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
    wattron(window, COLOR_PAIR(1));
    ostringstream ss;
    map.render(ss);
    mvwprintw(window, 0, 0, ss.str().c_str());
}

void Game::renderScoreBoard(){
    wattron(window, COLOR_PAIR(2));
    int percent = 100 * ((float)entityManager.player.getScore() / (float)map.getTotalScore());
    mvwprintw(window, map.getHeight(), 0, "Your score: %d / %d %d%c", entityManager.player.getScore(), map.getTotalScore(), percent, '%');
    mvwprintw(window, map.getHeight() + 1, 0, "Lives: %d, press q to quit", entityManager.player.getLives());
    wattron(window, COLOR_PAIR(1));
    mvwprintw(window, map.getHeight() + infoScreenSize - 1, 0, "%-9s %-9s", "Ghost", "State");
    for (size_t i = 0; i < entityManager.ghosts.size(); i++){
        //Print Ghost name in its color
        wattron(window, COLOR_PAIR(entityManager.ghosts[i]->color));
        mvwprintw(window, map.getHeight() + infoScreenSize + i, 0, "%-9s %-9s", entityManager.ghosts[i]->getName().c_str(), entityManager.ghosts[i]->getState().c_str());
    }
}

void Game::run(){
    initscr();

    start_color();
    //init_pair(2, 7, 8);
    init_pair(1, 7, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_BLUE, COLOR_BLACK);

    curs_set(0);

    int infoLines = this->infoScreenSize + entityManager.ghosts.size();
    int starty = (LINES - (map.getHeight() + infoLines)) / 2;
	int startx = (COLS - (2 * map.getWidth())) / 2;

    window = newwin((map.getHeight() + infoLines), (2 * map.getWidth()), starty, startx);
    noecho();

    entityManager.importWindow(window);
    renderScoreBoard();

    int c = 0;
    int ch;    
    keypad(window, TRUE );
    
    map.calculateScoreTarget();
    renderMap(map, window);
    entityManager.render();
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
                starty = (LINES - (map.getHeight() + infoLines)) / 2;
                startx = (COLS - (2 * map.getWidth())) / 2;
                mvwin(window, starty, startx);
                wresize(window, map.getHeight() + infoLines, (2 * map.getWidth()));
                renderMap(map, window);
                
            } else {
                entityManager.player.keyboardInput(ch);
            }
            wtimeout(window, 0);
        }
        if (not running){
            break;
        }

        //Animation stage in the tick <- should be stored into renderer TODO
        entityManager.tick().hide().renderHalf();
        
        if (entityManager.gameEnded()){
            running = false;
        }

        wrefresh(window);
        napms(tickLength);

        //Second stage in the tick
        entityManager.hide().render();


        //mvwaddstr(window, 2, 2, "Hello World!");
        //string str = to_string(entityManager.player.getScore()); //map.maxScore()
        //mvwaddstr(window, map.getHeight(), 0, "Score:   ");
        //mvwaddstr(window, map.getHeight(), 7, str.c_str());
        
        
        renderScoreBoard();
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