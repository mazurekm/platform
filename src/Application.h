

#ifndef APPLICATION_H
#define	APPLICATION_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <sstream>
#include "Character.h"
#include "Enemy.h"
#include "Timer.h"
#include "GlobalUtils.h"
#include "Map.h"
#include "Menu.h"
#include <iostream>

using namespace std;

class Application {
     private:    
       static const int FPS = 60;                                       //max ilość fps-ów  
       
       TTF_Font *font,
                *font1;                                                 //czcionki do wyświetlania tekstu w czasie gry
       SDL_Color color;                                                 //kolor tekstu wyświetlanego w trakcie gry
       
       Timer timer;                                                     //timer używany do ograniczenia fps-ów
       
       bool game_in_progress;                                           //true - gra się  toczy, false - wychodzi z pętli gry
       
       void dynamic_collisions(Character *c, Enemy *e,Player *);        //kolizje pomiędzy postacią i wrogami
                                                                        //parametry: wskaźniki na obiekt naszej postaci, obiekt wrogz z którym badamy kolizję, obiekt Player któremu dodajemy punkty lub odejmujemy życia
                                                                       
     public:
       SDL_Surface *text,                                               //surface wyświetlający teksty w trakcie gry
                   *end_game;                                           //surface wyświetlający "Game Over"
       
       Application();
       ~Application(); 
       
       int run_game(string,Player *);                                   //pętla główna gry; Parametry: string z nazwą pliku mapy, wskaźnik na obiekt Player  
                                                                        //zwraca wartości odpowiadające stanom: koniec poziomu i koniec gry
       bool init();                                                     //inicjacja wszystkiego co potrzebne
};

#endif	/* APPLICATION_H */

