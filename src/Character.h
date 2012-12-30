
#ifndef CHARACTER_H
#define	CHARACTER_H

#include "DynamicObject.h"
#include "Player.h"
#include <string>

using namespace std; 

class Character : public DynamicObject {
        private:
            static const int MAX_JUMP = 150;            //max wysokość skoku
            bool max_jump_reached,                      //czy max wysokość skoku została osiągnięta
                 up;                                    //czy skok w górę wciśnięty


        public:
            static const int GAME_OVER = -1;            //wartość oznaczająca przegraną
            
            int jump_height;                            //aktualna wysokość skoku
           
            Character(int xx,int yy);                   //parametry - pozycja postaci
            virtual ~Character();
            
            void handleinput();                         //przechwycenie eventów klawiatury dotyczących postaci
            int move();                                 //obliczenie nowych współrzędnych postaci, pozycję postaci lub wartość oznaczającą koniec gry, koniec poziomu lub zebranie monety
            void set_camera();                          //ustawienie kamery tak by postać była na środku
            bool die();                                 // zmniejsza liczbę żyć i ustawia postać na pozycji początkowej, zwraca true gdy liczba żyć < 0
};

#endif	/* CHARACTER_H */

