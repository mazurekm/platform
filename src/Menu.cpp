#include "Menu.h"


int Menu::main_menu(){
        SDL_Init( SDL_INIT_EVERYTHING );
  
        GlobalUtils::screen = SDL_SetVideoMode( GlobalUtils::SCREEN_WIDTH, GlobalUtils::SCREEN_HEIGHT, GlobalUtils::SCREEN_BPP, SDL_SWSURFACE );

	TTF_Init();
	TTF_Font *fontSmall = NULL,
                 *fontBig = NULL;
	
        SDL_Color textColor = {255,0,0};
	
        SDL_Surface* tabSmall[3];
	SDL_Surface* tabBig[3] ;

	fontSmall = TTF_OpenFont( "rsc/font.ttf", 18 );
        fontBig = TTF_OpenFont( "rsc/font.ttf", 28 );
        
	tabSmall[0] = TTF_RenderText_Solid( fontSmall, "Nowa gra", textColor );
	tabSmall[1] = TTF_RenderText_Solid( fontSmall, "Wczytaj gre", textColor );
	tabSmall[2] = TTF_RenderText_Solid( fontSmall, "Wyjscie", textColor );
        
        tabBig[0] = TTF_RenderText_Solid( fontBig, "Nowa gra", textColor );
	tabBig[1] = TTF_RenderText_Solid( fontBig, "Wczytaj gre", textColor );
	tabBig[2] = TTF_RenderText_Solid( fontBig, "Wyjscie", textColor );

	choice = 0;
	while(true){
		SDL_FillRect( GlobalUtils::screen, &GlobalUtils::screen->clip_rect, SDL_MapRGB( GlobalUtils::screen->format, 0, 0, 0 ) );

		if(choice == 0)
			GlobalUtils::apply_surface(GlobalUtils::SCREEN_WIDTH / 3, GlobalUtils::SCREEN_HEIGHT / 5, tabBig[0], GlobalUtils::screen,NULL);
		else
			GlobalUtils::apply_surface(GlobalUtils::SCREEN_WIDTH / 3, GlobalUtils::SCREEN_HEIGHT / 5, tabSmall[0], GlobalUtils::screen,NULL);
		if(choice == 1)
			GlobalUtils::apply_surface(GlobalUtils::SCREEN_WIDTH / 3, GlobalUtils::SCREEN_HEIGHT * 2 / 5, tabBig[1], GlobalUtils::screen,NULL);
		else
			GlobalUtils::apply_surface(GlobalUtils::SCREEN_WIDTH / 3, GlobalUtils::SCREEN_HEIGHT * 2 / 5, tabSmall[1], GlobalUtils::screen,NULL);
		if(choice == 2)
			GlobalUtils::apply_surface(GlobalUtils::SCREEN_WIDTH / 3, GlobalUtils::SCREEN_HEIGHT * 3 / 5, tabBig[2], GlobalUtils::screen,NULL);
		else
			GlobalUtils::apply_surface(GlobalUtils::SCREEN_WIDTH / 3, GlobalUtils::SCREEN_HEIGHT * 3 / 5, tabSmall[2], GlobalUtils::screen,NULL);

		SDL_Flip(GlobalUtils::screen);

		if(SDL_PollEvent(&GlobalUtils::event)){

                    if(GlobalUtils::event.type == SDL_KEYDOWN)
                            switch(GlobalUtils::event.key.keysym.sym){

                                case SDLK_UP:
                                        if(choice == 0) 
                                            choice = 2;
                                        else 
                                            choice--; 
                                        break;

                                case SDLK_DOWN:
                                        if(choice == 2) 
                                            choice = 0;
                                        else 
                                            choice++; 
                                        break;

                                case SDLK_RETURN:
                                        switch(choice){
                                            for(int i=0;i<3;i++){
                                                    //SDL_FreeSufrace(tabSmall[i]); SDL_FreeSurface(tabBig[i]);
                                            }
                                            TTF_CloseFont( fontSmall ); TTF_CloseFont( fontBig );

                                            case 0: 
                                                if(GlobalUtils::event.type == SDL_QUIT)
                                                        return 2;
                                                return 0; 
                                                break;

                                            case 1: 
                                                return 1; 
                                                break;

                                            case 2: 
                                                return 2; 
                                                break;
                                        }
                        }
                        if(GlobalUtils::event.type == SDL_QUIT)
                            return 2;

              }
	}



}

