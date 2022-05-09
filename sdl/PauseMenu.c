void initialiserPauseMenu(Game* jeu){
    jeu->pauseMenu.pausemenuBg = IMG_Load("ressources/PauseMenu/templatePause.png");
    jeu->pauseMenu.posPausemenuBg.w = jeu->pauseMenu.pausemenuBg->w;
    jeu->pauseMenu.posPausemenuBg.h = jeu->pauseMenu.pausemenuBg->h;
    jeu->pauseMenu.posPausemenuBg.x = 381;
    jeu->pauseMenu.posPausemenuBg.y = 210;

    jeu->pauseMenu.btn[0].btn[0] = IMG_Load("ressources/PauseMenu/resumeButtonNs.png");
    jeu->pauseMenu.btn[0].btn[1] = IMG_Load("ressources/PauseMenu/resumeButtonS.png");
    jeu->pauseMenu.btn[0].posBtn.x = 550;
    jeu->pauseMenu.btn[0].posBtn.y = 350;
    jeu->pauseMenu.btn[0].posBtn.w = jeu->pauseMenu.btn[0].btn[0]->w;
    jeu->pauseMenu.btn[0].posBtn.h = jeu->pauseMenu.btn[0].btn[0]->h;
    
    jeu->pauseMenu.btn[1].btn[0] = IMG_Load("ressources/PauseMenu/saveButtonNs.png");
    jeu->pauseMenu.btn[1].btn[1] = IMG_Load("ressources/PauseMenu/saveButtonS.png");
    jeu->pauseMenu.btn[1].posBtn.x = 550;
    jeu->pauseMenu.btn[1].posBtn.y = 380;
    jeu->pauseMenu.btn[1].posBtn.w = jeu->pauseMenu.btn[1].btn[0]->w;
    jeu->pauseMenu.btn[1].posBtn.h = jeu->pauseMenu.btn[1].btn[0]->h;
    
    jeu->pauseMenu.btn[2].btn[0] = IMG_Load("ressources/PauseMenu/quitButtonNs.png");
    jeu->pauseMenu.btn[2].btn[1] = IMG_Load("ressources/PauseMenu/quitButtonS.png");
    jeu->pauseMenu.btn[2].posBtn.x = 550;
    jeu->pauseMenu.btn[2].posBtn.y = 410;
    jeu->pauseMenu.btn[2].posBtn.w = jeu->pauseMenu.btn[2].btn[0]->w;
    jeu->pauseMenu.btn[2].posBtn.h = jeu->pauseMenu.btn[2].btn[0]->h;
}
void affichagePasueMenu(Game* jeu){
    SDL_BlitSurface(jeu->pauseMenu.pausemenuBg,NULL,jeu->fenetre,&jeu->pauseMenu.posPausemenuBg);
    SDL_BlitSurface(jeu->pauseMenu.btn[0].btn[jeu->pauseMenu.btn[0].state],NULL,jeu->fenetre,&jeu->pauseMenu.btn[0].posBtn);
    SDL_BlitSurface(jeu->pauseMenu.btn[1].btn[jeu->pauseMenu.btn[1].state],NULL,jeu->fenetre,&jeu->pauseMenu.btn[1].posBtn);
    SDL_BlitSurface(jeu->pauseMenu.btn[2].btn[jeu->pauseMenu.btn[2].state],NULL,jeu->fenetre,&jeu->pauseMenu.btn[2].posBtn);
    SDL_Flip(jeu->fenetre);
}
void pauseMousemotion(Game* jeu){
    SDL_GetMouseState(&mouseX,&mouseY);
    if (checkMouseInside(jeu->pauseMenu.btn[0].posBtn,mouseX,mouseY)){
        jeu->pauseMenu.btn[0].state = 1;
        jeu->pauseMenu.btn[1].state = 0;
        jeu->pauseMenu.btn[2].state = 0;
    }
    if (checkMouseInside(jeu->pauseMenu.btn[1].posBtn,mouseX,mouseY)){
        jeu->pauseMenu.btn[0].state = 0;
        jeu->pauseMenu.btn[1].state = 1;
        jeu->pauseMenu.btn[2].state = 0;
    }
    if (checkMouseInside(jeu->pauseMenu.btn[2].posBtn,mouseX,mouseY)){
        jeu->pauseMenu.btn[0].state = 0;
        jeu->pauseMenu.btn[1].state = 0;
        jeu->pauseMenu.btn[2].state = 1;
    }

}
void managepauseMouse(Game* jeu){
    if(jeu->pauseMenu.btn[0].state = 1){
        jeu->currentMenu = 2;
    }
    if(jeu->pauseMenu.btn[2].state = 1){
        jeu->currentMenu = 0;
    }
}