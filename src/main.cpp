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
    srand(time(NULL));

    if (config.performSelfTest){
        SelfTest(config.selfTestVerbose).test();
    }

    vector<shared_ptr<Screen>> screens;
    screens.emplace_back(make_shared<Menu>());
    screens.emplace_back(make_shared<Game>(config.defaultMapFileName));
    screens.emplace_back(make_shared<SelectFileName>(config.mapsFolder));
    screens.emplace_back(make_shared<TextScreen>(config.about));
    ScreenState current = ScreenState::MENU;

    while (current != ScreenState::EXIT)
        current = screens[current]->show();

    return EXIT_SUCCESS;
}