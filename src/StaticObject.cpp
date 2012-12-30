#include"StaticObject.h"

const int StaticObject::EMPTY_BLOCK;
const int StaticObject::NORMAL_BLOCK;
const int StaticObject::DISAPP_BLOCK;
const int StaticObject::TRAP_BLOCK;
const int StaticObject::ENEMY;
const int StaticObject::CHARACTER;
const int StaticObject::EXIT;
const int StaticObject::COIN;

vector<StaticObject*> StaticObject::st_tab;

StaticObject::StaticObject(){
    
}

StaticObject::StaticObject(int xx,int yy,string fname,int type){
    this->type = type; 
    
    x=xx; 
    y=yy;
    
    width = 40;
    height = 40;
    
    counter = 20;
    image=GlobalUtils::load_image(fname);
}

StaticObject::~StaticObject(){
    printf("StaticObject destroyed\n");
}