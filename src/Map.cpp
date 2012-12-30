#include "Map.h"

Character *character=NULL;
Player *player=NULL;

Map::Map(){
    GlobalUtils::level_width = 1440;
    GlobalUtils::level_height = 900;
    output="maps/save.sv";
}

Map::~Map(){
    erase_objects(); 
}

void Map::erase_objects() {
    for(int i=0; i<en_tab.size(); i++){
        en_tab[i]->~Enemy();
    }
    
    for(int i=0; i<StaticObject::st_tab.size(); i++){
        StaticObject::st_tab[i]->~StaticObject();
    }
    
    en_tab.clear();
    
    StaticObject::st_tab.clear(); 
    
    delete character; 
}

bool Map::loadmap(string fname) {
    string tmp; 
    fstream stream; 
    stream.open(fname.c_str(),fstream::in);
    
    while(getline(stream,tmp)) { //wczytanie macierzy elementów mapy
            string::iterator it=tmp.begin();
            for(int i=0; i<tmp.size(); ++i)
                            if(*(it+i)==' ') tmp.erase(it+i);
            map_elements.push_back(tmp); 			
    }
    
    int i,j;
    for(i=0; i<map_elements.size(); ++i) {      //tworzenie obiektów na mapie
        vector<string>::iterator it=map_elements.begin()+i;
        
        for(j=0; j < it->size(); ++j) {
            switch(map_elements[i][j])
            {
                case '0': {     //pusta przestrzeń
                    StaticObject *obj0=new StaticObject(j*40, i*40, "rsc/empty.png", StaticObject::EMPTY_BLOCK);
                    StaticObject::st_tab.push_back(obj0);
                    break;
                }
                
                case '1': {     //normalny klocek
                    StaticObject *obj1=new StaticObject(j*40, i*40, "rsc/normal_block.png", StaticObject::NORMAL_BLOCK);
                    StaticObject::st_tab.push_back(obj1);
                    break;
                }
                    
                case '2': {     //znikający klocek
                    StaticObject *obj2=new StaticObject(j*40, i*40, "rsc/disapp_block.png", StaticObject::DISAPP_BLOCK);
                    StaticObject::st_tab.push_back(obj2);
                    break;
                }
                
                case '3': {     //pułapka
                    StaticObject *obj3=new StaticObject(j*40, i*40, "rsc/trap_block.png", StaticObject::TRAP_BLOCK);
                    StaticObject::st_tab.push_back(obj3);
                    break;
                }
                    
                case '4': {     //enemy
                    StaticObject *obj0=new StaticObject(j*40, i*40, "rsc/empty.png", StaticObject::EMPTY_BLOCK);
                    StaticObject::st_tab.push_back(obj0);
                    Enemy *obj3=new Enemy(j*40, i*40);
                    en_tab.push_back(obj3);
                    break;
                }
                    
                case '5': {     //nasza postać
                    StaticObject *obj0=new StaticObject(j*40, i*40, "rsc/empty.png", StaticObject::EMPTY_BLOCK);
                    StaticObject::st_tab.push_back(obj0);
                    GlobalUtils::char_start_pos_x = j*40;
                    GlobalUtils::char_start_pos_y = i*40;
                    character=new Character(j*40, i*40);
                    break;
                }              
                
                case '6': {     //wyjście z levelu
                    StaticObject *obj6=new StaticObject(j*40, i*40, "rsc/door.png", StaticObject::EXIT);
                    StaticObject::st_tab.push_back(obj6);
                    break;
                }
                
                case '7': {     //moneta
                    StaticObject *obj7=new StaticObject(j*40, i*40, "rsc/coin.png", StaticObject::COIN);
                    StaticObject::st_tab.push_back(obj7);
                    break;
                }
            }
        }
    }
    
    //ustawienie wielkości levelu
    GlobalUtils::level_width = j*40;
    GlobalUtils::level_height = i*40;
    
    map_elements.clear();
    stream.close(); 
    return true;    
}

void Map::showmap(){
  //pokazywanie elementow statycznych
    vector<Enemy*>::iterator it1; 
    vector<StaticObject*>::iterator it2;
    
    for(it2 = StaticObject::st_tab.begin(); it2 != StaticObject::st_tab.end(); ++it2)
        (*it2)->show();
    
  //pokazywanie wrogów
    for(it1 = en_tab.begin(); it1 != en_tab.end(); ++it1){
            if(!(*it1)->dead){
                    (*it1)->show();
            }
    }
}
void Map::savemap() {
    fstream stream; 
    stream.open(output.c_str(),fstream::out);
  
  //stworzenie macierzy zer  
    string tmp(GlobalUtils::level_width/40,'0'); 
    tmp.push_back('\n');
  
  //zapisanie pozycji naszej postaci  
    vector<string> v(GlobalUtils::level_height/40,tmp);
    v[character->y/40][character->x/40]='5';
    
    vector<Enemy*>::iterator it1;    
    vector<StaticObject*>::iterator it2;

 //zapisanie pozycji wszystkich enemy   
    for(it1=en_tab.begin();it1!=en_tab.end();++it1){
        v[((*it1)->y)/40][((*it1)->x)/40]='4';
    }
 
 //zapisanie pozycji wszystkich elementow statycznych   
    for(it2=StaticObject::st_tab.begin(); it2!=StaticObject::st_tab.end(); ++it2){
        switch((*it2)->type) {
            case StaticObject::NORMAL_BLOCK:
                v[((*it2)->y)/40][((*it2)->x)/40]='1';
                break;       
            case StaticObject::DISAPP_BLOCK:
                v[((*it2)->y)/40][((*it2)->x)/40]='2';
                break;
            case StaticObject::TRAP_BLOCK:
                v[((*it2)->y)/40][((*it2)->x)/40]='3';
                break;
            case StaticObject::ENEMY:
                v[((*it2)->y)/40][((*it2)->x)/40]='4';
                break;
            case StaticObject::CHARACTER:
                v[((*it2)->y)/40][((*it2)->x)/40]='5';
                break;    
            case StaticObject::EXIT:
                v[((*it2)->y)/40][((*it2)->x)/40]='6';
                break;
            case StaticObject::COIN:
                v[((*it2)->y)/40][((*it2)->x)/40]='7';
                break;  
        }
    }
  
  //zrzut do pliku  
    for(vector<string>::iterator it=v.begin();it!=v.end();++it)
        stream <<*it;
    stream.close();
}

