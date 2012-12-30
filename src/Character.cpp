#include "Character.h"
const int Character::MAX_JUMP;
const int Character::GAME_OVER;

Character::Character(int xx, int yy){
    class_name = "Character";
    
    x=xx;
    y=yy;
    
    oy=0;
    ox=0;
    
    width = 40;
    height = 40;
    
    jump_height = 0;
    max_jump_reached = true;
    
    move_speed_x = 4;
    move_speed_y = 5;
    speed_up=1;
    
    up = false;
    
    image = GlobalUtils::load_image("rsc/ball.png");
}

Character::~Character(){
        printf("character destroyed\n");
}

void Character::handleinput(){
       
    if( GlobalUtils::event.type == SDL_KEYDOWN )
    {
        
        switch( GlobalUtils::event.key.keysym.sym )
        {
            case SDLK_SPACE: speed_up = 2; break;
            case SDLK_UP: oy -= move_speed_y; up = true; break;
            case SDLK_LEFT: ox -= move_speed_x; break;
            case SDLK_RIGHT: ox += move_speed_x; break;
        }
    }
    else if( GlobalUtils::event.type == SDL_KEYUP )
    {
        switch( GlobalUtils::event.key.keysym.sym )
        {
            case SDLK_SPACE: speed_up = 1; break;
            case SDLK_UP: oy += move_speed_y; up = false; break;
            case SDLK_LEFT: ox += move_speed_x; break;
            case SDLK_RIGHT: ox -= move_speed_x; break;
        }
    }
}



int Character::move(){
 
int return_value = 0;    
    
 //poruszanie się w poziomie       
    x += ox*speed_up;
    
    int c = collision_x();
    if( (c>=20) || (c==0)) {
        x = c;
    }
    
  switch(c){    //rozpoznanie z jakim blokiem jest kolizja
      case StaticObject::TRAP_BLOCK:
          if(die()){
              return_value=GAME_OVER;
          }
          break;
      case StaticObject::COIN:
          return_value=StaticObject::COIN;
          break;
      case StaticObject::EXIT:
          return_value=StaticObject::EXIT;
          break;
  }  
        
 //poruszanie się w pionie   
    if(up && !max_jump_reached){        //jeżeli wciśnięty skok w górę i nie osiągnięto jeszcze max wys skoku
        y+=oy*(MAX_JUMP-jump_height+20)/60;
        jump_height-=oy*(MAX_JUMP-jump_height+20)/60;
        
        if(jump_height >= MAX_JUMP){
           max_jump_reached = true;
        }
        
        int c = collision_y();
        if( (c>=20) || (c==0)){
            y=c;
            max_jump_reached = true;
        }
        switch(c){      //rozpoznanie z jakim blokiem jest kolizja
          case StaticObject::TRAP_BLOCK:
              if(die()){
                  return_value=GAME_OVER;
              }
              break;
          case StaticObject::COIN:
              return_value=StaticObject::COIN;
              break;
          case StaticObject::EXIT:
              return_value=StaticObject::EXIT;
              break;
        } 
    }else{ //spadek lub spoczywanie na platformie
        if(jump_height != 0){
                y += move_speed_y*(MAX_JUMP-jump_height+20)/60;
        }else{
            y += move_speed_y;
        }
        if(jump_height > 0){
            jump_height -= move_speed_y*(MAX_JUMP-jump_height+20)/60;
        }
        
        int c = collision_y();
        if( (c>=20) || (c==0) ){
            y=c;
            max_jump_reached = false;
            jump_height = 0;
        }
          switch(c){            //rozpoznanie z jakim blokiem jest kolizja
            case StaticObject::TRAP_BLOCK:
                if(die()){
                    return_value=GAME_OVER;
                }
                break;
            case StaticObject::COIN:
                return_value=StaticObject::COIN;
                break;
            case StaticObject::EXIT:
                return_value=StaticObject::EXIT;
                break;
        } 
    }
    return return_value;
}

void Character::set_camera(){
    //ustawienie kamery tak by postać była na środku
    GlobalUtils::camera.x = (x+width/2)-GlobalUtils::SCREEN_WIDTH/2;
    GlobalUtils::camera.y = (y+height/2)-GlobalUtils::SCREEN_HEIGHT/2;
    
    //warunki by kamera nie wyjechała poza planszę
    if(GlobalUtils::camera.x < 0){
        GlobalUtils::camera.x = 0;
    }
    if(GlobalUtils::camera.y < 0){
        GlobalUtils::camera.y = 0;
    }
    if(GlobalUtils::camera.x > (GlobalUtils::level_width - GlobalUtils::camera.w)){
        GlobalUtils::camera.x = GlobalUtils::level_width - GlobalUtils::camera.w;
    }
    if(GlobalUtils::camera.y > (GlobalUtils::level_height - GlobalUtils::camera.h)){
        GlobalUtils::camera.y = GlobalUtils::level_height - GlobalUtils::camera.h;
    }
}

bool Character::die(){
                   Player::lives--;

                if(Player::lives >=0 ){//powrót na początek poziomu
                    GlobalUtils::pause(500);
                    x = GlobalUtils::char_start_pos_x;
                    y = GlobalUtils::char_start_pos_y;
                    return false;
                }
return true;
}