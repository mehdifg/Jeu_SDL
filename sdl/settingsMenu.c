// #include <stdio.h>
// #include "SDL/SDL.h"
// #include "SDL/SDL_image.h"
// #include "SDL/SDL_mixer.h"
// #include "SDL/SDL_ttf.h"
// #include "header.h"
void initialiserSettings(Game* jeu){
    SDL_BlitSurface(jeu->settingmenu.SettingBg, NULL, jeu->fenetre, &jeu->settingmenu.posSettingBg);
    SDL_BlitSurface(jeu->settingmenu.sliders.slider[jeu->settingmenu.sliders.niveau],NULL,jeu->fenetre,&jeu->settingmenu.sliders.posSlider);
    SDL_BlitSurface(jeu->settingmenu.btn[0].btn[jeu->settingmenu.btn[0].state],NULL,jeu->fenetre,&jeu->settingmenu.btn[0].posBtn);
    SDL_BlitSurface(jeu->settingmenu.btn[1].btn[jeu->settingmenu.btn[1].state],NULL,jeu->fenetre,&jeu->settingmenu.btn[1].posBtn);
    SDL_Flip(jeu->fenetre);
}
void volumeDecrease(Game* jeu){
    if(jeu->bgvolume>0){
        jeu->settingmenu.btn[1].state=1;
        jeu->settingmenu.btn[0].state=0;
        jeu->bgvolume=jeu->bgvolume-32;
        jeu->settingmenu.sliders.niveau=jeu->settingmenu.sliders.niveau-1;
    }
}
void volumeIncrease(Game* jeu){
    if(jeu->bgvolume<128){
        jeu->settingmenu.btn[0].state=1;
        jeu->settingmenu.btn[1].state=0;
        jeu->bgvolume=jeu->bgvolume+32;
        jeu->settingmenu.sliders.niveau=jeu->settingmenu.sliders.niveau+1;
    }
}
void settingsMouseMotion(Game* jeu){
    SDL_GetMouseState(&mouseX,&mouseY);
    if (checkMouseInside(jeu->settingmenu.btn[0].posBtn,mouseX,mouseY)){
        jeu->settingmenu.btn[0].state = 1;
        jeu->settingmenu.btn[1].state = 0;
    }
    if (checkMouseInside(jeu->settingmenu.btn[1].posBtn,mouseX,mouseY)){
        jeu->settingmenu.btn[0].state = 0;
        jeu->settingmenu.btn[1].state = 1;
    }
}
void manageAudioMouse(Game* jeu){
    if(jeu->bgvolume>0&&jeu->settingmenu.btn[1].state==1){
        jeu->bgvolume=jeu->bgvolume-32;
        jeu->settingmenu.sliders.niveau=jeu->settingmenu.sliders.niveau-1;
    }
    if(jeu->bgvolume<128&&jeu->settingmenu.btn[0].state == 1){
        jeu->bgvolume=jeu->bgvolume+32;
        jeu->settingmenu.sliders.niveau=jeu->settingmenu.sliders.niveau+1;
    }
}