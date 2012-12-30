

#ifndef DYNAMICOBJECT_H
#define	DYNAMICOBJECT_H
#include "Object.h"
#include "StaticObject.h"


class DynamicObject: public Object {
   
    protected:
        static const int NO_COLLISION = -100;                   //wartość oznaczająca brak kolizji
        
        string class_name;                                      //nazwa klasy
        
        int move_speed_x,                                       //prędkość poruszania się w poziomie
            move_speed_y,                                       //prędkość poruszania się w pionie
            speed_up,                                           //przyspieszenie "tzw turbo"
            ox,                                                 //offset x obiektu 
            oy;                                                 //offset y obiektu
        
        SDL_Rect *clips;                                        //tablica obrazków postaci
        int clip_index;                                         //indeks aktualnie wykorzystywanego obrazka w tablicy
        
        int collision_x();                                      //wykrywanie kolizji z obiektami statycznymi w płaszczyźnie x
        int collision_y();                                      //wykrywanie kolizji z obiektami statycznymi w płaszczyźnie y

        virtual int move()=0;                                   //poruszanie obiektu
    
        
     public:        
        DynamicObject();
        virtual ~DynamicObject();
};

#endif	/* DYNAMICOBJECT_H */

