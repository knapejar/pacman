#include "screen/Menu.hpp"
//#include "screen/SelectFileName.hpp"
#include "game/Game.hpp"


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
    ScreenState current = ScreenState::MENU;
    
    while (current != ScreenState::EXIT){
        switch (current){
            case ScreenState::MENU:
                //Menu().show();
                Menu().show();
                break;
            case ScreenState::GAME:
                //Game game();
                //game.run();
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