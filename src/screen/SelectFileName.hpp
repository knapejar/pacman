#pragma once

#include "Screen.hpp"
#include <ncurses.h>
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>



/**
 * @brief This class is the map files selector
 * 
 * @details This class locates all candidates for the map files and makes them available for the user to select
 */

class SelectFileName : public Screen{
    private:
        std::string path;
        std::string chosenFileName;
        std::vector<std::string> content;
    public:
        SelectFileName();
        SelectFileName(std::string path);

        /**
         * @brief Loads the content of the directory
         */
        void load();

        /**
         * @brief Prompts the user to select a file
         * 
         * @return ScreenState 
         */
        ScreenState show();

        /**
         * @brief Get the Chosen File Name object - the selected file name
         * 
         * @return std::string 
         */
        std::string getChosenFileName();
};