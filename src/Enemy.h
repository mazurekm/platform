

#ifndef ENEMY_H
#define	ENEMY_H
#include "DynamicObject.h"

using namespace std;

class Enemy :public DynamicObject {
       
        public:
                bool dead;                              //true - obiekt został "rozdepnięty"
                
                Enemy();
                Enemy(int xx, int yy);                  //parametry: pozycja obiektu
                virtual ~Enemy();
                
                int move();                             //poruszanie postaci 
};

#endif	/* ENEMY_H */

