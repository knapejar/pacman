#include "TextScreen.hpp"

TextScreen::TextScreen() {
    this->content.resize(0);
    this->content.emplace_back("Call this constructor with a string");
}
TextScreen::TextScreen(string content) {
    if (content.length() <= 0) {
        this->content.resize(0);
        this->content.emplace_back("Call this constructor with a string");
    } else {
        this->content.resize(0);
        //Split the content into lines
        for (size_t i = 0; i < content.length(); i++) {
            if (content[i] == '\n') {
                this->content.push_back(content.substr(0, i));
                content = content.substr(i + 1);
                i = 0;
            }
        }
    }
}



ScreenState TextScreen::show() {
	int height = 4 + this->content.size();
	int width = 0;
    for (size_t i = 0; i < this->content.size(); i++) {
        if (static_cast<int>(this->content[i].length()) > width) {
            width = static_cast<int>(this->content[i].length());
        }
    }
    width += 4;
    if (width < 30) {
        width = 30;
    }
    if (width > COLS) {
        width = COLS;
    }
    int starty = (LINES - height) / 2;
	int startx = (COLS - width) / 2;
	this->newWindow(height, width, starty, startx);

    for (size_t i = 0; i < this->content.size(); i++) {
        //Print centered
        mvwprintw(this->window, i + 2, (width - this->content[i].length()) / 2, this->content[i].c_str());
    }

    mvwprintw(this->window, height - 2, (width - 26) / 2, "Press any key to continue");

    wrefresh(this->window); // update the terminal screen

    wgetch(this->window);

    destroyWindow();
    endwin();
    
    return ScreenState::MENU;
}