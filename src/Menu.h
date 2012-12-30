#ifndef MENU_H
#define MENU_H
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"

#include "GlobalUtils.h"

class Menu{
        private:
                bool still_in_menu;
                int choice;

	public:
            	Menu();
                ~Menu();
                int main_menu();
                int pause_menu();

};

#endif /* MENU_H */
