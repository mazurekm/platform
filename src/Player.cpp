#include "Player.h"

int Player::lives=5; 

Player::Player(string name){
    save_name = "maps/save.sv";
    player_name=name;
    lives=5;
    score=0;
}
void Player::save_data() {
    ostringstream ss; 
    ss <<player_name <<"\\" <<score <<"#" <<lives <<"^" <<level_name <<"@";
    
    string tmp=ss.str();
    
    fstream stream; 
    stream.open("maps/sv_data",fstream::out);
    stream <<tmp; stream.close();
}

void Player::load_data() {
    fstream stream; 
    string tmp; 
    
    stream.open("maps/sv_data",fstream::in);
    
    getline(stream,tmp); string tmp1;
    if(!tmp.empty()){    
        for(int i=0;i<tmp.size();++i){
            if(tmp.empty()) 
                break;
            if(tmp[i]!='\\'&&tmp[i]!='#'&&tmp[i]!='^'&&tmp[i]!='@') tmp1.push_back(tmp[i]);
            else if(tmp[i]=='\\') {
                player_name=tmp1; tmp1.clear();
            }else if(tmp[i]=='#') {
                score=atoi(tmp1.c_str()); tmp1.clear();
            }else if(tmp[i]=='^'){
                lives=atoi(tmp1.c_str()); tmp1.clear();
            }else if(tmp[i]=='@') {
                level_name=tmp1; tmp1.clear();
            }
        }
    }
    stream.close(); 
}

void Player::save_ranking() {
    fstream stream; 
    stream.open("scores",fstream::out|fstream::app);
    
    stream <<player_name <<"\t" <<score*lives <<endl;
}

