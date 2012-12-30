

#ifndef MAP_H
#define	MAP_H

#include "Character.h"
#include "Enemy.h"
#include "StaticObject.h"
#include "GlobalUtils.h"
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

extern Character *character;                            //wskaźnik na naszą postać
extern Player *player;                                  //wskaźnik na obiekt player

class Map {  
    public:  
        vector<string> map_elements;                    //vector wszystkich elementów mapy
        vector<Enemy*> en_tab;                          //vector wszystkich Enemy  
        string output;                                  //nazwa pliku z savem mapy
        
        Map();
        ~Map();
        
        void erase_objects();                           //czyści mapę - usuwa z niej wszystkie obiekty
        bool loadmap(string);                           //załadowanie mapy do pamięci, Parametr: ścieżka do mapy
        void showmap();                                 //pokazanie elementów mapy na ekranie
        void savemap();                                 //zapisanie aktualnego stanu mapy do pliku
}; 


#endif	/* MAP_H */

