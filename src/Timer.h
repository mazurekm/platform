

#ifndef TIMER_H
#define	TIMER_H


#include "SDL/SDL.h"

class Timer{
    private:
 
        int startTicks;                 //stan początkowy timera
        int pausedTicks;                //stan timera w momencie pauzy

        bool paused;                    //czy spauzowany
        bool started;                   //czy wystartowany

    public:
  
        Timer();
        
        void start();                   //start timera
        void stop();                    //stop timera
        void pause();                   //pauza timera
        void unpause();                 //odpauzowanie timera

        int get_ticks();                //zwraca ilość ticków timera

        bool is_started();              //getter 
        bool is_paused();               //getter
};


#endif	/* TIMER_H */

