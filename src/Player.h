

#ifndef PLAYER_H
#define	PLAYER_H

#include<string>
#include<sstream>
#include<fstream>
#include<cstdlib>

using namespace std;

class Player {
   public:
       string player_name,              //nick gracza
              level_name,               //nazwa levelu(ścieżka do pliku
              save_name;                //nazwa pliku z savem mapy
       
       int score;                       //wynik
       
       static int lives;                //ilość żyć
       
       Player(string name);             //Parametr: nick
       
       void save_data();                //zapis danych gracza do pliku
       void load_data();                //odczyt danych gracza z pliku
       void save_ranking();             //zapis do rankingu
};


#endif	/* PLAYER_H */

