#include "Menu.hpp"

Menu::Menu() {
    //To be implemented
}

/**
 * @brief Method to create a new menu window
 * 
 * @return ScreenState - the next screen state
 */

ScreenState Menu::show() {
    char list[4][6] = { "Play", "Load", "HowTo", "Exit" };
    char item[9]; //Currently printed item
    int ch, i = 0; //Temporary char from keyboard, i - current item
    initscr();
	int height = 12;
	int width = 15;
    int starty = (LINES - height) / 2;
	int startx = (COLS - width) / 2;
	this->newWindow(height, width, starty, startx);
        
    mvwprintw(this->window, 2, 4, "PACMAN");
    mvwprintw(this->window, 3, 2, "──────────");
    mvwprintw(this->window, 9, 1, "(c) KNAPEJAR");
    mvwprintw(this->window, 10, 1, "CVUT FIT 2022");

    // Print all the menu items and highlight the first one
    for(i = 0; i < 4; i++){
        if(i == 0) 
            wattron(this->window, A_STANDOUT);
        else
            wattroff(this->window, A_STANDOUT);
        sprintf(item, "%-7s", list[i]);
        mvwprintw(this->window, i+4, 2, "%s", item);
    }
    wrefresh(this->window);
    i = 0;
    noecho();
    keypad(this->window, TRUE);
    curs_set(0);
    
    while((ch = wgetch(this->window)) != 10){ 
        // Make the items appear with even width
        sprintf(item, "%-7s",  list[i]); 
        mvwprintw(this->window, i+4, 2, "%s", item); 
        // Move the cursor to the next item in the list
        switch(ch){
            case KEY_UP:
                i--;
                i = (i < 0) ? 3 : i;
                break;
            case KEY_DOWN:
                i++;
                i = (i > 3) ? 0 : i;
                break;
            }
        // Highlit the chosen item
        wattron(this->window, A_STANDOUT);
        sprintf(item, "%-7s", list[i]);
        mvwprintw(this->window, i+4, 2, "%s", item);
        wattroff(this->window, A_STANDOUT );
    }
    destroyWindow();
    endwin();

    switch(i){
        case 0:
            return ScreenState::GAME;
        case 1:
            return ScreenState::LOAD;
        case 2:
            return ScreenState::HOWTO;
        case 3:
            return ScreenState::EXIT;
        default:
            return ScreenState::EXIT;
    }
    return ScreenState::EXIT;
}