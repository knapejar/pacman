#include "Menu.hpp"

Menu::Menu() {
    //To be implemented
}


WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

ScreenState Menu::show() {
    WINDOW *w;
    char list[4][7] = { "Play", "Load", "About", "Exit" };
    char item[9];
    int ch, i = 0;
    initscr(); // initialize Ncurses
	int height = 10;
	int width = 12;
    int starty = (LINES - height) / 2;	/* Calculating for a center placement */
	int startx = (COLS - width) / 2;	/* of the window		*/
	w = create_newwin(height, width, starty, startx);
    // now print all the menu items and highlight the first one
    for( i=0; i<4; i++ ){
        if( i == 0 ) 
            wattron( w, A_STANDOUT ); // highlights the first item.
        else
            wattroff( w, A_STANDOUT );
        sprintf(item, "%-7s",  list[i]);
        mvwprintw( w, i+1, 2, "%s", item );
    }
    wrefresh( w ); // update the terminal screen
    i = 0;
    noecho(); // disable echoing of characters on the screen
    keypad( w, TRUE ); // enable keyboard input for the window.
    curs_set( 0 ); // hide the default screen cursor.
    // get the input
    while((ch = wgetch(w)) != 10){ 
        // right pad with spaces to make the items appear with even width.
        sprintf(item, "%-7s",  list[i]); 
        mvwprintw( w, i+1, 2, "%s", item ); 
        // use a variable to increment or decrement the value based on the input.
        switch( ch ) {
            case KEY_UP:
                i--;
                i = ( i<0 ) ? 3 : i;
                break;
            case KEY_DOWN:
                i++;
                i = ( i>3 ) ? 0 : i;
                break;
            }
        // now highlight the next item in the list.
        wattron( w, A_STANDOUT );
        sprintf(item, "%-7s",  list[i]);
        mvwprintw( w, i+1, 2, "%s", item);
        wattroff( w, A_STANDOUT );
    }
    delwin(w);
    endwin();

    switch(i){
        case 0:
            return ScreenState::GAME;
        case 1:
            return ScreenState::LOAD;
        case 2:
            return ScreenState::MENU;
        case 3:
            return ScreenState::EXIT;
        default:
            return ScreenState::EXIT;
    }
    return ScreenState::EXIT;
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);
	wrefresh(local_win);

	return local_win;
}

void destroy_win(WINDOW *local_win)
{	
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}