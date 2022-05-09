void initialisationLevelMenu(Game* jeu){
    for(int i=0;i<3;i++){
        jeu->levelmenu.btn[i].state=0;
    }
    jeu->levelmenu.levelBg = IMG_Load("ressources/ressource_background_lvl/backgroundlvl.png");
    jeu->levelmenu.poslevelBg.x = 0;
    jeu->levelmenu.poslevelBg.y = 0;
    jeu->levelmenu.poslevelBg.w = jeu->levelmenu.levelBg->w;
    jeu->levelmenu.poslevelBg.h = jeu->levelmenu.levelBg->h;
    
    jeu->levelmenu.btn[0].btn[0] = IMG_Load("ressources/ressource_background_lvl/lvl1-ns.png");
    jeu->levelmenu.btn[0].btn[1] = IMG_Load("ressources/ressource_background_lvl/lvl1-s.png");
    jeu->levelmenu.btn[0].posBtn.x = 485;
    jeu->levelmenu.btn[0].posBtn.y = 355;
    jeu->levelmenu.btn[0].posBtn.w = jeu->levelmenu.btn[0].btn[0]->w;
    jeu->levelmenu.btn[0].posBtn.h = jeu->levelmenu.btn[0].btn[0]->h;
    
    jeu->levelmenu.btn[1].btn[0] = IMG_Load("ressources/ressource_background_lvl/lvl2-ns.png");
    jeu->levelmenu.btn[1].btn[1] = IMG_Load("ressources/ressource_background_lvl/lvl2-s.png");
    jeu->levelmenu.btn[1].posBtn.x = 635;
    jeu->levelmenu.btn[1].posBtn.y = 190;
    jeu->levelmenu.btn[1].posBtn.w = jeu->levelmenu.btn[1].btn[0]->w;
    jeu->levelmenu.btn[1].posBtn.h = jeu->levelmenu.btn[1].btn[0]->h;
    
    jeu->levelmenu.btn[2].btn[0] = IMG_Load("ressources/ressource_background_lvl/lvl3-ns.png");
    jeu->levelmenu.btn[2].btn[1] = IMG_Load("ressources/ressource_background_lvl/lvl3-s.png");
    jeu->levelmenu.btn[2].posBtn.x = 650;
    jeu->levelmenu.btn[2].posBtn.y = 120;
    jeu->levelmenu.btn[2].posBtn.w = jeu->levelmenu.btn[2].btn[0]->w;
    jeu->levelmenu.btn[2].posBtn.h = jeu->levelmenu.btn[2].btn[0]->h;

}
void affichageLevelMenu(Game* jeu){
    SDL_BlitSurface(jeu->levelmenu.levelBg,NULL,jeu->fenetre,&jeu->levelmenu.poslevelBg);
    SDL_BlitSurface(jeu->levelmenu.btn[0].btn[jeu->levelmenu.btn[0].state],NULL,jeu->fenetre,&jeu->levelmenu.btn[0].posBtn);
    SDL_BlitSurface(jeu->levelmenu.btn[1].btn[jeu->levelmenu.btn[1].state],NULL,jeu->fenetre,&jeu->levelmenu.btn[1].posBtn);
    SDL_BlitSurface(jeu->levelmenu.btn[2].btn[jeu->levelmenu.btn[2].state],NULL,jeu->fenetre,&jeu->levelmenu.btn[2].posBtn);
    SDL_Flip(jeu->fenetre);
}
void levelsMousemotion(Game* jeu){
    SDL_GetMouseState(&mouseX,&mouseY);
    if (checkMouseInside(jeu->levelmenu.btn[0].posBtn,mouseX,mouseY)){
        jeu->levelmenu.btn[0].state = 1;
        jeu->levelmenu.btn[1].state = 0;
        jeu->levelmenu.btn[2].state = 0;
    }
    if (checkMouseInside(jeu->levelmenu.btn[1].posBtn,mouseX,mouseY)){
        jeu->levelmenu.btn[0].state = 0;
        jeu->levelmenu.btn[1].state = 1;
        jeu->levelmenu.btn[2].state = 0;
    }
    if (checkMouseInside(jeu->levelmenu.btn[2].posBtn,mouseX,mouseY)){
        jeu->levelmenu.btn[0].state = 0;
        jeu->levelmenu.btn[1].state = 0;
        jeu->levelmenu.btn[2].state = 1;
    }

}
void managelevelsMouse(Game* jeu){
    if(jeu->levelmenu.btn[0].state = 1){
        jeu->currentMenu = 2;
        printf("%d\n",jeu->currentMenu);
    }
}
/*void managelevelKey(Game* jeu){
    switch(event.key.keysym.sym){
        
    }
}*/