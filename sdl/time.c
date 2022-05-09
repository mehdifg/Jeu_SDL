/**
* @file time.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for minimap
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "time.h"
/**
* @brief To initialize timer .
* @param temps

* @return Nothing
*/
void Timer(int *tempsdebut)
{
    
   if( SDL_GetTicks() - *tempsdebut >= 1000 ) // tekhou kadech men milliseconds bech ki tousel el 1000 t3awed // 
    {
        *tempsdebut = SDL_GetTicks() ;
      
      
    }
  
} 
int loadFonttime(Text* T, char* path)
{
    TTF_Font* police = NULL;

    if(TTF_Init() == -1) {
        printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        return -1;
    }
    T->police= TTF_OpenFont(path,50);//pathn hoa esm l font o 60 l taile ( kima imgload ema thot police )
    if (police == NULL) {
        printf("Unable to load Font: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
}
int initTexttime(Text* T)
{ int testload;
    T->couleurTxt.r = 0; 
    T->couleurTxt.g = 0; 
    T->couleurTxt.b = 0;

    strcpy(T->txt, ""); 
    T->positionText.x = 977; 
    T->positionText.y = 150; 
    testload=loadFonttime(T,"ressources/Arabica.ttf");
    T->textSurface=NULL;
    return testload;   
}
/**
* @brief To initialize temps .
* @param the time t 

* @return Nothing
*/
void inittemps(Time *t)
{   int test; 
	t->tempsdebut=SDL_GetTicks();
	t->mm=0;
	t->ss=0;
	test=initTexttime(&t->temps);
} 
/**
* @brief To initialize the text   .
* @param t the text 
 
* @return Nothing
*/





void update_time(Time* T)
{   int ts;
    Timer(&T->tempsdebut);
    ts=T->tempsdebut/1000;
    T->mm=ts/ 60;
    T->ss=ts % 60;
    if(T->mm<10&&T->ss<10)
       sprintf(T->temps.txt," * time :  0%d:0%d * ",T->mm,T->ss);  
    else if(T->mm<10&&T->ss>10)
        sprintf(T->temps.txt," * time : 0%d:%d * ",T->mm,T->ss); 
    else if(T->mm>10&&T->ss<10)
          sprintf(T->temps.txt," * time :  %d:0%d * ",T->mm,T->ss); 
    /*else
         sprintf(T->temps.txt,"*** time :%d:%d  ***",T->mm,T->ss); */
    T->temps.textSurface=TTF_RenderText_Solid(T->temps.police,T->temps.txt,T->temps.couleurTxt);//ttfrender tekho l police o txt o couleur taa l text eli besh taficchiih
}
void displaytime(Time T,SDL_Surface *screen) // tafichi el kol e time welli yemchy kodemha // 
{
    
     
     SDL_BlitSurface(T.temps.textSurface,NULL,screen,&(T.temps.positionText)); // affihi text marra barka fel screen fel position hedhi // 

}

void freeTexttime(Text T) // faraghna memoire // 
{
    TTF_CloseFont(T.police); 
    TTF_Quit();    // okhrejli mel bib ta lektiba // 
}

