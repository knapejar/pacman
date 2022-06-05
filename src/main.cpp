#include "screen/Menu.hpp"
#include "screen/TextScreen.hpp"
#include "screen/SelectFileName.hpp"
#include "game/Game.hpp"
#include "selfTest.hpp"

#include "Config.hpp"
#include <locale.h>

using namespace std;

Config config;



/**
 * Main function
 * 
 * Current screen is set to Menu screen and waits for the user to choose a next screen state.
 * All screens are implemented in separate files.
 * Screen states can be edited in ScreenState.hpp
 * 
 * @return EXIT_SUCCESS
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
                SelectFileName selectFileName = SelectFileName(config.mapsFolder);
                selectFileName.show();
                try{
                    Game game = Game(selectFileName.getChosenFileName());
                    game.run();
                } catch (std::runtime_error const&e){
                    TextScreen textScreen = TextScreen(config.mapErrorMsg + "\n" + string(e.what()) + "\n \n");
                    current = textScreen.show();
                }
                current = ScreenState::MENU;
        } else if (current == ScreenState::HOWTO){
                TextScreen textScreen = TextScreen(config.about);
                current = textScreen.show();
        } else {
                current = ScreenState::EXIT;
        }
    }

	return EXIT_SUCCESS;
}