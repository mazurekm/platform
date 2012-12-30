#include "GlobalUtils.h"

SDL_Event GlobalUtils::event;
const int GlobalUtils::SCREEN_BPP;
const int GlobalUtils::SCREEN_HEIGHT;
const int GlobalUtils::SCREEN_WIDTH;

SDL_Surface* GlobalUtils::screen = NULL;

int GlobalUtils::level_width = 1440;
int GlobalUtils::level_height = 900;

int GlobalUtils::char_start_pos_x = 0;
int GlobalUtils::char_start_pos_y = 0;
        
SDL_Rect GlobalUtils::camera = {0,0,GlobalUtils::SCREEN_WIDTH,GlobalUtils::SCREEN_HEIGHT};

void GlobalUtils::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL){
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( source, clip, destination, &offset );
}

SDL_Surface* GlobalUtils::load_image(string filename){
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;

    loadedImage = IMG_Load( filename.c_str() );

    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormatAlpha( loadedImage );
        SDL_FreeSurface( loadedImage );
    }

    return optimizedImage;
}

void GlobalUtils::pause(int msec){
    Timer *t = new Timer;
    t->start();
    
    while(t->get_ticks()<msec){
    }
    
    t->stop();
    
    delete t;
}