

#ifndef STATICOBJECT_H
#define	STATICOBJECT_H
#include "Object.h"

using namespace std;

class StaticObject : public Object {
    public:
        int type,                                       //typ obiektu
            counter;                                    //licznik
        
        static const int EMPTY_BLOCK = 0;               //wartości określające typ danego obiektu
        static const int NORMAL_BLOCK = 1;
        static const int DISAPP_BLOCK = 2;
        static const int TRAP_BLOCK = 3;
        static const int ENEMY = 4;
        static const int CHARACTER = 5;
        static const int EXIT = 6;
        static const int COIN = 7;
        
        static vector<StaticObject*> st_tab;            //vector wszystkich obiektów statycznych na mapie
        
        StaticObject();
        StaticObject(int,int,string,int);               //Parametry: poxycja x, pozycja y, ścieżka do pliku z obrazkiem, typ obiektu
        virtual ~StaticObject();
          
};


#endif	/* STATICOBJECT_H */