int Menu::pause_menu(){

    TTF_Init();
    TTF_Font *fontSmall = NULL, *fontBig = NULL;
    
    fontSmall = TTF_OpenFont( "rsc/font.ttf", 18 );
    fontBig = TTF_OpenFont( "rsc/font.ttf", 28 );
    
    SDL_Color textColor = {255,0,0};
	
    SDL_Surface* tabSmall[3];
    SDL_Surface* tabBig[3] ;

    tabSmall[0] = TTF_RenderText_Solid( fontSmall, "Powrot", textColor );
    tabSmall[1] = TTF_RenderText_Solid( fontSmall, "Zapisz", textColor );
    tabSmall[2] = TTF_RenderText_Solid( fontSmall, "Wyjscie", textColor );
    
    tabBig[0] = TTF_RenderText_Solid( fontBig, "Powrot", textColor );
    tabBig[1] = TTF_RenderText_Solid( fontBig,"Zapisz", textColor );
    tabBig[2] = TTF_RenderText_Solid( fontBig, "Wyjscie", textColor );


    choice = 0;
    while(true){
    	SDL_FillRect( GlobalUtils::screen, &GlobalUtils::screen->clip_rect, SDL_MapRGB( GlobalUtils::screen->format, 0, 0, 0 ) );

        if(choice == 0)
                GlobalUtils::apply_surface(GlobalUtils::SCREEN_WIDTH / 3, GlobalUtils::SCREEN_HEIGHT / 5, tabBig[0], GlobalUtils::screen,NULL);
        else
                GlobalUtils::apply_surface(GlobalUtils::SCREEN_WIDTH / 3, GlobalUtils::SCREEN_HEIGHT / 5, tabSmall[0], GlobalUtils::screen,NULL);
        if(choice == 1)
                GlobalUtils::apply_surface(GlobalUtils::SCREEN_WIDTH / 3, GlobalUtils::SCREEN_HEIGHT * 2 / 5, tabBig[1], GlobalUtils::screen,NULL);
        else
                GlobalUtils::apply_surface(GlobalUtils::SCREEN_WIDTH / 3, GlobalUtils::SCREEN_HEIGHT * 2 / 5, tabSmall[1], GlobalUtils::screen,NULL);
        if(choice == 2)
                GlobalUtils::apply_surface(GlobalUtils::SCREEN_WIDTH / 3, GlobalUtils::SCREEN_HEIGHT * 3 / 5, tabBig[2], GlobalUtils::screen,NULL);
        else
                GlobalUtils::apply_surface(GlobalUtils::SCREEN_WIDTH / 3, GlobalUtils::SCREEN_HEIGHT * 3 / 5, tabSmall[2], GlobalUtils::screen,NULL);


        SDL_Flip(GlobalUtils::screen);

        if(SDL_PollEvent(&GlobalUtils::event)){
            if(GlobalUtils::event.type == SDL_QUIT)
                	return 2;
                if(GlobalUtils::event.type == SDL_KEYDOWN)
                    switch(GlobalUtils::event.key.keysym.sym){

                        case SDLK_UP:
                                if(choice == 0) 
                                    choice = 2;
                                else 
                                    choice--; 
                                break;

                        case SDLK_DOWN:
                                if(choice == 2) 
                                    choice = 0;
                                else 
                                    choice++; 
                                break;

                        case SDLK_RETURN:
                                switch(choice){
					for(int i=0;i<3;i++){
                                                //SDL_FreeSufrace(tabSmall[i]); SDL_FreeSurface(tabBig[i]);
                                        }
                                        TTF_CloseFont( fontSmall ); TTF_CloseFont( fontBig );

                                        case 0:
                                                return 0; 
                                                break;

                                        case 1:
                                                return 1;
                                                break;

                                        case 2: 
                                            return 2; 
                                            break;

                                        case 3:
                                            break;
                                }
                    }
                    
            }
        
        
    }

}

Menu::Menu(){
}

Menu::~Menu(){
    
}