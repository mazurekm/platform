#include "Enemy.h"

Enemy::Enemy(int xx, int yy){ 
    class_name = "Enemy";
    
    dead = false;
    
    width = 40;
    height = 40;
    
    move_speed_x = 2;
    move_speed_y = 3;
    
    x=xx;
    y=yy;
    
    oy=move_speed_y;
    ox=move_speed_x;
    
    clips = new SDL_Rect[2];
   //wyodrębnienie obrazków ze sprite'a 
    clips[0].x = 0;
    clips[0].y = 0;
    clips[0].h = 40;
    clips[0].w = 40;
    
    clips[1].x = 40;
    clips[1].y = 0;
    clips[1].h = 40;
    clips[1].w = 40;    
    
    clip_index = 1;

    image=GlobalUtils::load_image("rsc/dogs.png");
    
    clip = &clips[1];
}

Enemy::~Enemy(){
    printf("Enemy destroyed\n");
}

int Enemy::move(){
    //poruszanie się gnomów w prawo lub lewo (tylko jeżeli są na platformie - inaczej spadek pionowy)  
    y+=move_speed_y;
    int c = collision_y();
    if( c==StaticObject::EXIT || c>=20 || c==0 ){
        y = c;
        
        x += ox;
        c = collision_x();
        if( c== StaticObject::EXIT || c>=20 || c==0){
            clip_index = !clip_index;
            clip = &clips[clip_index];
            x = c;
            ox = -ox;
        }
    }
 return 0;   
}
