#include "screen/Menu.hpp"
#include "game/Game.hpp"
//#include "screen/SelectFileName.hpp"
#include "selfTest.hpp"

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

    SelfTest selfTest;
    selfTest.test();

    Menu menu = Menu();

    ScreenState current = ScreenState::MENU;
    
    while (current != ScreenState::EXIT){
        if (current == ScreenState::MENU){
                current = menu.show();
        } else if (current == ScreenState::GAME){
                Game game = Game();
                game.run();
                current = ScreenState::MENU;
        } else if (current == ScreenState::LOAD){
                Game game = Game("examples/medium.pacman");
                game.run();
                current = ScreenState::MENU;
        } else {
                current = ScreenState::EXIT;
        }
    }

	return 0;
}