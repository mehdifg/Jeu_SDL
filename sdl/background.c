/**
* @file fonction.c
* @brief background du jeu.
* @author mehdi FGAIER
* @version 0.1
* @date Mar 15, 2022
*
* Testing program for background initialisation/affichage/scrollilng/collision
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "header.h"
/**
* @brief To initialize the background b .
* @param b the background
* @return Nothing
*/
void initBack(background* b){
    b->gameBg = IMG_Load("ressources/background/bg.png");
    b->gameBgMasque = IMG_Load("ressources/background/mahdi codeee.png");
    b->posgameBgMasque.x=0;
    b->posgameBgMasque.y=0;
    b->posgameBgMasque.w=b->gameBgMasque->w;
    
    b->posgameBgMasque.h=b->gameBgMasque->h;
    b->posGameBg.x=0;
    b->posGameBg.y=0;
    
    b->posGameBg.w= b->gameBg->w;

    //printf("yo\n");
     b->posGameBg.h= (b->gameBg)->h;
    b->posCamera.x=0;
    b->posCamera.y=0;
    b->posCamera.w=screen_w;
    b->posCamera.h=screen_h;
    b->son = Mix_LoadMUS("/ressources/background/sonJeu.mp3");
    Mix_PlayMusic(b->son,-1);
    b->bird.imgBird[0] = IMG_Load("/home/nerone/Desktop/sdl/ressources/bird1.png");
    b->bird.imgBird[1] = IMG_Load("/home/nerone/Desktop/sdl/ressources/bird2.png");
    b->bird.imgBird[2] = IMG_Load("/home/nerone/Desktop/sdl/ressources/bird3.png");
    b->bird.posBird.x=10;
    b->bird.posBird.y=10;
    b->bird.posBird.w=b->bird.imgBird[0]->w;
    b->bird.posBird.h=b->bird.imgBird[0]->h;
    b->bird.num=0;
    b->currentSprite=0;
    b->bus.imgBus[0] = IMG_Load("ressources/poratail_fiinLVL1.png");
    b->bus.imgBus[1] = IMG_Load("ressources/portail_fiinLVL.png");
    b->bus.posBus.w = b->bus.imgBus[0]->w;
    b->bus.posBus.h = b->bus.imgBus[0]->h;
    b->bus.posBus.x =1800;
    b->bus.posBus.y = 350;
    b->bus.num=0;
}
/**
* @brief To show the background b on screen .
* @param b the background
* @param screen for game screen
* @return Nothing
*/
void afficherBack(background b, SDL_Surface* screen){
    SDL_BlitSurface(b.gameBg,&b.posCamera,screen,&b.posGameBg);
    //printf("yo\n");
}
/**
* @brief To move the camera so the background scroll.
* @param b the background
* @param direction direction we want to move the camera
* @param pasAvencement camera movement speed
* @return Nothing
*/
void scrolling(background* b,personne* p,int pasAvencement, map* m,int collision[]){ 
    int run = SDLK_LSHIFT;
  int right = SDLK_d;
  int left = SDLK_q;
  int attack = SDLK_x;
  int jumping = SDLK_z;
            if(p->keystate[right]){
                printf("%d\n",p->spritePos.x);
                if(p->spritePos.x<=screen_w/2||b->posCamera.x+screen_w>=b->posGameBg.w){
                    if(collision[2]==0&&collision[7]==0){
                        if(p->spritePos.x+p->spritePos.w<=screen_w){
                            p->spritePos.x+=10;
                            m->personne_pos_map.x+=1;
                        }
                    }
                }
                else{
                    b->posCamera.x+=10;
                    m->personne_pos_map.x+=1;
                }
            }
            if(p->keystate[left]){
                if(p->spritePos.x>=screen_w/2||b->posCamera.x==0){
                    if(collision[0]==0&&collision[3]==0){
                        if(p->spritePos.x>=0){
                            p->spritePos.x-=10;
                            m->personne_pos_map.x-=1;
                        }
                    }
                }
                else{
                    b->posCamera.x-=10;
                    m->personne_pos_map.x-= 1;
                }
            }
            

}
/**
* @brief To find pixels color.
* @param psurface background mask 
* @param x  absciss of reference point to test on "hero"
* @param y ordinate of reference point to test on "hero"
* @return color found
*/
SDL_Color getpixel ( SDL_Surface *psurface , int x , int y ) 
{
   SDL_Color color ; 
   Uint32 col = 0 ; 
   char* pPosition =(char*) psurface->pixels ; 
   pPosition+=(psurface->pitch * y ); 
   pPosition+=(psurface->format->BytesPerPixel * x ) ; 
   memcpy(&col,pPosition,psurface->format->BytesPerPixel) ; 
   SDL_GetRGB (col,psurface->format,&color.r,&color.g,&color.b); 
   return(color) ; 
}
/**
* @brief find if there is collision.
* @param p hero  
* @param Masque background mask
* @return if there is collision returns reference point where we found collision else return 10
*/
void collisionPP(personne p, SDL_Surface* Masque, int collision[] ){
    int tabx[7],taby[7],i;
	SDL_Color color1,color;
	color1.r = 0;
	color1.g = 255;
	color1.b = 255;
	tabx[0]=p.spritePos.x;
	tabx[1]=(p.spritePos.x)+((p.spritePos.w)/2);
	tabx[2]=(p.spritePos.x+p.spritePos.w);
	tabx[3]=p.spritePos.x;
	tabx[4]=p.spritePos.x;
	tabx[5]=(p.spritePos.x)+((p.spritePos.w)/2);
	tabx[6]=(p.spritePos.x+p.spritePos.w);
	tabx[7]=(p.spritePos.x+p.spritePos.w);
	taby[0]=p.spritePos.y;
	taby[1]=p.spritePos.y;
	taby[2]=p.spritePos.y;
	taby[3]=(p.spritePos.y)+((p.spritePos.h)/2);
	taby[4]=(p.spritePos.y+p.spritePos.h);
	taby[5]=(p.spritePos.y+p.spritePos.h);
	taby[6]=(p.spritePos.y+p.spritePos.h);
	taby[7]=(p.spritePos.y)+((p.spritePos.h)/2);
	
	for(i=0;i<8;i++){
	    color=getpixel(Masque,tabx[i],taby[i]);
	    if(color.r==color1.r && color.b==color1.b && color.g==color1.g){
	    	collision[i]=1;
            
	    }
        else
            collision[i]=0;
	}
}
/**
* @brief add animation to background.
* @param b game background 
* @param ecran for game screen
* @return Nothing
*/
void animerBackground(background *b,SDL_Surface* ecran){
        if(b->bird.posBird.x<ecran->w){
            b->bird.posBird.x+=3;
        }
        
}
/**
* @brief animates the entity.
* @param b game background 
* @param ecran for game screen
* @return Nothing
*/
Uint32 animateSprite(Uint32 interval, void* param) {
    background* b = param;
    b->currentSprite++;
    if(b->currentSprite >= 3) {
        b->currentSprite = 0;
        return interval;
        }
    return 0;
}
/*void manageCollision(personne* p,int collision){
    switch (collision){
		case 0:
			p.posHero.y+=6;
		break;
		case 1:
			p.posHero.y+=6;
		break;
		case 2:
			p.posHero.x-=6;
		break;
		case 3:
			p.posHero.x+=6;
		break;
		case 4:
			p.posHero.x+=6;
		break;
		case 5:
			p.posHero.y-=6;
		break;
		case 6:
			p.posHero.x-=6;
		break;
		case 7:
			p.posHero.x-=6;
		break;
	}
}*/
void initialiserCollision(int tab[]){
    int i;
    for(i=0;i<8;i++){
        tab[i]=0;
    }
}
void finLevel(int* achieve,personne* p,background* b){
    if(p->spritePos.x==970){
        //p->spritePos.y= -2000;
        b->bus.num=1;
        SDL_Delay(500);
        *achieve = 1;
    }
}



