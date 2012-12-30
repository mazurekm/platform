#include "Application.h"

const int Application::FPS;

Application::Application(){
    game_in_progress = true;
    
    color.r=255; 
    color.g=255; 
    color.b=255; 
}
Application::~Application(){
    delete player;
    
    TTF_Quit();
    SDL_Quit();
    
    //printf("Application destroyed\n");
}

bool Application::init(){
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ){
        return false;
    }
    GlobalUtils::screen = SDL_SetVideoMode( GlobalUtils::SCREEN_WIDTH, GlobalUtils::SCREEN_HEIGHT, GlobalUtils::SCREEN_BPP, SDL_SWSURFACE );

    if( GlobalUtils::screen == NULL ) {
        return false;
    }
    
    if( TTF_Init() == -1 ) {
        return false;    
    } else {
        font=TTF_OpenFont("rsc/font.ttf", 50);
        font1=TTF_OpenFont("rsc/font.ttf", 100);
        end_game=TTF_RenderText_Solid(font1,"GAME OVER", color);
    }
    
    SDL_WM_SetCaption( "Gra platformowa", NULL );
    return true;
}

int Application::run_game(string it, Player *player) {
    
    Menu* menu = new Menu();
    
    Map *map = new Map();
    map->loadmap(it);
    
    if(it!=player->save_name)player->level_name=it;
    
    int i;
    while(game_in_progress) {
        timer.start();
        //EVENTY//////////////////////////////////////////////////////////////////////////////////////////////////
        while(SDL_PollEvent(&GlobalUtils::event)) {
            
            character->handleinput();
            
            if(GlobalUtils::event.type==SDL_QUIT)       //wyjście z gry na "x" w górnym prawym rogu
                game_in_progress=false;      
           
            if(GlobalUtils::event.type==SDL_KEYDOWN)
                if(GlobalUtils::event.key.keysym.sym==SDLK_p) {
                    switch(menu->pause_menu()){         //wywołanie menu w trakcie pauzy
                        case 0: break;                  //powrót do gry
                        case 1:                         //zapis stanu gry
                            map->savemap();
                            player->save_data();
                            break;
                        case 2:                         //wyjście z gry
                            delete map;
                            return Character::GAME_OVER;
                            break;
                        
                    }
                }
            
        }/////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        //PORUSZANIE SIE OBIEKTOW/////////////////////////////////////////////////////////////////////////////////
        switch(character->move()){              //poruszanie się postaci
            case StaticObject::COIN:            //zebranie monety
                player->score += 10;
                if(player->score >= 1000){
                    Player::lives++;
                    player->score = 0;
                }
                break;
                
            case StaticObject::EXIT:            //wyjscie przez "drzwi" z poziomu
                GlobalUtils::pause(2000);
                delete map;
                return StaticObject::EXIT;
                break;
                
            case Character::GAME_OVER:          //przegrana
                GlobalUtils::apply_surface(0,0, text, GlobalUtils::screen,NULL);
                GlobalUtils::apply_surface(GlobalUtils::SCREEN_HEIGHT/2-180,GlobalUtils::SCREEN_WIDTH/2-180, end_game, GlobalUtils::screen,NULL);
                
                SDL_Flip(GlobalUtils::screen);
                GlobalUtils::pause(2000);
                
                delete map;
                return Character::GAME_OVER;
                break;
                
            default:
                break;
        } 
     
        //wyświetlanie wyniku, żyć
        ostringstream ss; ss <<"Wynik: " <<player->score <<" Zycia: " <<player->lives;
        string str=ss.str();
        text=TTF_RenderText_Solid(font, str.c_str(), color);
        
        //ustawienie "kamery tak by postać była na środku ekranu
        character->set_camera();
        
        //poruszanie się wrogów i badanie kolizji z nimi
        for(i=0; i<(map->en_tab).size(); i++){
                if(!map->en_tab[i]->dead){
                        map->en_tab[i]->move();
                        dynamic_collisions(character, map->en_tab[i],player);
                }
        }
        
        //////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        //RYSOWANIE///////////////////////////////////////////////////////////////////////////////////////////////
 
        SDL_FillRect( GlobalUtils::screen, &GlobalUtils::screen->clip_rect, SDL_MapRGB( GlobalUtils::screen->format, 0, 255, 0 ) );
        
        character->show();
        map->showmap();
        
        GlobalUtils::apply_surface(0,0, text, GlobalUtils::screen,NULL);
        if(!game_in_progress) {
            GlobalUtils::apply_surface(GlobalUtils::SCREEN_HEIGHT/2-180,GlobalUtils::SCREEN_WIDTH/2-180, end_game, GlobalUtils::screen,NULL);
        }
        
        SDL_Flip(GlobalUtils::screen);
        if(!game_in_progress) {
            GlobalUtils::pause(2000);
        }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        //OGRANICZENIE FPS////////////////////////////////////////////////////////////////////////////////////////
        if( timer.get_ticks() < 1000 / FPS ){        
            SDL_Delay( ( 1000 / FPS ) - timer.get_ticks() );
        }////////////////////////////////////////
    }
    //SPRZATANIE PO SOBIE////////////////////////////////////////////////////////////////////////////////////////
    delete map; 
    return Character::GAME_OVER;
}

void Application::dynamic_collisions(Character *c, Enemy *e,Player *player){
    //kolizja w pionie
    if((((c->y+c->height) >= (e->y+(e->height/2))) && ((c->y+c->height) <= (e->y+e->height))) || ( (c->y < (e->y+e->height)) && (c->y > e->y ) ) ){
        //kolizja w poziomie
        if( ( (c->x <= (e->x+e->width) ) && (c->x > e->x) ) || (((c->x+c->width)>e->x)&&((c->x+c->width)<(e->x+e->width)) ) ){
            
                if( c->die() ){
                    GlobalUtils::pause(2000);
                    game_in_progress=false;
                }
        }
    }
    
  //naskoczenie i zbicie gnoma
    //kolizja w pionie
    if((((c->y+c->height) > (e->y)) && ((c->y+c->height) < (e->y+(e->height/2)))) ){
        //kolizja w poziomie
        if( ( (c->x <= (e->x+e->width) ) && (c->x > e->x) ) || (((c->x+c->width)>e->x)&&((c->x+c->width)<(e->x+e->width)) ) ){

                c->y -= 40;
                c->jump_height = 80;
                player->score += 20;
                e->dead = true;
        }
    }    
}




