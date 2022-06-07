#include "SelectFileName.hpp"

using namespace std;
namespace fs = std::filesystem;

void SelectFileName::load(){
    this->content.clear();
    this->content.emplace_back(config.defaultMapPlaceholder);
    //Check if the folder exists
    if (!fs::exists(config.mapsFolder)){
        //Create the folder
        fs::create_directory(config.mapsFolder);
    }

    try{
        for (const auto & entry : fs::directory_iterator(this->path)) {
            content.emplace_back(entry.path());
        }
    } catch (std::filesystem::filesystem_error const &e){ //Catches the error when the map folder is not found
        TextScreen textScreen = TextScreen(config.mapErrorMsg + config.folderErrorMsg);
        textScreen.show();
        exit(1);
    }
}

SelectFileName::SelectFileName() {
    this->load();
}
SelectFileName::SelectFileName(string path) {
    this->path = path;
    this->load();
}



ScreenState SelectFileName::show() { 
    if (this->content.size() == 0) {
        this->chosenFileName = "";
        return ScreenState::MENU;
    }

	int height = 6 + this->content.size();
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

    mvwprintw(this->window, 2, (width - 15) / 2, "Select the map:");

    int ch = 0;
    int sel = 0;
    
    noecho();
    keypad(this->window, TRUE);
    curs_set(0);

    // Make the items appear with even width
    for (int i = 0; i < static_cast<int>(this->content.size()); i++) {
        if (i == sel){
            wattron(this->window, A_REVERSE);
        }
        mvwprintw(this->window, i + 4, (width - this->content[i].length()) / 2, this->content[i].c_str());
        wattroff(this->window, A_REVERSE);
    }
    wrefresh(this->window);

    while((ch = wgetch(this->window)) != 10){ 
        // Move the cursor to the next item in the list
        switch(ch){
            case (KEY_UP):
                sel--;
                sel = (sel < 0) ? (static_cast<int>(this->content.size() - 1)) : sel;
                break;
            case (KEY_DOWN):
                sel++;
                sel = (sel > static_cast<int>(this->content.size()) - 1) ? 0 : sel;
                break;
        }

        for (int i = 0; i < static_cast<int>(this->content.size()); i++) {
            if (i == sel){
                wattron(this->window, A_REVERSE);
            }
            mvwprintw(this->window, i + 4, (width - this->content[i].length()) / 2, this->content[i].c_str());
            wattroff(this->window, A_REVERSE);
        }
    }

    destroyWindow();
    endwin();

    this->chosenFileName = this->content[sel];

    //Copy the chosen map as the default
    ifstream  src(this->chosenFileName, std::ios::binary);
    ofstream  dst(config.defaultMapFileName, std::ios::binary);
    dst << src.rdbuf();
    
    return ScreenState::GAME;
}