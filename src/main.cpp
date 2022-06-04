#include "screen/Menu.hpp"
//#include "screen/SelectFileName.hpp"
#include "game/Game.hpp"

#include <locale.h>

using namespace std;
                                     


/**
 * Main function
 * 
 * Current screen is set to Menu screen and waits for the user to choose a next screen state.
 * All screens are implemented in separate files.
 * Screen states can be edited in ScreenState.hpp
 * 
 * @return 0
 * */

int main(){
    setlocale(LC_ALL, "");

    Menu menu = Menu();
    Game game = Game("examples/small.pacman");

    //Temporary turn on the game wight after the start
    
    game.run();

    ScreenState current = ScreenState::MENU;
    
    while (current != ScreenState::EXIT){
        printf("Hello, World!\n");
        switch (current){
            case ScreenState::MENU:
                current = menu.show();
                break;
            case ScreenState::GAME:
                game = Game();
                game.run();
                break;
            case ScreenState::LOAD:
                //Game game(SelectFileName::show("Load game"));
                //game.run();
                break;
            case ScreenState::EXIT:
                break;
        }
    }

	return 0;
}