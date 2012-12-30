#include "DynamicObject.h"

const int DynamicObject::NO_COLLISION;

DynamicObject::DynamicObject(){
    
}

DynamicObject::~DynamicObject(){
    
    printf("DynamicObject destroyed\n");
}


int DynamicObject::collision_x(){
   //czy obiekt jest wewnątrz mapy
    if(x<0){
        return 0;
    }
    if((x + width) > GlobalUtils::level_width){
        return GlobalUtils::level_width-width;
    }
    
   //układ "czułych punktów" obiektu
    //so1       so2
    //
    //so3       so4
    
    StaticObject *so1 = StaticObject::st_tab[(y+1)/40*GlobalUtils::level_width/40 + (x+1)/40]; 
    StaticObject *so2 = StaticObject::st_tab[(y+1)/40*GlobalUtils::level_width/40 + (x+width-1)/40];
    StaticObject *so3 = StaticObject::st_tab[(y+height-1)/40*GlobalUtils::level_width/40 + (x+1)/40];
    StaticObject *so4 = StaticObject::st_tab[(y+height-1)/40*GlobalUtils::level_width/40 + (x+width-1)/40];
    
//kolizja z monetą
    if( so1->type == StaticObject::COIN){
        if(class_name.compare("Character")==0){
                so1->set_image("rsc/empty.png");
                so1->type = StaticObject::EMPTY_BLOCK;
        }

        return StaticObject::COIN;
    }
    if(so2->type == StaticObject::COIN){
        if(class_name.compare("Character")==0){
                so2->set_image("rsc/empty.png");
                so2->type = StaticObject::EMPTY_BLOCK;
        }
  
        return StaticObject::COIN;
    }
    if(so3->type == StaticObject::COIN) {
        if(class_name.compare("Character")==0){
                so3->set_image("rsc/empty.png");
                so3->type = StaticObject::EMPTY_BLOCK;
        }

        return StaticObject::COIN;
    }
    if(so4->type == StaticObject::COIN){
        if(class_name.compare("Character")==0){
                so4->set_image("rsc/empty.png");
                so4->type = StaticObject::EMPTY_BLOCK;
        }

        return StaticObject::COIN;
    }
    
//kolizja z pułapką
    if( (so1->type == StaticObject::TRAP_BLOCK) || (so2->type == StaticObject::TRAP_BLOCK) || (so3->type == StaticObject::TRAP_BLOCK) || (so4->type == StaticObject::TRAP_BLOCK) ){
        if(class_name.compare("Character")==0)
                return StaticObject::TRAP_BLOCK;
    }
  
//kolizja z wyjściem
    if( (so1->type == StaticObject::EXIT) && (so3->type == StaticObject::EXIT) ){
        if(class_name.compare("Character")==0)
                return StaticObject::EXIT;
    }
    
    if( (so2->type == StaticObject::EXIT) && (so4->type == StaticObject::EXIT) ){
        if(class_name.compare("Character")==0)
                return StaticObject::EXIT;
    }
    
//kolizja z normalnym blokiem
    if( (so1->type == StaticObject::NORMAL_BLOCK) || (so3->type == StaticObject::NORMAL_BLOCK) ){
        return (so1->x + so1->width);
    }
    
    if( (so2->type == StaticObject::NORMAL_BLOCK) || (so4->type == StaticObject::NORMAL_BLOCK) ){
        return so2->x - width;
    }
    

    return NO_COLLISION;
}

int DynamicObject::collision_y(){
    //ograniczenie do wielkości mapy
    if( (y + height) > GlobalUtils::level_height ){
        return GlobalUtils::level_height-height;
    }
    
    if( y < 0 ){
        return 0;
    }     
    
    //układ czułych punktów
    //so1       so2
    //
    //so3       so4
    
    StaticObject *so1 = StaticObject::st_tab[(y+1)/40*GlobalUtils::level_width/40 + (x+1)/40]; 
    StaticObject *so2 = StaticObject::st_tab[(y+1)/40*GlobalUtils::level_width/40 + (x+width-1)/40];
    StaticObject *so3 = StaticObject::st_tab[(y+height-1)/40*GlobalUtils::level_width/40 + (x+1)/40];
    StaticObject *so4 = StaticObject::st_tab[(y+height-1)/40*GlobalUtils::level_width/40 + (x+width-1)/40];
    
//kolizja z monetą
    if( so1->type == StaticObject::COIN){
        if(class_name.compare("Character")==0){
                so1->set_image("rsc/empty.png");
                so1->type = StaticObject::EMPTY_BLOCK;
        }

        return StaticObject::COIN;
    }
    if(so2->type == StaticObject::COIN){
        if(class_name.compare("Character")==0){
                so2->set_image("rsc/empty.png");
                so2->type = StaticObject::EMPTY_BLOCK;
        }

        return StaticObject::COIN;
    }
    if(so3->type == StaticObject::COIN) {
        if(class_name.compare("Character")==0){
                so3->set_image("rsc/empty.png");
                so3->type = StaticObject::EMPTY_BLOCK;
        }

        return StaticObject::COIN;
    }
    if(so4->type == StaticObject::COIN){
        if(class_name.compare("Character")==0){
                so4->set_image("rsc/empty.png");
                so4->type = StaticObject::EMPTY_BLOCK;
        }

        return StaticObject::COIN;
    }
    
//kolizja z pułapką
    if( (so1->type == StaticObject::TRAP_BLOCK) || (so2->type == StaticObject::TRAP_BLOCK) || (so3->type == StaticObject::TRAP_BLOCK) || (so4->type == StaticObject::TRAP_BLOCK) ){
        if(class_name.compare("Character")==0)
        return StaticObject::TRAP_BLOCK;
    }
 
//kolizja z wyjściem
    if( (so1->type == StaticObject::EXIT) && (so2->type == StaticObject::EXIT) ){
        if(class_name.compare("Character")==0)
        return StaticObject::EXIT;
    }
    
    if( (so3->type == StaticObject::EXIT) && (so4->type == StaticObject::EXIT) ){
        if(class_name.compare("Character")==0)
        return StaticObject::EXIT;
    }
    
//kolizja ze znikającym blokiem    
    if( (so3->type == StaticObject::DISAPP_BLOCK) || (so4->type == StaticObject::DISAPP_BLOCK) ){
        if(class_name.compare("Character")==0){
            so3->counter--;
            so4->counter--;
            if( (so3->counter <= 0) && (so3->type == StaticObject::DISAPP_BLOCK) ){
                so3->type = StaticObject::EMPTY_BLOCK;
                so3->set_image("rsc/empty.png");
            }
            if((so4->counter <= 0) && (so4->type == StaticObject::DISAPP_BLOCK)){
                so4->type = StaticObject::EMPTY_BLOCK;
                so4->set_image("rsc/empty.png");
            }
        }
 
        return so3->y-height;
    }
    
//kolizja z normalnym klockiem
    if( (so1->type == StaticObject::NORMAL_BLOCK) || (so2->type == StaticObject::NORMAL_BLOCK) ){

        return (so1->y + so1->height);
    }
    
    if( (so3->type > 0) || (so4->type > 0) ){

        return so3->y - height;
    }
    
    return NO_COLLISION;
}


