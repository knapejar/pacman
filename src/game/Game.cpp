#include "Game.hpp"

using namespace std;



Game::Game(){
    this->mapFileName = "";
}

Game::Game(string & fileName){
    this->mapFileName = fileName;
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
    mvwprintw(window, map.getHeight() + infoScreenSize - 1, 0, "%-9s %-11s", "Ghost", "State");
    for (size_t i = 0; i < entityManager.ghosts.size(); i++){
        //Print Ghost name in its color
        wattron(window, COLOR_PAIR(entityManager.ghosts[i]->color));
        mvwprintw(window, map.getHeight() + infoScreenSize + i, 0, "%-9s %-11s", entityManager.ghosts[i]->getName().c_str(), entityManager.ghosts[i]->getStateString().c_str());
    }
}

void Game::run(){
    if (this->mapFileName.size() == 0){
        this->map = Map();
    } else {
        try{
            this->map = Map(this->mapFileName);
        } catch (std::runtime_error const&e){ //Catches any error with the map file
            TextScreen textScreen = TextScreen(config.mapErrorMsg + "\n" + string(e.what()) + "\n \n");
            textScreen.show();
            return;
        }
    }
    entityManager.importMap(&this->map);

    initscr();

    start_color();
    //init_pair(2, 7, 8);
    init_pair(1, 7, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_BLUE, COLOR_BLACK);
    init_pair(7, 8, COLOR_BLACK); //12

    curs_set(0);

    int infoLines = this->infoScreenSize + entityManager.ghosts.size();
    int starty = (LINES - (map.getHeight() + infoLines)) / 2;
	int startx = (COLS - (2 * map.getWidth())) / 2;

    window = newwin((map.getHeight() + infoLines), (2 * map.getWidth()), starty, startx);
    noecho();

    entityManager.importWindow(window);
    renderScoreBoard();

    int ch; //Temporary character loaded from keyboard
    keypad(window, TRUE );
    
    renderMap(map, window);
    entityManager.render();
    wrefresh(window);

    this->gameState = GameState::PLAYING;
    while(this->gameState == GameState::PLAYING){
        while ((ch = readOneChar(window)) && ch != -1){
            if (ch == 'q'){
                this->gameState = GameState::PAUSED;
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
        if (this->gameState != GameState::PLAYING){
            break;
        }

        //Animation stage in the tick <- should be stored into renderer TODO
        entityManager.tick().hide().renderHalf();

        wrefresh(window);
        napms(tickLength);

        //Second stage in the tick
        entityManager.hide().render();
        renderScoreBoard();

        wrefresh(window);

        //Check if the player has won
        if (entityManager.player.getScore() >= map.getTotalScore()){
            this->gameState = GameState::WON;
            break;
        }

        //Check if the player has lost
        if (entityManager.gameEnded()){
            this->gameState = GameState::GAMEOVER;
        }

        napms(tickLength);
    }
    
    wtimeout(window, 1);
    string message = "";
    if (gameState == GameState::WON){
        message = "You WON!\n \n";
    } else if (gameState == GameState::GAMEOVER){
        message = "Game Over!\nTry harder :)\n \n";
    } else {
        message = "You gave up!\n \n";
    }
    
    TextScreen textScreen = TextScreen(message);
    textScreen.show();

	//Clean window
    wclear(window);
    wrefresh(window);
    delwin(window);
    endwin();
}

ScreenState Game::show(){
    this->run();
    return ScreenState::MENU;
}