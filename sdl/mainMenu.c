// #include <stdio.h>
// #include "SDL/SDL.h"
// #include "SDL/SDL_image.h"
// #include "SDL/SDL_mixer.h"
// #include "SDL/SDL_ttf.h"
// #include "header.h"
int checkMouseInside(SDL_Rect pos, int mouseX, int mouseY) {
  return mouseX >= pos.x && mouseX <= pos.x + pos.w && mouseY >= pos.y && mouseY <= pos.y + pos.h;
}
/*Uint32 startGame(Uint32 interval, void* param) {
  Game* jeu = param;
  jeu->done=0;
  return 0;
}*/
Uint32 animateBg(Uint32 interval, void* param) {
  Game* jeu = param;
  jeu->mainMenu.currentBg++;
  if(jeu->mainMenu.currentBg==3) {
    jeu->mainMenu.currentBg=0;
    return interval;
  } 
  //printf("%d\n",jeu->mainMenu.currentBg);
}
void initialiserMenu(Game* jeu){
    for (int i=0; i<3; i++) {
        jeu->mainMenu.btn[i].state=0;
    }
    for(int j=0; j<2; j++){
        jeu->settingmenu.btn[j].state=0;
    }

    SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    atexit(SDL_Quit);
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 0);
    jeu->bgMusic = Mix_LoadMUS ("Audio/bgMusic.mp3");
    jeu->son_click=Mix_LoadWAV("Audio/click_sound.wav");
    if(jeu->son_click==NULL){
        //printf("el pointeur feragh\n");
    }
    //printf("%d \n",son_click->allocated);
    
    jeu->bgvolume = 128;
    jeu->musicPlaying = 0;
    SDL_WM_SetCaption("DAY DREAMER", NULL); // barre name
    //affiche menu
    jeu->mainMenu.bg[0] = IMG_Load ("Images/bg1.png"); //hot limage fel variable hedha
    jeu->mainMenu.bg[1] = IMG_Load ("Images/bg2.png");
    jeu->mainMenu.bg[2] = IMG_Load ("Images/bg3.png");

    jeu->mainMenu.currentBg = 0;
    //nik les positions taa el bg
    jeu->mainMenu.posBg.x = 0; 
    jeu->mainMenu.posBg.y = 0;
    jeu->mainMenu.posBg.w = jeu->mainMenu.bg[0]->w;
    jeu->mainMenu.posBg.h = jeu->mainMenu.bg[0]->h;
    //printf("yo\n");
    jeu->settingmenu.SettingBg = IMG_Load("Images/SettingBg.png");//load image settings
    //printf("yo\n");

    //position mtaa bg settings
    jeu->settingmenu.posSettingBg.x=0;
    jeu->settingmenu.posSettingBg.y=0;
    jeu->settingmenu.posSettingBg.w=jeu->settingmenu.SettingBg->w;
    jeu->settingmenu.posSettingBg.h=jeu->settingmenu.SettingBg->h;

    //init sliders
    jeu->settingmenu.sliders.slider[0] = IMG_Load("Sliders/volume0.png");
    jeu->settingmenu.sliders.slider[1] = IMG_Load("Sliders/volume32.png");
    jeu->settingmenu.sliders.slider[2] = IMG_Load("Sliders/volume64.png");
    jeu->settingmenu.sliders.slider[3] = IMG_Load("Sliders/volume96.png");
    jeu->settingmenu.sliders.slider[4] = IMG_Load("Sliders/volume128.png");

    //position sliders
    jeu->settingmenu.sliders.posSlider.x=316;
    jeu->settingmenu.sliders.posSlider.y=316;
    jeu->settingmenu.sliders.posSlider.w=jeu->settingmenu.sliders.slider[0]->w;
    jeu->settingmenu.sliders.posSlider.h=jeu->settingmenu.sliders.slider[0]->h;
    
    jeu->settingmenu.btn[0].btn[0] = IMG_Load("Buttons/+nonSelec.png");
    jeu->settingmenu.btn[0].btn[1] = IMG_Load("Buttons/+Selec.png");
    jeu->settingmenu.btn[1].btn[0] = IMG_Load("Buttons/-nonSelec.png");
    jeu->settingmenu.btn[1].btn[1] = IMG_Load("Buttons/-Selec.png");
    jeu->settingmenu.btn[0].posBtn.x = jeu->settingmenu.sliders.posSlider.x+jeu->settingmenu.sliders.posSlider.w+10;
    jeu->settingmenu.btn[0].posBtn.y = 316;
    //jeu->settingmenu.btn[0].posBtn.w = jeu->mainMenu.btn[0].btn[0]->w;
    //jeu->settingmenu.btn[0].posBtn.h = jeu->mainMenu.btn[0].btn[0]->h;
    
    jeu->settingmenu.btn[1].posBtn.x = jeu->settingmenu.sliders.posSlider.x - 100;
    jeu->settingmenu.btn[1].posBtn.y = 316;
    //jeu->settingmenu.btn[1].posBtn.w = jeu->mainMenu.btn[1].btn[0]->w;
    //jeu->settingmenu.btn[1].posBtn.h = jeu->mainMenu.btn[1].btn[0]->h;

    jeu->mainMenu.btn[0].btn[0] = IMG_Load ("Buttons/PlayB1.png");
    jeu->mainMenu.btn[0].btn[1] = IMG_Load ("Buttons/PlayB2.png");

    jeu->mainMenu.btn[0].posBtn.x = 12;
    jeu->mainMenu.btn[0].posBtn.y = 235;
    jeu->mainMenu.btn[0].posBtn.w = jeu->mainMenu.btn[0].btn[0]->w;
    jeu->mainMenu.btn[0].posBtn.h = jeu->mainMenu.btn[0].btn[0]->h;

    jeu->mainMenu.btn[1].btn[0] = IMG_Load ("Buttons/SettingsB1.png");
    jeu->mainMenu.btn[1].btn[1] = IMG_Load ("Buttons/SettingsB2.png");

    jeu->mainMenu.btn[1].posBtn.x = 12;
    jeu->mainMenu.btn[1].posBtn.y = 235 + jeu->mainMenu.btn[0].btn[0]->h+30;
    jeu->mainMenu.btn[1].posBtn.w = jeu->mainMenu.btn[0].btn[0]->w;
    jeu->mainMenu.btn[1].posBtn.h = jeu->mainMenu.btn[0].btn[0]->h;

    jeu->mainMenu.btn[2].btn[0] = IMG_Load ("Buttons/QuitB1.png");
    jeu->mainMenu.btn[2].btn[1] = IMG_Load ("Buttons/QuitB2.png");

    jeu->mainMenu.btn[2].posBtn.x = 12;
    jeu->mainMenu.btn[2].posBtn.y = 235 + (jeu->mainMenu.btn[1].btn[0]->h * 2) + 70;
    jeu->mainMenu.btn[2].posBtn.w = jeu->mainMenu.btn[0].btn[0]->w;
    jeu->mainMenu.btn[2].posBtn.h = jeu->mainMenu.btn[0].btn[0]->h;
    jeu->settingmenu.sliders.niveau=4;
}
void afficherMenu(Game* jeu){
    if (jeu->musicPlaying==0) { 
                Mix_PlayMusic(jeu->bgMusic, -1);
                jeu->musicPlaying=1;
            }
            SDL_BlitSurface(jeu->mainMenu.bg[jeu->mainMenu.currentBg], NULL, jeu->fenetre, &jeu->mainMenu.posBg);
            
            SDL_BlitSurface(jeu->mainMenu.btn[0].btn[jeu->mainMenu.btn[0].state], NULL, jeu->fenetre, &jeu->mainMenu.btn[0].posBtn);
            SDL_BlitSurface(jeu->mainMenu.btn[1].btn[jeu->mainMenu.btn[1].state], NULL, jeu->fenetre, &jeu->mainMenu.btn[1].posBtn);
            SDL_BlitSurface(jeu->mainMenu.btn[2].btn[jeu->mainMenu.btn[2].state], NULL, jeu->fenetre, &jeu->mainMenu.btn[2].posBtn);
            SDL_Flip(jeu->fenetre);
}
void manipulationBoutonDown(Game* jeu){
    
    if(jeu->mainMenu.btn[0].state==0&&jeu->mainMenu.btn[1].state==0&&jeu->mainMenu.btn[2].state==0){
                            //printf("%d \n",jeu->mainMenu.btn[0].state);
                            jeu->mainMenu.btn[0].state=1;
                            jeu->mainMenu.btn[1].state=0;
                            jeu->mainMenu.btn[2].state=0;
                            Mix_PlayChannel(1,jeu->son_click,0);
                            if(Mix_PlayChannel(1, jeu->son_click, 0)==-1) {
                                //printf("Mix_PlayChannel: %s\n",Mix_GetError());
                            }
                        }
                        else if(jeu->mainMenu.btn[0].state==1){
                            jeu->mainMenu.btn[0].state=0;
                            jeu->mainMenu.btn[1].state=1;
                            jeu->mainMenu.btn[2].state=0;
                            //Mix_PlayChannel(-1,son_click,0);
                        }
                        else if(jeu->mainMenu.btn[1].state==1){
                            jeu->mainMenu.btn[0].state=0;
                            jeu->mainMenu.btn[1].state=0;
                            jeu->mainMenu.btn[2].state=1;
                            //Mix_PlayChannel(-1,son_click,0);
                        }
                        else if(jeu->mainMenu.btn[2].state==1){
                            jeu->mainMenu.btn[0].state=1;
                            jeu->mainMenu.btn[1].state=0;
                            jeu->mainMenu.btn[2].state=0;
                            //Mix_PlayChannel(-1,son_click,1);
                        }

}
void manipulationBoutonUp(Game* jeu){
    if(jeu->mainMenu.btn[0].state==0&&jeu->mainMenu.btn[1].state==0&&jeu->mainMenu.btn[2].state==0){
                            jeu->mainMenu.btn[0].state=1;
                            jeu->mainMenu.btn[1].state=0;
                            jeu->mainMenu.btn[2].state=0;
                            
                        }
                        else if(jeu->mainMenu.btn[0].state==1){
                            jeu->mainMenu.btn[0].state=0;
                            jeu->mainMenu.btn[1].state=0;
                            jeu->mainMenu.btn[2].state=1;
                        }
                        else if(jeu->mainMenu.btn[1].state==1){
                            jeu->mainMenu.btn[0].state=1;
                            jeu->mainMenu.btn[1].state=0;
                            jeu->mainMenu.btn[2].state=0;
                        }
                        else if(jeu->mainMenu.btn[2].state==1){
                            jeu->mainMenu.btn[0].state=0;
                            jeu->mainMenu.btn[1].state=1;
                            jeu->mainMenu.btn[2].state=0;
                        }
}
void changementMenu(Game* jeu){
    if(jeu->mainMenu.btn[1].state==1){
        jeu->currentMenu=1;
    }
    if(jeu->mainMenu.btn[0].state==1){
        jeu->currentMenu=3;
    }
    if(jeu->mainMenu.btn[2].state==1){
        jeu->done=0;
    }
}
void mouseMotion(Game* jeu){
    SDL_GetMouseState(&mouseX,&mouseY);
            if (checkMouseInside(jeu->mainMenu.btn[0].posBtn,mouseX,mouseY)) {
                jeu->mainMenu.btn[0].state=1;
                jeu->mainMenu.btn[1].state=0;
                jeu->mainMenu.btn[2].state=0;
            }
            if (checkMouseInside(jeu->mainMenu.btn[1].posBtn,mouseX,mouseY)) {
                jeu->mainMenu.btn[0].state=0;
                jeu->mainMenu.btn[1].state=1;
                jeu->mainMenu.btn[2].state=0;
            }
            if (checkMouseInside(jeu->mainMenu.btn[2].posBtn,mouseX,mouseY)) {
                jeu->mainMenu.btn[0].state=0;
                jeu->mainMenu.btn[1].state=0;
                jeu->mainMenu.btn[2].state=1;
            }
}
void mouseBoutonsDown(Game* jeu,SDL_Event event){
    if(event.button.button==SDL_BUTTON_LEFT){
                    if(jeu->mainMenu.btn[0].state==1){
                        jeu->currentMenu=3;
                        //printf("yo\n");
                    }
                    else if(jeu->mainMenu.btn[1].state==1){
                        jeu->currentMenu=1;
                    }
                    if(jeu->mainMenu.btn[2].state==1){
                        jeu->done=0;
                    }
                }

}