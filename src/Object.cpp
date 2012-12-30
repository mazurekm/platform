#include "Object.h"

Object::Object(){
    clip = NULL;
}

Object::~Object(){
    SDL_FreeSurface(image);
    printf("object destroyed\n");
}

void Object::set_image(string fname){
    SDL_FreeSurface(image);
    image = GlobalUtils::load_image(fname);
}

void Object::show(){
        GlobalUtils::apply_surface( x - GlobalUtils::camera.x, y - GlobalUtils::camera.y, image, GlobalUtils::screen,clip );
}
