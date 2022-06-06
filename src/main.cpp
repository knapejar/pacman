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
    srand (time(NULL));

    if (config.performSelfTest){
        SelfTest selfTest = SelfTest(config.selfTestVerbose);
        if (!selfTest.test()){
            cout << config.selfTestFailure << endl;
            return EXIT_FAILURE;
        }
    }

    Menu menu = Menu();
    ScreenState current = ScreenState::MENU;

    while (current != ScreenState::EXIT){ // Repeat the state machine until the user chooses to exit

        if (current == ScreenState::MENU){

            current = menu.show();

        } else if (current == ScreenState::GAME){ // Start the game

            Game game = Game();
            game.run();
            current = ScreenState::MENU;

        } else if (current == ScreenState::LOAD){ // Load the map and start the game

            try{
                SelectFileName selectFileName = SelectFileName(config.mapsFolder);
                selectFileName.show(); //Prompts the user to select a map
                Game game = Game(selectFileName.getChosenFileName());
                game.run();
            } catch (std::filesystem::filesystem_error const&e){ //Catches the error when the map folder is not found
                TextScreen textScreen = TextScreen(config.mapErrorMsg + config.folderErrorMsg);
                current = textScreen.show();
            } catch (std::runtime_error const&e){ //Catches any error with the map file
                TextScreen textScreen = TextScreen(config.mapErrorMsg + "\n" + string(e.what()) + "\n \n");
                current = textScreen.show();
            }
            current = ScreenState::MENU;

        } else if (current == ScreenState::HOWTO){ // Show the how to play screen

            TextScreen textScreen = TextScreen(config.about);
            current = textScreen.show();

        } else {

            current = ScreenState::EXIT; // Exit the game

        }
    }

    return EXIT_SUCCESS;
}