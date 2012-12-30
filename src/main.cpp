

#include <cstdlib>
#include <ios>
#include "Application.h"
#include <algorithm>

using namespace std;


int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);
    
    fstream stream; 
    stream.open("maps/map_list",fstream::in);
    
    Player *player=new Player("noname");
    vector<string> levels; 
    string name;  
    
    while(getline(stream,name))
        levels.push_back(name);
    
    stream.close();
    
    bool game_over = false;
    
    Menu *menu = new Menu();
    
    switch(menu->main_menu()){
        case 0: {  
                for(vector<string>::iterator it=levels.begin();it!=levels.end();++it) {
                    Application *game=new Application();
                    if(!game->init()){
                            return 1;
                    }
                    switch(game->run_game(*it,player)){
                        case StaticObject::EXIT:
                            break;
                        case Character::GAME_OVER:
                            game_over = true;
                            break;
                    }
                    delete game;

                    if(game_over){
                        break;
                    }
                }   
            }
            break;  
        case 1: {
                player->load_data(); 
                vector<string>::iterator it1=find(levels.begin(),levels.end(),player->level_name);
				(*it1)=player->save_name; 
                for( ; it1!=levels.end(); ++it1) {
                    Application *game=new Application();
                    if(!game->init()){
                            return 1;
                    }
                    switch(game->run_game(*it1,player)){
                        case StaticObject::EXIT:
                            break;
                        case Character::GAME_OVER:
                            game_over = true;
                            break;
                    }
                    delete game;

                    if(game_over){
                        break;
                    }
                }
            }   
            break;   
        case 2:
            return 0;
            break;
    }
    player->save_ranking();
    delete player; 
    return 0;
}

