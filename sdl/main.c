#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "header.h"
#include "mainMenu.c"
#include "levelMenu.c"
#include "PauseMenu.c"
#include "perso.c"
#include "background.c"
#include "settingsMenu.c"
#include "time.c"
#include "map.c"


void main() {
    //initialization sdl
    Game jeu;
    jeu.done=1;
    jeu.currentMenu=0;
    jeu.fenetre = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); //bech ta3mel fenetre   
    background b;
    personne p;
    map m;
    Time temp;
    initBack(&b);
    initPerso(&p);
    initialiser_map(&m,jeu.fenetre,&p);
    inittemps(&temp);
    initialisationLevelMenu(&jeu);
    initialiserPauseMenu(&jeu);
    int continuer=1,pasAvencement=1,achieve=0;
    SDL_Event event;
    initialiserMenu(&jeu);
    animateMC = SDL_AddTimer(100, animatepersonne, &p);
    while (jeu.done!=0) {
        Mix_VolumeMusic(jeu.bgvolume);
        if (jeu.currentMenu==0) {
            afficherMenu(&jeu);
            achieve=0;
            startTimer = SDL_AddTimer(100, animateBg, &jeu);
        while (SDL_PollEvent(&event)){
		switch(event.type)
		{
			case SDL_QUIT:
				jeu.done=0;
			break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						jeu.done=0;
					break;
                    case SDLK_DOWN:
                        manipulationBoutonDown(&jeu);
                    break;
                    case SDLK_UP:
                        manipulationBoutonUp(&jeu);
                    break;
                    case SDLK_RETURN:
                       changementMenu(&jeu);

                }
            case SDL_MOUSEMOTION:
                mouseMotion(&jeu);
            break;
            case SDL_MOUSEBUTTONDOWN:
                mouseBoutonsDown(&jeu,event);
            break;
        }
            }}
             else if (jeu.currentMenu==1) {
            //affiche settings
            initialiserSettings(&jeu);
            //jeu.settingmenu.btn[1].state=0;
            //jeu.settingmenu.btn[0].state=0;
            //SDL_Event event;
            SDL_WaitEvent(&event);
            switch(event.type){
                case SDL_QUIT:
				    jeu.done=0;
			    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym){
                        case SDLK_ESCAPE:
                            jeu.done=0;
                        break;
                        case SDLK_KP_MINUS:
                            volumeDecrease(&jeu);
                        break;
                        case SDLK_KP_PLUS:
                            volumeIncrease(&jeu);
                        break;
                        case SDLK_BACKSPACE:
                            jeu.currentMenu=0;
                        break;

                    }
                case SDL_MOUSEMOTION:
                    settingsMouseMotion(&jeu);
                break;
                case SDL_MOUSEBUTTONDOWN:
                    manageAudioMouse(&jeu);
                break;
            }
         } 
            else if (jeu.currentMenu==2) {
                //SDL_EnableKeyRepeat(10,10);
                afficherBack(b,jeu.fenetre);
                SDL_BlitSurface(b.bird.imgBird[b.currentSprite],NULL,jeu.fenetre,&b.bird.posBird);
                afficherPerso(p,jeu.fenetre);
                affiche_map(&m,jeu.fenetre,&p);
                update_time(&temp);
                displaytime(temp,jeu.fenetre);
                animerBackground(&b,jeu.fenetre);
                SDL_BlitSurface(b.bus.imgBus[b.bus.num],NULL,b.gameBg,&b.bus.posBus);
                initialiserCollision(collision);
                p.keystate = SDL_GetKeyState(NULL);
                SDL_Flip(jeu.fenetre);
                while(SDL_PollEvent(&event)){
                    switch(event.type){
                        case SDL_QUIT:
                            jeu.done=0;
                        break;
                        case SDL_KEYDOWN:
                            switch(event.key.keysym.sym){
                                case SDLK_ESCAPE:
                                    jeu.currentMenu=4;
                                break;
                            }
                        break;
                    }
                }
                collisionPP(p,b.gameBgMasque,collision);
                manageState(&p);
                scrolling(&b,&p,pasAvencement,&m,collision);
                manageJump(&p);
                finLevel(&achieve,&p,&b);
                if(achieve==1){
                    jeu.currentMenu=0;
                    p.spritePos.x=10;
                    b.posCamera.x=0;
                    b.posCamera.y=0;
                }
                //personne_map(&m,&p);
            }
            else if(jeu.currentMenu==3){
                affichageLevelMenu(&jeu);
                while(SDL_PollEvent(&event)){
                    switch(event.type){
                        case SDL_QUIT:
                            jeu.done=0;
                        break;
                        case SDL_MOUSEMOTION:
                            levelsMousemotion(&jeu);
                        break;
                        case SDL_MOUSEBUTTONDOWN:
                            managelevelsMouse(&jeu);
                        break;
                    }
                }
            }
            else if(jeu.currentMenu==4){
                affichagePasueMenu(&jeu);
                while(SDL_PollEvent(&event)){
                    switch(event.type){
                        case SDL_QUIT:
                            jeu.done=0;
                        break;
                        case SDL_MOUSEMOTION:
                            pauseMousemotion(&jeu);
                        break;
                        case SDL_MOUSEBUTTONDOWN:
                            managepauseMouse(&jeu);
                        break;
                    }
                }
            }
    }
        
        
    for (int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            SDL_FreeSurface(jeu.mainMenu.btn[i].btn[j]);
        }
    }
    for (int k=0;k<3;k++){
        SDL_FreeSurface(jeu.mainMenu.bg[k]);
    }
    for (int p=0;p<5;p++){
        SDL_FreeSurface(jeu.settingmenu.sliders.slider[p]);
    }
    SDL_FreeSurface(jeu.settingmenu.SettingBg);
    SDL_FreeSurface(jeu.fenetre);
    for(int q=0;q<3;q++){
        SDL_FreeSurface(b.bird.imgBird[q]);
    }
    Mix_FreeMusic(jeu.bgMusic);
    SDL_Quit(); 
}