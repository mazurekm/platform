

#ifndef GLOBALUTILS_H
#define	GLOBALUTILS_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Timer.h"
#include <vector>
#include <string>

using namespace std;

class GlobalUtils{
public:
    static const int SCREEN_WIDTH = 800;                //szerokość ekranu
    static const int SCREEN_HEIGHT = 600;               //wysokość ekranu
    static const int SCREEN_BPP = 32;                   //ilość kolorów (np 32-bitowy)
    
    static SDL_Event event;                             //przechwycone evnty
    static SDL_Surface *screen;                         //surface wyświetlany na ekranie
    
    
    static int level_width;                             //szerokość mapy
    static int level_height;                            //wysokość mapy
    
    static int char_start_pos_x;                        //początkowa pozycja x naszej postaci
    static int char_start_pos_y;                        //początkowa pozycja y naszej postaci
    
    static SDL_Rect camera;                             //wyświetlany wycinek mapy tzw. "kamera"
    
    static void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);    //sklejanie obrazków do jednego surface'a Parametry: x, y na których ma być doklejony source do destination, wycinek ze sprite'a
    static SDL_Surface* load_image(string);                                                                     //ładowanie obrazków do pamięci Parametr: ścieżka do obrazka, zwraca wskaźnik na surface'a
    static void pause(int msec);                                                                                //pauza Parametr: ilość milisekund
};


#endif	/* GLOBALUTILS_H */

