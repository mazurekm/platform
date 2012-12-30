

#ifndef OBJECT_H
#define	OBJECT_H

#include"SDL/SDL.h"
#include "GlobalUtils.h"

using namespace std;
class Object {
    protected:
        SDL_Surface *image;                                     //sprite obrazków obiektu
        SDL_Rect *clip;                                         //aktualny clip ze sprite'a
    
    public:
        int x,                                                  //położenie obiektu x
            y;                                                  //położenie obiektu y
        unsigned short width,                                   //szerokość obiektu
                       height;                                  //wysokość obiektu
        
        
        Object();
        virtual ~Object();
        
        void set_image(string fname);                           //ustawia obrazek obiektu, Parametr: ścieżka do pliku
        void show();                                            //pokazanie obiektu na ekranie
};

#endif	/* OBJECT_H */

